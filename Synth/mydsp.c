/* ------------------------------------------------------------
name: "mydsp", "FaustDSP"
version: "2.50.2"
Code generated with Faust 2.49.1 (https://faust.grame.fr)
Compilation options: -lang c -es 1 -mcd 16 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 


#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

#include <math.h>
#include <stdint.h>
#include <stdlib.h>


#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

typedef struct {
	int iRec0[2];
	int fSampleRate;
} mydsp;

mydsp* newmydsp() { 
	mydsp* dsp = (mydsp*)calloc(1, sizeof(mydsp));
	return dsp;
}

void deletemydsp(mydsp* dsp) { 
	free(dsp);
}

void metadatamydsp(MetaGlue* m) { 
	m->declare(m->metaInterface, "compile_options", "-single -scal -I libraries/ -I project/ -lang wasm");
	m->declare(m->metaInterface, "filename", "mydsp.dsp");
	m->declare(m->metaInterface, "library_path0", "/libraries/stdfaust.lib");
	m->declare(m->metaInterface, "library_path1", "/libraries/noises.lib");
	m->declare(m->metaInterface, "name", "mydsp");
	m->declare(m->metaInterface, "noises_lib_name", "Faust Noise Generator Library");
	m->declare(m->metaInterface, "noises_lib_version", "0.4");
	m->declare(m->metaInterface, "version", "2.50.2");
}

int getSampleRatemydsp(mydsp* dsp) {
	return dsp->fSampleRate;
}

int getNumInputsmydsp(mydsp* dsp) {
	return 0;
}
int getNumOutputsmydsp(mydsp* dsp) {
	return 1;
}

void classInitmydsp(int sample_rate) {
}

void instanceResetUserInterfacemydsp(mydsp* dsp) {
}

void instanceClearmydsp(mydsp* dsp) {
	/* C99 loop */
	{
		int l0;
		for (l0 = 0; l0 < 2; l0 = l0 + 1) {
			dsp->iRec0[l0] = 0;
		}
	}
}

void instanceConstantsmydsp(mydsp* dsp, int sample_rate) {
	dsp->fSampleRate = sample_rate;
}

void instanceInitmydsp(mydsp* dsp, int sample_rate) {
	instanceConstantsmydsp(dsp, sample_rate);
	instanceResetUserInterfacemydsp(dsp);
	instanceClearmydsp(dsp);
}

void initmydsp(mydsp* dsp, int sample_rate) {
	classInitmydsp(sample_rate);
	instanceInitmydsp(dsp, sample_rate);
}

void buildUserInterfacemydsp(mydsp* dsp, UIGlue* ui_interface) {
	ui_interface->openVerticalBox(ui_interface->uiInterface, "mydsp");
	ui_interface->closeBox(ui_interface->uiInterface);
}

void computemydsp(mydsp* dsp, int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
	FAUSTFLOAT* output0 = outputs[0];
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			dsp->iRec0[0] = 1103515245 * dsp->iRec0[1] + 12345;
			output0[i0] = (FAUSTFLOAT)(4.656613e-10f * (float)(dsp->iRec0[0]));
			dsp->iRec0[1] = dsp->iRec0[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
