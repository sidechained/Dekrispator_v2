float scale_min_max(int val, float min, float max)
{
	float zeroToOne = ((float)val)/127;	
	return ((zeroToOne * (max-min)) + min);
}

void set_fHslider8(int val, float min, float max)
{
	dsp->fHslider8 = scale_min_max(val, min, max);
}

void set_fHslider2(int val, float min, float max)
{
	dsp->fHslider2 = scale_min_max(val, min, max);
}

void set_fHslider17(int val, float min, float max)
{
	dsp->fHslider17 = scale_min_max(val, min, max);
}

void set_fHslider10(int val, float min, float max)
{
	dsp->fHslider10 = scale_min_max(val, min, max);
}

void set_fHslider13(int val, float min, float max)
{
	dsp->fHslider13 = scale_min_max(val, min, max);
}

void set_fHslider15(int val, float min, float max)
{
	dsp->fHslider15 = scale_min_max(val, min, max);
}

void set_fHslider6(int val, float min, float max)
{
	dsp->fHslider6 = scale_min_max(val, min, max);
}

void set_fHslider18(int val, float min, float max)
{
	dsp->fHslider18 = scale_min_max(val, min, max);
}

void set_fHslider20(int val, float min, float max)
{
	dsp->fHslider20 = scale_min_max(val, min, max);
}

void set_fHslider19(int val, float min, float max)
{
	dsp->fHslider19 = scale_min_max(val, min, max);
}

void set_fHslider11(int val, float min, float max)
{
	dsp->fHslider11 = scale_min_max(val, min, max);
}

void set_fHslider0(int val, float min, float max)
{
	dsp->fHslider0 = scale_min_max(val, min, max);
}

void set_fHslider3(int val, float min, float max)
{
	dsp->fHslider3 = scale_min_max(val, min, max);
}

void set_fHslider4(int val, float min, float max)
{
	dsp->fHslider4 = scale_min_max(val, min, max);
}

void set_fHslider22(int val, float min, float max)
{
	dsp->fHslider22 = scale_min_max(val, min, max);
}

void set_fHslider7(int val, float min, float max)
{
	dsp->fHslider7 = scale_min_max(val, min, max);
}

void set_fHslider1(int val, float min, float max)
{
	dsp->fHslider1 = scale_min_max(val, min, max);
}

void set_fHslider21(int val, float min, float max)
{
	dsp->fHslider21 = scale_min_max(val, min, max);
}

void set_fHslider9(int val, float min, float max)
{
	dsp->fHslider9 = scale_min_max(val, min, max);
}

void set_fHslider16(int val, float min, float max)
{
	dsp->fHslider16 = scale_min_max(val, min, max);
}

void set_fHslider12(int val, float min, float max)
{
	dsp->fHslider12 = scale_min_max(val, min, max);
}

void set_fHslider14(int val, float min, float max)
{
	dsp->fHslider14 = scale_min_max(val, min, max);
}

void set_fHslider5(int val, float min, float max)
{
	dsp->fHslider5 = scale_min_max(val, min, max);
}

