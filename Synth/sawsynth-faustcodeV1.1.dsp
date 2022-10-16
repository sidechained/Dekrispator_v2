import("stdfaust.lib");

// TODO LIST
// FIX: filter depth should be +- not just +
// FIX: amp envs don't appear to affect sound (not enough anyway!)
// DONE: all envelope depths set to zero at default
// DONE: lower max of pitchenv1depth and pitchenv2depth
// DONE: env switches default to on
// DONE: autoenv_release1 should have a minimum that isn't zero
// DONE: smooth all continuous controls to fix zipper noise
// DONE: remove echo until we get it working

declare options "[midi:on]"; // is this needed?

routeamptoenv1 = hslider("[0]Env1 > Amp[midi:ctrl 58 1][style:knob]", 1, 0, 1, 1); // prevTrack
routepitchtoenv1 = hslider("[1]Env1 > Pitch[midi:ctrl 59 1][style:knob]", 1, 0, 1, 1); // nextTrack
transport_row1 = hgroup("1", routeamptoenv1 + routepitchtoenv1);

routefilttoenv1 = hslider("[0]Env1 > Filter[midi:ctrl 46 1][style:knob]", 1, 0, 1, 1); // Cycle
routeamptoenv2 = hslider("[1]Env2 > Amp[midi:ctrl 60 1][style:knob]", 1, 0, 1, 1); // Set
routepitchtoenv2 = hslider("[2]Env2 > Pitch[midi:ctrl 61 1][style:knob]", 1, 0, 1, 1); // prevMark
routefilttoenv2 = hslider("[3]Env2 > Filter[midi:ctrl 62 1][style:knob]", 1, 0, 1, 1); // nextMark
transport_row2 = hgroup("2", routefilttoenv1 + routeamptoenv2 + routepitchtoenv2 + routefilttoenv2);

autoenv1on = hslider("[0]Auto Env 1 On[midi:ctrl 43 1][style:knob]", 0, 0, 1, 1); // rwd
autoenv2on = hslider("[1]Auto Env 2 On[midi:ctrl 44 1][style:knob]", 0, 0, 1, 1); // fwd
unused3 = hslider("[2]stop[midi:ctrl 42 1][style:knob]", 0, 0, 1, 1);
unused4 = hslider("[3]play[midi:ctrl 41 1][style:knob]", 0, 0, 1, 1);
mute = 1-hslider("[4]Mute Output[midi:ctrl 45 1][style:knob]", 0, 0, 1, 1) : si.smoo; // rec
transport_row3 = hgroup("3", autoenv1on + autoenv2on + unused3 + unused4 + mute);

transportSection = vgroup("[0]Transport", transport_row1 + transport_row2 + transport_row3);

unused5 = button("[0]S1[midi:ctrl 32 1]");
unused6 = button("[1]M1[midi:ctrl 48 1]");
unused7 = button("[2]R1[midi:ctrl 64 1]");
buts1 = vgroup("buttons", unused5+unused6+unused7);

freq = hslider("[0]Oscillator Frequency[unit:PK][midi:ctrl 16 1] [style:knob]",49,0,88,0.01) : ba.pianokey2hz : si.smoo; // knob
env1 = vslider("[1]env1[midi:ctrl 0 1]",0,0,1,0.001) : si.smoo; // fader
knobfader1 = vgroup("knobfader",freq + env1);

hg1 = hgroup("1", buts1 + knobfader1);

unused8 = button("[0]S2[midi:ctrl 33 1]");
unused9 = button("[1]M2[midi:ctrl 49 1]");
unused10 = button("[2]R2[midi:ctrl 65 1]");
buts2 = vgroup("buttons", unused8+unused9+unused10);

detune1 = 1 + 0.01 * hslider("[0]Detune 1[unit:%%][midi:ctrl 17 1] [style:knob]",-0.1,-10,10,0.01) : si.smoo; // knob
env2 = vslider("[1]env2[midi:ctrl 1 1]",0,0,1,0.01) : si.smoo; // fader
knobfader2 = vgroup("knobfader",detune1 + env2);

hg2 = hgroup("2", buts2 + knobfader2);

unused11 = button("[0]S3[midi:ctrl 34 1]");
unused12 = button("[1]M3[midi:ctrl 50 1]");
unused13 = button("[2]R3[midi:ctrl 66 1]");
buts3 = vgroup("buttons", unused11+unused12+unused13);

detune2 = 1 + 0.01 * hslider("[0]Detune 2[unit:%%][midi:ctrl 18 1] [style:knob]",+0.1,-10,10,0.01) : si.smoo; // knob
ampenv1depth = hslider("[1]Amplitude Env1 Depth[midi:ctrl 2 1]",0,0,1,0.001) : si.smoo; // fader
knobfader3 = vgroup("knobfader",detune2 + ampenv1depth);

hg3 = hgroup("3", buts3 + knobfader3);

unused14 = button("[0]S4[midi:ctrl 35 1]");
unused15 = button("[1]M4[midi:ctrl 51 1]");
unused16 = button("[2]R4[midi:ctrl 67 1]");
buts4 = vgroup("buttons", unused14+unused15+unused16);

