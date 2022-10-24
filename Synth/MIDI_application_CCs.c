			case 0: //Fader1:Env 1 Level
				set_fHslider8(val, 0.0, 1.0);
				break;
			case 1: //Fader1:Env 2 Level
				set_fHslider2(val, 0.0, 1.0);
				break;
			case 3: //Fader1:Pitch Env1 Depth
				set_fHslider17(val, 0.0, 5e+02);
				break;
			case 4: //Fader1:Filter Env1 Depth
				set_fHslider10(val, 0.0, 1e+04);
				break;
			case 5: //Fader1:Amplitude Env2 Depth
				set_fHslider13(val, 0.0, 1.0);
				break;
			case 6: //Fader1:Pitch Env2 Depth
				set_fHslider15(val, 0.0, 5e+02);
				break;
			case 7: //Fader1:Filter Env2 Depth
				set_fHslider6(val, 0.0, 1e+04);
				break;
			case 16: //Knob1:Oscillator Frequency
				set_fHslider18(val, 0.0, 88.0);
				break;
			case 17: //Knob2:Detune 1
				set_fHslider20(val, -1e+01, 1e+01);
				break;
			case 18: //Knob3:Detune 2
				set_fHslider19(val, -1e+01, 1e+01);
				break;
			case 19: //Knob4:Filter Frequency
				set_fHslider11(val, 0.0, 1.5e+04);
				break;
			case 20: //Knob5:Filter Resonance
				set_fHslider0(val, 0.0, 1.0);
				break;
			case 21: //Knob6:Autoenv Attack Time
				set_fHslider3(val, 0.0, 2.0);
				break;
			case 22: //Knob7:Autoenv Release Time
				set_fHslider4(val, 0.1, 2.0);
				break;
			case 23: //Knob8:Master Volume
				set_fHslider22(val, -1.2e+02, 1e+01);
				break;
			case 43: //Rewind Button: Auto Env 1 On
				set_fHslider7(val, 0.0, 1.0);
				break;
			case 44: //Fast-Forward Button:Auto Env 2 On
				set_fHslider1(val, 0.0, 1.0);
				break;
			case 45: //Record Button: Mute Output
				set_fHslider21(val, 0.0, 1.0);
				break;
			case 46: //Cycle Button:Env1 > Filter
				set_fHslider9(val, 0.0, 1.0);
				break;
			case 59: //Track > Button:Env1 > Pitch
				set_fHslider16(val, 0.0, 1.0);
				break;
			case 60: //Set Marker Button:Env2 > Amp
				set_fHslider12(val, 0.0, 1.0);
				break;
			case 61: //Marker < Button:Env2 > Pitch
				set_fHslider14(val, 0.0, 1.0);
				break;
			case 62: //Marker > Button:Env2 > Filter
				set_fHslider5(val, 0.0, 1.0);
				break;
