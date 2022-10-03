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
static float mydsp_faustpower3_f(float value) {
	return value * value * value;
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
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fVslider0;
	int fSampleRate;
	int iConst1;
	int iVec0[4];
	int iRec1[2];
	int iVec1[2];
	int iRec0[2];
	float fConst2;
	float fConst3;
	float fConst4;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fVslider1;
	int iConst5;
	int iRec3[2];
	int iVec2[2];
	int iRec2[2];
	float fConst6;
	float fConst7;
	float fConst8;
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	float fConst9;
	FAUSTFLOAT fHslider8;
	FAUSTFLOAT fHslider9;
	FAUSTFLOAT fHslider10;
	FAUSTFLOAT fHslider11;
	FAUSTFLOAT fHslider12;
	float fConst10;
	FAUSTFLOAT fHslider13;
	float fConst11;
	float fRec6[2];
	FAUSTFLOAT fHslider14;
	FAUSTFLOAT fHslider15;
	float fRec7[2];
	FAUSTFLOAT fHslider16;
	float fConst12;
	float fRec8[2];
	FAUSTFLOAT fHslider17;
	float fConst13;
	float fRec9[2];
	float fVec3[2];
	float fVec4[2];
	float fVec5[2];
	FAUSTFLOAT fHslider18;
	float fRec10[2];
	float fVec6[2];
	float fVec7[2];
	float fVec8[2];
	float fRec11[2];
	float fVec9[2];
	float fVec10[2];
	float fVec11[2];
	FAUSTFLOAT fHslider19;
	float fRec12[2];
	float fConst14;
	float fConst15;
	FAUSTFLOAT fHslider20;
	float fRec13[2];
	float fConst17;
	float fRec5[3];
	float fRec4[3];
	float fConst18;
	float fRec15[3];
	float fRec14[3];
} mydsp;

mydsp* newmydsp() { 
	mydsp* dsp = (mydsp*)calloc(1, sizeof(mydsp));
	return dsp;
}

void deletemydsp(mydsp* dsp) { 
	free(dsp);
}