filtfr = hslider("[0]Filter Frequency[unit:Hz][midi:ctrl 19 1] [style:knob]", 3000, 0, 15000, 10) : si.smoo; // knob
pitchenv1depth = hslider("[1]Pitch Env1 Depth[unit:Hz][midi:ctrl 3 1]", 0, 0, 500, 1) : si.smoo; // fader
knobfader4 = vgroup("knobfader",filtfr + pitchenv1depth);

hg4 = hgroup("4", buts4 + knobfader4);

unused17 = button("[0]S5[midi:ctrl 36 1]");
unused18 = button("[1]M5[midi:ctrl 52 1]");
unused19 = button("[2]R5[midi:ctrl 68 1]");
buts5 = vgroup("buttons", unused17+unused18+unused19);

filtres = hslider("[0]Filter Resonance[midi:ctrl 20 1] [style:knob]", 0, 0, 1, 0.001) : si.smoo; // knob
filtenv1depth = hslider("[1]Filter Env1 Depth[unit:Hz][midi:ctrl 4 1]",0,0,10000,0.001) : si.smoo; // fader
knobfader5 = vgroup("knobfader",filtres + filtenv1depth);

hg5 = hgroup("5", buts5 + knobfader5);

unused20 = button("[0]S6[midi:ctrl 37 1]");
unused21 = button("[1]M6[midi:ctrl 53 1]");
unused22 = button("[2]R6[midi:ctrl 69 1]");
buts6 = vgroup("buttons", unused20+unused21+unused22);

autoenv_attack1 = hslider("[0]Autoenv Attack Time[midi:ctrl 21 1] [style:knob]", 0.5, 0, 2, 0.001) : si.smoo; // knob
ampenv2depth = hslider("[1]Amplitude Env2 Depth[midi:ctrl 5 1]",0,0,1,0.001) : si.smoo; // fader
knobfader6 = vgroup("knobfader",autoenv_attack1 + ampenv2depth);

hg6 = hgroup("6", buts6 + knobfader6);

unused23 = button("[0]S7[midi:ctrl 38 1]");
unused24 = button("[1]M7[midi:ctrl 54 1]");
unused25 = button("[2]R7[midi:ctrl 70 1]");
buts7 = vgroup("buttons", unused23+unused24+unused25);

autoenv_release1 = hslider("[0]Autoenv Release Time [midi:ctrl 22 1] [style:knob]", 0.5, 0.1, 2, 0.001); // knob
pitchenv2depth = hslider("[1]Pitch Env2 Depth[unit:Hz][midi:ctrl 6 1]", 0, 0, 500, 1) : si.smoo; // fader
knobfader7 = vgroup("knobfader",autoenv_release1 + pitchenv2depth);

hg7 = hgroup("7", buts7 + knobfader7);

unused26 = button("[0]S8[midi:ctrl 39 1]");
unused27 = button("[1]M8[midi:ctrl 55 1]");
unused28 = button("[2]R8[midi:ctrl 71 1]");
buts8 = vgroup("buttons", unused26+unused27+unused27);

amp = hslider("[0]Master Volume[unit:dB][midi:ctrl 23 1] [style:knob]",-6,-120,10,0.1) : ba.db2linear : si.smoo; // knob
filtenv2depth = hslider("[1]Filter Env2 Depth[unit:Hz][midi:ctrl 7 1]",0,0,10000,0.001) : si.smoo; // fader
knobfader8 = vgroup("knobfader",amp + filtenv2depth);

hg8 = hgroup("8", buts8 + knobfader8);

controlSection = hgroup("[1]Control", hg1 + hg2 + hg3 + hg4 + hg5 + hg6 + hg7 + hg8);

fullUI = hgroup("NanoKontrol2", transportSection + controlSection);

// portamento remains unmapped/hardcoded for now, but when mapping use the following line:
// hslider("[13]Portamento [unit:sec] [scale:log]",0.1,0.001,10,0.001);
portamento = 0.1;
// APPLY ENVS 1 + 2
// 1:
autoenv_trigger1 = ba.pulse(ba.sec2samp(autoenv_attack1+autoenv_release1));
autoenv1 = en.ar(autoenv_attack1, autoenv_release1, autoenv_trigger1);
routedenv1 = env1,autoenv1 : ba.selectn(2, autoenv1on);
routedampenv1depth1 = 1,ampenv1depth: ba.selectn(2, routeamptoenv1);
ampenv1 = routedenv1 * 1-routedampenv2depth1;
routedpitchenv1depth = 1,pitchenv1depth : ba.selectn(2, routepitchtoenv1);
pitchenv1 = routedenv1 * routedpitchenv1depth;
routedfiltenv1depth = 1,filtenv1depth : ba.selectn(2, routefilttoenv1);
filtenv1 = routedenv1 * routedfiltenv1depth;
// 2:
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
//unused = fullUI + 1;
//gain = (ampenv1 + ampenv2) * amp * mute * 0.5 + unused;
gain = (ampenv1 + ampenv2) * amp * mute * 0.5;
signal = toneL * gain,toneR * gain : filter,filter;
process = signal;