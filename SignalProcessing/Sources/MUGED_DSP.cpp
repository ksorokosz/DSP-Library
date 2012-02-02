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
	muged_scalar sum = INIT;

	for (size_t i = 0; i < size; i++)
		sum += *(signal.array + i);

	return sum/size;
}

muged_scalar MUGED_DSP::muged_root_mean_square(muged_array& signal)
{
	size_t size = signal.length;
	muged_scalar* array = signal.array;
	muged_scalar square_sum = INIT;

	for (size_t i = 0; i < size; i++)
		square_sum += pow(*(array + i),2);

	return sqrt(square_sum/size);
}

muged_scalar MUGED_DSP::muged_mean_square(muged_array& signal)
{
	size_t size = signal.length;
	muged_scalar* array = signal.array;
	muged_scalar square_sum = INIT;

	for (size_t i = 0; i < size; i++)
		square_sum += pow(*(array+i),2);

	return square_sum/size;
}

muged_scalar MUGED_DSP::muged_standard_deviation(muged_array& signal)
{
	return sqrt( muged_mean_square(signal) - pow(muged_mean(signal),2) );
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
		correlation.array[i] = INIT;

	//range: -max_lag : -min_lag
	for (int lag = -(int)max_lag; lag <= -(int)min_lag; lag++)
	{
		for (size_t sample = 0; sample < ref_size; sample++)
		{
			if (sample - lag < deg_size)
			{
				muged_scalar multi = *(ref_signal + sample) * (*(deg_signal + sample - lag));
				correlation.array[lag + max_lag] += multi;
			}
		}
	}

	//range: min_lag+1 : max_lag
	for (int lag = min_lag + 1; lag <= max_lag; lag++)
	{
		for (size_t sample = 0; sample < ref_size; sample++)
		{
			if (sample - lag < deg_size)
			{
				muged_scalar multi = *(ref_signal + sample) * (*(deg_signal + sample - lag));
				correlation.array[lag + max_lag] += multi;
			}
		}
	}
}

void MUGED_DSP::muged_2D_correlation(muged_matrix& fsignal, muged_matrix& ssignal, muged_matrix& correlation)
{
	muged_scalar** ref_matrix = fsignal.matrix;
	size_t ref_X = fsignal.rows;
	size_t ref_Y = fsignal.cols;

	muged_scalar** deg_matrix = ssignal.matrix;
	size_t deg_X = ssignal.rows;
	size_t deg_Y = ssignal.cols;

	correlation.matrix = new muged_scalar*[ref_X + deg_X - 1];

	//Initialization
	for ( size_t i = 0; i < ref_X + deg_X - 1; i++ )
	{
		correlation.matrix[i] = new muged_scalar[ref_Y + deg_Y - 1];
		for ( size_t j = 0; j < ref_Y + deg_Y - 1; j++ )
			correlation.matrix[i][j] = INIT;
	}

	//Calculate 2D correlation
	for ( size_t i = - deg_X + 1; i <= ref_X - 1; i++)
		for ( size_t j = - deg_Y + 1; j <= ref_Y - 1; j++)
		{
			muged_scalar sum = INIT;
			for ( size_t row = 0; row < ref_X + deg_X - 1; row++ )
			{
				for ( size_t col = 0; col < ref_Y + deg_Y - 1; col++ )
				{
					sum += ref_matrix[row][col] * deg_matrix[row + i][col + j];
				}
			}

			correlation.matrix[i][j] = sum;
		}
}

void MUGED_DSP::muged_1D_fft(muged_array& signal, muged_array& spectrum)
{
}

void MUGED_DSP::muged_2D_fft(muged_matrix& signal, muged_matrix& spectrum)
{
	muged_scalar** sig = signal.matrix;
	size_t rows = signal.rows;
	size_t cols = signal.cols;

	spectrum.matrix = new muged_scalar*[rows];

	//Initialization
	for ( size_t i = 0; i < rows; i++)
	{
		spectrum.matrix[i] = new muged_scalar[cols];
		for ( size_t j = 0; j < cols; j++)
			spectrum.matrix[i][j] = INIT;
	}
	spectrum.rows = rows;
	spectrum.cols = cols;

	muged_array temporary;

	//Across all rows of matrix
	/*for ( size_t i = 0; i < rows; i++)
	{
		muged_1D_fft(sig[i], temporary);
		for ( size_t j = 0; j < temporary.length; j++)
			spectrum[i][j] = temporary[j];

		delete [] temporary.array;
	}

	//Across all cols of matrix
	for ( size_t i = 0; i < rows; i++)
	{
		muged_1D_fft(sig[i], temporary);
		for ( size_t j = 0; j < temporary.length; j++)
			spectrum[i][j] = temporary[j];
	}*/
}

void MUGED_DSP::muged_kalman(muged_array& signal, muged_array& filtered_signal)
{
}
