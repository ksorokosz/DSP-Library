/**
 * @file MUGED_Complex.h
 * @date 05-02-2012
 * @author Kamil Sorokosz
 *
 * @brief File contains class describing complex type
 */

#ifndef _MUGED_COMPLEX_H_
#define _MUGED_COMPLEX_H_

#include "MUGED_Definitions.h"

/**
 * @class MUGED_Complex
 * @author Kamil Sorokosz
 * @brief Class allows to do the basic operations on complex values.
 *
 * Class implements several operations on complex values. It allows to:
 * - get real/imaginary part
 * - calculate absolute value
 * - calculate angle
 * - calculate conjugate
 * - adding, subtracting, multiplying, dividing complex values
 * - calculate power, e.g square power
 * - calculate root, e.g square root
 *
 */
class MUGED_Complex
{
public:

	/**
	 * Default contructor. Complex value equals 0 + 0i
	 */
	MUGED_Complex();

	/**
	 * Contructs complex value
	 *
	 * @param real_abs - real part or absolute value depends on flag
	 * @param imag_angle - imaginary part or angle depends on flag
	 * @param flag - if true arguments are treated as real and imaginary parts, otherwise
	 * as absolute and angle of complex value. For default flag equals false.
	 */
	MUGED_Complex(double real_abs, double imag_angle, bool flag = true);

	/**
	 * Default copy contructor
	 * @param scalar - complex value
	 */
	MUGED_Complex(const MUGED_Complex& scalar);

	/**
	 * Default destructor
	 */
	~MUGED_Complex();

	/**
	 * Assign the current complex value to specified
	 *
	 * @param scalar - specified complex
	 * @return MUGED_Complex - complex value equal to specified
	 */
	MUGED_Complex& operator=(const MUGED_Complex& scalar);

	/**
	 * @fn muged_real() const
	 *
	 * Returns real part of complex value
	 * @return double - real part
	 */
	double muged_real() const;

	/**
	 * @fn muged_imag() const
	 *
	 * Returns imaginary part of complex value
	 * @return double - imaginary part
	 */
	double muged_imag() const;

	/**
	 * @fn muged_abs() const
	 *
	 * Calculates absolute value of current complex
	 * @return double - absolute value of current complex
	 */
	double muged_abs() const;

	/**
	 * @fn muged_angle() const
	 *
	 * Calculates angle of current complex
	 * @return double - angle of current complex
	 */
	double muged_angle() const;

	/**
	 * Calculates conjugation of current complex value
	 * @return MUGED_Complex - complex value
	 */
	MUGED_Complex muged_conj();

	/**
	 * @fn operator+(const MUGED_Complex& scalar)
	 *
	 * Calculates sum of current complex value and some complex scalar
	 *
	 * @param scalar - complex value
	 * @return MUGED_Complex - sum of input and current complex value
	 */
	MUGED_Complex operator+(const MUGED_Complex& scalar);

	/**
	 * Calculates sum of two complex values [friend function]
	 *
	 * @param scalar1 - first complex value
	 * @param scalar2 - second complex value
	 * @return MUGED_Complex - sum of input complex values
	 */
  friend MUGED_Complex operator+(const MUGED_Complex& scalar1, const MUGED_Complex& scalar2);

  /**
   * Calculates sum of current complex value and input complex.
   * Updates the current complex value.
   *
   * @param scalar - complex value
   */
  void operator+=(const MUGED_Complex& scalar);

	/**
	 * @fn operator-(const MUGED_Complex& scalar)
	 *
	 * Calculates difference between current complex value and some complex scalar
	 *
	 * @param scalar - complex value
	 * @return MUGED_Complex - difference between input and current complex value
	 */
	MUGED_Complex operator-(const MUGED_Complex& scalar);

	/**
	 * Calculates difference between two complex values [friend function]
	 *
	 * @param scalar1 - first complex value
	 * @param scalar2 - second complex value
	 * @return MUGED_Complex - difference between input complex values
	 */
	friend MUGED_Complex operator-(const MUGED_Complex& scalar1, const MUGED_Complex& scalar2);

