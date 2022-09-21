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

static float mydsp_faustpower2_f(float value) {
	return value * value;
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

typedef struct {
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	FAUSTFLOAT fHslider1;
	int iRec1[2];
	float fRec0[3];
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	float fRec2[3];
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
	m->declare(m->metaInterface, "filters_lib_fir_author", "Julius O. Smith III");
	m->declare(m->metaInterface, "filters_lib_fir_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "filters_lib_fir_license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters_lib_iir_author", "Julius O. Smith III");
	m->declare(m->metaInterface, "filters_lib_iir_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "filters_lib_iir_license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters_lib_lowpass0_highpass1", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters_lib_name", "Faust Filters Library");
	m->declare(m->metaInterface, "filters_lib_resonlp_author", "Julius O. Smith III");
	m->declare(m->metaInterface, "filters_lib_resonlp_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "filters_lib_resonlp_license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters_lib_tf2_author", "Julius O. Smith III");
	m->declare(m->metaInterface, "filters_lib_tf2_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "filters_lib_tf2_license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters_lib_tf2s_author", "Julius O. Smith III");
	m->declare(m->metaInterface, "filters_lib_tf2s_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "filters_lib_tf2s_license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters_lib_version", "0.3");
	m->declare(m->metaInterface, "library_path0", "/libraries/stdfaust.lib");
	m->declare(m->metaInterface, "library_path1", "/libraries/noises.lib");
	m->declare(m->metaInterface, "library_path2", "/libraries/filters.lib");
	m->declare(m->metaInterface, "library_path3", "/libraries/maths.lib");
	m->declare(m->metaInterface, "library_path4", "/libraries/platform.lib");
	m->declare(m->metaInterface, "maths_lib_author", "GRAME");
	m->declare(m->metaInterface, "maths_lib_copyright", "GRAME");
	m->declare(m->metaInterface, "maths_lib_license", "LGPL with exception");
	m->declare(m->metaInterface, "maths_lib_name", "Faust Math Library");
	m->declare(m->metaInterface, "maths_lib_version", "2.5");
	m->declare(m->metaInterface, "name", "mydsp");
	m->declare(m->metaInterface, "noises_lib_name", "Faust Noise Generator Library");
	m->declare(m->metaInterface, "noises_lib_version", "0.4");
	m->declare(m->metaInterface, "platform_lib_name", "Generic Platform Library");
	m->declare(m->metaInterface, "platform_lib_version", "0.2");
	m->declare(m->metaInterface, "version", "2.50.2");
}

int getSampleRatemydsp(mydsp* dsp) {
	return dsp->fSampleRate;
}

int getNumInputsmydsp(mydsp* dsp) {
	return 0;
}
int getNumOutputsmydsp(mydsp* dsp) {
	return 2;
}

void classInitmydsp(int sample_rate) {
}

void instanceResetUserInterfacemydsp(mydsp* dsp) {
	dsp->fHslider0 = (FAUSTFLOAT)(5e+02f);
	dsp->fHslider1 = (FAUSTFLOAT)(5.0f);
	dsp->fHslider2 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider3 = (FAUSTFLOAT)(5e+02f);
}

void instanceClearmydsp(mydsp* dsp) {
	/* C99 loop */
	{
		int l0;
		for (l0 = 0; l0 < 2; l0 = l0 + 1) {
			dsp->iRec1[l0] = 0;
		}
	}
	/* C99 loop */
	{
		int l1;
		for (l1 = 0; l1 < 3; l1 = l1 + 1) {
			dsp->fRec0[l1] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l2;
		for (l2 = 0; l2 < 3; l2 = l2 + 1) {
			dsp->fRec2[l2] = 0.0f;
		}
	}
}

void instanceConstantsmydsp(mydsp* dsp, int sample_rate) {
	dsp->fSampleRate = sample_rate;
	dsp->fConst0 = 3.1415927f / fminf(1.92e+05f, fmaxf(1.0f, (float)(dsp->fSampleRate)));
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
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "0", "");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "cutoffFrequencyL", &dsp->fHslider0, (FAUSTFLOAT)5e+02f, (FAUSTFLOAT)5e+01f, (FAUSTFLOAT)1e+04f, (FAUSTFLOAT)0.01f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "1", "");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "cutoffFrequencyR", &dsp->fHslider3, (FAUSTFLOAT)5e+02f, (FAUSTFLOAT)5e+01f, (FAUSTFLOAT)1e+04f, (FAUSTFLOAT)0.01f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "2", "");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "q", &dsp->fHslider1, (FAUSTFLOAT)5.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)3e+01f, (FAUSTFLOAT)0.1f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider2, "3", "");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "gain", &dsp->fHslider2, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.01f);
	ui_interface->closeBox(ui_interface->uiInterface);
}

void buildEmbeddedUserInterfacemydsp(mydsp* dsp) {
	synth_interface.slider1 = &dsp->fHslider0;
	synth_interface.slider2 = &dsp->fHslider3;
	synth_interface.slider3 = &dsp->fHslider1;
	synth_interface.slider4 = &dsp->fHslider2;
}

void computemydsp(mydsp* dsp, int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
	FAUSTFLOAT* output0 = outputs[0];
	FAUSTFLOAT* output1 = outputs[1];
	float fSlow0 = tanf(dsp->fConst0 * (float)(dsp->fHslider0));
	float fSlow1 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fSlow0));
	float fSlow2 = 1.0f / (float)(dsp->fHslider1);
	float fSlow3 = 1.0f / fSlow0;
	float fSlow4 = (fSlow3 - fSlow2) / fSlow0 + 1.0f;
	float fSlow5 = (fSlow2 + fSlow3) / fSlow0 + 1.0f;
	float fSlow6 = 1.0f / fSlow5;
	float fSlow7 = (float)(dsp->fHslider2);
	float fSlow8 = fSlow7 / fSlow5;
	float fSlow9 = tanf(dsp->fConst0 * (float)(dsp->fHslider3));
	float fSlow10 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fSlow9));
	float fSlow11 = 1.0f / fSlow9;
	float fSlow12 = (fSlow11 - fSlow2) / fSlow9 + 1.0f;
	float fSlow13 = (fSlow2 + fSlow11) / fSlow9 + 1.0f;
	float fSlow14 = 1.0f / fSlow13;
	float fSlow15 = fSlow7 / fSlow13;
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			dsp->iRec1[0] = 1103515245 * dsp->iRec1[1] + 12345;
			float fTemp0 = 4.656613e-10f * (float)(dsp->iRec1[0]);
			dsp->fRec0[0] = fTemp0 - fSlow6 * (fSlow4 * dsp->fRec0[2] + fSlow1 * dsp->fRec0[1]);
			output0[i0] = (FAUSTFLOAT)(fSlow8 * (dsp->fRec0[2] + dsp->fRec0[0] + 2.0f * dsp->fRec0[1]));
			dsp->fRec2[0] = fTemp0 - fSlow14 * (fSlow12 * dsp->fRec2[2] + fSlow10 * dsp->fRec2[1]);
			output1[i0] = (FAUSTFLOAT)(fSlow15 * (dsp->fRec2[2] + dsp->fRec2[0] + 2.0f * dsp->fRec2[1]));
			dsp->iRec1[1] = dsp->iRec1[0];
			dsp->fRec0[2] = dsp->fRec0[1];
			dsp->fRec0[1] = dsp->fRec0[0];
			dsp->fRec2[2] = dsp->fRec2[1];
			dsp->fRec2[1] = dsp->fRec2[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
