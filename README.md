This is a fork of the original Dekrispator project, found [here](https://github.com/MrBlueXav/Dekrispator_v2), which allows a STM32F407VG Discovery board to be used as a standlone synthesiser and controlled over USB MIDI.

In this version, I swapped out the original synthesiser code for C code generated by [Faust](https://faust.grame.fr]) and updated the MIDI controller from the Korg NanoKontrol 1 to 2, making this a useful environment for developing embedded synthesisers. Any MIDI controller can be used with minimal changes to the code. Also, when the project gets beyond the prototyping stage, the MIDI control can relatively simply be swapped out for custom electronics (next on my to-do list!).

The original project was built with Eclipse, whereas I'm building on a Mac from the command line, so some ruthless edits may have been made :)

# Usage Instructions

In short:
- write some Faust code and export it as C source code
- define a set of interface functions in Synth/soundGen.c
- call them from Synth/MIDI_Application.c
- install [arm toolchain](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)* and [Faust](https://faust.grame.fr/downloads/) on your system and edit ARM_PATH and FAUST_PATH makefile entries to reference the correct locations of these on your system
- rebuild the project, flash it to the board and have fun!

* Note: I used 'arm-gnu-toolchain-12.2.MPACBTI-Bet1-darwin-x86_64-arm-none-eabi.pkg'

## 1. Writing/Exporting Faust Code

Write or copy some simple Faust code using the [Faust Online IDE](https://faustide.grame.fr). For the example included in this I repo I used the following code snippet, which can be found in [Synth/mydsp-faustcode.dsp](Synth/mydsp-faustcode.dsp).

```import("stdfaust.lib");

cutl = hslider("[0]cutoffFrequencyL",500,50,10000,0.01);
cutr = hslider("[1]cutoffFrequencyR",500,50,10000,0.01);
q = hslider("[2]q",5,1,30,0.1);
gain = hslider("[3]gain",1,0,1,0.01);

process = no.noise : _ <: fi.resonlp(cutl,q,gain),fi.resonlp(cutr,q,gain);
```

This produces stereo filtered-noise with four possible filter controls: Q, gain and separate cutoff frequencies for the left and right channels.

Once done, export the code from the IDE (via the truck icon) using the following settings:

- File Name: 'mydsp'
- Platform 'source'
- Architecture 'c'

Click 'compile', then 'download', then copy the contents of the downloaded folder into the Synth directory of this repo (overwriting the existing mydsp.c file). Note: the code can have any name, but the include statement in Synth/soundGen.c must also be altered i.e. `#include "mydsp.c"` -> `#include "<myfilename>.c"`

## 2. Writing a Set of User Interface Functions

Faust code is typically developed using a simple Graphical User Interface with buttons/sliders etc. In our example stereo noise-filter, there were four onscreen horizontal sliders controlling the four parameters. In Synth/mydsp.c, we can see how these are set to their initial values:

```
void instanceResetUserInterfacemydsp(mydsp* dsp) {
      dsp->fHslider0 = (FAUSTFLOAT)(5e+02f);
      dsp->fHslider1 = (FAUSTFLOAT)(5.0f);
      dsp->fHslider2 = (FAUSTFLOAT)(1.0f);
      dsp->fHslider3 = (FAUSTFLOAT)(5e+02f);
}
```

In addition, further down in the same file we can see what parameters they control (some lines have been omitted here for clarity):

```
void buildUserInterfacemydsp(mydsp* dsp, UIGlue* ui_interface) {
      ui_interface->addHorizontalSlider(ui_interface->uiInterface, "cutoffFrequencyL", &dsp->fHslider0, (FAUSTFLOAT)5e+02f, (FAUSTFLOAT)5e+01f, (FAUSTFLOAT)1e+04f, (FAUSTFLOAT)0.01f);
      ui_interface->addHorizontalSlider(ui_interface->uiInterface, "cutoffFrequencyR", &dsp->fHslider3, (FAUSTFLOAT)5e+02f, (FAUSTFLOAT)5e+01f, (FAUSTFLOAT)1e+04f, (FAUSTFLOAT)0.01f);
      ui_interface->addHorizontalSlider(ui_interface->uiInterface, "q", &dsp->fHslider1, (FAUSTFLOAT)5.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)3e+01f, (FAUSTFLOAT)0.1f);
      ui_interface->addHorizontalSlider(ui_interface->uiInterface, "gain", &dsp->fHslider2, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.01f);
}
```

So by writing a set of user interface functions in Synth/soundGen.c, we can expose the existing faust interface to MIDI control. As you can see in what follows, I have already done this for the four controls above (not forgetting to also add their prototypes to soundGen.h):

```
void set_filter_cutoffFreqL(int val) {
    float floval;
    floval = ((float)val/127) * 9950 + 50;
    dsp->fHslider0 = floval; // "[0]cutoffFrequencyL",500,50,10000,0.01   
}

void set_filter_cutoffFreqR(int val) {
    float floval;
    floval = ((float)val/127) * 9950 + 50;
    dsp->fHslider3 = floval; // "[1]cutoffFrequencyR",500,50,10000,0.01  
}

void set_filter_q(int val) {
    float floval;
    floval = ((float)val/127) * 29 + 1;
    dsp->fHslider1 = floval; // "[2]q",5,1,30,0.1);  
}

void set_filter_gain(int val) {
    float floval;
    floval = (float)val/127;
    dsp->fHslider2 = floval; // "[3]gain",1,0,1,0.01);    
}
```

These functions assume that MIDI CC values will come in as integers in the standard 0-127 range and will then be converted to floats and scaled accordingly (e.g. in the case of a filter cutoff frequency we require floats between 50-10000 (Hz)).

## 3. Adding MIDI Control

All that is left to do now is insert calls to our previously written functions into the Synth/MIDI_Application.c file. This is done towards the bottom of the `ProcessReceivedMidiDatas` function, pasting over the `// unmapped` sections with the appropriate function calls, as follows:

```
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
```

And so on... In my case I am using the Korg NanoKontrol2 as a generic MIDI controller and have modified the original Synth/MIDI_Application.c file to create a simple Control Change (CC) and Note mapping for all NanoKontrol2 controls. In the above snippet, the 0, 1, 2, 3 etc are the MIDI CC numbers which the NanoKontrol is mapped to. Feel free to edit this file to suit your own MIDI controller.

## 4. Remake and Flash

To remake and flash the edited code to the board, connect the board to your PC via the mini-B USB connector and run the following commands from the root repo directory:

```
cd Release
make clean
make
st-flash write Dekrispator_v2.bin 0x8000000
```

Note: for the last line to work, the st-link utility will have to be installed on your system. I installed [st-link using homebrew](https://formulae.brew.sh/formula/stlink).

# Further Aims

- Further simplify the makefile (change %.o %.d approach)
- Audio output seems a bit 'crispy' - solve strange clicks and pops within first few seconds of board power-up!
- Make into an official architecture file i.e. faust2stm32f4
https://faustdoc.grame.fr/manual/architectures/
- Add support for inbuilt microphone and accelerometers (see notes below)

# Notes

- (`CInterface.h` eliminates need to comment out 'meta' and 'ui' sections of mydsp.c code. More info [here](https://sourceforge.net/p/faudiostream/mailman/message/30907474/))
- General note: I did not have to #include "soundGen.h" from "MIDI_application.c"

# Notes on Using the Inbuilt MEMs Microphone and Accelerometers

- Q: do these have to use HAL library to work well with Dekrispator?
- A: Ideally, yes

STM32F4-Discovery_FW_V1.1.0/Project/Demonstration
Uses both the microphone and accelerometers
Performs a series of tests
      
```
Accelerometer_MEMS_Test(); // Move discovery kit to detect negative and positive acceleration values on X, Y and Z axis
USB_Test(); // USB Hardware connection
Audio_Test(); // Audio Hardware connection
Microphone_MEMS_Test(); // Microphone MEMS Hardware connection
```

Main functions are in selftest.c
Microphone uses I2S over SPI2
Q: Which library are these demos using? StdPer or HAL? A: StdPer
Dekrispator uses HAL
So best to find separate examples
Also need to be careful of peripheral conflicts (i.e. I2S for recording and playback)
Best would be to find a simultaneous audio record/playback example using HAL
STM32CubeF4 projects are good candidates, particularly this audio one here:
https://github.com/nguyenvuhung/STM32Cube_FW_F4/tree/master/Projects/STM32F4-Discovery/Applications/Audio/Audio_playback_and_record


## MEMs Microphone
ST-MEMS audio sensor omni-directional digital microphone
Vocoder project: https://github.com/Shaylin/stm32f4-discovery-vocoder (StdPeripheral Lib)

Also this demo, record to USB from microphone, playback (not simultaneously) (StdPeripheral Lib)
https://www.st.com/resource/en/application_note/an3997-audio-playback-and-recording-using-the-stm32f4discovery-stmicroelectronics.pdf
STM32F4-Discovery_FW_V1.1.0/Project/Audio_playback_and_record

## MEMS Accelerometer (LIS302DL)
ST MEMS 3-axis accelerometer

STM32F4-Discovery_FW_V1.1.0/Project/Peripheral_Examples/MEMS  (StdPeripheral Lib)
If the board is moved the acceleration is detected on x/Y axis and LEDs toggles according to the motion direction and speed

./STM32F4-Discovery_FW_V1.1.0/Utilities/STM32F4-Discovery/stm32f4_discovery_lis302dl.c

# Writing a Faust Architecture File

faust -a myArchitecture.c myDsp.dsp


- it can be .c as well as .cpp. Yes...see "Other Languages Than C++" section
the C backend needs additional CGlue.h and CInterface.h files, with the minimal-c file as a simple console mode example using them

- can it be more than one file? How? Yes

Generally, several files to connect to the audio layer, controller layer, and possibly other (MIDI, OSC...) have to be used. One of them is the main file and include the others. The -i option can be added to actually inline all #include "faust/xxx/yyy" headers (all files starting with faust) to produce a single self-contained unique file. Then a faust2xxx script has to be written to chain the Faust compilation step and the C++ compilation one (and possibly others). Look at the Developing a faust2xx Script section.

See "Embedded Platforms" section
-uim compiler option
faust -uim foo.dsp

## Types of Architecture

What kind of architecture? I need to look at an example. Perhaps minimal.c

./share/faust/minimal.c

Audio architecture - connect to a underlying audio layer
MIDI architecture - A MIDI architecture module typically connects a Faust program to the MIDI drivers.
UI architecture - links user actions (i.e., via graphic widgets, command line parameters, OSC messages, etc.) with the Faust program to control. 
DSP Architecture Modules - ?

Replace MIDI_Application with MIDI_Interface that just controls the existing MIDI spec coded in Faust

## Developing a New Architecture File


## Using faust2xx Scripts

The faust2xx scripts finally combine different architecture files to generate a ready-to-use application or plugin, etc... from a Faust DSP program. They typically combine the generated DSP with an UI architecture file and an audio architecture file. Most of the also have addition options like -midi, -nvoices <num>, -effect <auto|effect.dsp> or -soundfile to generate polyphonic instruments with or without effects, or audio file support. Look at the following page for a more complete description.

https://github.com/grame-cncm/faust/blob/master-dev/tools/faust2appls/faust2minimal