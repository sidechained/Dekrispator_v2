// Author: Xavier Halgand

#ifndef __SOUNDGEN_H
#define __SOUNDGEN_H

#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include "CONSTANTS.h"
#include "MIDI_application.h"
#include "timers.h"

void Synth_Init(void);
void set_env1(int val);
void set_env2(int val);
void set_Amplitude_Env1_Depth(int val);
void set_Pitch_Env1_Depth(int val);
void set_Filter_Env1_Depth(int val);
void set_Amplitude_Env2_Depth(int val);
void set_Pitch_Env2_Depth(int val);
void set_Filter_Env2_Depth(int val);
void set_Oscillator_Frequency(int val);
void set_Detune_1(int val);
void set_Detune_2(int val);
void set_Filter_Frequency(int val);
void set_Filter_Resonance(int val);
// void set_Echo_Duration(int val);
// void set_Echo_Feedback(int val);
void set_Master_Volume(int val);
void set_Env1toAmp(int val);
void set_Env1toPitch(int val);
void set_Env1toFilter(int val);
void set_Env2toAmp(int val);
void set_Env2toPitch(int val);
void set_Env2toFilter(int val);
void set_Auto_Env_1_On(int val);
void set_Auto_Env_2_On(int val);
// void set_Echo_Gate(int val) {
void set_Mute_Output(int val);
void make_sound(uint16_t *buf , uint16_t len);

#endif