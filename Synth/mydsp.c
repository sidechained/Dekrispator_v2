/* ------------------------------------------------------------
name: "mydsp", "FaustDSP"
version: "2.52.3"
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
	int iVec0[4];
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	float fRec1[2];
	FAUSTFLOAT fHslider3;
	float fRec2[2];
	float fConst3;
	FAUSTFLOAT fHslider4;
	int iRec4[2];
	int iVec1[2];
	int iRec3[2];
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	float fRec5[2];
	FAUSTFLOAT fHslider7;
	FAUSTFLOAT fHslider8;
	float fRec6[2];
	int iRec8[2];
	int iVec2[2];
	int iRec7[2];
	FAUSTFLOAT fHslider9;
	FAUSTFLOAT fHslider10;
	float fRec9[2];
	FAUSTFLOAT fHslider11;
	float fRec10[2];
	float fConst4;
	FAUSTFLOAT fHslider12;
	FAUSTFLOAT fHslider13;
	float fRec13[2];
	FAUSTFLOAT fHslider14;
	FAUSTFLOAT fHslider15;
	float fRec14[2];
	FAUSTFLOAT fHslider16;
	FAUSTFLOAT fHslider17;
	float fRec15[2];
	float fConst5;
	FAUSTFLOAT fHslider18;
	float fConst6;
	float fRec17[2];
	float fConst7;
	float fRec16[2];
	FAUSTFLOAT fHslider19;
	float fRec18[2];
	float fConst8;
	float fRec19[2];
	float fVec3[2];
	float fVec4[2];
	float fVec5[2];
	FAUSTFLOAT fHslider20;
	float fRec20[2];
	float fRec21[2];
	float fVec6[2];
	float fVec7[2];
	float fVec8[2];
	float fRec22[2];
	float fVec9[2];
	float fVec10[2];
	float fVec11[2];
	FAUSTFLOAT fHslider21;
	float fRec23[2];
	FAUSTFLOAT fHslider22;
	float fRec24[2];
	float fConst10;
	float fRec12[3];
	float fRec11[3];
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
	m->declare(m->metaInterface, "options", "[midi:on]");
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
	m->declare(m->metaInterface, "version", "2.52.3");
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
	dsp->fHslider2 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider3 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider4 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider5 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider6 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider7 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider8 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider9 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider10 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider11 = (FAUSTFLOAT)(3e+03f);
	dsp->fHslider12 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider13 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider14 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider15 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider16 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider17 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider18 = (FAUSTFLOAT)(49.0f);
	dsp->fHslider19 = (FAUSTFLOAT)(0.1f);
	dsp->fHslider20 = (FAUSTFLOAT)(-0.1f);
	dsp->fHslider21 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider22 = (FAUSTFLOAT)(-6.0f);
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
			dsp->fRec0[l1] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l2;
		for (l2 = 0; l2 < 2; l2 = l2 + 1) {
			dsp->fRec1[l2] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l3;
		for (l3 = 0; l3 < 2; l3 = l3 + 1) {
			dsp->fRec2[l3] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l4;
		for (l4 = 0; l4 < 2; l4 = l4 + 1) {
			dsp->iRec4[l4] = 0;
		}
	}
	/* C99 loop */
	{
		int l5;
		for (l5 = 0; l5 < 2; l5 = l5 + 1) {
			dsp->iVec1[l5] = 0;
		}
	}
	/* C99 loop */
	{
		int l6;
		for (l6 = 0; l6 < 2; l6 = l6 + 1) {
			dsp->iRec3[l6] = 0;
		}
	}
	/* C99 loop */
	{
		int l7;
		for (l7 = 0; l7 < 2; l7 = l7 + 1) {
			dsp->fRec5[l7] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l8;
		for (l8 = 0; l8 < 2; l8 = l8 + 1) {
			dsp->fRec6[l8] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l9;
		for (l9 = 0; l9 < 2; l9 = l9 + 1) {
			dsp->iRec8[l9] = 0;
		}
	}
	/* C99 loop */
	{
		int l10;
		for (l10 = 0; l10 < 2; l10 = l10 + 1) {
			dsp->iVec2[l10] = 0;
		}
	}
	/* C99 loop */
	{
		int l11;
		for (l11 = 0; l11 < 2; l11 = l11 + 1) {
			dsp->iRec7[l11] = 0;
		}
	}
	/* C99 loop */
	{
		int l12;
		for (l12 = 0; l12 < 2; l12 = l12 + 1) {
			dsp->fRec9[l12] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l13;
		for (l13 = 0; l13 < 2; l13 = l13 + 1) {
			dsp->fRec10[l13] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l14;
		for (l14 = 0; l14 < 2; l14 = l14 + 1) {
			dsp->fRec13[l14] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l15;
		for (l15 = 0; l15 < 2; l15 = l15 + 1) {
			dsp->fRec14[l15] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l16;
		for (l16 = 0; l16 < 2; l16 = l16 + 1) {
			dsp->fRec15[l16] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l17;
		for (l17 = 0; l17 < 2; l17 = l17 + 1) {
			dsp->fRec17[l17] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l18;
		for (l18 = 0; l18 < 2; l18 = l18 + 1) {
			dsp->fRec16[l18] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l19;
		for (l19 = 0; l19 < 2; l19 = l19 + 1) {
			dsp->fRec18[l19] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l20;
		for (l20 = 0; l20 < 2; l20 = l20 + 1) {
			dsp->fRec19[l20] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l21;
		for (l21 = 0; l21 < 2; l21 = l21 + 1) {
			dsp->fVec3[l21] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l22;
		for (l22 = 0; l22 < 2; l22 = l22 + 1) {
			dsp->fVec4[l22] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l23;
		for (l23 = 0; l23 < 2; l23 = l23 + 1) {
			dsp->fVec5[l23] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l24;
		for (l24 = 0; l24 < 2; l24 = l24 + 1) {
			dsp->fRec20[l24] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l25;
		for (l25 = 0; l25 < 2; l25 = l25 + 1) {
			dsp->fRec21[l25] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l26;
		for (l26 = 0; l26 < 2; l26 = l26 + 1) {
			dsp->fVec6[l26] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l27;
		for (l27 = 0; l27 < 2; l27 = l27 + 1) {
			dsp->fVec7[l27] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l28;
		for (l28 = 0; l28 < 2; l28 = l28 + 1) {
			dsp->fVec8[l28] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l29;
		for (l29 = 0; l29 < 2; l29 = l29 + 1) {
			dsp->fRec22[l29] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l30;
		for (l30 = 0; l30 < 2; l30 = l30 + 1) {
			dsp->fVec9[l30] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l31;
		for (l31 = 0; l31 < 2; l31 = l31 + 1) {
			dsp->fVec10[l31] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l32;
		for (l32 = 0; l32 < 2; l32 = l32 + 1) {
			dsp->fVec11[l32] = 0.0f;
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
			dsp->fRec12[l35] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l36;
		for (l36 = 0; l36 < 3; l36 = l36 + 1) {
			dsp->fRec11[l36] = 0.0f;
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
	dsp->fConst0 = fminf(1.92e+05f, fmaxf(1.0f, (float)(dsp->fSampleRate)));
	dsp->fConst1 = 44.1f / dsp->fConst0;
	dsp->fConst2 = 1.0f - dsp->fConst1;
	dsp->fConst3 = 0.5f * dsp->fConst0;
	dsp->fConst4 = 3.1415927f / dsp->fConst0;
	dsp->fConst5 = expf(0.0f - 1e+01f / dsp->fConst0);
	dsp->fConst6 = 19404.0f / dsp->fConst0;
	dsp->fConst7 = 1.0f - dsp->fConst5;
	dsp->fConst8 = 1.0f / dsp->fConst0;
	float fConst9 = mydsp_faustpower3_f(dsp->fConst0);
	dsp->fConst10 = 0.16666667f * fConst9;
	dsp->fConst11 = 0.00026041668f * fConst9;
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
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider18, "00", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider18, "midi", "ctrl 16 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider18, "unit", "PK");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Knob1:Oscillator Frequency", &dsp->fHslider18, (FAUSTFLOAT)49.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)88.0f, (FAUSTFLOAT)0.01f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider20, "01", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider20, "midi", "ctrl 17 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider20, "unit", "%%");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Knob2:Detune 1", &dsp->fHslider20, (FAUSTFLOAT)-0.1f, (FAUSTFLOAT)-1e+01f, (FAUSTFLOAT)1e+01f, (FAUSTFLOAT)0.01f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider19, "02", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider19, "midi", "ctrl 18 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider19, "unit", "%%");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Knob3:Detune 2", &dsp->fHslider19, (FAUSTFLOAT)0.1f, (FAUSTFLOAT)-1e+01f, (FAUSTFLOAT)1e+01f, (FAUSTFLOAT)0.01f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider11, "03", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider11, "midi", "ctrl 19 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider11, "unit", "Hz");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Knob4:Filter Frequency", &dsp->fHslider11, (FAUSTFLOAT)3e+03f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.5e+04f, (FAUSTFLOAT)1e+01f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "04", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "midi", "ctrl 20 1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Knob5:Filter Resonance", &dsp->fHslider0, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "05", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "midi", "ctrl 21 1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Knob6:Autoenv Attack Time", &dsp->fHslider3, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider4, "06", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider4, "midi", "ctrl 22 1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Knob7:Autoenv Release Time", &dsp->fHslider4, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.1f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider22, "07", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider22, "midi", "ctrl 23 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider22, "unit", "dB");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Knob8:Master Volume", &dsp->fHslider22, (FAUSTFLOAT)-6.0f, (FAUSTFLOAT)-1.2e+02f, (FAUSTFLOAT)1e+01f, (FAUSTFLOAT)0.1f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider8, "08", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider8, "midi", "ctrl 0 1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Fader1:Env 1 Level", &dsp->fHslider8, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider2, "09", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider2, "midi", "ctrl 1 1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Fader1:Env 2 Level", &dsp->fHslider2, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.01f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider17, "11", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider17, "midi", "ctrl 3 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider17, "unit", "Hz");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Fader1:Pitch Env1 Depth", &dsp->fHslider17, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)5e+02f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider10, "12", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider10, "midi", "ctrl 4 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider10, "unit", "Hz");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Fader1:Filter Env1 Depth", &dsp->fHslider10, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1e+04f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider13, "13", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider13, "midi", "ctrl 5 1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Fader1:Amplitude Env2 Depth", &dsp->fHslider13, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider15, "14", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider15, "midi", "ctrl 6 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider15, "unit", "Hz");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Fader1:Pitch Env2 Depth", &dsp->fHslider15, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)5e+02f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider6, "15", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider6, "midi", "ctrl 7 1");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider6, "unit", "Hz");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Fader1:Filter Env2 Depth", &dsp->fHslider6, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1e+04f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider16, "17", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider16, "midi", "ctrl 59 1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Track > Button:Env1 > Pitch", &dsp->fHslider16, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider9, "18", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider9, "midi", "ctrl 46 1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Cycle Button:Env1 > Filter", &dsp->fHslider9, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider12, "19", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider12, "midi", "ctrl 60 1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Set Marker Button:Env2 > Amp", &dsp->fHslider12, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider14, "20", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider14, "midi", "ctrl 61 1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Marker < Button:Env2 > Pitch", &dsp->fHslider14, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider5, "21", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider5, "midi", "ctrl 62 1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Marker > Button:Env2 > Filter", &dsp->fHslider5, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider7, "22", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider7, "midi", "ctrl 43 1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Rewind Button: Auto Env 1 On", &dsp->fHslider7, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "23", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "midi", "ctrl 44 1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Fast-Forward Button:Auto Env 2 On", &dsp->fHslider1, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider21, "24", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider21, "midi", "ctrl 45 1");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Record Button: Mute Output", &dsp->fHslider21, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)1.0f);
	ui_interface->closeBox(ui_interface->uiInterface);
}

void computemydsp(mydsp* dsp, int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
	FAUSTFLOAT* output0 = outputs[0];
	FAUSTFLOAT* output1 = outputs[1];
	float fSlow0 = dsp->fConst1 * (float)(dsp->fHslider0);
	int iSlow1 = (float)(dsp->fHslider1) >= 1.0f;
	float fSlow2 = dsp->fConst1 * (float)(dsp->fHslider2);
	float fSlow3 = dsp->fConst1 * (float)(dsp->fHslider3);
	float fSlow4 = (float)(dsp->fHslider4);
	float fSlow5 = 1.0f / fmaxf(1.0f, dsp->fConst3 * fSlow4);
	int iSlow6 = (float)(dsp->fHslider5) >= 1.0f;
	float fSlow7 = dsp->fConst1 * (float)(dsp->fHslider6);
	int iSlow8 = (float)(dsp->fHslider7) >= 1.0f;
	float fSlow9 = dsp->fConst1 * (float)(dsp->fHslider8);
	float fSlow10 = 1.0f / fmaxf(1.0f, dsp->fConst0 * fSlow4);
	int iSlow11 = (float)(dsp->fHslider9) >= 1.0f;
	float fSlow12 = dsp->fConst1 * (float)(dsp->fHslider10);
	float fSlow13 = dsp->fConst1 * (float)(dsp->fHslider11);
	int iSlow14 = (float)(dsp->fHslider12) >= 1.0f;
	float fSlow15 = dsp->fConst1 * (float)(dsp->fHslider13);
	int iSlow16 = (float)(dsp->fHslider14) >= 1.0f;
	float fSlow17 = dsp->fConst1 * (float)(dsp->fHslider15);
	int iSlow18 = (float)(dsp->fHslider16) >= 1.0f;
	float fSlow19 = dsp->fConst1 * (float)(dsp->fHslider17);
	float fSlow20 = dsp->fConst6 * powf(2.0f, 0.083333336f * ((float)(dsp->fHslider18) + -49.0f));
	float fSlow21 = dsp->fConst1 * (0.01f * (float)(dsp->fHslider19) + 1.0f);
	float fSlow22 = dsp->fConst1 * (0.01f * (float)(dsp->fHslider20) + 1.0f);
	float fSlow23 = dsp->fConst1 * (1.0f - (float)(dsp->fHslider21));
	float fSlow24 = dsp->fConst1 * powf(1e+01f, 0.05f * (float)(dsp->fHslider22));
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			dsp->iVec0[0] = 1;
			dsp->fRec0[0] = fSlow0 + dsp->fConst2 * dsp->fRec0[1];
			float fTemp0 = fminf(1.4141995f, 1.4142135f * dsp->fRec0[0]);
			float fTemp1 = 1.4142135f * fTemp0;
			float fTemp2 = 1.0f - fTemp1;
			dsp->fRec1[0] = fSlow2 + dsp->fConst2 * dsp->fRec1[1];
			dsp->fRec2[0] = fSlow3 + dsp->fConst2 * dsp->fRec2[1];
			float fTemp3 = fmaxf(1.0f, dsp->fConst3 * dsp->fRec2[0]);
			float fTemp4 = fSlow4 + dsp->fRec2[0];
			dsp->iRec4[0] = (dsp->iVec0[1] + dsp->iRec4[1]) % (int)(dsp->fConst3 * fTemp4);
			int iTemp5 = dsp->iRec4[0] <= dsp->iRec4[1];
			dsp->iVec1[0] = iTemp5;
			dsp->iRec3[0] = (dsp->iRec3[1] + (dsp->iRec3[1] > 0)) * (iTemp5 <= dsp->iVec1[1]) + (iTemp5 > dsp->iVec1[1]);
			float fTemp6 = (float)(dsp->iRec3[0]);
			float fElse0 = fmaxf(0.0f, fminf(fTemp6 / fTemp3, fSlow5 * (fTemp3 - fTemp6) + 1.0f));
			float fTemp7 = ((iSlow1) ? fElse0 : dsp->fRec1[0]);
			dsp->fRec5[0] = fSlow7 + dsp->fConst2 * dsp->fRec5[1];
			dsp->fRec6[0] = fSlow9 + dsp->fConst2 * dsp->fRec6[1];
			float fTemp8 = fmaxf(1.0f, dsp->fConst0 * dsp->fRec2[0]);
			dsp->iRec8[0] = (dsp->iVec0[1] + dsp->iRec8[1]) % (int)(dsp->fConst0 * fTemp4);
			int iTemp9 = dsp->iRec8[0] <= dsp->iRec8[1];
			dsp->iVec2[0] = iTemp9;
			dsp->iRec7[0] = (dsp->iRec7[1] + (dsp->iRec7[1] > 0)) * (iTemp9 <= dsp->iVec2[1]) + (iTemp9 > dsp->iVec2[1]);
			float fTemp10 = (float)(dsp->iRec7[0]);
			float fElse2 = fmaxf(0.0f, fminf(fTemp10 / fTemp8, fSlow10 * (fTemp8 - fTemp10) + 1.0f));
			float fTemp11 = ((iSlow8) ? fElse2 : dsp->fRec6[0]);
			dsp->fRec9[0] = fSlow12 + dsp->fConst2 * dsp->fRec9[1];
			dsp->fRec10[0] = fSlow13 + dsp->fConst2 * dsp->fRec10[1];
			float fTemp12 = tanf(dsp->fConst4 * fmaxf(2e+01f, fminf(1e+04f, dsp->fRec10[0] + ((iSlow11) ? dsp->fRec9[0] : 1.0f) * fTemp11 + ((iSlow6) ? dsp->fRec5[0] : 1.0f) * fTemp7)));
			float fTemp13 = 1.0f / fTemp12;
			float fTemp14 = 2.0f - fTemp1;
			float fTemp15 = mydsp_faustpower2_f(fTemp0);
			float fTemp16 = fTemp15 + (fTemp14 + fTemp13) / fTemp12 + fTemp2;
			float fTemp17 = 1.0f / mydsp_faustpower2_f(fTemp12);
			float fTemp18 = fTemp15 + (1.0f - (fTemp1 + fTemp17));
			float fTemp19 = fTemp15 + (fTemp13 - fTemp14) / fTemp12 + fTemp2;
			float fTemp20 = fTemp1 + 2.0f;
			float fTemp21 = fTemp1 + fTemp15;
			float fTemp22 = fTemp21 + (fTemp13 + fTemp20) / fTemp12 + 1.0f;
			float fTemp23 = fTemp21 + (1.0f - fTemp17);
			float fTemp24 = fTemp21 + (fTemp13 - fTemp20) / fTemp12 + 1.0f;
			dsp->fRec13[0] = fSlow15 + dsp->fConst2 * dsp->fRec13[1];
			float fTemp25 = fTemp11 + fTemp7 - 2.0f * ((iSlow14) ? dsp->fRec13[0] : 1.0f);
			dsp->fRec14[0] = fSlow17 + dsp->fConst2 * dsp->fRec14[1];
			dsp->fRec15[0] = fSlow19 + dsp->fConst2 * dsp->fRec15[1];
			dsp->fRec17[0] = fSlow20 + dsp->fConst2 * dsp->fRec17[1];
			dsp->fRec16[0] = dsp->fConst7 * dsp->fRec17[0] + dsp->fConst5 * dsp->fRec16[1];
			float fTemp26 = dsp->fRec16[0] + ((iSlow18) ? dsp->fRec15[0] : 1.0f) * fTemp11 + ((iSlow16) ? dsp->fRec14[0] : 1.0f) * fTemp7;
			dsp->fRec18[0] = fSlow21 + dsp->fConst2 * dsp->fRec18[1];
			float fTemp27 = fmaxf(2e+01f, fabsf(dsp->fRec18[0] * fTemp26));
			float fTemp28 = dsp->fRec19[1] + dsp->fConst8 * fTemp27;
			dsp->fRec19[0] = fTemp28 - floorf(fTemp28);
			float fTemp29 = mydsp_faustpower2_f(2.0f * dsp->fRec19[0] + -1.0f);
			float fTemp30 = fTemp29 * (fTemp29 + -2.0f);
			dsp->fVec3[0] = fTemp30;
			float fTemp31 = (fTemp30 - dsp->fVec3[1]) / fTemp27;
			dsp->fVec4[0] = fTemp31;
			float fTemp32 = (fTemp31 - dsp->fVec4[1]) / fTemp27;
			dsp->fVec5[0] = fTemp32;
			float fTemp33 = (fTemp32 - dsp->fVec5[1]) / fTemp27;
			dsp->fRec20[0] = fSlow22 + dsp->fConst2 * dsp->fRec20[1];
			float fTemp34 = fmaxf(2e+01f, fabsf(dsp->fRec20[0] * fTemp26));
			float fTemp35 = dsp->fRec21[1] + dsp->fConst8 * fTemp34;
			dsp->fRec21[0] = fTemp35 - floorf(fTemp35);
			float fTemp36 = mydsp_faustpower2_f(2.0f * dsp->fRec21[0] + -1.0f);
			float fTemp37 = fTemp36 * (fTemp36 + -2.0f);
			dsp->fVec6[0] = fTemp37;
			float fTemp38 = (fTemp37 - dsp->fVec6[1]) / fTemp34;
			dsp->fVec7[0] = fTemp38;
			float fTemp39 = (fTemp38 - dsp->fVec7[1]) / fTemp34;
			dsp->fVec8[0] = fTemp39;
			float fTemp40 = (fTemp39 - dsp->fVec8[1]) / fTemp34;
			float fTemp41 = fmaxf(2e+01f, fabsf(fTemp26));
			float fTemp42 = dsp->fRec22[1] + dsp->fConst8 * fTemp41;
			dsp->fRec22[0] = fTemp42 - floorf(fTemp42);
			float fTemp43 = mydsp_faustpower2_f(2.0f * dsp->fRec22[0] + -1.0f);
			float fTemp44 = fTemp43 * (fTemp43 + -2.0f);
			dsp->fVec9[0] = fTemp44;
			float fTemp45 = (fTemp44 - dsp->fVec9[1]) / fTemp41;
			dsp->fVec10[0] = fTemp45;
			float fTemp46 = (fTemp45 - dsp->fVec10[1]) / fTemp41;
			dsp->fVec11[0] = fTemp46;
			float fTemp47 = (fTemp46 - dsp->fVec11[1]) / fTemp41;
			dsp->fRec23[0] = fSlow23 + dsp->fConst2 * dsp->fRec23[1];
			dsp->fRec24[0] = fSlow24 + dsp->fConst2 * dsp->fRec24[1];
			float fTemp48 = mydsp_faustpower2_f(dsp->fRec24[0]) * dsp->fRec23[0] * (float)(dsp->iVec0[3]);
			dsp->fRec12[0] = dsp->fConst10 * fTemp48 * (0.0052083335f * fTemp47 + 0.0015625f * fTemp40 + 0.0052083335f * fTemp33) * fTemp25 - (dsp->fRec12[2] * fTemp24 + 2.0f * dsp->fRec12[1] * fTemp23) / fTemp22;
			dsp->fRec11[0] = (dsp->fRec12[2] + dsp->fRec12[0] + 2.0f * dsp->fRec12[1]) / fTemp22 - (dsp->fRec11[2] * fTemp19 + 2.0f * dsp->fRec11[1] * fTemp18) / fTemp16;
			output0[i0] = (FAUSTFLOAT)((dsp->fRec11[2] + dsp->fRec11[0] + 2.0f * dsp->fRec11[1]) / fTemp16);
			dsp->fRec26[0] = dsp->fConst11 * fTemp48 * fTemp25 * (fTemp33 + fTemp47 + fTemp40) - (fTemp24 * dsp->fRec26[2] + 2.0f * fTemp23 * dsp->fRec26[1]) / fTemp22;
			dsp->fRec25[0] = (dsp->fRec26[2] + dsp->fRec26[0] + 2.0f * dsp->fRec26[1]) / fTemp22 - (fTemp19 * dsp->fRec25[2] + 2.0f * fTemp18 * dsp->fRec25[1]) / fTemp16;
			output1[i0] = (FAUSTFLOAT)((dsp->fRec25[2] + dsp->fRec25[0] + 2.0f * dsp->fRec25[1]) / fTemp16);
			/* C99 loop */
			{
				int j0;
				for (j0 = 3; j0 > 0; j0 = j0 - 1) {
					dsp->iVec0[j0] = dsp->iVec0[j0 - 1];
				}
			}
			dsp->fRec0[1] = dsp->fRec0[0];
			dsp->fRec1[1] = dsp->fRec1[0];
			dsp->fRec2[1] = dsp->fRec2[0];
			dsp->iRec4[1] = dsp->iRec4[0];
			dsp->iVec1[1] = dsp->iVec1[0];
			dsp->iRec3[1] = dsp->iRec3[0];
			dsp->fRec5[1] = dsp->fRec5[0];
			dsp->fRec6[1] = dsp->fRec6[0];
			dsp->iRec8[1] = dsp->iRec8[0];
			dsp->iVec2[1] = dsp->iVec2[0];
			dsp->iRec7[1] = dsp->iRec7[0];
			dsp->fRec9[1] = dsp->fRec9[0];
			dsp->fRec10[1] = dsp->fRec10[0];
			dsp->fRec13[1] = dsp->fRec13[0];
			dsp->fRec14[1] = dsp->fRec14[0];
			dsp->fRec15[1] = dsp->fRec15[0];
			dsp->fRec17[1] = dsp->fRec17[0];
			dsp->fRec16[1] = dsp->fRec16[0];
			dsp->fRec18[1] = dsp->fRec18[0];
			dsp->fRec19[1] = dsp->fRec19[0];
			dsp->fVec3[1] = dsp->fVec3[0];
			dsp->fVec4[1] = dsp->fVec4[0];
			dsp->fVec5[1] = dsp->fVec5[0];
			dsp->fRec20[1] = dsp->fRec20[0];
			dsp->fRec21[1] = dsp->fRec21[0];
			dsp->fVec6[1] = dsp->fVec6[0];
			dsp->fVec7[1] = dsp->fVec7[0];
			dsp->fVec8[1] = dsp->fVec8[0];
			dsp->fRec22[1] = dsp->fRec22[0];
			dsp->fVec9[1] = dsp->fVec9[0];
			dsp->fVec10[1] = dsp->fVec10[0];
			dsp->fVec11[1] = dsp->fVec11[0];
			dsp->fRec23[1] = dsp->fRec23[0];
			dsp->fRec24[1] = dsp->fRec24[0];
			dsp->fRec12[2] = dsp->fRec12[1];
			dsp->fRec12[1] = dsp->fRec12[0];
			dsp->fRec11[2] = dsp->fRec11[1];
			dsp->fRec11[1] = dsp->fRec11[0];
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
