declare filename "mydsp.dsp"; declare name "mydsp"; declare version "2.52.3";
declare compile_options "-single -scal -I libraries/ -I project/ -lang wasm";
declare library_path0 "/libraries/stdfaust.lib";
declare library_path1 "/libraries/basics.lib";
declare library_path2 "/libraries/signals.lib";
declare library_path3 "/libraries/maths.lib";
declare library_path4 "/libraries/platform.lib";
declare library_path5 "/libraries/oscillators.lib";
declare library_path6 "/libraries/envelopes.lib";
declare library_path7 "/libraries/vaeffects.lib";
declare library_path8 "/libraries/filters.lib";
declare basics_lib_name "Faust Basic Element Library";
declare basics_lib_version "0.8";
declare envelopes_lib_ar_author "Yann Orlarey, Stéphane Letz";
declare envelopes_lib_author "GRAME";
declare envelopes_lib_copyright "GRAME";
declare envelopes_lib_license "LGPL with exception";
declare envelopes_lib_name "Faust Envelope Library";
declare envelopes_lib_version "0.2";
declare filename "FaustDSP";
declare filters_lib_fir_author "Julius O. Smith III";
declare filters_lib_fir_copyright "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>";
declare filters_lib_fir_license "MIT-style STK-4.3 license";
declare filters_lib_iir_author "Julius O. Smith III";
declare filters_lib_iir_copyright "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>";
declare filters_lib_iir_license "MIT-style STK-4.3 license";
declare filters_lib_lowpass0_highpass1 "MIT-style STK-4.3 license";
declare filters_lib_name "Faust Filters Library";
declare filters_lib_tf2_author "Julius O. Smith III";
declare filters_lib_tf2_copyright "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>";
declare filters_lib_tf2_license "MIT-style STK-4.3 license";
declare filters_lib_tf2s_author "Julius O. Smith III";
declare filters_lib_tf2s_copyright "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>";
declare filters_lib_tf2s_license "MIT-style STK-4.3 license";
declare filters_lib_version "0.3";
declare maths_lib_author "GRAME";
declare maths_lib_copyright "GRAME";
declare maths_lib_license "LGPL with exception";
declare maths_lib_name "Faust Math Library";
declare maths_lib_version "2.5";
declare name "FaustDSP";
declare options "[midi:on]";
declare oscillators_lib_lf_sawpos_author "Bart Brouns, revised by Stéphane Letz";
declare oscillators_lib_lf_sawpos_licence "STK-4.3";
declare oscillators_lib_name "Faust Oscillator Library";
declare oscillators_lib_version "0.3";
declare platform_lib_name "Generic Platform Library";
declare platform_lib_version "0.2";
declare signals_lib_name "Faust Signal Routing Library";
declare signals_lib_version "0.3";
declare vaeffects_lib_moog_vcf_2b_author "Julius O. Smith III";
declare vaeffects_lib_moog_vcf_2b_copyright "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>";
declare vaeffects_lib_moog_vcf_2b_license "MIT-style STK-4.3 license";
declare vaeffects_lib_name "Faust Virtual Analog Filter Effect Library";
declare vaeffects_lib_version "0.2";
ID_0 = hslider("[07]Knob8:Master Volume[unit:dB][midi:ctrl 23 1]", -6.0f, -1.2e+02f, 1e+01f, 0.1f);
ID_1 = \(x216).(1e+01f,(x216,2e+01f : /) : pow) : \(x42).(\(x43).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x42 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x43 : *) : +)~_);
ID_2 = (ID_0 : ID_1);
ID_3 = ID_2, 3;
ID_4 = (ID_3 : /);
ID_5 = hslider("[00]Knob1:Oscillator Frequency[unit:PK][midi:ctrl 16 1]", 49.0f, 0.0f, 88.0f, 0.01f);
ID_6 = \(x41).(4.4e+02f,(2.0f,((x41,49.0f : -),12.0f : /) : pow) : *) : \(x42).(\(x43).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x42 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x43 : *) : +)~_);
ID_7 = ID_5 : ID_6;
ID_8 = hslider("[08]Fader1:Env 1 Level[midi:ctrl 0 1]", 0.0f, 0.0f, 1.0f, 0.001f);
ID_9 = (ID_8 : \(x42).(\(x43).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x42 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x43 : *) : +)~_));
ID_10 = hslider("[05]Knob6:Autoenv Attack Time[midi:ctrl 21 1]", 0.5f, 0.0f, 2.0f, 0.001f);
ID_11 = (ID_10 : \(x17).(\(x18).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x17 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x18 : *) : +)~_));
ID_12 = hslider("[06]Knob7:Autoenv Release Time [midi:ctrl 22 1]", 0.5f, 0.1f, 2.0f, 0.001f);
ID_13 = ID_11, ID_12;
ID_14 = (ID_13 : +);
ID_15 = fconstant(int fSamplingFreq, <math.h>);
ID_16 = 1.0f, ID_15;
ID_17 = (ID_16 : max);
ID_18 = 1.92e+05f, ID_17;
ID_19 = (ID_18 : min);
ID_20 = ID_14, ID_19;
ID_21 = ID_20 : *;
ID_22 = (ID_21 : int);
ID_23 = _, ID_22;
ID_24 = (ID_23 : %);
ID_25 = (1 : mem);
ID_26 = _, ID_25;
ID_27 = (ID_26 : +);
ID_28 = ID_24 ~ ID_27;
ID_29 = (ID_28 : \(x19).(x19,(x19 : mem) : <=));
ID_30 = (ID_29 : mem);
ID_31 = ID_29, ID_30;
ID_32 = (ID_31 : <=);
ID_33 = \(x16).(x16,(x16,0 : >) : +), ID_32;
ID_34 = (ID_33 : *);
ID_35 = (ID_31 : >);
ID_36 = ID_34, ID_35;
ID_37 = (ID_36 : +);
ID_38 = ID_37 ~ _;
ID_39 = (ID_10 : \(x14).(\(x15).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x14 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x15 : *) : +)~_));
ID_40 = ID_39, ID_19;
ID_41 = (ID_40 : *);
ID_42 = 1, ID_41;
ID_43 = (ID_42 : max);
ID_44 = 1, ID_43;
ID_45 = (ID_44 : /);
ID_46 = ID_38, ID_45;
ID_47 = (ID_46 : *);
ID_48 = ID_12, ID_19;
ID_49 = (ID_48 : *);
ID_50 = 1, ID_49;
ID_51 = (ID_50 : max);
ID_52 = 1, ID_51;
ID_53 = (ID_52 : /);
ID_54 = ID_43, ID_53;
ID_55 = (ID_54 : *);
ID_56 = 1, ID_55;
ID_57 = (ID_56 : +);
ID_58 = ID_38, ID_53;
ID_59 = (ID_58 : *);
ID_60 = ID_57, ID_59;
ID_61 = (ID_60 : -);
ID_62 = ID_47, ID_61;
ID_63 = ID_62 : min;
ID_64 = 0, _;
ID_65 = ID_64 : max;
ID_66 = (ID_63 : ID_65);
ID_67 = ID_9, ID_66;
ID_68 = _, _;
ID_69 = ID_68 : \(x46).(\(x47).((hslider("[22]Rewind Button: Auto Env 1 On[midi:ctrl 43 1]", 0.0f, 0.0f, 1.0f, 1.0f),1 : >=),x46,x47 : select2));
ID_70 = (ID_67 : ID_69);
ID_71 = hslider("[11]Fader1:Pitch Env1 Depth[unit:Hz][midi:ctrl 3 1]", 0.0f, 0.0f, 5e+02f, 1.0f);
ID_72 = (ID_71 : \(x42).(\(x43).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x42 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x43 : *) : +)~_));
ID_73 = 1, ID_72;
ID_74 = ID_68 : \(x48).(\(x49).((hslider("[17]Track > Button:Env1 > Pitch[midi:ctrl 59 1]", 1.0f, 0.0f, 1.0f, 1.0f),1 : >=),x48,x49 : select2));
ID_75 = (ID_73 : ID_74);
ID_76 = ID_70, ID_75;
ID_77 = (ID_76 : *);
ID_78 = \(x44).(\(x45).(((1.0f,(0,(-1.0f,((0,0.1f,1.0f : select2),(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min : float) : *) : / : exp),0.0f : select2) : -),x44 : *),((0,(-1.0f,((0,0.1f,1.0f : select2),(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min : float) : *) : / : exp),0.0f : select2),x45 : *) : +)~_), ID_77;
ID_79 = (ID_78 : +);
ID_80 = hslider("[09]Fader1:Env 2 Level[midi:ctrl 1 1]", 0.0f, 0.0f, 1.0f, 0.01f);
ID_81 = (ID_80 : \(x42).(\(x43).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x42 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x43 : *) : +)~_));
ID_82 = ID_11, 2;
ID_83 = (ID_82 : /);
ID_84 = ID_12, 2;
ID_85 = (ID_84 : /);
ID_86 = ID_83, ID_85;
ID_87 = (ID_86 : +);
ID_88 = ID_87, ID_19;
ID_89 = ID_88 : *;
ID_90 = (ID_89 : int);
ID_91 = _, ID_90;
ID_92 = (ID_91 : %);
ID_93 = ID_92 ~ ID_27;
ID_94 = (ID_93 : \(x22).(x22,(x22 : mem) : <=));
ID_95 = (ID_94 : mem);
ID_96 = ID_94, ID_95;
ID_97 = (ID_96 : <=);
ID_98 = \(x21).(x21,(x21,0 : >) : +), ID_97;
ID_99 = (ID_98 : *);
ID_100 = (ID_96 : >);
ID_101 = ID_99, ID_100;
ID_102 = (ID_101 : +);
ID_103 = ID_102 ~ _;
ID_104 = ID_39, 2;
ID_105 = (ID_104 : /);
ID_106 = ID_105, ID_19;
ID_107 = (ID_106 : *);
ID_108 = 1, ID_107;
ID_109 = (ID_108 : max);
ID_110 = 1, ID_109;
ID_111 = (ID_110 : /);
ID_112 = ID_103, ID_111;
ID_113 = (ID_112 : *);
ID_114 = ID_85, ID_19;
ID_115 = (ID_114 : *);
ID_116 = 1, ID_115;
ID_117 = (ID_116 : max);
ID_118 = 1, ID_117;
ID_119 = (ID_118 : /);
ID_120 = ID_109, ID_119;
ID_121 = (ID_120 : *);
ID_122 = 1, ID_121;
ID_123 = (ID_122 : +);
ID_124 = ID_103, ID_119;
ID_125 = (ID_124 : *);
ID_126 = ID_123, ID_125;
ID_127 = (ID_126 : -);
ID_128 = ID_113, ID_127;
ID_129 = ID_128 : min;
ID_130 = (ID_129 : ID_65);
ID_131 = ID_81, ID_130;
ID_132 = ID_68 : \(x50).(\(x51).((hslider("[23]Fast-Forward Button:Auto Env 2 On[midi:ctrl 44 1]", 0.0f, 0.0f, 1.0f, 1.0f),1 : >=),x50,x51 : select2));
ID_133 = (ID_131 : ID_132);
ID_134 = hslider("[14]Fader1:Pitch Env2 Depth[unit:Hz][midi:ctrl 6 1]", 0.0f, 0.0f, 5e+02f, 1.0f);
ID_135 = (ID_134 : \(x42).(\(x43).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x42 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x43 : *) : +)~_));
ID_136 = 1, ID_135;
ID_137 = ID_68 : \(x52).(\(x53).((hslider("[20]Marker < Button:Env2 > Pitch[midi:ctrl 61 1]", 1.0f, 0.0f, 1.0f, 1.0f),1 : >=),x52,x53 : select2));
ID_138 = (ID_136 : ID_137);
ID_139 = ID_133, ID_138;
ID_140 = (ID_139 : *);
ID_141 = ID_79, ID_140;
ID_142 = ID_141 : +;
ID_143 = ID_7 : ID_142;
ID_144 = \(x29).((2,(0,(_,((2e+01f,(x29 : abs) : max),(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : +),0 : select2 : \(x24).(x24,(x24 : floor) : -))~_ : *),1 : - : \(x30).(((x30,x30 : *),x30 : *),x30 : -) : (\(x31).((x31,(x31 : mem) : -),(2.0f,((1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min : float),(2e+01f,(x29 : abs) : max) : /) : /) : /) : \(x31).((x31,(x31 : mem) : -),(2.0f,((1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min : float),(2e+01f,(x29 : abs) : max) : /) : /) : /)),6 : / : _,(1,2 : @) : *), \(x32).((2,(0,(_,((2e+01f,(x32 : abs) : max),(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : +),0 : select2 : \(x24).(x24,(x24 : floor) : -))~_ : *),1 : - : \(x33).((x33,x33 : *),((x33,x33 : *),2.0f : -) : *) : (\(x34).((x34,(x34 : mem) : -),(2.0f,((1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min : float),(2e+01f,(x32 : abs) : max) : /) : /) : /) : \(x34).((x34,(x34 : mem) : -),(2.0f,((1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min : float),(2e+01f,(x32 : abs) : max) : /) : /) : /) : \(x34).((x34,(x34 : mem) : -),(2.0f,((1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min : float),(2e+01f,(x32 : abs) : max) : /) : /) : /)),24 : / : _,(1,3 : @) : *);
ID_145 = \(x26).((2,(0,(_,((2e+01f,(x26 : abs) : max),(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : +),0 : select2 : \(x24).(x24,(x24 : floor) : -))~_ : *),1 : - : \(x27).(x27,x27 : *) : \(x28).((x28,(x28 : mem) : -),(2.0f,((1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min : float),(2e+01f,(x26 : abs) : max) : /) : /) : /),2 : / : _,(1,1 : @) : *), ID_144;
ID_146 = \(x23).((2,(0,(_,((2e+01f,(x23 : abs) : max),(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : +),0 : select2 : \(x24).(x24,(x24 : floor) : -))~_ : *),1 : - : \(x25).(x25) : _ : _,1 : *), ID_145;
ID_147 = (ID_68 : \(x35).(\(x36).(1,x35,x36 : select2)));
ID_148 = (ID_68 : \(x37).(\(x38).(1,x37,x38 : select2)));
ID_149 = ID_147, ID_148;
ID_150 = ID_149 : \(x39).(\(x40).(1,x39,x40 : select2));
ID_151 = ID_146 : ID_150;
ID_152 = _ <: ID_151;
ID_153 = (ID_143 : ID_152);
ID_154 = hslider("[01]Knob2:Detune 1[unit:%%][midi:ctrl 17 1]", -0.1f, -1e+01f, 1e+01f, 0.01f);
ID_155 = 0.01f, ID_154;
ID_156 = (ID_155 : *);
ID_157 = 1, ID_156;
ID_158 = ID_157 : +;
ID_159 = (ID_158 : \(x42).(\(x43).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x42 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x43 : *) : +)~_));
ID_160 = ID_143, ID_159;
ID_161 = ID_160 : *;
ID_162 = (ID_161 : ID_152);
ID_163 = ID_162, 0.3f;
ID_164 = (ID_163 : *);
ID_165 = ID_153, ID_164;
ID_166 = (ID_165 : +);
ID_167 = hslider("[02]Knob3:Detune 2[unit:%%][midi:ctrl 18 1]", 0.1f, -1e+01f, 1e+01f, 0.01f);
ID_168 = 0.01f, ID_167;
ID_169 = (ID_168 : *);
ID_170 = 1, ID_169;
ID_171 = ID_170 : +;
ID_172 = (ID_171 : \(x42).(\(x43).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x42 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x43 : *) : +)~_));
ID_173 = ID_143, ID_172;
ID_174 = ID_173 : *;
ID_175 = (ID_174 : ID_152);
ID_176 = ID_166, ID_175;
ID_177 = (ID_176 : +);
ID_178 = ID_4, ID_177;
ID_179 = (ID_178 : *);
ID_180 = ID_70, 1;
ID_181 = (ID_180 : *);
ID_182 = hslider("[13]Fader1:Amplitude Env2 Depth[midi:ctrl 5 1]", 0.0f, 0.0f, 1.0f, 0.001f);
ID_183 = (ID_182 : \(x42).(\(x43).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x42 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x43 : *) : +)~_));
ID_184 = 1, ID_183;
ID_185 = ID_68 : \(x217).(\(x218).((hslider("[19]Set Marker Button:Env2 > Amp[midi:ctrl 60 1]", 1.0f, 0.0f, 1.0f, 1.0f),1 : >=),x217,x218 : select2));
ID_186 = (ID_184 : ID_185);
ID_187 = ID_181, ID_186;
ID_188 = (ID_187 : -);
ID_189 = ID_133, 1;
ID_190 = (ID_189 : *);
ID_191 = ID_190, ID_186;
ID_192 = (ID_191 : -);
ID_193 = ID_188, ID_192;
ID_194 = (ID_193 : +);
ID_195 = ID_194, ID_2;
ID_196 = (ID_195 : *);
ID_197 = hslider("[24]Record Button: Mute Output[midi:ctrl 45 1]", 0.0f, 0.0f, 1.0f, 1.0f);
ID_198 = 1, ID_197;
ID_199 = ID_198 : -;
ID_200 = (ID_199 : \(x42).(\(x43).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x42 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x43 : *) : +)~_));
ID_201 = ID_196, ID_200;
ID_202 = (ID_201 : *);
ID_203 = ID_202, 0.5f;
ID_204 = (ID_203 : *);
ID_205 = ID_179, ID_204;
ID_206 = (ID_205 : *);
ID_207 = ID_153, ID_162;
ID_208 = (ID_207 : +);
ID_209 = ID_208, ID_175;
ID_210 = (ID_209 : +);
ID_211 = ID_4, ID_210;
ID_212 = (ID_211 : *);
ID_213 = ID_212, 0.3f;
ID_214 = (ID_213 : *);
ID_215 = ID_214, ID_204;
ID_216 = (ID_215 : *);
ID_217 = ID_206, ID_216;
ID_218 = hslider("[04]Knob5:Filter Resonance[midi:ctrl 20 1]", 0.0f, 0.0f, 1.0f, 0.001f);
ID_219 = (ID_218 : \(x162).(\(x163).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x162 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x163 : *) : +)~_));
ID_220 = 1.4142135f, ID_219;
ID_221 = (ID_220 : *);
ID_222 = 1.4141995f, ID_221;
ID_223 = (ID_222 : min);
ID_224 = 1.4142135f, ID_223;
ID_225 = (ID_224 : *);
ID_226 = 1, ID_225;
ID_227 = (ID_226 : +);
ID_228 = ID_223, 2;
ID_229 = (ID_228 : pow);
ID_230 = ID_227, ID_229;
ID_231 = (ID_230 : +);
ID_232 = 1, ID_231;
ID_233 = (ID_232 : *);
ID_234 = hslider("[03]Knob4:Filter Frequency[unit:Hz][midi:ctrl 19 1]", 3e+03f, 0.0f, 1.5e+04f, 1e+01f);
ID_235 = (ID_234 : \(x162).(\(x163).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x162 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x163 : *) : +)~_));
ID_236 = (ID_8 : \(x162).(\(x163).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x162 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x163 : *) : +)~_));
ID_237 = (ID_10 : \(x165).(\(x166).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x165 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x166 : *) : +)~_));
ID_238 = ID_237, ID_12;
ID_239 = (ID_238 : +);
ID_240 = ID_239, ID_19;
ID_241 = ID_240 : *;
ID_242 = (ID_241 : int);
ID_243 = _, ID_242;
ID_244 = (ID_243 : %);
ID_245 = ID_244 ~ ID_27;
ID_246 = (ID_245 : \(x167).(x167,(x167 : mem) : <=));
ID_247 = (ID_246 : mem);
ID_248 = ID_246, ID_247;
ID_249 = (ID_248 : <=);
ID_250 = \(x164).(x164,(x164,0 : >) : +), ID_249;
ID_251 = (ID_250 : *);
ID_252 = (ID_248 : >);
ID_253 = ID_251, ID_252;
ID_254 = (ID_253 : +);
ID_255 = ID_254 ~ _;
ID_256 = (ID_10 : \(x168).(\(x169).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x168 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x169 : *) : +)~_));
ID_257 = ID_256, ID_19;
ID_258 = (ID_257 : *);
ID_259 = 1, ID_258;
ID_260 = (ID_259 : max);
ID_261 = 1, ID_260;
ID_262 = (ID_261 : /);
ID_263 = ID_255, ID_262;
ID_264 = (ID_263 : *);
ID_265 = ID_260, ID_53;
ID_266 = (ID_265 : *);
ID_267 = 1, ID_266;
ID_268 = (ID_267 : +);
ID_269 = ID_255, ID_53;
ID_270 = (ID_269 : *);
ID_271 = ID_268, ID_270;
ID_272 = (ID_271 : -);
ID_273 = ID_264, ID_272;
ID_274 = ID_273 : min;
ID_275 = (ID_274 : ID_65);
ID_276 = ID_236, ID_275;
ID_277 = ID_68 : \(x170).(\(x171).((hslider("[22]Rewind Button: Auto Env 1 On[midi:ctrl 43 1]", 0.0f, 0.0f, 1.0f, 1.0f),1 : >=),x170,x171 : select2));
ID_278 = (ID_276 : ID_277);
ID_279 = hslider("[12]Fader1:Filter Env1 Depth[unit:Hz][midi:ctrl 4 1]", 0.0f, 0.0f, 1e+04f, 0.001f);
ID_280 = (ID_279 : \(x162).(\(x163).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x162 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x163 : *) : +)~_));
ID_281 = 1, ID_280;
ID_282 = ID_68 : \(x172).(\(x173).((hslider("[18]Cycle Button:Env1 > Filter[midi:ctrl 46 1]", 1.0f, 0.0f, 1.0f, 1.0f),1 : >=),x172,x173 : select2));
ID_283 = (ID_281 : ID_282);
ID_284 = ID_278, ID_283;
ID_285 = (ID_284 : *);
ID_286 = ID_235, ID_285;
ID_287 = (ID_286 : +);
ID_288 = (ID_80 : \(x162).(\(x163).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x162 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x163 : *) : +)~_));
ID_289 = ID_237, 2;
ID_290 = (ID_289 : /);
ID_291 = ID_290, ID_85;
ID_292 = (ID_291 : +);
ID_293 = ID_292, ID_19;
ID_294 = ID_293 : *;
ID_295 = (ID_294 : int);
ID_296 = _, ID_295;
ID_297 = (ID_296 : %);
ID_298 = ID_297 ~ ID_27;
ID_299 = (ID_298 : \(x175).(x175,(x175 : mem) : <=));
ID_300 = (ID_299 : mem);
ID_301 = ID_299, ID_300;
ID_302 = (ID_301 : <=);
ID_303 = \(x174).(x174,(x174,0 : >) : +), ID_302;
ID_304 = (ID_303 : *);
ID_305 = (ID_301 : >);
ID_306 = ID_304, ID_305;
ID_307 = (ID_306 : +);
ID_308 = ID_307 ~ _;
ID_309 = ID_256, 2;
ID_310 = (ID_309 : /);
ID_311 = ID_310, ID_19;
ID_312 = (ID_311 : *);
ID_313 = 1, ID_312;
ID_314 = (ID_313 : max);
ID_315 = 1, ID_314;
ID_316 = (ID_315 : /);
ID_317 = ID_308, ID_316;
ID_318 = (ID_317 : *);
ID_319 = ID_314, ID_119;
ID_320 = (ID_319 : *);
ID_321 = 1, ID_320;
ID_322 = (ID_321 : +);
ID_323 = ID_308, ID_119;
ID_324 = (ID_323 : *);
ID_325 = ID_322, ID_324;
ID_326 = (ID_325 : -);
ID_327 = ID_318, ID_326;
ID_328 = ID_327 : min;
ID_329 = (ID_328 : ID_65);
ID_330 = ID_288, ID_329;
ID_331 = ID_68 : \(x176).(\(x177).((hslider("[23]Fast-Forward Button:Auto Env 2 On[midi:ctrl 44 1]", 0.0f, 0.0f, 1.0f, 1.0f),1 : >=),x176,x177 : select2));
ID_332 = (ID_330 : ID_331);
ID_333 = hslider("[15]Fader1:Filter Env2 Depth[unit:Hz][midi:ctrl 7 1]", 0.0f, 0.0f, 1e+04f, 0.001f);
ID_334 = (ID_333 : \(x162).(\(x163).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x162 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x163 : *) : +)~_));
ID_335 = 1, ID_334;
ID_336 = ID_68 : \(x178).(\(x179).((hslider("[21]Marker > Button:Env2 > Filter[midi:ctrl 62 1]", 1.0f, 0.0f, 1.0f, 1.0f),1 : >=),x178,x179 : select2));
ID_337 = (ID_335 : ID_336);
ID_338 = ID_332, ID_337;
ID_339 = (ID_338 : *);
ID_340 = ID_287, ID_339;
ID_341 = (ID_340 : +);
ID_342 = 10000, ID_341;
ID_343 = (ID_342 : min);
ID_344 = 20, ID_343;
ID_345 = (ID_344 : max);
ID_346 = 6.2831855f, ID_345;
ID_347 = (ID_346 : *);
ID_348 = ID_347, 0.5f;
ID_349 = (ID_348 : *);
ID_350 = ID_349, ID_19;
ID_351 = ID_350 : /;
ID_352 = (ID_351 : tan);
ID_353 = 1, ID_352;
ID_354 = (ID_353 : /);
ID_355 = ID_354, ID_354;
ID_356 = (ID_355 : *);
ID_357 = ID_233, ID_356;
ID_358 = (ID_357 : -);
ID_359 = 2, ID_358;
ID_360 = (ID_359 : *);
ID_361 = 2, ID_225;
ID_362 = (ID_361 : +);
ID_363 = 1, ID_362;
ID_364 = (ID_363 : *);
ID_365 = ID_364, ID_354;
ID_366 = (ID_365 : *);
ID_367 = ID_233, ID_366;
ID_368 = (ID_367 : +);
ID_369 = ID_368, ID_356;
ID_370 = (ID_369 : +);
ID_371 = ID_360, ID_370;
ID_372 = (ID_371 : /);
ID_373 = _, ID_372;
ID_374 = (ID_373 : *);
ID_375 = _, 1;
ID_376 = ID_375 : @;
ID_377 = (ID_218 : \(x180).(\(x181).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x180 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x181 : *) : +)~_));
ID_378 = 1.4142135f, ID_377;
ID_379 = (ID_378 : *);
ID_380 = 1.4141995f, ID_379;
ID_381 = (ID_380 : min);
ID_382 = 1.4142135f, ID_381;
ID_383 = (ID_382 : *);
ID_384 = 1, ID_383;
ID_385 = (ID_384 : +);
ID_386 = ID_381, 2;
ID_387 = (ID_386 : pow);
ID_388 = ID_385, ID_387;
ID_389 = (ID_388 : +);
ID_390 = 1, ID_389;
ID_391 = (ID_390 : *);
ID_392 = 2, ID_383;
ID_393 = (ID_392 : +);
ID_394 = 1, ID_393;
ID_395 = (ID_394 : *);
ID_396 = (ID_234 : \(x180).(\(x181).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x180 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x181 : *) : +)~_));
ID_397 = (ID_8 : \(x180).(\(x181).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x180 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x181 : *) : +)~_));
ID_398 = (ID_10 : \(x183).(\(x184).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x183 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x184 : *) : +)~_));
ID_399 = ID_398, ID_12;
ID_400 = (ID_399 : +);
ID_401 = ID_400, ID_19;
ID_402 = ID_401 : *;
ID_403 = (ID_402 : int);
ID_404 = _, ID_403;
ID_405 = (ID_404 : %);
ID_406 = ID_405 ~ ID_27;
ID_407 = (ID_406 : \(x185).(x185,(x185 : mem) : <=));
ID_408 = (ID_407 : mem);
ID_409 = ID_407, ID_408;
ID_410 = (ID_409 : <=);
ID_411 = \(x182).(x182,(x182,0 : >) : +), ID_410;
ID_412 = (ID_411 : *);
ID_413 = (ID_409 : >);
ID_414 = ID_412, ID_413;
ID_415 = (ID_414 : +);
ID_416 = ID_415 ~ _;
ID_417 = (ID_10 : \(x186).(\(x187).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x186 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x187 : *) : +)~_));
ID_418 = ID_417, ID_19;
ID_419 = (ID_418 : *);
ID_420 = 1, ID_419;
ID_421 = (ID_420 : max);
ID_422 = 1, ID_421;
ID_423 = (ID_422 : /);
ID_424 = ID_416, ID_423;
ID_425 = (ID_424 : *);
ID_426 = ID_421, ID_53;
ID_427 = (ID_426 : *);
ID_428 = 1, ID_427;
ID_429 = (ID_428 : +);
ID_430 = ID_416, ID_53;
ID_431 = (ID_430 : *);
ID_432 = ID_429, ID_431;
ID_433 = (ID_432 : -);
ID_434 = ID_425, ID_433;
ID_435 = ID_434 : min;
ID_436 = (ID_435 : ID_65);
ID_437 = ID_397, ID_436;
ID_438 = ID_68 : \(x188).(\(x189).((hslider("[22]Rewind Button: Auto Env 1 On[midi:ctrl 43 1]", 0.0f, 0.0f, 1.0f, 1.0f),1 : >=),x188,x189 : select2));
ID_439 = (ID_437 : ID_438);
ID_440 = (ID_279 : \(x180).(\(x181).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x180 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x181 : *) : +)~_));
ID_441 = 1, ID_440;
ID_442 = ID_68 : \(x190).(\(x191).((hslider("[18]Cycle Button:Env1 > Filter[midi:ctrl 46 1]", 1.0f, 0.0f, 1.0f, 1.0f),1 : >=),x190,x191 : select2));
ID_443 = (ID_441 : ID_442);
ID_444 = ID_439, ID_443;
ID_445 = (ID_444 : *);
ID_446 = ID_396, ID_445;
ID_447 = (ID_446 : +);
ID_448 = (ID_80 : \(x180).(\(x181).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x180 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x181 : *) : +)~_));
ID_449 = ID_398, 2;
ID_450 = (ID_449 : /);
ID_451 = ID_450, ID_85;
ID_452 = (ID_451 : +);
ID_453 = ID_452, ID_19;
ID_454 = ID_453 : *;
ID_455 = (ID_454 : int);
ID_456 = _, ID_455;
ID_457 = (ID_456 : %);
ID_458 = ID_457 ~ ID_27;
ID_459 = (ID_458 : \(x193).(x193,(x193 : mem) : <=));
ID_460 = (ID_459 : mem);
ID_461 = ID_459, ID_460;
ID_462 = (ID_461 : <=);
ID_463 = \(x192).(x192,(x192,0 : >) : +), ID_462;
ID_464 = (ID_463 : *);
ID_465 = (ID_461 : >);
ID_466 = ID_464, ID_465;
ID_467 = (ID_466 : +);
ID_468 = ID_467 ~ _;
ID_469 = ID_417, 2;
ID_470 = (ID_469 : /);
ID_471 = ID_470, ID_19;
ID_472 = (ID_471 : *);
ID_473 = 1, ID_472;
ID_474 = (ID_473 : max);
ID_475 = 1, ID_474;
ID_476 = (ID_475 : /);
ID_477 = ID_468, ID_476;
ID_478 = (ID_477 : *);
ID_479 = ID_474, ID_119;
ID_480 = (ID_479 : *);
ID_481 = 1, ID_480;
ID_482 = (ID_481 : +);
ID_483 = ID_468, ID_119;
ID_484 = (ID_483 : *);
ID_485 = ID_482, ID_484;
ID_486 = (ID_485 : -);
ID_487 = ID_478, ID_486;
ID_488 = ID_487 : min;
ID_489 = (ID_488 : ID_65);
ID_490 = ID_448, ID_489;
ID_491 = ID_68 : \(x194).(\(x195).((hslider("[23]Fast-Forward Button:Auto Env 2 On[midi:ctrl 44 1]", 0.0f, 0.0f, 1.0f, 1.0f),1 : >=),x194,x195 : select2));
ID_492 = (ID_490 : ID_491);
ID_493 = (ID_333 : \(x180).(\(x181).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x180 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x181 : *) : +)~_));
ID_494 = 1, ID_493;
ID_495 = ID_68 : \(x196).(\(x197).((hslider("[21]Marker > Button:Env2 > Filter[midi:ctrl 62 1]", 1.0f, 0.0f, 1.0f, 1.0f),1 : >=),x196,x197 : select2));
ID_496 = (ID_494 : ID_495);
ID_497 = ID_492, ID_496;
ID_498 = (ID_497 : *);
ID_499 = ID_447, ID_498;
ID_500 = (ID_499 : +);
ID_501 = 10000, ID_500;
ID_502 = (ID_501 : min);
ID_503 = 20, ID_502;
ID_504 = (ID_503 : max);
ID_505 = 6.2831855f, ID_504;
ID_506 = (ID_505 : *);
ID_507 = ID_506, 0.5f;
ID_508 = (ID_507 : *);
ID_509 = ID_508, ID_19;
ID_510 = ID_509 : /;
ID_511 = (ID_510 : tan);
ID_512 = 1, ID_511;
ID_513 = (ID_512 : /);
ID_514 = ID_395, ID_513;
ID_515 = (ID_514 : *);
ID_516 = ID_391, ID_515;
ID_517 = (ID_516 : -);
ID_518 = ID_513, ID_513;
ID_519 = (ID_518 : *);
ID_520 = ID_517, ID_519;
ID_521 = (ID_520 : +);
ID_522 = (ID_516 : +);
ID_523 = ID_522, ID_519;
ID_524 = (ID_523 : +);
ID_525 = ID_521, ID_524;
ID_526 = (ID_525 : /);
ID_527 = _, ID_526;
ID_528 = ID_527 : *;
ID_529 = (ID_376 : ID_528);
ID_530 = ID_374, ID_529;
ID_531 = ID_530 :> _;
ID_532 = (_ <: ID_531);
ID_533 = \(x219).(\(x220).(x220,x219 : -)) ~ ID_532;
ID_534 = 0, ID_354;
ID_535 = (ID_534 : *);
ID_536 = 1, ID_535;
ID_537 = (ID_536 : +);
ID_538 = 0, ID_356;
ID_539 = (ID_538 : *);
ID_540 = ID_537, ID_539;
ID_541 = (ID_540 : +);
ID_542 = ID_541, ID_370;
ID_543 = (ID_542 : /);
ID_544 = _, ID_543;
ID_545 = (ID_544 : *);
ID_546 = 0, ID_519;
ID_547 = (ID_546 : *);
ID_548 = 1, ID_547;
ID_549 = (ID_548 : -);
ID_550 = 2, ID_549;
ID_551 = (ID_550 : *);
ID_552 = ID_551, ID_524;
ID_553 = (ID_552 : /);
ID_554 = _, ID_553;
ID_555 = ID_554 : *;
ID_556 = (ID_376 : ID_555);
ID_557 = _, 2;
ID_558 = ID_557 : @;
ID_559 = (ID_234 : \(x198).(\(x199).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x198 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x199 : *) : +)~_));
ID_560 = (ID_8 : \(x198).(\(x199).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x198 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x199 : *) : +)~_));
ID_561 = (ID_10 : \(x201).(\(x202).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x201 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x202 : *) : +)~_));
ID_562 = ID_561, ID_12;
ID_563 = (ID_562 : +);
ID_564 = ID_563, ID_19;
ID_565 = ID_564 : *;
ID_566 = (ID_565 : int);
ID_567 = _, ID_566;
ID_568 = (ID_567 : %);
ID_569 = ID_568 ~ ID_27;
ID_570 = (ID_569 : \(x203).(x203,(x203 : mem) : <=));
ID_571 = (ID_570 : mem);
ID_572 = ID_570, ID_571;
ID_573 = (ID_572 : <=);
ID_574 = \(x200).(x200,(x200,0 : >) : +), ID_573;
ID_575 = (ID_574 : *);
ID_576 = (ID_572 : >);
ID_577 = ID_575, ID_576;
ID_578 = (ID_577 : +);
ID_579 = ID_578 ~ _;
ID_580 = (ID_10 : \(x204).(\(x205).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x204 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x205 : *) : +)~_));
ID_581 = ID_580, ID_19;
ID_582 = (ID_581 : *);
ID_583 = 1, ID_582;
ID_584 = (ID_583 : max);
ID_585 = 1, ID_584;
ID_586 = (ID_585 : /);
ID_587 = ID_579, ID_586;
ID_588 = (ID_587 : *);
ID_589 = ID_584, ID_53;
ID_590 = (ID_589 : *);
ID_591 = 1, ID_590;
ID_592 = (ID_591 : +);
ID_593 = ID_579, ID_53;
ID_594 = (ID_593 : *);
ID_595 = ID_592, ID_594;
ID_596 = (ID_595 : -);
ID_597 = ID_588, ID_596;
ID_598 = ID_597 : min;
ID_599 = (ID_598 : ID_65);
ID_600 = ID_560, ID_599;
ID_601 = ID_68 : \(x206).(\(x207).((hslider("[22]Rewind Button: Auto Env 1 On[midi:ctrl 43 1]", 0.0f, 0.0f, 1.0f, 1.0f),1 : >=),x206,x207 : select2));
ID_602 = (ID_600 : ID_601);
ID_603 = (ID_279 : \(x198).(\(x199).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x198 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x199 : *) : +)~_));
ID_604 = 1, ID_603;
ID_605 = ID_68 : \(x208).(\(x209).((hslider("[18]Cycle Button:Env1 > Filter[midi:ctrl 46 1]", 1.0f, 0.0f, 1.0f, 1.0f),1 : >=),x208,x209 : select2));
ID_606 = (ID_604 : ID_605);
ID_607 = ID_602, ID_606;
ID_608 = (ID_607 : *);
ID_609 = ID_559, ID_608;
ID_610 = (ID_609 : +);
ID_611 = (ID_80 : \(x198).(\(x199).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x198 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x199 : *) : +)~_));
ID_612 = ID_561, 2;
ID_613 = (ID_612 : /);
ID_614 = ID_613, ID_85;
ID_615 = (ID_614 : +);
ID_616 = ID_615, ID_19;
ID_617 = ID_616 : *;
ID_618 = (ID_617 : int);
ID_619 = _, ID_618;
ID_620 = (ID_619 : %);
ID_621 = ID_620 ~ ID_27;
ID_622 = (ID_621 : \(x211).(x211,(x211 : mem) : <=));
ID_623 = (ID_622 : mem);
ID_624 = ID_622, ID_623;
ID_625 = (ID_624 : <=);
ID_626 = \(x210).(x210,(x210,0 : >) : +), ID_625;
ID_627 = (ID_626 : *);
ID_628 = (ID_624 : >);
ID_629 = ID_627, ID_628;
ID_630 = (ID_629 : +);
ID_631 = ID_630 ~ _;
ID_632 = ID_580, 2;
ID_633 = (ID_632 : /);
ID_634 = ID_633, ID_19;
ID_635 = (ID_634 : *);
ID_636 = 1, ID_635;
ID_637 = (ID_636 : max);
ID_638 = 1, ID_637;
ID_639 = (ID_638 : /);
ID_640 = ID_631, ID_639;
ID_641 = (ID_640 : *);
ID_642 = ID_637, ID_119;
ID_643 = (ID_642 : *);
ID_644 = 1, ID_643;
ID_645 = (ID_644 : +);
ID_646 = ID_631, ID_119;
ID_647 = (ID_646 : *);
ID_648 = ID_645, ID_647;
ID_649 = (ID_648 : -);
ID_650 = ID_641, ID_649;
ID_651 = ID_650 : min;
ID_652 = (ID_651 : ID_65);
ID_653 = ID_611, ID_652;
ID_654 = ID_68 : \(x212).(\(x213).((hslider("[23]Fast-Forward Button:Auto Env 2 On[midi:ctrl 44 1]", 0.0f, 0.0f, 1.0f, 1.0f),1 : >=),x212,x213 : select2));
ID_655 = (ID_653 : ID_654);
ID_656 = (ID_333 : \(x198).(\(x199).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x198 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x199 : *) : +)~_));
ID_657 = 1, ID_656;
ID_658 = ID_68 : \(x214).(\(x215).((hslider("[21]Marker > Button:Env2 > Filter[midi:ctrl 62 1]", 1.0f, 0.0f, 1.0f, 1.0f),1 : >=),x214,x215 : select2));
ID_659 = (ID_657 : ID_658);
ID_660 = ID_655, ID_659;
ID_661 = (ID_660 : *);
ID_662 = ID_610, ID_661;
ID_663 = (ID_662 : +);
ID_664 = 10000, ID_663;
ID_665 = (ID_664 : min);
ID_666 = 20, ID_665;
ID_667 = (ID_666 : max);
ID_668 = 6.2831855f, ID_667;
ID_669 = (ID_668 : *);
ID_670 = ID_669, 0.5f;
ID_671 = (ID_670 : *);
ID_672 = ID_671, ID_19;
ID_673 = ID_672 : /;
ID_674 = (ID_673 : tan);
ID_675 = 1, ID_674;
ID_676 = (ID_675 : /);
ID_677 = 0, ID_676;
ID_678 = (ID_677 : *);
ID_679 = 1, ID_678;
ID_680 = (ID_679 : -);
ID_681 = ID_676, ID_676;
ID_682 = (ID_681 : *);
ID_683 = 0, ID_682;
ID_684 = (ID_683 : *);
ID_685 = ID_680, ID_684;
ID_686 = (ID_685 : +);
ID_687 = (ID_218 : \(x198).(\(x199).(((1.0f,(1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -) : -),x198 : *),((1,(44.1f,(1.92e+05f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : -),x199 : *) : +)~_));
ID_688 = 1.4142135f, ID_687;
ID_689 = (ID_688 : *);
ID_690 = 1.4141995f, ID_689;
ID_691 = (ID_690 : min);
ID_692 = 1.4142135f, ID_691;
ID_693 = (ID_692 : *);
ID_694 = 1, ID_693;
ID_695 = (ID_694 : +);
ID_696 = ID_691, 2;
ID_697 = (ID_696 : pow);
ID_698 = ID_695, ID_697;
ID_699 = (ID_698 : +);
ID_700 = 1, ID_699;
ID_701 = (ID_700 : *);
ID_702 = 2, ID_693;
ID_703 = (ID_702 : +);
ID_704 = 1, ID_703;
ID_705 = (ID_704 : *);
ID_706 = ID_705, ID_676;
ID_707 = (ID_706 : *);
ID_708 = ID_701, ID_707;
ID_709 = (ID_708 : +);
ID_710 = ID_709, ID_682;
ID_711 = (ID_710 : +);
ID_712 = ID_686, ID_711;
ID_713 = (ID_712 : /);
ID_714 = _, ID_713;
ID_715 = ID_714 : *;
ID_716 = (ID_558 : ID_715);
ID_717 = ID_556, ID_716;
ID_718 = ID_545, ID_717;
ID_719 = ID_718 :> _;
ID_720 = _ <: ID_719;
ID_721 = ID_533 : ID_720;
ID_722 = (ID_226 : -);
ID_723 = ID_722, ID_229;
ID_724 = (ID_723 : +);
ID_725 = 1, ID_724;
ID_726 = (ID_725 : *);
ID_727 = ID_726, ID_356;
ID_728 = (ID_727 : -);
ID_729 = 2, ID_728;
ID_730 = (ID_729 : *);
ID_731 = (ID_361 : -);
ID_732 = 1, ID_731;
ID_733 = (ID_732 : *);
ID_734 = ID_733, ID_354;
ID_735 = (ID_734 : *);
ID_736 = ID_726, ID_735;
ID_737 = (ID_736 : +);
ID_738 = ID_737, ID_356;
ID_739 = (ID_738 : +);
ID_740 = ID_730, ID_739;
ID_741 = (ID_740 : /);
ID_742 = _, ID_741;
ID_743 = (ID_742 : *);
ID_744 = (ID_384 : -);
ID_745 = ID_744, ID_387;
ID_746 = (ID_745 : +);
ID_747 = 1, ID_746;
ID_748 = (ID_747 : *);
ID_749 = (ID_392 : -);
ID_750 = 1, ID_749;
ID_751 = (ID_750 : *);
ID_752 = ID_751, ID_513;
ID_753 = (ID_752 : *);
ID_754 = ID_748, ID_753;
ID_755 = (ID_754 : -);
ID_756 = ID_755, ID_519;
ID_757 = (ID_756 : +);
ID_758 = (ID_754 : +);
ID_759 = ID_758, ID_519;
ID_760 = (ID_759 : +);
ID_761 = ID_757, ID_760;
ID_762 = (ID_761 : /);
ID_763 = _, ID_762;
ID_764 = ID_763 : *;
ID_765 = (ID_376 : ID_764);
ID_766 = ID_743, ID_765;
ID_767 = ID_766 :> _;
ID_768 = (_ <: ID_767);
ID_769 = \(x219).(\(x220).(x220,x219 : -)) ~ ID_768;
ID_770 = ID_541, ID_739;
ID_771 = (ID_770 : /);
ID_772 = _, ID_771;
ID_773 = (ID_772 : *);
ID_774 = ID_551, ID_760;
ID_775 = (ID_774 : /);
ID_776 = _, ID_775;
ID_777 = ID_776 : *;
ID_778 = (ID_376 : ID_777);
ID_779 = (ID_694 : -);
ID_780 = ID_779, ID_697;
ID_781 = (ID_780 : +);
ID_782 = 1, ID_781;
ID_783 = (ID_782 : *);
ID_784 = (ID_702 : -);
ID_785 = 1, ID_784;
ID_786 = (ID_785 : *);
ID_787 = ID_786, ID_676;
ID_788 = (ID_787 : *);
ID_789 = ID_783, ID_788;
ID_790 = (ID_789 : +);
ID_791 = ID_790, ID_682;
ID_792 = (ID_791 : +);
ID_793 = ID_686, ID_792;
ID_794 = (ID_793 : /);
ID_795 = _, ID_794;
ID_796 = ID_795 : *;
ID_797 = (ID_558 : ID_796);
ID_798 = ID_778, ID_797;
ID_799 = ID_773, ID_798;
ID_800 = ID_799 :> _;
ID_801 = _ <: ID_800;
ID_802 = ID_769 : ID_801;
ID_803 = (ID_721 : ID_802);
ID_804 = ID_803, ID_803;
ID_805 = ID_217 : ID_804;
process = ID_805;
