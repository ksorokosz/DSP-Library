/**
 * @file MUGED_DSP.h
 * @date 2011-12-31
 * @author Kamil Sorokosz
 *
 * @brief Digital Signal Processing Library
 */

#ifndef _MUGED_DSP_H_
#define _MUGED_DSP_H_

#include "MUGED_Definitions.h"
#include "MUGED_Types.h"
#include "_MUGED_DSP_.h"

/**
 * @class MUGED_DSP
 * @author Kamil Sorokosz
 *
 * @brief Class implements basic DSP algorithms.
 *
 * Class implements basic DSP algorithms such as:
 * - 1D correlation
 * - 2D correlation (not yet)
 * - mean
 * - mean square
 * - root mean square
 * - standard deviation
 * - Kalman filter (not yet)
 * - Fast Fourier transform
 *
 * This class supports complex values.
 * @see MUGED_Complex
 */
class MUGED_DSP : public _MUGED_DSP_
{
public:

	/**
	 * @fn MUGED_DSP()
	 *
	 * Default contructor
	 */
	MUGED_DSP();
	~MUGED_DSP();

	/**
	 * @fn muged_1D_correlation(muged_array& fsignal, muged_array& ssignal,
   *                          size_t min_lag, size_t max_lag,
   *                          muged_array& correlation);
	 * @see _MUGED_DSP_::muged_1D_correlation(muged_array& fsignal, muged_array& ssignal,
   *                          size_t min_lag, size_t max_lag,
   *                          muged_array& correlation);
	 *
	 * Calculates 2D correlation of signals in ranges: -max_lag : -min_lag and min_lag : max_lag
	 *
	 * @param fsignal - first 2D signal
	 * @param ssignal - second 2D signal
	 * @param min_lag - minimum range
	 * @param max_lag - maximum range
	 * @param correlation - result (memory will be allocated)
	 */
	void muged_1D_correlation(muged_array& fsignal, muged_array& ssignal,
                            size_t min_lag, size_t max_lag,
                            muged_array& correlation);

	/**
	 * @fn muged_2D_correlation(muged_matrix& fsignal, muged_matrix& ssignal, muged_matrix& correlation)
	 * @see _MUGED_DSP_::muged_2D_correlation(muged_matrix& fsignal, muged_matrix& ssignal, muged_matrix& correlation)
	 *
	 * Calculates 2D correlation of signals
	 *
	 * @param fsignal - first 2D signal
	 * @param ssignal - second 2D signal
	 * @param correlation - result (memory will be allocated)
	 * @attention Not implemented yet!
	 */
	void muged_2D_correlation(muged_matrix& fsignal, muged_matrix& ssignal,
                            muged_matrix& correlation);

	/**
	 * @fn muged_1D_fft(muged_array& signal, muged_array& spectrum)
	 * @see _MUGED_DSP_::muged_1D_fft(muged_array& signal, muged_array& spectrum)
	 *
	 * Calculates 1D Fast Fourier Transform
	 *
	 * @param signal - 1D signal
	 * @param spectrum - result (memory will be allocated)
	 */
	void muged_1D_fft(muged_array& signal, muged_array& spectrum);

	/**
	 * @fn muged_1D_ifft(muged_array& spectrum, muged_array& signal)
	 * @see _MUGED_DSP_::muged_1D_ifft(muged_array& spectrum, muged_array& signal)
	 *
	 * Calculates 1D Inverse Fast Fourier Transform
	 *
	 * @param spectrum - 1D signal spectrum
	 * @param signal - result, signal in time domain (memory will be allocated)
	 */
	void muged_1D_ifft(muged_array& spectrum, muged_array& signal);

	/**
	 * @fn muged_2D_fft(muged_matrix& signal, muged_matrix& spectrum)
	 * @see _MUGED_DSP_::muged_2D_fft(muged_matrix& signal, muged_matrix& spectrum)
	 *
	 * Calculates 2D Fast Fourier Transform
	 *
	 * @param signal - 1D signal
	 * @param spectrum - result (memory will be allocated)
	 * @attention Not implemented yet!
	 */
	void muged_2D_fft(muged_matrix& signal, muged_matrix& spectrum);

	/**
	 * @fn muged_2D_ifft(muged_matrix& spectrum, muged_matrix& signal)
	 * @see _MUGED_DSP_::muged_2D_ifft(muged_matrix& spectrum, muged_matrix& signal)
	 *
	 * Calculates 2D Inverse Fast Fourier Transform
	 *
	 * @param spectrum - 2D signal spectrum
	 * @param signal - result, signal in "time" domain (memory will be allocated)
	 */
	void muged_2D_ifft(muged_matrix& spectrum, muged_matrix& signal);

