// Author: Xavier Halgand & Graham Booth

#include "MIDI_application.h"

#define RX_BUFF_SIZE 64 /* USB MIDI buffer : max received data 64 bytes */

uint8_t MIDI_RX_Buffer[RX_BUFF_SIZE]; // MIDI reception buffer

int8_t currentNote;
int8_t velocity;
uint8_t notes_On[128] = {0};
int8_t notesCount = 0; // number of notes on (keys pressed)

// Table of notes frequencies: 107 notes, first one is MIDI note #21 (A0), last one is #127 (G9)

const float_t notesFreq[] =
{
/*  A0 --> */ 27.50000000, 29.13523509, 30.86770633,
		32.70319566, // <-- C1 (#24)
		34.64782887, 36.70809599, 38.89087297, 41.20344461,
		43.65352893, 46.24930284, 48.99942950, 51.91308720,
		55.00000000, 58.27047019, 61.73541266,
		65.40639133, // <-- C2
		69.29565774, 73.41619198, 77.78174593, 82.40688923,
		87.30705786, 92.49860568, 97.99885900, 103.82617439,
		110.00000000, 116.54094038, 123.47082531,
		130.81278265, //<-- C3
		138.59131549, 146.83238396, 155.56349186, 164.81377846,
		174.61411572, 184.99721136, 195.99771799, 207.65234879,
		220.00000000, 233.08188076, 246.94165063,
		261.62556530, // <-- C4
		277.18263098,293.66476792, 311.12698372, 329.62755691,
		349.22823143, 369.99442271, 391.99543598, 415.30469758,
		440.00000000, 466.16376152, 493.88330126,
		523.25113060, // <-- C5
		554.36526195, 587.32953583, 622.25396744, 659.25511383,
		698.45646287, 739.98884542, 783.99087196, 830.60939516,
		880.00000000, 932.32752304, 987.76660251,
		1046.50226120, // <-- C6
		1108.73052391, 1174.65907167, 1244.50793489, 1318.51022765,
		1396.91292573, 1479.97769085, 1567.98174393, 1661.21879032,
		1760.00000000, 1864.65504607, 1975.53320502,
		2093.00452240, // <-- C7
		2217.46104781, 2349.31814334, 2489.01586978, 2637.02045530,
		2793.82585146, 2959.95538169, 3135.96348785, 3322.43758064,
		3520.00000000, 3729.31009214, 3951.06641005,
		4186.00904481, // <-- C8
		4434.92209563, 4698.63628668, 4978.03173955, 5274.04091061,
		5587.65170293, 5919.91076339, 6271.92697571, 6644.87516128,
		7040.00000000, 7458.62018429, 7902.13282010,
		8372.01808962, // <-- C9
		8869.84419126, 9397.27257336, 9956.06347911, 10548.08182121,
		11175.30340586, 11839.82152677, 12543.85395142
};

void ProcessReceivedMidiDatas(void);

void MIDI_Application(void)
{
	if (Appli_state == APPLICATION_READY)
	{
		USBH_MIDI_Receive(&hUSBHost, MIDI_RX_Buffer, RX_BUFF_SIZE); // just once at the beginning, start the first reception
		Appli_state = APPLICATION_RUNNING;
	}
	if (Appli_state == APPLICATION_RUNNING)
	{
		// DO NOTHING
	}
	if (Appli_state == APPLICATION_DISCONNECT)
	{
		Appli_state = APPLICATION_IDLE;
		USBH_MIDI_Stop(&hUSBHost);
	}
}

void USBH_MIDI_ReceiveCallback(USBH_HandleTypeDef *phost)
{
	ProcessReceivedMidiDatas();
	USBH_MIDI_Receive(&hUSBHost, MIDI_RX_Buffer, RX_BUFF_SIZE); // start a new reception
}

void Reset_notes_On(void)
{
	notesCount = 0;
	for (uint8_t i = 0; i < 128; i++)
		notes_On[i] = 0;
}

