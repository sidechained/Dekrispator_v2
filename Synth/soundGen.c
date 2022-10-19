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
    dsp->fHslider0 = (zeroToOne * (max-min)) + min;
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

