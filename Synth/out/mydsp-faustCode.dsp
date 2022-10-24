import("stdfaust.lib");

declare options "[midi:on]";

env1 = hslider("env1[midi:ctrl 0 1]",0,0,1,0.001) : si.smoo; // fader 1
process = no.noise * env1;