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
#include "MUGED_DSPInterface.h"

class MUGED_DSP : public MUGED_DSPInterface
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
	 * @fn muged_2D_correlation(muged_matrix& fsignal, muged_matrix& ssignal,
	 * 													muged_scalar min_lag, muged_scalar max_lag,
	 *													muged_matrix& correlation)
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
														muged_array& correlation) = 0;

	/**
	 * @fn muged_2D_correlation(muged_matrix& fsignal, muged_matrix& ssignal, muged_matrix& correlation)
	 * @see MUGED_DSPInterface::muged_2D_correlation(muged_matrix& fsignal, muged_matrix& ssignal, muged_matrix& correlation)
	 *
	 * Calculates 2D correlation of signals
	 *
	 * @param fsignal - first 2D signal
	 * @param ssignal - second 2D signal
	 * @param correlation - result (memory will be allocated)
	 */
	void muged_2D_correlation(muged_matrix& fsignal, muged_matrix& ssignal,
														muged_matrix& correlation);

	/**
	 * @fn muged_1D_fft(muged_array& signal, muged_array& spectrum)
	 * @see MUGED_DSPInterface::muged_1D_fft(muged_array& signal, muged_array& spectrum)
	 *
	 * Calculates 1D Fast Fourier Transform
	 *
	 * @param signal - 1D signal
	 * @param spectrum - result (memory will be allocated)
	 */
	void muged_1D_fft(muged_array& signal, muged_array& spectrum);

	/**
	 * @fn muged_2D_fft(muged_matrix& signal, muged_matrix& spectrum)
	 * @see MUGED_DSPInterface::muged_2D_fft(muged_matrix& signal, muged_matrix& spectrum)
	 *
	 * Calculates 2D Fast Fourier Transform
	 *
	 * @param signal - 1D signal
	 * @param spectrum - result (memory will be allocated)
	 */
	void muged_2D_fft(muged_matrix& signal, muged_matrix& spectrum);

	/**
	 * @fn muged_mean(muged_array& signal)
	 * @see MUGED_DSPInterface::muged_mean(muged_array& signal, muged_scalar mean)
	 *
	 * Calculates mean of 1D signal
	 *
	 * @param signal - 1D signal
	 * @return muged_scalar - result
	 */
	muged_scalar muged_mean(muged_array& signal);

	/**
	 * @fn muged_root_mean_square(muged_array& signal)
	 * @see MUGED_DSPInterface::muged_root_mean_square(muged_array& signal, muged_scalar rms)
	 *
	 * Calculates RMS of 1D signal
	 *
	 * @param signal - 1D signal
	 * @return muged_scalar - result
	 */
	muged_scalar muged_root_mean_square(muged_array& signal);

	/**
	 * @fn muged_mean_square(muged_array& signal)
	 * @see MUGED_DSPInterface::muged_mean_square(muged_array& signal, muged_scalar mean_square)
	 *
	 * Calculates mean square of 1D signal
	 *
	 * @param signal - 1D signal
	 * @return muged_scalar - result
	 */
	muged_scalar muged_mean_square(muged_array& signal);

	/**
	 * @fn muged_standard_deviation(muged_array& signal)
	 * @see MUGED_DSPInterface::muged_standard_deviation(muged_array& signal, muged_scalar std)
	 *
	 * Calculates standard deviation of 1D signal
	 *
	 * @param signal - 1D signal
	 * @return muged_scalar - result
	 */
	muged_scalar muged_standard_deviation(muged_array& signal);

	/**
	 * @fn muged_kalman(muged_array& signal, muged_array& filtered_signal)
	 * @see MUGED_DSPInterface::muged_kalman(muged_array& signal, muged_array& filtered_signal)
	 *
	 * Performs Kalman filtration on 1D signal
	 *
	 * @param signal - 1D signal
	 * @param filtered_signal - result (memory will be allocated)
	 */
	void muged_kalman(muged_array& signal, muged_array& filtered_signal);

};

#endif /* _MUGED_DSP_H_ */
