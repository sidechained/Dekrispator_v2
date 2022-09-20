/**
 ******************************************************************************
 * File Name          : soundGen.c
 * Author			  : Xavier Halgand
 * Date               :
 * Description        :
 ******************************************************************************
 */

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 */

#include "soundGen.h"
#include "CInterface.h"
#include "mydsp.c"

// #define EPSI				.00002f

static float output0[BUFF_LEN_DIV4] = {0.0};
static float output1[BUFF_LEN_DIV4] = {0.0};
static float* output[2] = {output0, output1};

mydsp* dsp;

void Synth_Init(void) {
    dsp = newmydsp();
    initmydsp(dsp, SAMPLERATE);
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

