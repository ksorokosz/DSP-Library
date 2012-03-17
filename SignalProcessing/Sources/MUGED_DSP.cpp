#include "MUGED_DSP.h"

MUGED_DSP::MUGED_DSP()
{
}

MUGED_DSP::~MUGED_DSP()
{
}

muged_scalar MUGED_DSP::muged_mean(muged_array& signal)
{
	size_t size = signal.length;
	muged_scalar sum;

	for (size_t i = 0; i < size; i++)
	{
		muged_scalar& current_scalar = signal.array[i];
		sum += current_scalar;
	}

	muged_scalar mean = sum/size;

	return mean;
}

muged_scalar MUGED_DSP::muged_root_mean_square(muged_array& signal)
{
	muged_array local_signal;
	local_signal.array = new muged_scalar[signal.length];
	local_signal.length = signal.length;

	for (unsigned int i = 0; i < signal.length; i++)
	{
		muged_scalar& current_scalar = signal.array[i];
		muged_scalar square_scalar = current_scalar.muged_pow();
		muged_scalar square_abs_scalar = muged_scalar(square_scalar.muged_abs(),0,false);

		local_signal.array[i] = square_abs_scalar;
	}

	muged_scalar mean_square = muged_mean(local_signal);

	delete [] local_signal.array;
	return mean_square.muged_sqrt();
}

muged_scalar MUGED_DSP::muged_mean_square(muged_array& signal)
{
	size_t size = signal.length;
	muged_scalar* array = signal.array;
	muged_scalar square_sum, mean_square;

	for (size_t i = 0; i < size; i++)
	{
		muged_scalar& current_scalar = array[i];
		square_sum += current_scalar.muged_pow();
	}
	mean_square = square_sum/size;

	return mean_square;
}

muged_scalar MUGED_DSP::muged_standard_deviation(muged_array& signal)
{
	muged_scalar mean_square = muged_mean_square(signal);
	muged_scalar mean = muged_mean(signal);

	return ( mean_square - mean.muged_pow() ).muged_sqrt();
}

void MUGED_DSP::muged_1D_correlation(muged_array& fsignal, muged_array& ssignal,
																		 size_t min_lag, size_t max_lag,
																		 muged_array& correlation)
{
	muged_scalar* ref_signal = fsignal.array;
	size_t ref_size = fsignal.length;

	muged_scalar* deg_signal = ssignal.array;
	size_t deg_size = ssignal.length;

	correlation.length = 2 * max_lag + 1;
	correlation.array = new muged_scalar[ correlation.length ];

	for (size_t i = 0; i < correlation.length; i++)
		correlation.array[i] = muged_scalar(INIT,INIT);

	//range: -max_lag : -min_lag
	for (int lag = -(int)max_lag; lag <= -(int)min_lag; lag++)
	{
		for (size_t sample = 0; sample < ref_size; sample++)
		{
			if (sample - lag < deg_size)
			{
				muged_scalar multi = *(ref_signal + sample) * (*(deg_signal + sample - lag)).muged_conj();
				correlation.array[lag + max_lag] += multi;
			}
		}
	}

	//range: min_lag+1 : max_lag
	for (int lag = (int)min_lag + 1; lag <= (int)max_lag; lag++)
	{
		for (size_t sample = 0; sample < ref_size; sample++)
		{
			if (sample - lag < deg_size)
			{
				muged_scalar multi = *(ref_signal + sample) * (*(deg_signal + sample - lag)).muged_conj();
				correlation.array[lag + max_lag] += multi;
			}
		}
	}
}

void MUGED_DSP::muged_2D_correlation(muged_matrix& fsignal, muged_matrix& ssignal, muged_matrix& correlation)
{
	throw new MUGED_DSPException(ERR_NOT_IMPLEMENTED);
}

void MUGED_DSP::muged_1D_fft(muged_array& signal, muged_array& spectrum)
{
	//Zero padded
	muged_array radix_2_signal;
	muged_array W;

	//Initialize FFT
	muged_initialize_fft(signal, radix_2_signal, spectrum, W);

	//Calculate spectrum
	muged_array* result = muged_fft_kernel(radix_2_signal);

	//Store result
	for (unsigned int i = 0; i < spectrum.length; i++)
		spectrum.array[i] = (*result).array[i];

	//Clean memory
	delete [] radix_2_signal.array;
	delete [] result->array;
	delete result;
}

void MUGED_DSP::muged_1D_ifft(muged_array& spectrum, muged_array& signal)
{
	muged_array radix_2_signal;
	muged_array W;

	//Initialize IFFT
	muged_initialize_fft(spectrum, radix_2_signal, signal, W);

	//Calculate IFFT
	muged_array* result = muged_ifft_kernel(radix_2_signal);

	//Store result
	for (unsigned int i = 0; i < signal.length; i++)
		signal.array[i] = (*result).array[i]/radix_2_signal.length;

	//Clean memory
	delete [] radix_2_signal.array;
	delete [] result->array;
	delete result;

}

