#include "MUGED_Tests.h"
#include "MUGED_Complex.h"

/**
 * Complex class test. Compares calculated value to results of
 * the same operation in GNU Octave.
 */
void _complex_test_()
{
	ASSERTM("Test shouldn't fails", true);

	const double precision = 0.0001;

	MUGED_Complex complex_init;
	MUGED_Complex complex1(1,1);
	MUGED_Complex complex2(1,2);

	ASSERT_EQUAL_DELTA(1, complex1.muged_real(), precision);
	ASSERT_EQUAL_DELTA(1, complex1.muged_imag(), precision);
	ASSERT_EQUAL_DELTA(1, complex2.muged_real(), precision);
	ASSERT_EQUAL_DELTA(2, complex2.muged_imag(), precision);

	MUGED_Complex complex3 = complex1 + complex2;

	ASSERT_EQUAL_DELTA(2, complex3.muged_real(), precision);
	ASSERT_EQUAL_DELTA(3, complex3.muged_imag(), precision);

	MUGED_Complex complex4 = complex1;

	ASSERT_EQUAL_DELTA(1, complex4.muged_real(), precision);
	ASSERT_EQUAL_DELTA(1, complex4.muged_imag(), precision);

	double absolute1 = complex1.muged_abs();
	double angle1 = complex1.muged_angle();

	ASSERT_EQUAL_DELTA(1.4142, absolute1, precision);
	ASSERT_EQUAL_DELTA(0.78540, angle1, precision);

	double absolute2 = complex2.muged_abs();
	double angle2 = complex2.muged_angle();

	ASSERT_EQUAL_DELTA(2.2361, absolute2, precision);
	ASSERT_EQUAL_DELTA(1.1071, angle2, precision);

	double absolute3 = complex3.muged_abs();
	double angle3 = complex3.muged_angle();

	ASSERT_EQUAL_DELTA(3.6056, absolute3, precision);
	ASSERT_EQUAL_DELTA(0.98279, angle3, precision);

	ASSERT_EQUAL_DELTA(0, complex_init.muged_real(), precision);
	ASSERT_EQUAL_DELTA(0, complex_init.muged_imag(), precision);

	complex_init += complex3;

	ASSERT_EQUAL_DELTA(2, complex_init.muged_real(), precision);
	ASSERT_EQUAL_DELTA(3, complex_init.muged_imag(), precision);

	MUGED_Complex complex5 = complex4/2;

	ASSERT_EQUAL_DELTA(0.5, complex5.muged_real(), precision);
	ASSERT_EQUAL_DELTA(0.5, complex5.muged_imag(), precision);

	complex5/=2;

	ASSERT_EQUAL_DELTA(0.25, complex5.muged_real(), precision);
	ASSERT_EQUAL_DELTA(0.25, complex5.muged_imag(), precision);

	MUGED_Complex complex6 = MUGED_Complex(1,30, false);

	ASSERT_EQUAL_DELTA(0.15425, complex6.muged_real(), precision);
	ASSERT_EQUAL_DELTA(-0.98803, complex6.muged_imag(), precision);

	MUGED_Complex complex7 = complex3.muged_pow();

	ASSERT_EQUAL_DELTA(-5, complex7.muged_real(), precision);
	ASSERT_EQUAL_DELTA(12, complex7.muged_imag(), precision);

	MUGED_Complex complex8 = complex3.muged_pow(3);

	ASSERT_EQUAL_DELTA(-46, complex8.muged_real(), precision);
	ASSERT_EQUAL_DELTA(9, complex8.muged_imag(), precision);

	MUGED_Complex complex9 = complex3.muged_sqrt();

	ASSERT_EQUAL_DELTA(1.67415, complex9.muged_real(), precision);
	ASSERT_EQUAL_DELTA(0.89598, complex9.muged_imag(), precision);

	MUGED_Complex complex10 = complex3.muged_sqrt(3);

	ASSERT_EQUAL_DELTA(1.45186, complex10.muged_real(), precision);
	ASSERT_EQUAL_DELTA(0.49340, complex10.muged_imag(), precision);

	MUGED_Complex complex11 = complex10 * complex3;

	ASSERT_EQUAL_DELTA(1.4235, complex11.muged_real(), precision);
	ASSERT_EQUAL_DELTA(5.3424, complex11.muged_imag(), precision);

	MUGED_Complex complex12 = complex1.muged_conj();

	ASSERT_EQUAL_DELTA(1, complex12.muged_real(), precision);
	ASSERT_EQUAL_DELTA(-1, complex12.muged_imag(), precision);

	MUGED_Complex complex13 = complex10/complex3;

	ASSERT_EQUAL_DELTA(0.33722, complex13.muged_real(), precision);
	ASSERT_EQUAL_DELTA(-0.25914, complex13.muged_imag(), precision);

	ASSERTM("Test shouldn't fails", true);
}