	/**
	 * Calculates difference between current complex value and input complex.
	 * Updates the current complex value.
	 *
	 * @param scalar - complex value
	 */
	void operator-=(const MUGED_Complex& scalar);

	/**
	 * Multiplies current complex value and input argument
	 *
	 * @param scalar - complex value
	 * @return MUGED_Complex - complex value
	 */
	MUGED_Complex operator*(MUGED_Complex& scalar);

	/**
	 * Multiplies input complex values
	 *
	 * @param scalar1 - first complex value
	 * @param scalar2 - second complex value
	 * @return MUGED_Complex - complex value
	 */
	friend MUGED_Complex operator*(const MUGED_Complex& scalar1, const MUGED_Complex& scalar2);

	/**
	 * Divides current complex by specified double precision number
	 *
	 * @param value - specified double precision number
	 * @return MUGED_Complex - complex value
	 */
	MUGED_Complex operator/(double value);

	/**
	 * Divides current complex by specified double precision number
	 * Updates current complex value
	 *
	 * @param value - specified double precision number
	 */
	void operator/=(double value);

	/**
	 * Divides current complex value by another complex
	 *
	 * @param scalar - specified complex value
	 * @return MUGED_Complex - division result
	 */
	MUGED_Complex operator/(MUGED_Complex& scalar);

	/**
	 * Divides current complex value by another complex
	 *
	 * @param scalar - specified complex value
	 */
	void operator/=(MUGED_Complex& scalar);

	/**
	 * @fn muged_pow()
	 *
	 * Calculates power of complex value
	 *
	 * @param exp - exponent (default: 2)
	 * @return MUGED_Complex - power of input value
	 */
	MUGED_Complex muged_pow(double exp = 2);

	/**
	 * @fn muged_sqrt()
	 *
	 * Calculates square root of complex value
	 *
	 * @param exp - exponent (default: 2)
	 * @return MUGED_Complex - square root of input value
	 */
	MUGED_Complex muged_sqrt(double exp = 2);

private:

	/// Real part of complex value
	double real;

	/// Imaginary part of complex value
	double imaginary;
};


inline MUGED_Complex::MUGED_Complex()
{
	real = INIT;
	imaginary = INIT;
}

inline MUGED_Complex::MUGED_Complex(double real_abs, double imag_angle, bool flag)
{
	if (flag)
	{
		this->real = real_abs;
		this->imaginary = imag_angle;
	}
	else
	{
		this->real = real_abs * cos(imag_angle);
		this->imaginary = real_abs * sin(imag_angle);
	}

}

inline MUGED_Complex::MUGED_Complex(const MUGED_Complex& scalar)
{
	real = scalar.real;
	imaginary = scalar.imaginary;
}

inline MUGED_Complex::~MUGED_Complex()
{
	real = INIT;
	imaginary = INIT;
}

inline MUGED_Complex& MUGED_Complex::operator=(const MUGED_Complex& scalar)
{
	real = scalar.muged_real();
	imaginary = scalar.muged_imag();

	return (*this);
}

inline double MUGED_Complex::muged_real() const
{
	return this->real;
}

inline double MUGED_Complex::muged_imag() const
{
	return this->imaginary;
}

inline double MUGED_Complex::muged_abs() const
{
	double real = this->real;
	double imag = this->imaginary;

	return sqrt(real*real + imag*imag);
}

inline double MUGED_Complex::muged_angle() const
{
	double real = this->real;
	double imag = this->imaginary;

	return atan2(imag,real);
}

inline MUGED_Complex MUGED_Complex::muged_conj()
{
	MUGED_Complex complex;
	complex.real = this->real;
	complex.imaginary = -this->imaginary;

	return complex;
}

inline MUGED_Complex MUGED_Complex::operator+(const MUGED_Complex & scalar)
{
	MUGED_Complex complex;
	complex.real = (this->real) + scalar.real;
	complex.imaginary = (this->imaginary) + scalar.imaginary;

	return complex;
}

