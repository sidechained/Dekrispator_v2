// TODO:
// Integrate with real world code
// Store in separate file (include)
// Why aren't buttons controlled?
// What values should be used? 0-127 or actual values
// Maybe the former and scale manually?
// Smoothing

import("stdfaust.lib");
declare options "[midi:on]";

prevTrackBut = button("[0]prevTrack[midi:ctrl 58 1]");
nextTrackBut = button("[1]nextTrack[midi:ctrl 59 1]");
transport_row1 = hgroup("1", prevTrackBut + nextTrackBut);

cycleBut = button("[0]Cycle[midi:ctrl 46 1]");
setMarkerBut = button("[1]Set[midi:ctrl 60 1]");
prevMarkerBut = button("[2]prevMark[midi:ctrl 61 1]");
nextMarkerBut = button("[3]nextMark[midi:ctrl 62 1]");
transport_row2 = hgroup("2", cycleBut + setMarkerBut + prevMarkerBut + nextMarkerBut);

rewindBut = button("[0]rwd[midi:ctrl 43 1]");
forwardBut = button("[1]fwd[midi:ctrl 44 1]");
stopBut = button("[2]stop[midi:ctrl 42 1]");
playBut = button("[3]play[midi:ctrl 41 1]");
recBut = button("[4]rec[midi:ctrl 45 1]");
transport_row3 = hgroup("3", rewindBut + forwardBut + stopBut + playBut + recBut);

transportSection = vgroup("[0]Transport", transport_row1 + transport_row2 + transport_row3);

solo_but1 = button("[0]S[midi:ctrl 32 1]");
mute_but1 = button("[1]M[midi:ctrl 48 1]");
rec_but1 = button("[2]R[midi:ctrl 64 1]");
buts1 = vgroup("buttons", solo_but1+mute_but1+rec_but1);

knob1 = vslider("[0]knob[midi:ctrl 16 1] [style:knob]",0,0,1,0.001);
fader1 = vslider("[1]fader[midi:ctrl 0 1]",0,0,1,0.001);
knobfader1 = vgroup("knobfader",knob1 + fader1);

hg1 = hgroup("1", buts1 + knobfader1);

solo_but2 = button("[0]S[midi:ctrl 33 1]");
mute_but2 = button("[1]M[midi:ctrl 49 1]");
rec_but2 = button("[2]R[midi:ctrl 65 1]");
buts2 = vgroup("buttons", solo_but2+mute_but2+rec_but2);

knob2 = vslider("[0]knob[midi:ctrl 17 1] [style:knob]",0,0,1,0.001);
fader2 = vslider("[1]fader[midi:ctrl 1 1]",0,0,1,0.01);
knobfader2 = vgroup("knobfader",knob2 + fader2);

hg2 = hgroup("2", buts2 + knobfader2);

solo_but3 = button("[0]S[midi:ctrl 34 1]");
mute_but3 = button("[1]M[midi:ctrl 50 1]");
rec_but3 = button("[2]R[midi:ctrl 66 1]");
buts3 = vgroup("buttons", solo_but3+mute_but3+rec_but3);

knob3 = vslider("[0]knob[midi:ctrl 18 1] [style:knob]",0,0,1,0.001);
fader3 = vslider("[1]fader[midi:ctrl 2 1]",0,0,1,0.01);
knobfader3 = vgroup("knobfader",knob3 + fader3);

hg3 = hgroup("3", buts3 + knobfader3);

solo_but4 = button("[0]S[midi:ctrl 35 1]");
mute_but4 = button("[1]M[midi:ctrl 51 1]");
rec_but4 = button("[2]R[midi:ctrl 67 1]");
buts4 = vgroup("buttons", solo_but4+mute_but4+rec_but4);

knob4 = vslider("[0]knob[midi:ctrl 19 1] [style:knob]",0,0,1,0.001);
fader4 = vslider("[1]fader[midi:ctrl 3 1]",0,0,1,0.01);
knobfader4 = vgroup("knobfader",knob4 + fader4);

hg4 = hgroup("4", buts4 + knobfader4);

solo_but5 = button("[0]S[midi:ctrl 36 1]");
mute_but5 = button("[1]M[midi:ctrl 52 1]");
rec_but5 = button("[2]R[midi:ctrl 68 1]");
buts5 = vgroup("buttons", solo_but5+mute_but5+rec_but5);

knob5 = vslider("[0]knob[midi:ctrl 20 1] [style:knob]",0,0,1,0.001);
fader5 = vslider("[1]fader[midi:ctrl 4 1]",0,0,1,0.01);
knobfader5 = vgroup("knobfader",knob5 + fader5);

hg5 = hgroup("5", buts5 + knobfader5);

solo_but6 = button("[0]S[midi:ctrl 37 1]");
mute_but6 = button("[1]M[midi:ctrl 53 1]");
rec_but6 = button("[2]R[midi:ctrl 69 1]");
buts6 = vgroup("buttons", solo_but6+mute_but6+rec_but6);

knob6 = vslider("[0]knob[midi:ctrl 21 1] [style:knob]",0,0,1,0.001);
fader6 = vslider("[1]fader[midi:ctrl 5 1]",0,0,1,0.01);
knobfader6 = vgroup("knobfader",knob6 + fader6);

hg6 = hgroup("6", buts6 + knobfader6);

solo_but7 = button("[0]S[midi:ctrl 38 1]");
mute_but7 = button("[1]M[midi:ctrl 54 1]");
rec_but7 = button("[2]R[midi:ctrl 70 1]");
buts7 = vgroup("buttons", solo_but7+mute_but7+rec_but7);

knob7 = vslider("[0]knob[midi:ctrl 22 1] [style:knob]",0,0,1,0.001);
fader7 = vslider("[1]fader[midi:ctrl 6 1]",0,0,1,0.01);
knobfader7 = vgroup("knobfader",knob7 + fader7);

hg7 = hgroup("7", buts7 + knobfader7);

solo_but8 = button("[0]S[midi:ctrl 39 1]");
mute_but8 = button("[1]M[midi:ctrl 55 1]");
rec_but8 = button("[2]R[midi:ctrl 71 1]");
buts8 = vgroup("buttons", solo_but8+mute_but8+rec_but8);

knob8 = vslider("[0]knob[midi:ctrl 23 1] [style:knob]",0,0,1,0.001);
fader8 = vslider("[1]fader[midi:ctrl 7 1]",0,0,1,0.01);
knobfader8 = vgroup("knobfader",knob8 + fader8);

hg8 = hgroup("8", buts8 + knobfader8);

controlSection = hgroup("[1]Control", hg1 + hg2 + hg3 + hg4 + hg5 + hg6 + hg7 + hg8);

fullUI = hgroup("NanoKontrol2", transportSection + controlSection);

process = fullUI;
