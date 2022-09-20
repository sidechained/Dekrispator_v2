/* ------------------------------------------------------------
name: "sine"
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
	int fSampleRate;
	float fConst0;
	float fRec0[2];
} mydsp;

mydsp* newmydsp() { 
	mydsp* dsp = (mydsp*)calloc(1, sizeof(mydsp));
	return dsp;
}

void deletemydsp(mydsp* dsp) { 
	free(dsp);
}

// void metadatamydsp(MetaGlue* m) { 
// 	m->declare(m->metaInterface, "compile_options", "-single -scal -I libraries/ -I project/ -lang wasm");
// 	m->declare(m->metaInterface, "filename", "sine.dsp");
// 	m->declare(m->metaInterface, "library_path0", "/libraries/stdfaust.lib");
// 	m->declare(m->metaInterface, "library_path1", "/libraries/maths.lib");
// 	m->declare(m->metaInterface, "library_path2", "/libraries/platform.lib");
// 	m->declare(m->metaInterface, "maths_lib_author", "GRAME");
// 	m->declare(m->metaInterface, "maths_lib_copyright", "GRAME");
// 	m->declare(m->metaInterface, "maths_lib_license", "LGPL with exception");
// 	m->declare(m->metaInterface, "maths_lib_name", "Faust Math Library");
// 	m->declare(m->metaInterface, "maths_lib_version", "2.5");
// 	m->declare(m->metaInterface, "name", "sine");
// 	m->declare(m->metaInterface, "platform_lib_name", "Generic Platform Library");
// 	m->declare(m->metaInterface, "platform_lib_version", "0.2");
// 	m->declare(m->metaInterface, "version", "2.50.2");
// }

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
			dsp->fRec0[l0] = 0.0f;
		}
	}
}

void instanceConstantsmydsp(mydsp* dsp, int sample_rate) {
	dsp->fSampleRate = sample_rate;
	dsp->fConst0 = 1e+03f / fminf(1.92e+05f, fmaxf(1.0f, (float)(dsp->fSampleRate)));
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

// void buildUserInterfacemydsp(mydsp* dsp, UIGlue* ui_interface) {
// 	ui_interface->openVerticalBox(ui_interface->uiInterface, "sine");
// 	ui_interface->closeBox(ui_interface->uiInterface);
// }

void computemydsp(mydsp* dsp, int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
	FAUSTFLOAT* output0 = outputs[0];
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			dsp->fRec0[0] = dsp->fConst0 + (dsp->fRec0[1] - floorf(dsp->fRec0[1]));
			output0[i0] = (FAUSTFLOAT)(0.75f * sinf(6.2831855f * dsp->fRec0[0]));
			dsp->fRec0[1] = dsp->fRec0[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
