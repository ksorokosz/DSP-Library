/**
 * @file MUGED_DSPInterface.h
 * @date 2011-12-31
 * @author Kamil Sorokosz
 *
 * @brief Interface for Digital Signal Processing
 */

#ifndef __MUGED_DSP__H_
#define __MUGED_DSP__H_

#include "MUGED_Definitions.h"
#include "MUGED_Types.h"

/**
 * @class _MUGED_DSP_
 * @author Kamil Sorokosz
 *
 * @brief Interface for DSP class
 */
class _MUGED_DSP_
{
public:

	/**
	 * @fn _MUGED_DSP_()
	 *
	 * Default constructor
	 */
	_MUGED_DSP_() {};
	virtual ~_MUGED_DSP_() {};

	/**
	 * @fn muged_1D_correlation(muged_array& fsignal, muged_array& ssignal,
	 *                          muged_array& correlation)
	 *
	 * Calculates 1D correlation of signals
	 *
	 * @param fsignal - first 1D signal
	 * @param ssignal - second 1D signal
	 * @param correlation - result
	 */
	virtual void muged_1D_correlation(muged_array& fsignal, muged_array& ssignal,
                                    size_t min_lag, size_t max_lag,
                                    muged_array& correlation) = 0;

	/**
	 * @fn muged_2D_correlation(muged_matrix& fsignal, muged_matrix& ssignal,
	 *                          muged_scalar min_lag, muged_scalar max_lag,
	 *                          muged_matrix& correlation)
	 *
	 * Calculates 2D correlation of signals in ranges: -max_lag : -min_lag and min_lag : max_lag
 	 *
	 * @param fsignal - first 2D signal
	 * @param ssignal - second 2D signal
	 * @param min_lag - minimum range
	 * @param max_lag - maximum range
	 * @param correlation - result (memory will be allocated)
	 */
	virtual void muged_2D_correlation(muged_matrix& fsignal, muged_matrix& ssignal,
                                    muged_matrix& correlation) = 0;

	/**
	 * @fn muged_1D_fft(muged_array& fsignal, muged_array& spectrum)
	 *
	 * Calculates 1D Fast Fourier Transform
	 *
	 * @param signal - 1D signal
	 * @param spectrum - result (memory will be allocated)
	 */
	virtual void muged_1D_fft(muged_array& signal, muged_array& spectrum) = 0;

	/**
	 * @fn muged_1D_ifft(muged_array& spectrum, muged_array& signal)
	 *
	 * Calculates 1D Inverse Fast Fourier Transform
	 *
	 * @param spectrum - 1D signal spectrum
	 * @param signal - result, signal in time domain (memory will be allocated)
	 */
	virtual void muged_1D_ifft(muged_array& spectrum, muged_array& signal) = 0;

	/**
	 * @fn muged_2D_fft(muged_matrix& ssignal, muged_matrix& spectrum)
	 *
	 * Calculates 2D Fast Fourier Transform
	 *
	 * @param signal - 2D signal
	 * @param spectrum - result (memory will be allocated)
	 */
	virtual void muged_2D_fft(muged_matrix& signal, muged_matrix& spectrum) = 0;

	/**
	 * @fn muged_2D_ifft(muged_matrix& spectrum, muged_matrix& signal)
	 *
	 * Calculates 2D Inverse Fast Fourier Transform
	 *
	 * @param spectrum - 2D signal spectrum
	 * @param signal - result, signal in "time" domain (memory will be allocated)
	 */
	virtual void muged_2D_ifft(muged_matrix& spectrum, muged_matrix& signal) = 0;

	/**
	 * @fn muged_mean(muged_array& signal)
	 *
	 * Calculates mean of 1D signal
	 *
	 * @param signal - 1D signal
	 * @return muged_scalar - result
	 */
	virtual muged_scalar muged_mean(muged_array& signal) = 0;

	/**
	 * @fn muged_root_mean_square(muged_array& signal) = 0
	 *
	 * Calculates RMS of 1D signal
	 *
	 * @param signal - 1D signal
	 * @return muged_scalar - result
	 */
	virtual muged_scalar muged_root_mean_square(muged_array& signal) = 0;

	/**
	 * @fn muged_mean_square(muged_array& signal) = 0
	 *
	 * Calculates mean square of 1D signal
	 *
	 * @param signal - 1D signal
	 * @return muged_scalar - result
	 */
	virtual muged_scalar muged_mean_square(muged_array& signal) = 0;

	/**
	 * @fn muged_standard_deviation(muged_array& signal) = 0
	 *
	 * Calculates standard deviation of 1D signal
	 *
	 * @param signal - 1D signal
	 * @return muged_scalar - result
	 */
	virtual muged_scalar muged_standard_deviation(muged_array& signal) = 0;

	/**
	 * @fn muged_kalman(muged_array& signal, muged_array& filtered_signal)
	 *
	 * Performs Kalman filtration on 1D signal
	 *
	 * @param signal - 1D signal
	 * @param filtered_signal - result (memory will be allocated)
	 */
	virtual void muged_kalman(muged_array& signal, muged_array& filtered_signal) = 0;

};

#endif /* __MUGED_DSP__H_ */
