// Author: Xavier Halgand

#include "soundGen.h"
#include "CInterface.h" // For MetaGlue and UIGlue located in /Applications/Faust-2.41.1/include/faust/gui

#include "mydsp.c"

static float output0[BUFF_LEN_DIV4] = {0.0};
static float output1[BUFF_LEN_DIV4] = {0.0};
static float* output[2] = {output0, output1};

mydsp* dsp;

void Synth_Init(void) {
    dsp = newmydsp();
    initmydsp(dsp, SAMPLERATE);
}

// Faders

void set_env1(int val) {
    float min = 0.0f;
    float max = 1.0f;
    float zeroToOne = ((float)val)/127;
    dsp->fVslider1 = (zeroToOne * (max-min)) + min;
}

void set_env2(int val) {
    float min = 0.0f;
    float max = 1.0f;
    float zeroToOne = ((float)val)/127;
    dsp->fVslider0 = (zeroToOne * (max-min)) + min;
}

void set_Amplitude_Env1_Depth(int val) {
    float min = 0.0f;
    float max = 1.0f;
    float zeroToOne = ((float)val)/127;
    dsp->fHslider9 = (zeroToOne * (max-min)) + min;
}

void set_Pitch_Env1_Depth(int val) {
    float min = 0.0f;
    float max = 5e+03f;
    float zeroToOne = ((float)val)/127;
    dsp->fHslider15 = (zeroToOne * (max-min)) + min;
}

void set_Filter_Env1_Depth(int val) {
    float min = 0.0f;
    float max = 1e+04f;
    float zeroToOne = ((float)val)/127;
    dsp->fHslider6 = (zeroToOne * (max-min)) + min;
}

void set_Amplitude_Env2_Depth(int val) {
    float min = 0.0f;
    float max = 1.0f;
    float zeroToOne = ((float)val)/127;
    dsp->fHslider11 = (zeroToOne * (max-min)) + min;
}

void set_Pitch_Env2_Depth(int val) {
    float min = 0.0f;
    float max = 5e+03f;
    float zeroToOne = ((float)val)/127;
    dsp->fHslider13 = (zeroToOne * (max-min)) + min;
}

void set_Filter_Env2_Depth(int val) {
    float min = 0.0f;
    float max = 1e+04f;
    float zeroToOne = ((float)val)/127;
    dsp->fHslider3 = (zeroToOne * (max-min)) + min;
}

// Knobs

void set_Oscillator_Frequency(int val) {
    float min = 0.0f;
    float max = 88.0f;
    float zeroToOne = ((float)val)/127;
    dsp->fHslider16 = (zeroToOne * (max-min)) + min;
}

void set_Detune_1(int val) {
    float min = -1e+01f;
    float max = 1e+01f;
    float zeroToOne = ((float)val)/127;
    dsp->fHslider18 = (zeroToOne * (max-min)) + min;
}

void set_Detune_2(int val) {
    float min = -1e+01f;
    float max = 1e+01f;
    float zeroToOne = ((float)val)/127;
    dsp->fHslider17 = (zeroToOne * (max-min)) + min;
}

void set_Filter_Frequency(int val) {
    float min = 0.0f;
    float max = 1.5e+04f;
    float zeroToOne = ((float)val)/127;
    dsp->fHslider7 = (zeroToOne * (max-min)) + min;
}

void set_Filter_Resonance(int val) {
    float min = 0.0f;
    float max = 1.0f;
    float zeroToOne = ((float)val)/127;
    dsp->fHslider0 = (zeroToOne * (max-min)) + min;
}

// void set_Echo_Duration(int val) {
//     float min = 0.0f;
//     float max = 0.5f;
//     float zeroToOne = ((float)val)/127;
//     dsp->fHslider22 = (zeroToOne * (max-min)) + min;
// }

// void set_Echo_Feedback(int val) {
//     float min = 0.0f;
//     float max = 1.0f;
//     float zeroToOne = ((float)val)/127;
//     dsp->fHslider23 = (zeroToOne * (max-min)) + min;
// }

void set_Master_Volume(int val) {
    float min = -1.2e+02f;
    float max = 1e+01f;
    float zeroToOne = ((float)val)/127;
    dsp->fHslider20 = (zeroToOne * (max-min)) + min;
}

// TRANSPORT

void set_Env1toAmp(int val) {
    float min = 0.0f;
    float max = 1.0f;
    float zeroToOne = ((float)val)/127;
    dsp->fHslider8 = (zeroToOne * (max-min)) + min;
}

void set_Env1toPitch(int val) {
    float min = 0.0f;
    float max = 1.0f;
    float zeroToOne = ((float)val)/127;
    dsp->fHslider14 = (zeroToOne * (max-min)) + min;
}

void set_Env1toFilter(int val) {
    float min = 0.0f;
    float max = 1.0f;
    float zeroToOne = ((float)val)/127;
    dsp->fHslider5 = (zeroToOne * (max-min)) + min;
}

void set_Env2toAmp(int val) {
    float min = 0.0f;
    float max = 1.0f;
    float zeroToOne = ((float)val)/127;
    dsp->fHslider10 = (zeroToOne * (max-min)) + min;
}

void set_Env2toPitch(int val) {
    float min = 0.0f;
    float max = 1.0f;
    float zeroToOne = ((float)val)/127;
    dsp->fHslider12 = (zeroToOne * (max-min)) + min;
}

void set_Env2toFilter(int val) {
    float min = 0.0f;
    float max = 1.0f;
    float zeroToOne = ((float)val)/127;
    dsp->fHslider2 = (zeroToOne * (max-min)) + min;
}

void set_Auto_Env_1_On(int val) {
    float min = 0.0f;
    float max = 1.0f;
    float zeroToOne = ((float)val)/127;
    dsp->fHslider4 = (zeroToOne * (max-min)) + min;
}

void set_Auto_Env_2_On(int val) {
    float min = 0.0f;
    float max = 1.0f;
    float zeroToOne = ((float)val)/127;
    dsp->fHslider1 = (zeroToOne * (max-min)) + min;
}

// void set_Echo_Gate(int val) {
//     float min = 0.0f;
//     float max = 1.0f;
//     float zeroToOne = ((float)val)/127;
//     dsp->fHslider21 = (zeroToOne * (max-min)) + min;
// }

void set_Mute_Output(int val) {
    float min = 0.0f;
    float max = 1.0f;
    float zeroToOne = ((float)val)/127;
    dsp->fHslider19 = (zeroToOne * (max-min)) + min;
}

void make_sound(uint16_t *buf, uint16_t len) // BUF_LEN_DIV4
{
    uint16_t pos;
    uint16_t *outp;

    computemydsp(dsp, len, NULL, output); // ignores everything but output[0] - so right channel SHOULD be silent
    
    // conversion float -> int (l, r interleaved)
    outp = buf;
    for (pos=0;pos<len;pos++)
    {
        *outp++ = (uint16_t) ((int16_t) ((32767.0f) * output0[pos]));
        *outp++ = (uint16_t) ((int16_t) ((32767.0f) * output1[pos]));
    }
}