void ProcessReceivedMidiDatas(void)
{
	uint16_t numberOfPackets;
	uint8_t *ptr = MIDI_RX_Buffer;
	midi_package_t pack;

	numberOfPackets = USBH_MIDI_GetLastReceivedDataSize(&hUSBHost) / 4; //each USB midi package is 4 bytes long

	while (numberOfPackets--)
	{
		pack.cin_cable = *ptr;
		ptr++;
		pack.evnt0 = *ptr;
		ptr++;
		pack.evnt1 = *ptr;
		ptr++;
		pack.evnt2 = *ptr;
		ptr++;

		if (pack.cin_cable != 0) // if incoming midi message...
			start_LED_On(LED_Blue, 8);

		if ((pack.evnt0 & 0xF0) == 0x80) // Note off ? -------------------------------
		{
			uint8_t noteOff = pack.evnt1;
			//if (notes_On[noteOff] == 1) {
			notes_On[noteOff] = 0;
			notesCount--;
			if (notesCount <= 0) // no more keys pressed
			{
				// NOTE OFF FUNCTION CALL GOES HERE
				notesCount = 0;
			}
			else // some keys still pressed... (legato)
			{
				if ((noteOff - LOWEST_NOTE) == currentNote) // then let sound the lowest key pressed
				{
					uint8_t i;
					for (i = 0; i < 128; i++)
					{
						if (notes_On[i] == 1) // find the lowest key pressed
							break;
					}
					currentNote = i - LOWEST_NOTE; // conversion for notesFreq[]
				}
			}
			//}
		}
		else if ((pack.evnt0 & 0xF0) == 0x90) // Note on ----------------------------
		{
			uint8_t noteOn = pack.evnt1;
			velocity = pack.evnt2;
			if (velocity > 0) // True note on !
			{
				if (noteOn < LOWEST_NOTE) // filtering notes
				{
					currentNote = 0;
				}
				else
				{
					currentNote = noteOn - LOWEST_NOTE; // conversion for notesFreq[]
				}
				// NOTE ON FUNCTION CALL GOES HERE
				notesCount++;
				notes_On[noteOn] = 1;
			}
			else
			{
				// ---------  Sometimes Note On with zero velocity means Note Off !
				notes_On[noteOn] = 0;
				notesCount--;
				if (notesCount <= 0)
				{
					// NOTE OFF FUNCTION CALL GOES HERE
					notesCount = 0;
				}
				else
				{
					if ((noteOn - LOWEST_NOTE) == currentNote)
					{
						uint8_t i;
						for (i = 0; i < 128; i++)
						{
							if (notes_On[i] == 1) // find the lowest key pressed
								break;
						}
						currentNote = i - LOWEST_NOTE; // conversion for notesFreq[]
					}
				}
			}
		}
		else if ((pack.evnt0 & 0xF0) == 0xA0) // Aftertouch
		{
			// AFTERTOUCH FUNCTION CALL GOES HERE(pack.evnt2);
		}
		else if ((pack.evnt0 & 0xF0) == 0xE0) // Pitch Bend
		{
			// PITCHBEND FUNCTION CALL GOES HERE(pack.evnt2);
			// int16_t pitchBend = ((pack.evnt1 << 7) + pack.evnt2) - 0x2000;
		}

		if ((pack.evnt0 & 0xF0) == 0xB0) /* If incoming midi message is a Control Change... */
		{
			uint8_t val = pack.evnt2;

			switch (pack.evnt1) // CC number
			{
			// MIDI CC MAPPING FOR KORG NANOKONTROL 2

			// FADERS 1-8
			case 0:
				set_filter_cutoffFreqL(val);
				break;
			case 1:
				set_filter_cutoffFreqR(val);
				break;
			case 2:
				set_filter_q(val);
				break;
			case 3:
				set_filter_gain(val);
				break;
			case 4:
				// unmapped
				break;
			case 5:
				// unmapped
				break;
			case 6:
				// unmapped
				break;
			case 7:
				// unmapped
				break;

			// KNOBS 1-8
			case 16:
				// unmapped
				break;
			case 17:
				// unmapped
				break;
			case 18:
				// unmapped
				break;
			case 19:
				// unmapped
				break;
			case 20:
				// unmapped
				break;
			case 21:
				// unmapped
				break;
			case 22:
				// unmapped
				break;
			case 23:
				// unmapped
				break;

			// SOLO BUTTONS 1-8
			case 32:
				// unmapped
				break;
			case 33: 
				// unmapped
				break;
			case 34:
				// unmapped
				break;
			case 35:
				// unmapped
				break;
			case 36:
				// unmapped
				break;
			case 37:
				// unmapped
				break;
			case 38:
				// unmapped
				break;
			case 39:
				// unmapped
				break;

			// MUTE BUTTONS 1-8
			case 48:
				// unmapped
				break;
			case 49:
				// unmapped
				break;
			case 50:
				// unmapped
				break;
			case 51:
				// unmapped
				break;
			case 52:
				// unmapped
				break;
			case 53:
				// unmapped
				break;
			case 54:
				// unmapped
				break;
			case 55:
				// unmapped
				break;

			// // RECORD ARM BUTTONS 1-8 (commented out as these currently play notes 96-103)
			// case 64:
			// 	// unmapped
			// 	break;
			// case 65:
			// 	// unmapped
			// 	break;
			// case 66:
			// 	// unmapped
			// 	break;
			// case 67:
			// 	// unmapped
			// 	break;
			// case 68:
			// 	// unmapped
			// 	break;
			// case 69:
			// 	// unmapped
			// 	break;
			// case 70:
			// 	// unmapped
			// 	break;
			// case 71:
			// 	// unmapped
			// 	break;

			// LOWER TRANSPORT SECTION
			case 43: // Rewind Button
				// unmapped
				break;
			case 44: // Fast Forward Button
				// unmapped
				break;
			case 42: // Stop
				// unmapped
				break;
			case 41: // Play
				// unmapped
				break;
			case 45: // Record
				break;
			
			// UPPER TRANSPORT SECTION
			case 46: // Cycle 
				// Delay_toggle(val);
				break;
			case 58: // Track Decrement (<)
				// unmapped
				break;
			case 59: // Track Increment (>)
				// unmapped
				break;
			case 60: // Marker Set
				// unmapped
				break;
			case 61: // Marker Increment (<)
				// unmapped
				break;
			case 62: // Marker Decrement (>)
				// unmapped
				break;
			}
		}
	}
}