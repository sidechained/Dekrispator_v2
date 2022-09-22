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

void set_filter_cutoffFreqL(int val) {
    float floval;
    floval = ((float)val/127) * 9950 + 50;
    dsp->fHslider0 = floval; // "[0]cutoffFrequencyL",500,50,10000,0.01   
}

void set_filter_cutoffFreqR(int val) {
    float floval;
    floval = ((float)val/127) * 9950 + 50;
    dsp->fHslider3 = floval; // "[1]cutoffFrequencyR",500,50,10000,0.01  
}

void set_filter_q(int val) {
    float floval;
    floval = ((float)val/127) * 29 + 1;
    dsp->fHslider1 = floval; // "[2]q",5,1,30,0.1);  
}

void set_filter_gain(int val) {
    float floval;
    floval = (float)val/127;
    dsp->fHslider2 = floval; // "[3]gain",1,0,1,0.01);    
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

