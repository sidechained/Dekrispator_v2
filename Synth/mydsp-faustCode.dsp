// V1.2: stripped back the user interface code to bare minimum
// - all controls are hsliders
// - got rid of knobs, as not much text can be displayed alongside them

import("stdfaust.lib");

declare options "[midi:on]"; // is this needed?

// USER INTERFACE CODE

// KNOBS 1-8:
freq = hslider("[00]Knob1:Oscillator Frequency[unit:PK][midi:ctrl 16 1]",49,0,88,0.01) : ba.pianokey2hz : si.smoo;
detune1 = 1 + 0.01 * hslider("[01]Knob2:Detune 1[unit:%%][midi:ctrl 17 1]",-0.1,-10,10,0.01) : si.smoo;
detune2 = 1 + 0.01 * hslider("[02]Knob3:Detune 2[unit:%%][midi:ctrl 18 1]",+0.1,-10,10,0.01) : si.smoo;
filtfr = hslider("[03]Knob4:Filter Frequency[unit:Hz][midi:ctrl 19 1]", 3000, 0, 15000, 10) : si.smoo;
filtres = hslider("[04]Knob5:Filter Resonance[midi:ctrl 20 1]", 0, 0, 1, 0.001) : si.smoo;
autoenv_attack1 = hslider("[05]Knob6:Autoenv Attack Time[midi:ctrl 21 1]", 0.5, 0, 2, 0.001) : si.smoo;
autoenv_release1 = hslider("[06]Knob7:Autoenv Release Time [midi:ctrl 22 1]", 0.5, 0.1, 2, 0.001);
amp = hslider("[07]Knob8:Master Volume[unit:dB][midi:ctrl 23 1]",-6,-120,10,0.1) : ba.db2linear : si.smoo;

// FADERS 1-8:
env1 = hslider("[08]Fader1:Env 1 Level[midi:ctrl 0 1]",0,0,1,0.001) : si.smoo;
env2 = hslider("[09]Fader1:Env 2 Level[midi:ctrl 1 1]",0,0,1,0.01) : si.smoo;
ampenv1depth = hslider("[10]Fader1:Amplitude Env1 Depth[midi:ctrl 2 1]",0,0,1,0.001) : si.smoo;
pitchenv1depth = hslider("[11]Fader1:Pitch Env1 Depth[unit:Hz][midi:ctrl 3 1]", 0, 0, 500, 1) : si.smoo;
filtenv1depth = hslider("[12]Fader1:Filter Env1 Depth[unit:Hz][midi:ctrl 4 1]",0,0,10000,0.001) : si.smoo;
ampenv2depth = hslider("[13]Fader1:Amplitude Env2 Depth[midi:ctrl 5 1]",0,0,1,0.001) : si.smoo;
pitchenv2depth = hslider("[14]Fader1:Pitch Env2 Depth[unit:Hz][midi:ctrl 6 1]", 0, 0, 500, 1) : si.smoo;
filtenv2depth = hslider("[15]Fader1:Filter Env2 Depth[unit:Hz][midi:ctrl 7 1]",0,0,10000,0.001) : si.smoo;

// TRANSPORT SECTION:
routeamptoenv1 = hslider("[16]Track < Button:Env1 > Amp[midi:ctrl 58 1]", 1, 0, 1, 1);
routepitchtoenv1 = hslider("[17]Track > Button:Env1 > Pitch[midi:ctrl 59 1]", 1, 0, 1, 1);
routefilttoenv1 = hslider("[18]Cycle Button:Env1 > Filter[midi:ctrl 46 1]", 1, 0, 1, 1);
routeamptoenv2 = hslider("[19]Set Marker Button:Env2 > Amp[midi:ctrl 60 1]", 1, 0, 1, 1);
routepitchtoenv2 = hslider("[20]Marker < Button:Env2 > Pitch[midi:ctrl 61 1]", 1, 0, 1, 1);
routefilttoenv2 = hslider("[21]Marker > Button:Env2 > Filter[midi:ctrl 62 1]", 1, 0, 1, 1);
autoenv1on = hslider("[22]Rewind Button: Auto Env 1 On[midi:ctrl 43 1]", 0, 0, 1, 1);
autoenv2on = hslider("[23]Fast-Forward Button:Auto Env 2 On[midi:ctrl 44 1]", 0, 0, 1, 1);
mute = 1-hslider("[24]Record Button: Mute Output[midi:ctrl 45 1]", 0, 0, 1, 1) : si.smoo;

// # SYNTHESIS CODE

portamento = 0.1;
// ENV 1:
autoenv_trigger1 = ba.pulse(ba.sec2samp(autoenv_attack1+autoenv_release1));
autoenv1 = en.ar(autoenv_attack1, autoenv_release1, autoenv_trigger1);
routedenv1 = env1,autoenv1 : ba.selectn(2, autoenv1on);
routedampenv1depth1 = 1,ampenv1depth: ba.selectn(2, routeamptoenv1);
ampenv1 = routedenv1 * 1-routedampenv2depth1;
routedpitchenv1depth = 1,pitchenv1depth : ba.selectn(2, routepitchtoenv1);
pitchenv1 = routedenv1 * routedpitchenv1depth;
routedfiltenv1depth = 1,filtenv1depth : ba.selectn(2, routefilttoenv1);
filtenv1 = routedenv1 * routedfiltenv1depth;
// ENV 2:
autoenv_attack2 = autoenv_attack1/2;
autoenv_release2 = autoenv_release1/2;
autoenv_trigger2 = ba.pulse(ba.sec2samp(autoenv_attack2+autoenv_release2));
autoenv2 = en.ar(autoenv_attack2, autoenv_release2, autoenv_trigger2);
routedenv2 = env2,autoenv2 : ba.selectn(2, autoenv2on);
routedampenv2depth1 = 1,ampenv2depth: ba.selectn(2, routeamptoenv2);
ampenv2 = routedenv2 * 1-routedampenv2depth1;
routedpitchenv2depth = 1,pitchenv2depth : ba.selectn(2, routepitchtoenv2);
pitchenv2 = routedenv2 * routedpitchenv2depth;
routedfiltenv2depth = 1,filtenv2depth : ba.selectn(2, routefilttoenv2);
filtenv2 = routedenv2 * routedfiltenv2depth;
// OSCILLATOR/FILTER/DELAY
sfreq = freq : si.smooth(ba.tau2pole(portamento)) + pitchenv1 + pitchenv2;
sawchoice = _ <: par(i,os.MAX_SAW_ORDER,os.sawN(i+1)) : ba.selectn(int(os.MAX_SAW_ORDER), int(3));
toneL = (amp/3) * (sawchoice(sfreq) + sawchoice(sfreq*detune1) * 0.3 + sawchoice(sfreq*detune2));
toneR = (amp/3) * (sawchoice(sfreq) + sawchoice(sfreq*detune1) + sawchoice(sfreq*detune2)) * 0.3;
filter = ve.moog_vcf_2b(filtres,filtfr + filtenv1 + filtenv2);
gain = (ampenv1 + ampenv2) * amp * mute * 0.5;
signal = toneL * gain,toneR * gain : filter,filter;
process = signal;