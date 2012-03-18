#include "MUGED_Tests.h"
#include "MUGED_DSP.h"

/**
 * DSP test - testing DSP library. Compares calculated values to
 * the results obtained from GNU Octave
 */
void _dsp_test_()
{
	ASSERTM("Test shouldn't fails", true);

	const double precision = 0.0001;

	MUGED_DSP dsp;
	muged_array signal1;
	signal1.length = 5;
	signal1.array = new muged_scalar[signal1.length];

	for (unsigned int i = 0; i < signal1.length; i++)
	{
		muged_scalar scalar = muged_scalar(i,2*i);
		signal1.array[i] = scalar;
	}

	muged_array signal2;
	signal2.length = 5;
	signal2.array = new muged_scalar[signal2.length];

	for (unsigned int i = 0; i < signal2.length; i++)
	{
		muged_scalar scalar = muged_scalar(i+1,0);
		signal2.array[i] = scalar;
	}

	muged_scalar mean = dsp.muged_mean(signal1);

	ASSERT_EQUAL_DELTA(2, mean.muged_real(), precision);
	ASSERT_EQUAL_DELTA(4, mean.muged_imag(), precision);

	muged_scalar mean_square = dsp.muged_mean_square(signal1);

	ASSERT_EQUAL_DELTA(-18, mean_square.muged_real(), precision);
	ASSERT_EQUAL_DELTA(24, mean_square.muged_imag(), precision);

	muged_scalar root_mean_square = dsp.muged_root_mean_square(signal1);

	ASSERT_EQUAL_DELTA(5.4772, root_mean_square.muged_real(), precision);
	ASSERT_EQUAL_DELTA(0, root_mean_square.muged_imag(), precision);

	muged_scalar std_real = dsp.muged_standard_deviation(signal2);

	ASSERT_EQUAL_DELTA(1.4142, std_real.muged_real(), precision);
	ASSERT_EQUAL_DELTA(0, std_real.muged_imag(), precision);

	muged_scalar std = dsp.muged_standard_deviation(signal1);

	ASSERT_EQUAL_DELTA(1.4142, std.muged_real(), precision);
	ASSERT_EQUAL_DELTA(2.8284, std.muged_imag(), precision);

	muged_array ref_correlation;
	ref_correlation.length = 21;
	ref_correlation.array = new muged_scalar[ref_correlation.length];

	ref_correlation.array[0] = muged_scalar(3,3.5527e-15);
	ref_correlation.array[1] = muged_scalar(2,6);
	ref_correlation.array[2] = muged_scalar(9,1.1e1);
	ref_correlation.array[3] = muged_scalar(8,2);
	ref_correlation.array[4] = muged_scalar(-7.4654e-15, 1.0000e1);
	ref_correlation.array[5] = muged_scalar(-8, 1.4e1);
	ref_correlation.array[6] = muged_scalar(-1.5e1, -1.3e1);
	ref_correlation.array[7] = muged_scalar(1.8e1, -1.4e1);
	ref_correlation.array[8] = muged_scalar(6.6e1, -3.1086e-15);
	ref_correlation.array[9] = muged_scalar(1.8e1, 1.4e1);
	ref_correlation.array[10]= muged_scalar(-1.5e1, 1.3e1);
	ref_correlation.array[11]= muged_scalar(-8,-1.4e1);
	ref_correlation.array[12]= muged_scalar(1.2794e-14, -1e1);
	ref_correlation.array[13]= muged_scalar(8,-2);
	ref_correlation.array[14]= muged_scalar(9,-1.1e1);
	ref_correlation.array[15]= muged_scalar(2,-6);
	ref_correlation.array[16]= muged_scalar(3, 3.5527e-15);
	ref_correlation.array[17]= muged_scalar(-5.7732e-15, -4.4409e-16);
	ref_correlation.array[18]= muged_scalar(-7.6605e-15, -1.2768e-15);
	ref_correlation.array[19]= muged_scalar(-1.5773e-15, -7.5495e-15);
	ref_correlation.array[20]= muged_scalar(5.2820e-16, -1.7764e-15);

	muged_array signal3;
	signal3.length = 9;
	signal3.array = new muged_scalar[signal3.length];
	signal3.array[0] = muged_scalar(1,0);
	signal3.array[1] = muged_scalar(0,2);
	signal3.array[2] = muged_scalar(3,1);
	signal3.array[3] = muged_scalar(4,0);
	signal3.array[4] = muged_scalar(-1,1);
	signal3.array[5] = muged_scalar(-2,0);
	signal3.array[6] = muged_scalar(0,-4);
	signal3.array[7] = muged_scalar(2, 0);
	signal3.array[8] = muged_scalar(3, 0);

	muged_array signal4;
	signal4.length = 11;
	signal4.array = new muged_scalar[signal4.length];
	signal4.array[0] = muged_scalar(0,0);
	signal4.array[1] = muged_scalar(0,0);
	signal4.array[2] = muged_scalar(1,0);
	signal4.array[3] = muged_scalar(0,2);
	signal4.array[4] = muged_scalar(3,1);
	signal4.array[5] = muged_scalar(4,0);
	signal4.array[6] = muged_scalar(-1,1);
	signal4.array[7] = muged_scalar(-2,0);
	signal4.array[8] = muged_scalar(0,-4);
	signal4.array[9] = muged_scalar(2, 0);
	signal4.array[10] = muged_scalar(3, 0);

	muged_array correlation;
  dsp.muged_1D_correlation(signal3, signal4, 0, signal4.length-1, correlation);

  for (unsigned int i = 0; i < correlation.length; i++)
  {
  	ASSERT_EQUAL_DELTA(ref_correlation.array[i].muged_real(), correlation.array[i].muged_real(), precision);
  	ASSERT_EQUAL_DELTA(ref_correlation.array[i].muged_imag(), correlation.array[i].muged_imag(), precision);
  }

  muged_array correlation_part_1;
  dsp.muged_1D_correlation(signal3, signal4, 0, 3, correlation_part_1);

  for (unsigned int i = 0; i < correlation_part_1.length; i++)
  {
  	ASSERT_EQUAL_DELTA(ref_correlation.array[i + signal4.length -1 - 3].muged_real(), correlation_part_1.array[i].muged_real(), precision);
  	ASSERT_EQUAL_DELTA(ref_correlation.array[i + signal4.length -1 - 3].muged_imag(), correlation_part_1.array[i].muged_imag(), precision);
  }

  muged_array correlation_part_2;
  dsp.muged_1D_correlation(signal3, signal4, 3, signal4.length-1, correlation_part_2);

  for (unsigned int i = 0; i < correlation_part_2.length; i++)
  {
  	if ( i >= signal4.length - 1 - 3 && i < correlation_part_1.length + signal4.length - 1 - 3)
  		continue; // In this range correlation part 1 is valid

  	ASSERT_EQUAL_DELTA(ref_correlation.array[i].muged_real(), correlation_part_2.array[i].muged_real(), precision);
  	ASSERT_EQUAL_DELTA(ref_correlation.array[i].muged_imag(), correlation_part_2.array[i].muged_imag(), precision);
  }

  //Merge correlation
  muged_array correlation_merged;
  correlation_merged.array = new muged_scalar[ref_correlation.length];
  correlation_merged.length = ref_correlation.length;
  for (unsigned int i = 0; i < correlation_merged.length; i++)
  {
  	if ( i >= signal4.length - 1 - 3 && i < correlation_part_1.length + signal4.length - 1 - 3)
  		correlation_merged.array[i] = correlation_part_1.array[i - (signal4.length - 1 - 3)];
  	else
  		correlation_merged.array[i] = correlation_part_2.array[i];
  }

	for (unsigned int i = 0; i < correlation_merged.length; i++)
	{
		ASSERT_EQUAL_DELTA(ref_correlation.array[i].muged_real(), correlation_merged.array[i].muged_real(), precision);
		ASSERT_EQUAL_DELTA(ref_correlation.array[i].muged_imag(), correlation_merged.array[i].muged_imag(), precision);
	}


	muged_array signal5;
	signal5.length = 112;
	signal5.array = new muged_scalar[signal5.length];

	//Signal
	for (unsigned int i = 0; i < signal5.length; i++)
		signal5.array[i] = muged_scalar((i+1) % 2, 0);

	muged_array ref_spectrum;
	ref_spectrum.length = 128;
	ref_spectrum.array = new muged_scalar[ref_spectrum.length];

	//Reference spectrum
	for (unsigned int i = 0; i < ref_spectrum.length; i++)
		ref_spectrum.array[i] = muged_scalar(real_fft_128_ref[i], imag_fft_128_ref[i]);

	//Calculate spectrum
	muged_array spectrum;
	dsp.muged_1D_fft(signal5, spectrum);

	//Check
	for (unsigned int i = 0; i < ref_spectrum.length; i++)
	{
		ASSERT_EQUAL_DELTA(ref_spectrum.array[i].muged_real(), spectrum.array[i].muged_real(), precision);
		ASSERT_EQUAL_DELTA(ref_spectrum.array[i].muged_imag(), spectrum.array[i].muged_imag(), precision);
	}

	//Calculate IFFT
	muged_array signal6;
	dsp.muged_1D_ifft(spectrum, signal6);
	for (unsigned int i = 0; i < signal5.length; i++)
	{
		ASSERT_EQUAL_DELTA(signal5.array[i].muged_real(), signal6.array[i].muged_real(), precision);
		ASSERT_EQUAL_DELTA(signal5.array[i].muged_imag(), signal6.array[i].muged_imag(), precision);
	}

	delete [] signal1.array;
	delete [] signal2.array;
	delete [] signal3.array;
	delete [] signal4.array;
	delete [] signal5.array;
	delete [] signal6.array;
	delete [] ref_correlation.array;
	delete [] correlation.array;
	delete [] correlation_part_1.array;
	delete [] correlation_part_2.array;
	delete [] correlation_merged.array;
	delete [] spectrum.array;
	delete [] ref_spectrum.array;

	ASSERTM("Test shouldn't fails", true);
}