void MUGED_DSP::muged_initialize_fft(muged_array& signal, muged_array& radix_2_signal, muged_array& spectrum, muged_array& W)
{
	//Current signal length
	size_t N = signal.length;

	//Get next 2 power
	double next_2_pow = pow(2.0, (int)(log2(N) + 0.5));

	//Spectrum
	spectrum.length = next_2_pow;
	spectrum.array = new muged_scalar[spectrum.length];

	//Zero padded
	radix_2_signal.length = spectrum.length;
	radix_2_signal.array = new muged_scalar[radix_2_signal.length];

	//Padding zeros
	for (unsigned int i = 0; i < radix_2_signal.length; i++)
	{
		if ( i < signal.length)
			radix_2_signal.array[i] = signal.array[i];
		else
			radix_2_signal.array[i] = muged_scalar();
	}

	///TODO calculate twiddle factors
}

muged_array* MUGED_DSP::muged_fft_kernel(muged_array& radix_2_signal)
{
	size_t N = radix_2_signal.length;

	//Create output array
	muged_array* spectrum = new muged_array;

	(*spectrum).length = N;
	(*spectrum).array = new muged_scalar[(*spectrum).length];

	//Stop condition
	if (N == 1)
	{
		for (unsigned int i = 0; i < (*spectrum).length; i++)
			(*spectrum).array[i] = radix_2_signal.array[i];

		//Output
		return spectrum;
	}

	double pi = 4 * atan(1);

	//Calculate W - wage of twiddle factor
	muged_scalar W = muged_scalar(1, -2*pi/N, false);

	//Even part
	muged_array even_part;
	even_part.length = N/2;
	even_part.array = new muged_scalar[even_part.length];

	for (unsigned int sample = 0; sample < N; sample += 2)
		even_part.array[sample/2] = radix_2_signal.array[sample];

	//Odd part
	muged_array odd_part;
	odd_part.length = N/2;
	odd_part.array = new muged_scalar[odd_part.length];

	for (unsigned int sample = 1; sample < N; sample += 2)
		odd_part.array[sample/2] = radix_2_signal.array[sample];

	//Spectrum
	muged_array* spectrum_even = muged_fft_kernel(even_part);
	muged_array* spectrum_odd  = muged_fft_kernel(odd_part);

	for (unsigned int k = 0; k < N/2; k++)
	{
		(*spectrum).array[k]       = (*spectrum_even).array[k] + W.muged_pow(k)*(*spectrum_odd).array[k];
		(*spectrum).array[k + N/2] = (*spectrum_even).array[k] - W.muged_pow(k)*(*spectrum_odd).array[k];
	}

	//Clean memory
	delete [] spectrum_even->array;
	delete [] spectrum_odd->array;
	delete [] even_part.array;
	delete [] odd_part.array;
	delete spectrum_even;
	delete spectrum_odd;

	//Output
	return spectrum;
}

muged_array* MUGED_DSP::muged_ifft_kernel(muged_array& radix_2_signal)
{
	size_t N = radix_2_signal.length;

	//Create output array
	muged_array* signal = new muged_array;

	(*signal).length = N;
	(*signal).array = new muged_scalar[(*signal).length];

	//Stop condition
	if (N == 1)
	{
		for (unsigned int i = 0; i < (*signal).length; i++)
			(*signal).array[i] = radix_2_signal.array[i];

		//Output
		return signal;
	}

	double pi = 4 * atan(1);

	//Calculate W - wage of twiddle factor
	muged_scalar W = muged_scalar(1, -2*pi/N, false).muged_conj();

	//Even part
	muged_array even_part;
	even_part.length = N/2;
	even_part.array = new muged_scalar[even_part.length];

	for (unsigned int sample = 0; sample < N; sample += 2)
		even_part.array[sample/2] = radix_2_signal.array[sample];

	//Odd part
	muged_array odd_part;
	odd_part.length = N/2;
	odd_part.array = new muged_scalar[odd_part.length];

	for (unsigned int sample = 1; sample < N; sample += 2)
		odd_part.array[sample/2] = radix_2_signal.array[sample];

	//Spectrum
	muged_array* signal_even = muged_ifft_kernel(even_part);
	muged_array* signal_odd  = muged_ifft_kernel(odd_part);

	for (unsigned int k = 0; k < N/2; k++)
	{
		(*signal).array[k]       = (*signal_even).array[k] + W.muged_pow(k)*(*signal_odd).array[k];
		(*signal).array[k + N/2] = (*signal_even).array[k] - W.muged_pow(k)*(*signal_odd).array[k];
	}

	//Clean memory
	delete [] signal_even->array;
	delete [] signal_odd->array;
	delete [] even_part.array;
	delete [] odd_part.array;
	delete signal_even;
	delete signal_odd;

	//Output
	return signal;
}

void MUGED_DSP::muged_2D_fft(muged_matrix& signal, muged_matrix& spectrum)
{
	throw new MUGED_DSPException(ERR_NOT_IMPLEMENTED);
}

void MUGED_DSP::muged_2D_ifft(muged_matrix& spectrum, muged_matrix& signal)
{
	throw new MUGED_DSPException(ERR_NOT_IMPLEMENTED);
}

void MUGED_DSP::muged_kalman(muged_array& signal, muged_array& filtered_signal)
{
	throw new MUGED_DSPException(ERR_NOT_IMPLEMENTED);
}

