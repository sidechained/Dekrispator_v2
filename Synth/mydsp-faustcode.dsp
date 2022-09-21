import("stdfaust.lib");

cutl = hslider("[0]cutoffFrequencyL",500,50,10000,0.01);
cutr = hslider("[1]cutoffFrequencyR",500,50,10000,0.01);
q = hslider("[2]q",5,1,30,0.1);
gain = hslider("[3]gain",1,0,1,0.01);

process = no.noise : _ <: fi.resonlp(cutl,q,gain),fi.resonlp(cutr,q,gain);