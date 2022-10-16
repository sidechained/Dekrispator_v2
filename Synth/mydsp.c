/* ------------------------------------------------------------
name: "sawsynth-faustcodeV1.1"
Code generated with Faust 2.41.1 (https://faust.grame.fr)
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

static float mydsp_faustpower3_f(float value) {
	return value * value * value;
}
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
	int fSampleRate;
	float fConst0;
	float fConst2;
	float fConst3;
	FAUSTFLOAT fHslider0;
	float fConst4;
	int iVec0[4];
	float fRec2[2];
	FAUSTFLOAT fHslider1;
	float fRec3[2];
	float fConst5;
	float fConst6;
	float fConst7;
	float fConst8;
	FAUSTFLOAT fHslider2;
	float fRec6[2];
	float fRec5[2];
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fRec7[2];
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fVslider0;
	float fRec8[2];
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	float fRec11[2];
	int iRec10[2];
	int iVec1[2];
	int iRec9[2];
	FAUSTFLOAT fHslider8;
	FAUSTFLOAT fHslider9;
	float fRec12[2];
	FAUSTFLOAT fHslider10;
	FAUSTFLOAT fVslider1;
	float fRec13[2];
	float fConst9;
	int iRec15[2];
	int iVec2[2];
	int iRec14[2];
	float fRec4[2];
	float fVec3[2];
	float fVec4[2];
	float fVec5[2];
	FAUSTFLOAT fHslider11;
	float fRec17[2];
	float fRec16[2];
	float fVec6[2];
	float fVec7[2];
	float fVec8[2];
	FAUSTFLOAT fHslider12;
	float fRec19[2];
	float fRec18[2];
	float fVec9[2];
	float fVec10[2];
	float fVec11[2];
	FAUSTFLOAT fHslider13;
	FAUSTFLOAT fHslider14;
	float fRec20[2];
	FAUSTFLOAT fHslider15;
	float fRec21[2];
	float fConst10;
	FAUSTFLOAT fHslider16;
	float fRec22[2];
	FAUSTFLOAT fHslider17;
	FAUSTFLOAT fHslider18;
	float fRec23[2];
	FAUSTFLOAT fHslider19;
	FAUSTFLOAT fHslider20;
	float fRec24[2];
	float fRec1[3];
	float fRec0[3];
	float fConst11;
	float fRec26[3];
	float fRec25[3];
} mydsp;

mydsp* newmydsp() { 
	mydsp* dsp = (mydsp*)calloc(1, sizeof(mydsp));
	return dsp;
}

void deletemydsp(mydsp* dsp) { 
	free(dsp);
}

void metadatamydsp(MetaGlue* m) { 
	m->declare(m->metaInterface, "basics.lib/name", "Faust Basic Element Library");
	m->declare(m->metaInterface, "basics.lib/version", "0.8");
	m->declare(m->metaInterface, "compile_options", "-lang c -es 1 -mcd 16 -single -ftz 0");
	m->declare(m->metaInterface, "envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
	m->declare(m->metaInterface, "envelopes.lib/author", "GRAME");
	m->declare(m->metaInterface, "envelopes.lib/copyright", "GRAME");
	m->declare(m->metaInterface, "envelopes.lib/license", "LGPL with exception");
	m->declare(m->metaInterface, "envelopes.lib/name", "Faust Envelope Library");
	m->declare(m->metaInterface, "envelopes.lib/version", "0.2");
	m->declare(m->metaInterface, "filename", "sawsynth-faustcodeV1.1.dsp");
	m->declare(m->metaInterface, "filters.lib/fir:author", "Julius O. Smith III");
	m->declare(m->metaInterface, "filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "filters.lib/fir:license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters.lib/iir:author", "Julius O. Smith III");
	m->declare(m->metaInterface, "filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "filters.lib/iir:license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters.lib/name", "Faust Filters Library");
	m->declare(m->metaInterface, "filters.lib/tf2:author", "Julius O. Smith III");
	m->declare(m->metaInterface, "filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "filters.lib/tf2:license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters.lib/tf2s:author", "Julius O. Smith III");
	m->declare(m->metaInterface, "filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "filters.lib/tf2s:license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters.lib/version", "0.3");
	m->declare(m->metaInterface, "maths.lib/author", "GRAME");
	m->declare(m->metaInterface, "maths.lib/copyright", "GRAME");
	m->declare(m->metaInterface, "maths.lib/license", "LGPL with exception");
	m->declare(m->metaInterface, "maths.lib/name", "Faust Math Library");
	m->declare(m->metaInterface, "maths.lib/version", "2.5");
	m->declare(m->metaInterface, "name", "sawsynth-faustcodeV1.1");
	m->declare(m->metaInterface, "options", "[midi:on]");
	m->declare(m->metaInterface, "oscillators.lib/lf_sawpos:author", "Bart Brouns, revised by Stéphane Letz");
	m->declare(m->metaInterface, "oscillators.lib/lf_sawpos:licence", "STK-4.3");
	m->declare(m->metaInterface, "oscillators.lib/name", "Faust Oscillator Library");
	m->declare(m->metaInterface, "oscillators.lib/version", "0.3");
	m->declare(m->metaInterface, "platform.lib/name", "Generic Platform Library");
	m->declare(m->metaInterface, "platform.lib/version", "0.2");
	m->declare(m->metaInterface, "signals.lib/name", "Faust Signal Routing Library");
	m->declare(m->metaInterface, "signals.lib/version", "0.3");
	m->declare(m->metaInterface, "vaeffects.lib/moog_vcf_2b:author", "Julius O. Smith III");
	m->declare(m->metaInterface, "vaeffects.lib/moog_vcf_2b:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "vaeffects.lib/moog_vcf_2b:license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "vaeffects.lib/name", "Faust Virtual Analog Filter Effect Library");
	m->declare(m->metaInterface, "vaeffects.lib/version", "0.2");
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
	dsp->fHslider0 = (FAUSTFLOAT)(-6.0f);
	dsp->fHslider1 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider2 = (FAUSTFLOAT)(49.0f);
	dsp->fHslider3 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider4 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider5 = (FAUSTFLOAT)(0.0f);
	dsp->fVslider0 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider6 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider7 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider8 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider9 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider10 = (FAUSTFLOAT)(0.0f);
	dsp->fVslider1 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider11 = (FAUSTFLOAT)(-0.10000000000000001f);
	dsp->fHslider12 = (FAUSTFLOAT)(0.10000000000000001f);
	dsp->fHslider13 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider14 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider15 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider16 = (FAUSTFLOAT)(3000.0f);
	dsp->fHslider17 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider18 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider19 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider20 = (FAUSTFLOAT)(0.0f);
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
			dsp->fRec2[l1] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l2;
		for (l2 = 0; l2 < 2; l2 = l2 + 1) {
			dsp->fRec3[l2] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l3;
		for (l3 = 0; l3 < 2; l3 = l3 + 1) {
			dsp->fRec6[l3] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l4;
		for (l4 = 0; l4 < 2; l4 = l4 + 1) {
			dsp->fRec5[l4] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l5;
		for (l5 = 0; l5 < 2; l5 = l5 + 1) {
			dsp->fRec7[l5] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l6;
		for (l6 = 0; l6 < 2; l6 = l6 + 1) {
			dsp->fRec8[l6] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l7;
		for (l7 = 0; l7 < 2; l7 = l7 + 1) {
			dsp->fRec11[l7] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l8;
		for (l8 = 0; l8 < 2; l8 = l8 + 1) {
			dsp->iRec10[l8] = 0;
		}
	}
	/* C99 loop */
	{
		int l9;
		for (l9 = 0; l9 < 2; l9 = l9 + 1) {
			dsp->iVec1[l9] = 0;
		}
	}
	/* C99 loop */
	{
		int l10;
		for (l10 = 0; l10 < 2; l10 = l10 + 1) {
			dsp->iRec9[l10] = 0;
		}
	}
	/* C99 loop */
	{
		int l11;
		for (l11 = 0; l11 < 2; l11 = l11 + 1) {
			dsp->fRec12[l11] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l12;
		for (l12 = 0; l12 < 2; l12 = l12 + 1) {
			dsp->fRec13[l12] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l13;
		for (l13 = 0; l13 < 2; l13 = l13 + 1) {
			dsp->iRec15[l13] = 0;
		}
	}
	/* C99 loop */
	{
		int l14;
		for (l14 = 0; l14 < 2; l14 = l14 + 1) {
			dsp->iVec2[l14] = 0;
		}
	}
	/* C99 loop */
	{
		int l15;
		for (l15 = 0; l15 < 2; l15 = l15 + 1) {
			dsp->iRec14[l15] = 0;
		}
	}
	/* C99 loop */
	{
		int l16;
		for (l16 = 0; l16 < 2; l16 = l16 + 1) {
			dsp->fRec4[l16] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l17;
		for (l17 = 0; l17 < 2; l17 = l17 + 1) {
			dsp->fVec3[l17] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l18;
		for (l18 = 0; l18 < 2; l18 = l18 + 1) {
			dsp->fVec4[l18] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l19;
		for (l19 = 0; l19 < 2; l19 = l19 + 1) {
			dsp->fVec5[l19] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l20;
		for (l20 = 0; l20 < 2; l20 = l20 + 1) {
			dsp->fRec17[l20] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l21;
		for (l21 = 0; l21 < 2; l21 = l21 + 1) {
			dsp->fRec16[l21] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l22;
		for (l22 = 0; l22 < 2; l22 = l22 + 1) {
			dsp->fVec6[l22] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l23;
		for (l23 = 0; l23 < 2; l23 = l23 + 1) {
			dsp->fVec7[l23] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l24;
		for (l24 = 0; l24 < 2; l24 = l24 + 1) {
			dsp->fVec8[l24] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l25;
		for (l25 = 0; l25 < 2; l25 = l25 + 1) {
			dsp->fRec19[l25] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l26;
		for (l26 = 0; l26 < 2; l26 = l26 + 1) {
			dsp->fRec18[l26] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l27;
		for (l27 = 0; l27 < 2; l27 = l27 + 1) {
			dsp->fVec9[l27] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l28;
		for (l28 = 0; l28 < 2; l28 = l28 + 1) {
			dsp->fVec10[l28] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l29;
		for (l29 = 0; l29 < 2; l29 = l29 + 1) {
			dsp->fVec11[l29] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l30;
		for (l30 = 0; l30 < 2; l30 = l30 + 1) {
			dsp->fRec20[l30] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l31;
		for (l31 = 0; l31 < 2; l31 = l31 + 1) {
			dsp->fRec21[l31] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l32;
		for (l32 = 0; l32 < 2; l32 = l32 + 1) {
			dsp->fRec22[l32] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l33;
		for (l33 = 0; l33 < 2; l33 = l33 + 1) {
			dsp->fRec23[l33] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l34;
		for (l34 = 0; l34 < 2; l34 = l34 + 1) {
			dsp->fRec24[l34] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l35;
		for (l35 = 0; l35 < 3; l35 = l35 + 1) {
			dsp->fRec1[l35] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l36;
		for (l36 = 0; l36 < 3; l36 = l36 + 1) {
			dsp->fRec0[l36] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l37;
		for (l37 = 0; l37 < 3; l37 = l37 + 1) {
			dsp->fRec26[l37] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l38;
		for (l38 = 0; l38 < 3; l38 = l38 + 1) {
			dsp->fRec25[l38] = 0.0f;
		}
	}
}

void instanceConstantsmydsp(mydsp* dsp, int sample_rate) {
	dsp->fSampleRate = sample_rate;
	dsp->fConst0 = fminf(192000.0f, fmaxf(1.0f, (float)(dsp->fSampleRate)));
	float fConst1 = mydsp_faustpower3_f(dsp->fConst0);
	dsp->fConst2 = 0.166666672f * fConst1;
	dsp->fConst3 = 44.0999985f / dsp->fConst0;
	dsp->fConst4 = 1.0f - dsp->fConst3;
	dsp->fConst5 = 1.0f / dsp->fConst0;
	dsp->fConst6 = expf(0.0f - 10.0f / dsp->fConst0);
	dsp->fConst7 = 1.0f - dsp->fConst6;
	dsp->fConst8 = 19404.0f / dsp->fConst0;
	dsp->fConst9 = 0.5f * dsp->fConst0;
	dsp->fConst10 = 3.14159274f / dsp->fConst0;
	dsp->fConst11 = 0.00026041668f * fConst1;
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
	ui_interface->openVerticalBox(ui_interface->uiInterface, "sawsynth-faustcodeV1.1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider5, "0", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider5, "midi", "ctrl 43 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider5, "style", "knob");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Auto Env 1 On", &dsp->fHslider5, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider7, "0", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider7, "midi", "ctrl 21 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider7, "style", "knob");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Autoenv Attack Time", &dsp->fHslider7, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)0.00100000005f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider6, "0", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider6, "midi", "ctrl 22 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider6, "style", "knob");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Autoenv Release Time", &dsp->fHslider6, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.100000001f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)0.00100000005f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider11, "0", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider11, "midi", "ctrl 17 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider11, "style", "knob");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider11, "unit", "%%");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Detune 1", &dsp->fHslider11, (FAUSTFLOAT)-0.100000001f, (FAUSTFLOAT)-10.0f, (FAUSTFLOAT)10.0f, (FAUSTFLOAT)0.00999999978f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider12, "0", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider12, "midi", "ctrl 18 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider12, "style", "knob");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider12, "unit", "%%");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Detune 2", &dsp->fHslider12, (FAUSTFLOAT)0.100000001f, (FAUSTFLOAT)-10.0f, (FAUSTFLOAT)10.0f, (FAUSTFLOAT)0.00999999978f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider17, "0", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider17, "midi", "ctrl 46 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider17, "style", "knob");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Env1 > Filter", &dsp->fHslider17, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider16, "0", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider16, "midi", "ctrl 19 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider16, "style", "knob");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider16, "unit", "Hz");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Filter Frequency", &dsp->fHslider16, (FAUSTFLOAT)3000.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)15000.0f, (FAUSTFLOAT)10.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider15, "0", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider15, "midi", "ctrl 20 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider15, "style", "knob");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Filter Resonance", &dsp->fHslider15, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.00100000005f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "0", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "midi", "ctrl 23 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "style", "knob");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "unit", "dB");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Master Volume", &dsp->fHslider0, (FAUSTFLOAT)-6.0f, (FAUSTFLOAT)-120.0f, (FAUSTFLOAT)10.0f, (FAUSTFLOAT)0.100000001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider2, "0", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider2, "midi", "ctrl 16 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider2, "style", "knob");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider2, "unit", "PK");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Oscillator Frequency", &dsp->fHslider2, (FAUSTFLOAT)49.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)88.0f, (FAUSTFLOAT)0.00999999978f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider14, "1", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider14, "midi", "ctrl 5 1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Amplitude Env2 Depth", &dsp->fHslider14, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.00100000005f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider10, "1", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider10, "midi", "ctrl 44 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider10, "style", "knob");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Auto Env 2 On", &dsp->fHslider10, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "1", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "midi", "ctrl 59 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "style", "knob");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Env1 > Pitch", &dsp->fHslider3, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider13, "1", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider13, "midi", "ctrl 60 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider13, "style", "knob");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Env2 > Amp", &dsp->fHslider13, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider18, "1", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider18, "midi", "ctrl 4 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider18, "unit", "Hz");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Filter Env1 Depth", &dsp->fHslider18, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)10000.0f, (FAUSTFLOAT)0.00100000005f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider20, "1", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider20, "midi", "ctrl 7 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider20, "unit", "Hz");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Filter Env2 Depth", &dsp->fHslider20, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)10000.0f, (FAUSTFLOAT)0.00100000005f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider4, "1", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider4, "midi", "ctrl 3 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider4, "unit", "Hz");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Pitch Env1 Depth", &dsp->fHslider4, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)500.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider9, "1", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider9, "midi", "ctrl 6 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider9, "unit", "Hz");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Pitch Env2 Depth", &dsp->fHslider9, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)500.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVslider0, "1", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVslider0, "midi", "ctrl 0 1");
	ui_interface->addVerticalSlider(ui_interface->uiInterface, "env1", &dsp->fVslider0, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.00100000005f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVslider1, "1", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fVslider1, "midi", "ctrl 1 1");
	ui_interface->addVerticalSlider(ui_interface->uiInterface, "env2", &dsp->fVslider1, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.00999999978f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider8, "2", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider8, "midi", "ctrl 61 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider8, "style", "knob");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Env2 > Pitch", &dsp->fHslider8, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider19, "3", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider19, "midi", "ctrl 62 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider19, "style", "knob");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Env2 > Filter", &dsp->fHslider19, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "4", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "midi", "ctrl 45 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "style", "knob");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Mute Output", &dsp->fHslider1, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->closeBox(ui_interface->uiInterface);
}

void computemydsp(mydsp* dsp, int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
	FAUSTFLOAT* output0 = outputs[0];
	FAUSTFLOAT* output1 = outputs[1];
	float fSlow0 = dsp->fConst3 * powf(10.0f, 0.0500000007f * (float)(dsp->fHslider0));
	float fSlow1 = dsp->fConst3 * (1.0f - (float)(dsp->fHslider1));
	float fSlow2 = dsp->fConst8 * powf(2.0f, 0.0833333358f * ((float)(dsp->fHslider2) + -49.0f));
	int iSlow3 = (float)(dsp->fHslider3) >= 1.0f;
	float fSlow4 = dsp->fConst3 * (float)(dsp->fHslider4);
	int iSlow5 = (float)(dsp->fHslider5) >= 1.0f;
	float fSlow6 = dsp->fConst3 * (float)(dsp->fVslider0);
	float fSlow7 = (float)(dsp->fHslider6);
	float fSlow8 = dsp->fConst3 * (float)(dsp->fHslider7);
	float fSlow9 = 1.0f / fmaxf(1.0f, dsp->fConst0 * fSlow7);
	int iSlow10 = (float)(dsp->fHslider8) >= 1.0f;
	float fSlow11 = dsp->fConst3 * (float)(dsp->fHslider9);
	int iSlow12 = (float)(dsp->fHslider10) >= 1.0f;
	float fSlow13 = dsp->fConst3 * (float)(dsp->fVslider1);
	float fSlow14 = 1.0f / fmaxf(1.0f, dsp->fConst9 * fSlow7);
	float fSlow15 = dsp->fConst3 * (0.00999999978f * (float)(dsp->fHslider11) + 1.0f);
	float fSlow16 = dsp->fConst3 * (0.00999999978f * (float)(dsp->fHslider12) + 1.0f);
	int iSlow17 = (float)(dsp->fHslider13) >= 1.0f;
	float fSlow18 = dsp->fConst3 * (float)(dsp->fHslider14);
	float fSlow19 = dsp->fConst3 * (float)(dsp->fHslider15);
	float fSlow20 = dsp->fConst3 * (float)(dsp->fHslider16);
	int iSlow21 = (float)(dsp->fHslider17) >= 1.0f;
	float fSlow22 = dsp->fConst3 * (float)(dsp->fHslider18);
	int iSlow23 = (float)(dsp->fHslider19) >= 1.0f;
	float fSlow24 = dsp->fConst3 * (float)(dsp->fHslider20);
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			dsp->iVec0[0] = 1;
			dsp->fRec2[0] = fSlow0 + dsp->fConst4 * dsp->fRec2[1];
			dsp->fRec3[0] = fSlow1 + dsp->fConst4 * dsp->fRec3[1];
			float fTemp0 = mydsp_faustpower2_f(dsp->fRec2[0]) * dsp->fRec3[0] * (float)(dsp->iVec0[3]);
			dsp->fRec6[0] = fSlow2 + dsp->fConst4 * dsp->fRec6[1];
			dsp->fRec5[0] = dsp->fConst7 * dsp->fRec6[0] + dsp->fConst6 * dsp->fRec5[1];
			dsp->fRec7[0] = fSlow4 + dsp->fConst4 * dsp->fRec7[1];
			dsp->fRec8[0] = fSlow6 + dsp->fConst4 * dsp->fRec8[1];
			dsp->fRec11[0] = fSlow8 + dsp->fConst4 * dsp->fRec11[1];
			float fTemp1 = fSlow7 + dsp->fRec11[0];
			dsp->iRec10[0] = (dsp->iVec0[1] + dsp->iRec10[1]) % (int)(dsp->fConst0 * fTemp1);
			int iTemp2 = dsp->iRec10[0] <= dsp->iRec10[1];
			dsp->iVec1[0] = iTemp2;
			dsp->iRec9[0] = (dsp->iRec9[1] + (dsp->iRec9[1] > 0)) * (iTemp2 <= dsp->iVec1[1]) + (iTemp2 > dsp->iVec1[1]);
			float fTemp3 = (float)(dsp->iRec9[0]);
			float fTemp4 = fmaxf(1.0f, dsp->fConst0 * dsp->fRec11[0]);
			float fElse1 = fmaxf(0.0f, fminf(fTemp3 / fTemp4, fSlow9 * (fTemp4 - fTemp3) + 1.0f));
			float fTemp5 = ((iSlow5) ? fElse1 : dsp->fRec8[0]);
			dsp->fRec12[0] = fSlow11 + dsp->fConst4 * dsp->fRec12[1];
			dsp->fRec13[0] = fSlow13 + dsp->fConst4 * dsp->fRec13[1];
			dsp->iRec15[0] = (dsp->iVec0[1] + dsp->iRec15[1]) % (int)(dsp->fConst9 * fTemp1);
			int iTemp6 = dsp->iRec15[0] <= dsp->iRec15[1];
			dsp->iVec2[0] = iTemp6;
			dsp->iRec14[0] = (dsp->iRec14[1] + (dsp->iRec14[1] > 0)) * (iTemp6 <= dsp->iVec2[1]) + (iTemp6 > dsp->iVec2[1]);
			float fTemp7 = (float)(dsp->iRec14[0]);
			float fTemp8 = fmaxf(1.0f, dsp->fConst9 * dsp->fRec11[0]);
			float fElse3 = fmaxf(0.0f, fminf(fTemp7 / fTemp8, fSlow14 * (fTemp8 - fTemp7) + 1.0f));
			float fTemp9 = ((iSlow12) ? fElse3 : dsp->fRec13[0]);
			float fTemp10 = dsp->fRec5[0] + ((iSlow3) ? dsp->fRec7[0] : 1.0f) * fTemp5 + ((iSlow10) ? dsp->fRec12[0] : 1.0f) * fTemp9;
			float fTemp11 = fmaxf(20.0f, fabsf(fTemp10));
			float fTemp12 = dsp->fRec4[1] + dsp->fConst5 * fTemp11;
			dsp->fRec4[0] = fTemp12 - floorf(fTemp12);
			float fTemp13 = mydsp_faustpower2_f(2.0f * dsp->fRec4[0] + -1.0f);
			float fTemp14 = fTemp13 * (fTemp13 + -2.0f);
			dsp->fVec3[0] = fTemp14;
			float fTemp15 = (fTemp14 - dsp->fVec3[1]) / fTemp11;
			dsp->fVec4[0] = fTemp15;
			float fTemp16 = (fTemp15 - dsp->fVec4[1]) / fTemp11;
			dsp->fVec5[0] = fTemp16;
			float fTemp17 = (fTemp16 - dsp->fVec5[1]) / fTemp11;
			dsp->fRec17[0] = fSlow15 + dsp->fConst4 * dsp->fRec17[1];
			float fTemp18 = fmaxf(20.0f, fabsf(dsp->fRec17[0] * fTemp10));
			float fTemp19 = dsp->fRec16[1] + dsp->fConst5 * fTemp18;
			dsp->fRec16[0] = fTemp19 - floorf(fTemp19);
			float fTemp20 = mydsp_faustpower2_f(2.0f * dsp->fRec16[0] + -1.0f);
			float fTemp21 = fTemp20 * (fTemp20 + -2.0f);
			dsp->fVec6[0] = fTemp21;
			float fTemp22 = (fTemp21 - dsp->fVec6[1]) / fTemp18;
			dsp->fVec7[0] = fTemp22;
			float fTemp23 = (fTemp22 - dsp->fVec7[1]) / fTemp18;
			dsp->fVec8[0] = fTemp23;
			float fTemp24 = (fTemp23 - dsp->fVec8[1]) / fTemp18;
			dsp->fRec19[0] = fSlow16 + dsp->fConst4 * dsp->fRec19[1];
			float fTemp25 = fmaxf(20.0f, fabsf(dsp->fRec19[0] * fTemp10));
			float fTemp26 = dsp->fRec18[1] + dsp->fConst5 * fTemp25;
			dsp->fRec18[0] = fTemp26 - floorf(fTemp26);
			float fTemp27 = mydsp_faustpower2_f(2.0f * dsp->fRec18[0] + -1.0f);
			float fTemp28 = fTemp27 * (fTemp27 + -2.0f);
			dsp->fVec9[0] = fTemp28;
			float fTemp29 = (fTemp28 - dsp->fVec9[1]) / fTemp25;
			dsp->fVec10[0] = fTemp29;
			float fTemp30 = (fTemp29 - dsp->fVec10[1]) / fTemp25;
			dsp->fVec11[0] = fTemp30;
			float fTemp31 = (fTemp30 - dsp->fVec11[1]) / fTemp25;
			dsp->fRec20[0] = fSlow18 + dsp->fConst4 * dsp->fRec20[1];
			float fTemp32 = (fTemp5 + fTemp9) - 2.0f * ((iSlow17) ? dsp->fRec20[0] : 1.0f);
			dsp->fRec21[0] = fSlow19 + dsp->fConst4 * dsp->fRec21[1];
			float fTemp33 = fminf(1.41419947f, 1.41421354f * dsp->fRec21[0]);
			float fTemp34 = fTemp33 * (fTemp33 + 1.41421354f);
			dsp->fRec22[0] = fSlow20 + dsp->fConst4 * dsp->fRec22[1];
			dsp->fRec23[0] = fSlow22 + dsp->fConst4 * dsp->fRec23[1];
			dsp->fRec24[0] = fSlow24 + dsp->fConst4 * dsp->fRec24[1];
			float fTemp35 = tanf(dsp->fConst10 * fmaxf(20.0f, fminf(10000.0f, dsp->fRec22[0] + ((iSlow21) ? dsp->fRec23[0] : 1.0f) * fTemp5 + ((iSlow23) ? dsp->fRec24[0] : 1.0f) * fTemp9)));
			float fTemp36 = 1.0f / fTemp35;
			float fTemp37 = 1.41421354f * fTemp33;
			float fTemp38 = fTemp37 + 2.0f;
			float fTemp39 = fTemp34 + (fTemp36 - fTemp38) / fTemp35 + 1.0f;
			float fTemp40 = 1.0f - 1.0f / mydsp_faustpower2_f(fTemp35);
			float fTemp41 = fTemp34 + fTemp40;
			float fTemp42 = fTemp34 + (fTemp36 + fTemp38) / fTemp35 + 1.0f;
			dsp->fRec1[0] = dsp->fConst2 * fTemp0 * (0.00520833349f * fTemp17 + 0.00156250002f * fTemp24 + 0.00520833349f * fTemp31) * fTemp32 - (dsp->fRec1[2] * fTemp39 + 2.0f * dsp->fRec1[1] * fTemp41) / fTemp42;
			float fTemp43 = fTemp33 * (fTemp33 + -1.41421354f);
			float fTemp44 = 2.0f - fTemp37;
			float fTemp45 = fTemp43 + (fTemp36 - fTemp44) / fTemp35 + 1.0f;
			float fTemp46 = fTemp43 + fTemp40;
			float fTemp47 = fTemp43 + (fTemp44 + fTemp36) / fTemp35 + 1.0f;
			dsp->fRec0[0] = (dsp->fRec1[2] + dsp->fRec1[0] + 2.0f * dsp->fRec1[1]) / fTemp42 - (dsp->fRec0[2] * fTemp45 + 2.0f * dsp->fRec0[1] * fTemp46) / fTemp47;
			output0[i0] = (FAUSTFLOAT)((dsp->fRec0[2] + dsp->fRec0[0] + 2.0f * dsp->fRec0[1]) / fTemp47);
			dsp->fRec26[0] = dsp->fConst11 * fTemp0 * fTemp32 * (fTemp31 + fTemp17 + fTemp24) - (fTemp39 * dsp->fRec26[2] + 2.0f * fTemp41 * dsp->fRec26[1]) / fTemp42;
			dsp->fRec25[0] = (dsp->fRec26[2] + dsp->fRec26[0] + 2.0f * dsp->fRec26[1]) / fTemp42 - (fTemp45 * dsp->fRec25[2] + 2.0f * fTemp46 * dsp->fRec25[1]) / fTemp47;
			output1[i0] = (FAUSTFLOAT)((dsp->fRec25[2] + dsp->fRec25[0] + 2.0f * dsp->fRec25[1]) / fTemp47);
			/* C99 loop */
			{
				int j0;
				for (j0 = 3; j0 > 0; j0 = j0 - 1) {
					dsp->iVec0[j0] = dsp->iVec0[j0 - 1];
				}
			}
			dsp->fRec2[1] = dsp->fRec2[0];
			dsp->fRec3[1] = dsp->fRec3[0];
			dsp->fRec6[1] = dsp->fRec6[0];
			dsp->fRec5[1] = dsp->fRec5[0];
			dsp->fRec7[1] = dsp->fRec7[0];
			dsp->fRec8[1] = dsp->fRec8[0];
			dsp->fRec11[1] = dsp->fRec11[0];
			dsp->iRec10[1] = dsp->iRec10[0];
			dsp->iVec1[1] = dsp->iVec1[0];
			dsp->iRec9[1] = dsp->iRec9[0];
			dsp->fRec12[1] = dsp->fRec12[0];
			dsp->fRec13[1] = dsp->fRec13[0];
			dsp->iRec15[1] = dsp->iRec15[0];
			dsp->iVec2[1] = dsp->iVec2[0];
			dsp->iRec14[1] = dsp->iRec14[0];
			dsp->fRec4[1] = dsp->fRec4[0];
			dsp->fVec3[1] = dsp->fVec3[0];
			dsp->fVec4[1] = dsp->fVec4[0];
			dsp->fVec5[1] = dsp->fVec5[0];
			dsp->fRec17[1] = dsp->fRec17[0];
			dsp->fRec16[1] = dsp->fRec16[0];
			dsp->fVec6[1] = dsp->fVec6[0];
			dsp->fVec7[1] = dsp->fVec7[0];
			dsp->fVec8[1] = dsp->fVec8[0];
			dsp->fRec19[1] = dsp->fRec19[0];
			dsp->fRec18[1] = dsp->fRec18[0];
			dsp->fVec9[1] = dsp->fVec9[0];
			dsp->fVec10[1] = dsp->fVec10[0];
			dsp->fVec11[1] = dsp->fVec11[0];
			dsp->fRec20[1] = dsp->fRec20[0];
			dsp->fRec21[1] = dsp->fRec21[0];
			dsp->fRec22[1] = dsp->fRec22[0];
			dsp->fRec23[1] = dsp->fRec23[0];
			dsp->fRec24[1] = dsp->fRec24[0];
			dsp->fRec1[2] = dsp->fRec1[1];
			dsp->fRec1[1] = dsp->fRec1[0];
			dsp->fRec0[2] = dsp->fRec0[1];
			dsp->fRec0[1] = dsp->fRec0[0];
			dsp->fRec26[2] = dsp->fRec26[1];
			dsp->fRec26[1] = dsp->fRec26[0];
			dsp->fRec25[2] = dsp->fRec25[1];
			dsp->fRec25[1] = dsp->fRec25[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
