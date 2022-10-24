# About The Project

This project is a first attempt at building a portable battery-powered digital synthesiser using a STM32F407VG Discovery Board and a Korg NanoKontol 2 MIDI Controller. Please try it out and give your feedback online or on the back of this sheet.

The project was coded using the dedicated synthesis programming language [Faust](https://faust.grame.fr), with the aim being to enable synthesiser designs to be prototyped interactively in the browser, then uploaded to the board. The code for the whole project can be found [here](https://github.com/sidechained/Faust2STMSynth) and is a fork of the excellent [Dekrispator](https://github.com/MrBlueXav/Dekrispator_v2) synthesiser project, using their drivers as a template. The [STM32F4-Synth](https://github.com/pierstitus/STM32F4-Synth) project was also very helpful.

# Getting Connected

1. First, ensure the short cable on the left hand side is plugged into both the NanoKontrol (top connection) and the discovery board (bottom connection).

2. Connect a source source (typically headphones or a powered speaker) to the 3.5mm audio jack on the left hand side of the case.

3. To power-on the synth, plug the loose USB cable (hanging from the right hand side of the case) into one of the empty USB ports (on the same side). The PWR indicator on the top left of the synthesiser should come on.

NOTE: If it doesn't, the power bank likely needs charging. Plug the loose USB cable instead into any standard USB phone-charger (specs) and wait a while.

4. Once powered-on, the synth does not initially make sound. To hear anything you need to first turn up the 'E1 LEVEL' and/or 'E2 LEVEL' faders. Once you hear something, begin adjusting the knobs at the top, paying partcular attention to the volume control on the far right (take care, volume can jump loudly!). Each control will need to be adjusted once to reach it's 'true' value.

# SawSynth Design - How The Synth Works

SawSynth uses classic additive synthesis model, consisting of three saw wave oscillators which are combined and sent through a low pass 'moog-style' filter. Two of oscillators can be detuned to create 'thicker' sounds. The oscillators exhibit noise artifacts at lower frequencies, which the synth a raw, dirty sound in the low range.

SawSynth also features two independant envelopes, which can manually or automatically control combinations of amplitude (i.e. volume), oscillator frequency (i.e. pitch) and filter frequency. Here and below, we will just describe the controls for Envelope 1.

To quickly hear the effect of Envelope 1, place it in automatic mode, by pressing the AE1ON button once (lights red). This will create a retriggering Attack-Release envelope, with times set by knobs 6 and 7, respectively. Now adjust faders 3, 4 and 5 as you like, to have the envelope modulate volume, pitch or filter frequency by setting their depths. When the AE1ON button is off, fader 1 (E1 LEVEL) manually controls the level of the envelope.

The full range of controls are described as follows:

Knobs 1-8:
1. OSC FREQ			master pitch reference for all three saw waves
					ranges from 138.59Hz (MIDI Note 49) to 1318.51Hz (MIDI Note 88)
2. DETUNE 1			slightly detune the second of the three saw oscillators
3. DETUNE 2			slightly detune the third of the three saw oscillators
4. FILT FREQ		set cutoff frequency of the moog-style low-pass filter
5. FILT RES			set resonance of the moog-style low-pass filter ('sings' at high values)
6. AENV ATK			set the attack time of the automatic envelope
7. AENV RLS			set the release time of the automatic envelope
					NOTE: ENV2 operates at twice the speed of ENV1!
8. MAIN VOL			does what it says on the tin (can distort when too loud!)

Faders:
1. E1 LEVEL 		sets the current level of the envelope (only works when AE1ON is set to off)
3. E1 AMP DEPTH		sets the amount of amplitude modulation, when the envelope is at it's highest
4. E1 OSC DEPTH		sets the amount of pitch modulation, when the envelope is at it's highest
5. E1 FILT DEPTH	sets the amount of filter frequency modulation, when the envelope is at it's highest
(same for Faders 2, 6, 7, & 8 but controlling Envelope 2)

Transport:
E1>AMP				map envelope 1 to amplitude (on by default, when off E1 AMP DEPTH has no effect)
E1>OSC				map envelope 1 to pitch (on by default, when off E1 OSC DEPTH has no effect)
E1>FILT				map envelope 1 to filter (on by default, when off E1 FILT DEPTH has no effect)
AE1ON				places Envelope 1 into automatic mode (E1 LEVEL no longer has any effect)
(these controls are also repeated for Envelope 2)
MUTE				simply mutes the entire output of the synth

# Code Your Own Version

As mentioned previously, the project was designed so that you can easily code your own synth and upload it to the board. Here I explain how to do this. This requires that you have the [arm toolchain](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)* and [Faust](https://faust.grame.fr/downloads/) installed locally on your system.

* Note: I installed 'arm-gnu-toolchain-12.2.MPACBTI-Bet1-darwin-x86_64-arm-none-eabi.pkg'

NOTE: Currently, many of the more demanding time-based audio effects available in Faust (reverbs, delays etc) are not working on the STM discovery board, so stick to the oscillators, envelopes etc for now. I hope to be able to fix this soon.

1. Disconnect the cable on the left hand side and instead connect the NanoKontrol2 (top output) to your PC (requires additional mini-USB to standard-USB cable).

2. Open [Faust](https://faust.grame.fr) in your browser (Chrome recommended!) and begin coding your new synth. When creating the user interface for your synth, ALL controls must be hsliders. Yes that even means buttons (this can be achieved by setting the step parameter of the hslider to 1). See the [SawSynth Faust code](https://github.com/sidechained/Faust2STMSynth/blob/dekrispatorV3/Synth/mydsp-faustCode.dsp) for reference or to use as a template.

3. Assign your interface controls to the appropriate MIDI CC's for the NanoKontrol 2 by including \[midi:ctrl CC CHANNEL\] in the name. It also helps to follow the naming convention Control:Parameter i.e. Knob4:Filter Frequency. `si.smoo` is recommended in order to avoid 'zipper noise' i.e. nasty sonic jumps when adjusting controls. For example:

`filtfr = hslider("[03]Knob4:Filter Frequency[unit:Hz][midi:ctrl 19 1]", 3000, 0, 15000, 10) : si.smoo;`

NOTE: We are using the standard NanoKontrol 2 midi template, as found in the Korg Kontrol Editor.

4. Export the code using the truck icon, naming it 'mydsp', choosing Platform 'source' and Architecture 'c', then click Compile, followed by Download.

5. Clone the [github repo](https://github.com/sidechained/Faust2STMSynth) locally, then copy the extracted files from Step 4
(mydsp.dsp and mydsp.c) into the /Synth directory in the repo.

6. In terminal, navigate to the root folder of the repo and then into the "Release" folder. Open the 'makefile' in the text editor of your choice, editing the first two lines (ARM_PATH and FAUST_PATH) to reference the correct locations of these on your system.

7. Still in the  "Release" folder, run 'make' to compile the project, then 'make flash' to flash it to the STM32F407VG discovery board (connected to your PC via the larger of the two USB connectors on the board, mini-B). After flashing, harsh noise can be heard from the audio output. Unplug and replug power to allow the new synth to be heard/controlled.

8. Disconnect the NanoKontrol from your PC and reconnect it to the discovery board's USB OTG port using the short cable mentioned previously.