void metadatamydsp(MetaGlue* m) { 
	m->declare(m->metaInterface, "basics_lib_name", "Faust Basic Element Library");
	m->declare(m->metaInterface, "basics_lib_version", "0.8");
	m->declare(m->metaInterface, "compile_options", "-single -scal -I libraries/ -I project/ -lang wasm");
	m->declare(m->metaInterface, "envelopes_lib_ar_author", "Yann Orlarey, Stéphane Letz");
	m->declare(m->metaInterface, "envelopes_lib_author", "GRAME");
	m->declare(m->metaInterface, "envelopes_lib_copyright", "GRAME");
	m->declare(m->metaInterface, "envelopes_lib_license", "LGPL with exception");
	m->declare(m->metaInterface, "envelopes_lib_name", "Faust Envelope Library");
	m->declare(m->metaInterface, "envelopes_lib_version", "0.2");
	m->declare(m->metaInterface, "filename", "mydsp.dsp");
	m->declare(m->metaInterface, "filters_lib_fir_author", "Julius O. Smith III");
	m->declare(m->metaInterface, "filters_lib_fir_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "filters_lib_fir_license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters_lib_iir_author", "Julius O. Smith III");
	m->declare(m->metaInterface, "filters_lib_iir_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "filters_lib_iir_license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters_lib_lowpass0_highpass1", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters_lib_name", "Faust Filters Library");
	m->declare(m->metaInterface, "filters_lib_tf2_author", "Julius O. Smith III");
	m->declare(m->metaInterface, "filters_lib_tf2_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "filters_lib_tf2_license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters_lib_tf2s_author", "Julius O. Smith III");
	m->declare(m->metaInterface, "filters_lib_tf2s_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "filters_lib_tf2s_license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters_lib_version", "0.3");
	m->declare(m->metaInterface, "library_path0", "/libraries/stdfaust.lib");
	m->declare(m->metaInterface, "library_path1", "/libraries/basics.lib");
	m->declare(m->metaInterface, "library_path2", "/libraries/signals.lib");
	m->declare(m->metaInterface, "library_path3", "/libraries/maths.lib");
	m->declare(m->metaInterface, "library_path4", "/libraries/platform.lib");
	m->declare(m->metaInterface, "library_path5", "/libraries/oscillators.lib");
	m->declare(m->metaInterface, "library_path6", "/libraries/envelopes.lib");
	m->declare(m->metaInterface, "library_path7", "/libraries/vaeffects.lib");
	m->declare(m->metaInterface, "library_path8", "/libraries/filters.lib");
	m->declare(m->metaInterface, "maths_lib_author", "GRAME");
	m->declare(m->metaInterface, "maths_lib_copyright", "GRAME");
	m->declare(m->metaInterface, "maths_lib_license", "LGPL with exception");
	m->declare(m->metaInterface, "maths_lib_name", "Faust Math Library");
	m->declare(m->metaInterface, "maths_lib_version", "2.5");
	m->declare(m->metaInterface, "name", "mydsp");
	m->declare(m->metaInterface, "oscillators_lib_lf_sawpos_author", "Bart Brouns, revised by Stéphane Letz");
	m->declare(m->metaInterface, "oscillators_lib_lf_sawpos_licence", "STK-4.3");
	m->declare(m->metaInterface, "oscillators_lib_name", "Faust Oscillator Library");
	m->declare(m->metaInterface, "oscillators_lib_version", "0.3");
	m->declare(m->metaInterface, "platform_lib_name", "Generic Platform Library");
	m->declare(m->metaInterface, "platform_lib_version", "0.2");
	m->declare(m->metaInterface, "signals_lib_name", "Faust Signal Routing Library");
	m->declare(m->metaInterface, "signals_lib_version", "0.3");
	m->declare(m->metaInterface, "vaeffects_lib_moog_vcf_2b_author", "Julius O. Smith III");
	m->declare(m->metaInterface, "vaeffects_lib_moog_vcf_2b_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "vaeffects_lib_moog_vcf_2b_license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "vaeffects_lib_name", "Faust Virtual Analog Filter Effect Library");
	m->declare(m->metaInterface, "vaeffects_lib_version", "0.2");
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
	dsp->fHslider0 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider1 = (FAUSTFLOAT)(0.0f);
	dsp->fVslider0 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider2 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider3 = (FAUSTFLOAT)(5e+03f);
	dsp->fHslider4 = (FAUSTFLOAT)(0.0f);
	dsp->fVslider1 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider5 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider6 = (FAUSTFLOAT)(5e+03f);
	dsp->fHslider7 = (FAUSTFLOAT)(3e+03f);
	dsp->fHslider8 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider9 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider10 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider11 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider12 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider13 = (FAUSTFLOAT)(5e+03f);
	dsp->fHslider14 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider15 = (FAUSTFLOAT)(5e+03f);
	dsp->fHslider16 = (FAUSTFLOAT)(49.0f);
	dsp->fHslider17 = (FAUSTFLOAT)(0.1f);
	dsp->fHslider18 = (FAUSTFLOAT)(-0.1f);
	dsp->fHslider19 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider20 = (FAUSTFLOAT)(-6.0f);
}

void instanceClearmydsp(mydsp* dsp) {
	/* C99 loop */
	{
		int l0;
		for (l0 = 0; l0 < 4; l0 = l0 + 1) {
			dsp->iVec0[l0] = 0;
		}
	}
	/* C99 loop */
	{
		int l1;
		for (l1 = 0; l1 < 2; l1 = l1 + 1) {
			dsp->iRec1[l1] = 0;
		}
	}
	/* C99 loop */
	{
		int l2;
		for (l2 = 0; l2 < 2; l2 = l2 + 1) {
			dsp->iVec1[l2] = 0;
		}
	}
	/* C99 loop */
	{
		int l3;
		for (l3 = 0; l3 < 2; l3 = l3 + 1) {
			dsp->iRec0[l3] = 0;
		}
	}
	/* C99 loop */
	{
		int l4;
		for (l4 = 0; l4 < 2; l4 = l4 + 1) {
			dsp->iRec3[l4] = 0;
		}
	}
	/* C99 loop */
	{
		int l5;
		for (l5 = 0; l5 < 2; l5 = l5 + 1) {
			dsp->iVec2[l5] = 0;
		}
	}
	/* C99 loop */
	{
		int l6;
		for (l6 = 0; l6 < 2; l6 = l6 + 1) {
			dsp->iRec2[l6] = 0;
		}
	}
	/* C99 loop */
	{
		int l7;
		for (l7 = 0; l7 < 2; l7 = l7 + 1) {
			dsp->fRec6[l7] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l8;
		for (l8 = 0; l8 < 2; l8 = l8 + 1) {
			dsp->fRec7[l8] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l9;
		for (l9 = 0; l9 < 2; l9 = l9 + 1) {
			dsp->fRec8[l9] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l10;
		for (l10 = 0; l10 < 2; l10 = l10 + 1) {
			dsp->fRec9[l10] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l11;
		for (l11 = 0; l11 < 2; l11 = l11 + 1) {
			dsp->fVec3[l11] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l12;
		for (l12 = 0; l12 < 2; l12 = l12 + 1) {
			dsp->fVec4[l12] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l13;
		for (l13 = 0; l13 < 2; l13 = l13 + 1) {
			dsp->fVec5[l13] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l14;
		for (l14 = 0; l14 < 2; l14 = l14 + 1) {
			dsp->fRec10[l14] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l15;
		for (l15 = 0; l15 < 2; l15 = l15 + 1) {
			dsp->fVec6[l15] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l16;
		for (l16 = 0; l16 < 2; l16 = l16 + 1) {
			dsp->fVec7[l16] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l17;
		for (l17 = 0; l17 < 2; l17 = l17 + 1) {
			dsp->fVec8[l17] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l18;
		for (l18 = 0; l18 < 2; l18 = l18 + 1) {
			dsp->fRec11[l18] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l19;
		for (l19 = 0; l19 < 2; l19 = l19 + 1) {
			dsp->fVec9[l19] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l20;
		for (l20 = 0; l20 < 2; l20 = l20 + 1) {
			dsp->fVec10[l20] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l21;
		for (l21 = 0; l21 < 2; l21 = l21 + 1) {
			dsp->fVec11[l21] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l22;
		for (l22 = 0; l22 < 2; l22 = l22 + 1) {
			dsp->fRec12[l22] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l23;
		for (l23 = 0; l23 < 2; l23 = l23 + 1) {
			dsp->fRec13[l23] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l24;
		for (l24 = 0; l24 < 3; l24 = l24 + 1) {
			dsp->fRec5[l24] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l25;
		for (l25 = 0; l25 < 3; l25 = l25 + 1) {
			dsp->fRec4[l25] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l26;
		for (l26 = 0; l26 < 3; l26 = l26 + 1) {
			dsp->fRec15[l26] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l27;
		for (l27 = 0; l27 < 3; l27 = l27 + 1) {
			dsp->fRec14[l27] = 0.0f;
		}
	}
}

void instanceConstantsmydsp(mydsp* dsp, int sample_rate) {
	dsp->fSampleRate = sample_rate;
	float fConst0 = fminf(1.92e+05f, fmaxf(1.0f, (float)(dsp->fSampleRate)));
	dsp->iConst1 = (int)(0.7f * fConst0);
	dsp->fConst2 = fmaxf(1.0f, 0.4f * fConst0);
	dsp->fConst3 = 1.0f / dsp->fConst2;
	dsp->fConst4 = 1.0f / fmaxf(1.0f, 0.3f * fConst0);
	dsp->iConst5 = (int)(1.1f * fConst0);
	dsp->fConst6 = fmaxf(1.0f, 0.1f * fConst0);
	dsp->fConst7 = 1.0f / dsp->fConst6;
	dsp->fConst8 = 1.0f / fmaxf(1.0f, fConst0);
	dsp->fConst9 = 3.1415927f / fConst0;
	dsp->fConst10 = expf(0.0f - 1e+01f / fConst0);
	dsp->fConst11 = 1.0f - dsp->fConst10;
	dsp->fConst12 = 4.4e+02f * dsp->fConst11;
	dsp->fConst13 = 1.0f / fConst0;
	dsp->fConst14 = 44.1f / fConst0;
	dsp->fConst15 = 1.0f - dsp->fConst14;
	float fConst16 = mydsp_faustpower3_f(fConst0);
	dsp->fConst17 = 0.16666667f * fConst16;
	dsp->fConst18 = 0.00026041668f * fConst16;
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
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider4, "0", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider4, "midi", "ctrl 43 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider4, "style", "knob");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Auto Env 1 On", &dsp->fHslider4, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider18, "0", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider18, "midi", "ctrl 17 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider18, "style", "knob");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider18, "unit", "%%");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Detune 1", &dsp->fHslider18, (FAUSTFLOAT)-0.1f, (FAUSTFLOAT)-1e+01f, (FAUSTFLOAT)1e+01f, (FAUSTFLOAT)0.01f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider17, "0", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider17, "midi", "ctrl 18 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider17, "style", "knob");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider17, "unit", "%%");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Detune 2", &dsp->fHslider17, (FAUSTFLOAT)0.1f, (FAUSTFLOAT)-1e+01f, (FAUSTFLOAT)1e+01f, (FAUSTFLOAT)0.01f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider8, "0", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider8, "midi", "ctrl 58 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider8, "style", "knob");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Env1 > Amp", &dsp->fHslider8, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider5, "0", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider5, "midi", "ctrl 46 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider5, "style", "knob");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Env1 > Filter", &dsp->fHslider5, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider7, "0", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider7, "midi", "ctrl 19 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider7, "style", "knob");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider7, "unit", "Hz");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Filter Frequency", &dsp->fHslider7, (FAUSTFLOAT)3e+03f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.5e+04f, (FAUSTFLOAT)1e+01f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "0", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "midi", "ctrl 20 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "style", "knob");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Filter Resonance", &dsp->fHslider0, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider20, "0", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider20, "midi", "ctrl 23 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider20, "style", "knob");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider20, "unit", "dB");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Master Volume", &dsp->fHslider20, (FAUSTFLOAT)-6.0f, (FAUSTFLOAT)-1.2e+02f, (FAUSTFLOAT)1e+01f, (FAUSTFLOAT)0.1f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider16, "0", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider16, "midi", "ctrl 16 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider16, "style", "knob");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider16, "unit", "PK");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Oscillator Frequency", &dsp->fHslider16, (FAUSTFLOAT)49.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)88.0f, (FAUSTFLOAT)0.01f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider9, "1", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider9, "midi", "ctrl 2 1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Amplitude Env1 Depth", &dsp->fHslider9, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider11, "1", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider11, "midi", "ctrl 5 1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Amplitude Env2 Depth", &dsp->fHslider11, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "1", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "midi", "ctrl 44 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "style", "knob");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Auto Env 2 On", &dsp->fHslider1, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider14, "1", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider14, "midi", "ctrl 59 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider14, "style", "knob");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Env1 > Pitch", &dsp->fHslider14, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider10, "1", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider10, "midi", "ctrl 60 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider10, "style", "knob");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Env2 > Amp", &dsp->fHslider10, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider6, "1", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider6, "midi", "ctrl 4 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider6, "unit", "Hz");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Filter Env1 Depth", &dsp->fHslider6, (FAUSTFLOAT)5e+03f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1e+04f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "1", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "midi", "ctrl 7 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "unit", "Hz");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Filter Env2 Depth", &dsp->fHslider3, (FAUSTFLOAT)5e+03f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1e+04f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider15, "1", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider15, "midi", "ctrl 3 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider15, "unit", "Hz");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Pitch Env1 Depth", &dsp->fHslider15, (FAUSTFLOAT)5e+03f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)5e+03f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider13, "1", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider13, "midi", "ctrl 6 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider13, "unit", "Hz");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Pitch Env2 Depth", &dsp->fHslider13, (FAUSTFLOAT)5e+03f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)5e+03f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVslider1, "1", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVslider1, "midi", "ctrl 0 1");
	ui_interface->addVerticalSlider(ui_interface->uiInterface, "env1", &dsp->fVslider1, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVslider0, "1", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVslider0, "midi", "ctrl 1 1");
	ui_interface->addVerticalSlider(ui_interface->uiInterface, "env2", &dsp->fVslider0, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.01f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider12, "2", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider12, "midi", "ctrl 61 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider12, "style", "knob");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Env2 > Pitch", &dsp->fHslider12, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider2, "3", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider2, "midi", "ctrl 62 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider2, "style", "knob");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Env2 > Filter", &dsp->fHslider2, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider19, "4", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider19, "midi", "ctrl 45 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider19, "style", "knob");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Mute Output", &dsp->fHslider19, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->closeBox(ui_interface->uiInterface);
}

void computemydsp(mydsp* dsp, int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
	FAUSTFLOAT* output0 = outputs[0];
	FAUSTFLOAT* output1 = outputs[1];
	float fSlow0 = fminf(1.4141995f, 1.4142135f * (float)(dsp->fHslider0));
	float fSlow1 = 1.4142135f * fSlow0;
	int iSlow2 = (float)(dsp->fHslider1) >= 1.0f;
	float fSlow3 = (float)(dsp->fVslider0);
	float fElse1 = (float)(dsp->fHslider3);
	float fSlow4 = (((float)(dsp->fHslider2) >= 1.0f) ? fElse1 : 1.0f);
	int iSlow5 = (float)(dsp->fHslider4) >= 1.0f;
	float fSlow6 = (float)(dsp->fVslider1);
	float fElse3 = (float)(dsp->fHslider6);
	float fSlow7 = (((float)(dsp->fHslider5) >= 1.0f) ? fElse3 : 1.0f);
	float fSlow8 = (float)(dsp->fHslider7);
	float fSlow9 = 2.0f - fSlow1;
	float fSlow10 = mydsp_faustpower2_f(fSlow0);
	float fSlow11 = fSlow1 + 2.0f;
	float fSlow12 = fSlow1 + fSlow10;
	int iSlow13 = (float)(dsp->fHslider8) >= 1.0f;
	float fSlow14 = (float)(dsp->fHslider9);
	float fElse4 = 1.0f - fSlow14;
	int iSlow15 = (float)(dsp->fHslider10) >= 1.0f;
	float fSlow16 = (float)(dsp->fHslider11);
	float fElse5 = 1.0f - fSlow16;
	float fSlow17 = ((iSlow15) ? fElse5 : 0.5f) + ((iSlow13) ? fElse4 : 0.5f);
	float fSlow18 = ((iSlow13) ? fSlow14 : 0.5f);
	float fSlow19 = ((iSlow15) ? fSlow16 : 0.5f);
	int iSlow20 = (float)(dsp->fHslider12) >= 1.0f;
	float fSlow21 = dsp->fConst11 * (float)(dsp->fHslider13);
	int iSlow22 = (float)(dsp->fHslider14) >= 1.0f;
	float fSlow23 = dsp->fConst11 * (float)(dsp->fHslider15);
	float fSlow24 = dsp->fConst12 * powf(2.0f, 0.083333336f * ((float)(dsp->fHslider16) + -49.0f));
	float fSlow25 = 0.01f * (float)(dsp->fHslider17) + 1.0f;
	float fSlow26 = 0.01f * (float)(dsp->fHslider18) + 1.0f;
	float fSlow27 = dsp->fConst11 * (1.0f - (float)(dsp->fHslider19));
	float fSlow28 = dsp->fConst14 * powf(1e+01f, 0.05f * (float)(dsp->fHslider20));
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			dsp->iVec0[0] = 1;
			dsp->iRec1[0] = (dsp->iVec0[1] + dsp->iRec1[1]) % dsp->iConst1;
			int iTemp0 = dsp->iRec1[0] <= dsp->iRec1[1];
			dsp->iVec1[0] = iTemp0;
			dsp->iRec0[0] = (dsp->iRec0[1] + (dsp->iRec0[1] > 0)) * (iTemp0 <= dsp->iVec1[1]) + (iTemp0 > dsp->iVec1[1]);
			float fTemp1 = (float)(dsp->iRec0[0]);
			float fElse0 = fmaxf(0.0f, fminf(dsp->fConst3 * fTemp1, dsp->fConst4 * (dsp->fConst2 - fTemp1) + 1.0f));
			float fTemp2 = ((iSlow2) ? fElse0 : fSlow3);
			dsp->iRec3[0] = (dsp->iVec0[1] + dsp->iRec3[1]) % dsp->iConst5;
			int iTemp3 = dsp->iRec3[0] <= dsp->iRec3[1];
			dsp->iVec2[0] = iTemp3;
			dsp->iRec2[0] = (dsp->iRec2[1] + (dsp->iRec2[1] > 0)) * (iTemp3 <= dsp->iVec2[1]) + (iTemp3 > dsp->iVec2[1]);
			float fTemp4 = (float)(dsp->iRec2[0]);
			float fElse2 = fmaxf(0.0f, fminf(dsp->fConst7 * fTemp4, dsp->fConst8 * (dsp->fConst6 - fTemp4) + 1.0f));
			float fTemp5 = ((iSlow5) ? fElse2 : fSlow6);
			float fTemp6 = tanf(dsp->fConst9 * fmaxf(2e+01f, fminf(1e+04f, fSlow8 + fSlow7 * fTemp5 + fSlow4 * fTemp2)));
			float fTemp7 = 1.0f / fTemp6;
			float fTemp8 = fSlow10 + ((fSlow9 + fTemp7) / fTemp6 + 1.0f - fSlow1);
			float fTemp9 = 1.0f - 1.0f / mydsp_faustpower2_f(fTemp6);
			float fTemp10 = fSlow10 + (fTemp9 - fSlow1);
			float fTemp11 = fSlow10 + ((fTemp7 - fSlow9) / fTemp6 + 1.0f - fSlow1);
			float fTemp12 = fSlow12 + (fSlow11 + fTemp7) / fTemp6 + 1.0f;
			float fTemp13 = fSlow12 + fTemp9;
			float fTemp14 = fSlow12 + (fTemp7 - fSlow11) / fTemp6 + 1.0f;
			float fTemp15 = fSlow19 * fTemp2 + fSlow18 * fTemp5 + fSlow17;
			dsp->fRec6[0] = fSlow21 + dsp->fConst10 * dsp->fRec6[1];
			dsp->fRec7[0] = fSlow23 + dsp->fConst10 * dsp->fRec7[1];
			dsp->fRec8[0] = fSlow24 + dsp->fConst10 * dsp->fRec8[1];
			float fTemp16 = dsp->fRec8[0] + ((iSlow22) ? dsp->fRec7[0] : 1.0f) * fTemp5 + ((iSlow20) ? dsp->fRec6[0] : 1.0f) * fTemp2;
			float fTemp17 = fmaxf(2e+01f, fabsf(fSlow25 * fTemp16));
			float fTemp18 = dsp->fRec9[1] + dsp->fConst13 * fTemp17;
			dsp->fRec9[0] = fTemp18 - floorf(fTemp18);
			float fTemp19 = mydsp_faustpower2_f(2.0f * dsp->fRec9[0] + -1.0f);
			float fTemp20 = fTemp19 * (fTemp19 + -2.0f);
			dsp->fVec3[0] = fTemp20;
			float fTemp21 = (fTemp20 - dsp->fVec3[1]) / fTemp17;
			dsp->fVec4[0] = fTemp21;
			float fTemp22 = (fTemp21 - dsp->fVec4[1]) / fTemp17;
			dsp->fVec5[0] = fTemp22;
			float fTemp23 = (fTemp22 - dsp->fVec5[1]) / fTemp17;
			float fTemp24 = fmaxf(2e+01f, fabsf(fSlow26 * fTemp16));
			float fTemp25 = dsp->fRec10[1] + dsp->fConst13 * fTemp24;
			dsp->fRec10[0] = fTemp25 - floorf(fTemp25);
			float fTemp26 = mydsp_faustpower2_f(2.0f * dsp->fRec10[0] + -1.0f);
			float fTemp27 = fTemp26 * (fTemp26 + -2.0f);
			dsp->fVec6[0] = fTemp27;
			float fTemp28 = (fTemp27 - dsp->fVec6[1]) / fTemp24;
			dsp->fVec7[0] = fTemp28;
			float fTemp29 = (fTemp28 - dsp->fVec7[1]) / fTemp24;
			dsp->fVec8[0] = fTemp29;
			float fTemp30 = (fTemp29 - dsp->fVec8[1]) / fTemp24;
			float fTemp31 = fmaxf(2e+01f, fabsf(fTemp16));
			float fTemp32 = dsp->fRec11[1] + dsp->fConst13 * fTemp31;
			dsp->fRec11[0] = fTemp32 - floorf(fTemp32);
			float fTemp33 = mydsp_faustpower2_f(2.0f * dsp->fRec11[0] + -1.0f);
			float fTemp34 = fTemp33 * (fTemp33 + -2.0f);
			dsp->fVec9[0] = fTemp34;
			float fTemp35 = (fTemp34 - dsp->fVec9[1]) / fTemp31;
			dsp->fVec10[0] = fTemp35;
			float fTemp36 = (fTemp35 - dsp->fVec10[1]) / fTemp31;
			dsp->fVec11[0] = fTemp36;
			float fTemp37 = (fTemp36 - dsp->fVec11[1]) / fTemp31;
			dsp->fRec12[0] = fSlow27 + dsp->fConst10 * dsp->fRec12[1];
			dsp->fRec13[0] = fSlow28 + dsp->fConst15 * dsp->fRec13[1];
			float fTemp38 = mydsp_faustpower2_f(dsp->fRec13[0]) * dsp->fRec12[0] * (float)(dsp->iVec0[3]);
			dsp->fRec5[0] = dsp->fConst17 * fTemp38 * (0.0052083335f * fTemp37 + 0.0015625f * fTemp30 + 0.0052083335f * fTemp23) * fTemp15 - (dsp->fRec5[2] * fTemp14 + 2.0f * dsp->fRec5[1] * fTemp13) / fTemp12;
			dsp->fRec4[0] = (dsp->fRec5[2] + dsp->fRec5[0] + 2.0f * dsp->fRec5[1]) / fTemp12 - (dsp->fRec4[2] * fTemp11 + 2.0f * dsp->fRec4[1] * fTemp10) / fTemp8;
			output0[i0] = (FAUSTFLOAT)((dsp->fRec4[2] + dsp->fRec4[0] + 2.0f * dsp->fRec4[1]) / fTemp8);
			dsp->fRec15[0] = dsp->fConst18 * fTemp38 * fTemp15 * (fTemp23 + fTemp37 + fTemp30) - (fTemp14 * dsp->fRec15[2] + 2.0f * fTemp13 * dsp->fRec15[1]) / fTemp12;
			dsp->fRec14[0] = (dsp->fRec15[2] + dsp->fRec15[0] + 2.0f * dsp->fRec15[1]) / fTemp12 - (fTemp11 * dsp->fRec14[2] + 2.0f * fTemp10 * dsp->fRec14[1]) / fTemp8;
			output1[i0] = (FAUSTFLOAT)((dsp->fRec14[2] + dsp->fRec14[0] + 2.0f * dsp->fRec14[1]) / fTemp8);
			/* C99 loop */
			{
				int j0;
				for (j0 = 3; j0 > 0; j0 = j0 - 1) {
					dsp->iVec0[j0] = dsp->iVec0[j0 - 1];
				}
			}
			dsp->iRec1[1] = dsp->iRec1[0];
			dsp->iVec1[1] = dsp->iVec1[0];
			dsp->iRec0[1] = dsp->iRec0[0];
			dsp->iRec3[1] = dsp->iRec3[0];
			dsp->iVec2[1] = dsp->iVec2[0];
			dsp->iRec2[1] = dsp->iRec2[0];
			dsp->fRec6[1] = dsp->fRec6[0];
			dsp->fRec7[1] = dsp->fRec7[0];
			dsp->fRec8[1] = dsp->fRec8[0];
			dsp->fRec9[1] = dsp->fRec9[0];
			dsp->fVec3[1] = dsp->fVec3[0];
			dsp->fVec4[1] = dsp->fVec4[0];
			dsp->fVec5[1] = dsp->fVec5[0];
			dsp->fRec10[1] = dsp->fRec10[0];
			dsp->fVec6[1] = dsp->fVec6[0];
			dsp->fVec7[1] = dsp->fVec7[0];
			dsp->fVec8[1] = dsp->fVec8[0];
			dsp->fRec11[1] = dsp->fRec11[0];
			dsp->fVec9[1] = dsp->fVec9[0];
			dsp->fVec10[1] = dsp->fVec10[0];
			dsp->fVec11[1] = dsp->fVec11[0];
			dsp->fRec12[1] = dsp->fRec12[0];
			dsp->fRec13[1] = dsp->fRec13[0];
			dsp->fRec5[2] = dsp->fRec5[1];
			dsp->fRec5[1] = dsp->fRec5[0];
			dsp->fRec4[2] = dsp->fRec4[1];
			dsp->fRec4[1] = dsp->fRec4[0];
			dsp->fRec15[2] = dsp->fRec15[1];
			dsp->fRec15[1] = dsp->fRec15[0];
			dsp->fRec14[2] = dsp->fRec14[1];
			dsp->fRec14[1] = dsp->fRec14[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