	/**
	 * @fn muged_mean(muged_array& signal)
	 * @see _MUGED_DSP_::muged_mean(muged_array& signal, muged_scalar mean)
	 *
	 * Calculates mean of 1D signal
	 *
	 * @param signal - 1D signal
	 * @return muged_scalar - result
	 */
	muged_scalar muged_mean(muged_array& signal);

	/**
	 * @fn muged_root_mean_square(muged_array& signal)
	 * @see _MUGED_DSP_::muged_root_mean_square(muged_array& signal, muged_scalar rms)
	 *
	 * Calculates RMS of 1D signal
	 *
	 * @param signal - 1D signal
	 * @return muged_scalar - result
	 */
	muged_scalar muged_root_mean_square(muged_array& signal);

	/**
	 * @fn muged_mean_square(muged_array& signal)
	 * @see _MUGED_DSP_::muged_mean_square(muged_array& signal, muged_scalar mean_square)
	 *
	 * Calculates mean square of 1D signal
	 *
	 * @param signal - 1D signal
	 * @return muged_scalar - result
	 */
	muged_scalar muged_mean_square(muged_array& signal);

	/**
	 * @fn muged_standard_deviation(muged_array& signal)
	 * @see _MUGED_DSP_::muged_standard_deviation(muged_array& signal, muged_scalar std)
	 *
	 * Calculates standard deviation of 1D signal (normalized with number of samples)
	 *
	 * @param signal - 1D signal
	 * @return muged_scalar - result
	 */
	muged_scalar muged_standard_deviation(muged_array& signal);

	/**
	 * @fn muged_kalman(muged_array& signal, muged_array& filtered_signal)
	 * @see _MUGED_DSP_::muged_kalman(muged_array& signal, muged_array& filtered_signal)
	 *
	 * Performs Kalman filtration on 1D signal
	 *
	 * @param signal - 1D signal
	 * @param filtered_signal - result (memory will be allocated)
	 */
	void muged_kalman(muged_array& signal, muged_array& filtered_signal);

protected:

	/**
	 * @fn muged_initialize_fft(muged_array& signal, muged_array& radix_2_signal, muged_array& spectrum)
	 *
	 * Appends zeros to the signal to provide divisibility by power of two and initialize spectrum
	 *
	 * @param signal - input signal
	 * @param radix_2_signal - zero padded signal
	 * @param spectrum - spectrum
	 * @param W - wages for each twiddle factors
	 * @attention This method has not calculated wages for twiddle factors (W) yet
	 */
	void muged_initialize_fft(muged_array& signal, muged_array& radix_2_signal, muged_array& spectrum, muged_array& W);

	/**
	 * @fn muged_fft_kernel(muged_array& radix_2_signal)
	 *
	 * FFT kernel - it calculates fft using
	 * divide and conquer algorithm (Cooley–Tukey)
	 *
	 * @param radix_2_signal - time samples
	 * @return muged_array* - spectrum
	 *
	 * FFT(n, a0, a1, a2, a3, ... , an-1)
	 * {
	 * 	if (n == 1) return a0;
	 * 	w = e^-2πi/n;
	 * 	(e0, e1, e2, e3,..., en/2-1) = FFT(n/2, a0, a2, a4, a6,..., an-2);
	 * 	(d0, d1, d2, d3,..., dn/2-1) = FFT(n/2, a1, a3, a5, a7,..., an-1);
	 * 	for k = 0 to n/2-1
	 * 	{
	 * 		y_k = e_k + w^k*d_k;
	 * 		y_k+n/2 = e_k – w^k*d_k
	 * 	};
	 * 	return (y1, y2, y3,..., yn-1);
	 * }
	 */
	muged_array* muged_fft_kernel(muged_array& radix_2_signal);

	/**
	 * @fn muged_ifft_kernel(muged_array& radix_2_signal)
	 *
	 * IFFT kernel - it calculates ifft using
	 * divide and conquer algorithm (Cooley–Tukey)
	 *
	 * @param radix_2_signal - time samples
	 * @return muged_array* - signal in time domain
	 *
	 * IFFT(n, a0, a1, a2, a3, ... , an-1)
	 * {
	 * 	if (n == 1) return a0;
	 * 	w = e^2πi/n;
	 * 	(e0, e1, e2, e3,..., en/2-1) = IFFT(n/2, a0, a2, a4, a6,..., an-2);
	 * 	(d0, d1, d2, d3,..., dn/2-1) = IFFT(n/2, a1, a3, a5, a7,..., an-1);
	 * 	for k = 0 to n/2-1
	 * 	{
	 * 		y_k = e_k + w^k*d_k;
	 * 		y_k+n/2 = e_k – w^k*d_k
	 * 	};
	 * 	return (y1, y2, y3,..., yn-1);
	 * }
	 */
	muged_array* muged_ifft_kernel(muged_array& radix_2_signal);

};

#endif /* _MUGED_DSP_H_ */