inline MUGED_Complex operator+(const MUGED_Complex & scalar1, const MUGED_Complex & scalar2)
{
	MUGED_Complex complex;
	complex.real = scalar1.real + scalar2.real;
	complex.imaginary = scalar1.imaginary + scalar2.imaginary;

	return complex;
}

inline void MUGED_Complex::operator+=(const MUGED_Complex & scalar)
{
	this->real += scalar.real;
	this->imaginary += scalar.imaginary;
}

inline MUGED_Complex MUGED_Complex::operator-(const MUGED_Complex & scalar)
{
	MUGED_Complex reverse_scalar = MUGED_Complex(-scalar.real, -scalar.imaginary);
	return (*this) + reverse_scalar;
}

inline MUGED_Complex operator-(const MUGED_Complex & scalar1, const MUGED_Complex & scalar2)
{
	MUGED_Complex reverse_scalar2 = MUGED_Complex(-scalar2.real, -scalar2.imaginary);
	return scalar1 + reverse_scalar2;
}

inline void MUGED_Complex::operator-=(const MUGED_Complex & scalar)
{
	MUGED_Complex reverse_scalar = MUGED_Complex(-scalar.real, -scalar.imaginary);
	(*this) += reverse_scalar;
}

inline MUGED_Complex MUGED_Complex::operator*(MUGED_Complex & scalar)
{
	double abs1 = this->muged_abs();
	double angle1 = this->muged_angle();

	double abs2 = scalar.muged_abs();
	double angle2 = scalar.muged_angle();

	MUGED_Complex complex;
	complex.real = abs1*abs2*cos(angle1 + angle2);
	complex.imaginary = abs1*abs2*sin(angle1 + angle2);

	return complex;
}

inline MUGED_Complex operator*(const MUGED_Complex & scalar1, const MUGED_Complex & scalar2)
{
	double abs1 = scalar1.muged_abs();
	double angle1 = scalar1.muged_angle();

	double abs2 = scalar2.muged_abs();
	double angle2 = scalar2.muged_angle();

	MUGED_Complex complex;
	complex.real = abs1*abs2*cos(angle1 + angle2);
	complex.imaginary = abs1*abs2*sin(angle1 + angle2);

	return complex;
}

inline MUGED_Complex MUGED_Complex::operator/(double value)
{
	MUGED_Complex complex;

	complex.real = (this->real)/value;
	complex.imaginary = (this->imaginary)/value;

	return complex;
}

inline void MUGED_Complex::operator/=(double value)
{
	this->real/=value;
	this->imaginary/=value;
}

inline MUGED_Complex MUGED_Complex::operator/(MUGED_Complex& scalar)
{
	MUGED_Complex complex;
	complex.real = this->real * scalar.real + this->imaginary * scalar.imaginary;
	complex.imaginary = this->imaginary * scalar.real - this->real * scalar.imaginary;

	complex /= (pow(scalar.real,2) + pow(scalar.imaginary,2));

	return complex;
}

inline void MUGED_Complex::operator/=(MUGED_Complex& scalar)
{
	MUGED_Complex complex;
	complex.real = this->real * scalar.real + this->imaginary * scalar.imaginary;
	complex.imaginary = this->imaginary * scalar.real - this->real * scalar.imaginary;

	complex /= (pow(scalar.real,2) + pow(scalar.imaginary,2));

	this->real = complex.real;
	this->imaginary = complex.imaginary;
}

inline MUGED_Complex MUGED_Complex::muged_pow(double exp)
{
	double abs = muged_abs();
	double angle = muged_angle();

	MUGED_Complex complex;
	complex.real = pow(abs,exp) * cos(angle * exp);
	complex.imaginary = pow(abs,exp) * sin(angle * exp);

	return complex;
}

inline MUGED_Complex MUGED_Complex::muged_sqrt(double exp)
{
	double abs = muged_abs();
	double angle = muged_angle();

	MUGED_Complex complex;
	complex.real = pow(abs,1/exp) * cos(angle/exp);
	complex.imaginary = pow(abs, 1/exp) * sin(angle/exp);

	return complex;
}

#endif /* _MUGED_COMPLEX_H_ */

