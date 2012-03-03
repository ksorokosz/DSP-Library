#include "MUGED_Complex.h"
#include "MUGED_Tests.h"

/**
 * Complex class test. Compares calculated value to results of
 * the same operation in GNU Octave.
 */
void _complex_test_()
{
	INFO("--> complex test invoke");

	MUGED_Complex complex_init;
	MUGED_Complex complex1(1,1);
	MUGED_Complex complex2(1,2);

	__check__(complex1.muged_real(), 0, 1);
	__check__(complex1.muged_imag(), 0, 1);
	__check__(complex2.muged_real(), 0, 1);
	__check__(complex2.muged_imag(), 0, 2);

	MUGED_Complex complex3 = complex1 + complex2;

	__check__(complex3.muged_real(), 0, 2);
	__check__(complex3.muged_imag(), 0, 3);

	MUGED_Complex complex4 = complex1;

	__check__(complex4.muged_real(), 0, 1);
	__check__(complex4.muged_imag(), 0, 1);

	double absolute1 = complex1.muged_abs();
	double angle1 = complex1.muged_angle();

	__check__(absolute1, 4, 1.4142);
	__check__(angle1, 5, 0.78540);

	double absolute2 = complex2.muged_abs();
	double angle2 = complex2.muged_angle();

	__check__(absolute2, 4, 2.2361);
	__check__(angle2, 4, 1.1071);

	double absolute3 = complex3.muged_abs();
	double angle3 = complex3.muged_angle();

	__check__(absolute3, 4, 3.6056);
	__check__(angle3, 5, 0.98279);

	__check__(complex_init.muged_real(), 0, 0);
	__check__(complex_init.muged_imag(), 0, 0);

	complex_init += complex3;

	__check__(complex_init.muged_real(), 0, 2);
	__check__(complex_init.muged_imag(), 0, 3);

	MUGED_Complex complex5 = complex4/2;

	__check__(complex5.muged_real(), 1, 0.5);
	__check__(complex5.muged_imag(), 1, 0.5);

	complex5/=2;

	__check__(complex5.muged_real(), 2, 0.25);
	__check__(complex5.muged_imag(), 2, 0.25);

	MUGED_Complex complex6 = MUGED_Complex(1,30, false);

	__check__(complex6.muged_real(), 5,  0.15425);
	__check__(complex6.muged_imag(), 5, -0.98803);

	MUGED_Complex complex7 = complex3.muged_pow();
	__check__(complex7.muged_real(), 0, -5);
	__check__(complex7.muged_imag(), 0, 12);

	MUGED_Complex complex8 = complex3.muged_pow(3);
	__check__(complex8.muged_real(), 0, -46);
	__check__(complex8.muged_imag(), 0, 9);

	MUGED_Complex complex9 = complex3.muged_sqrt();
	__check__(complex9.muged_real(), 5, 1.67415);
	__check__(complex9.muged_imag(), 5, 0.89598);

	MUGED_Complex complex10 = complex3.muged_sqrt(3);
	__check__(complex10.muged_real(), 5, 1.45186);
	__check__(complex10.muged_imag(), 5, 0.49340);

	MUGED_Complex complex11 = complex10 * complex3;
	__check__(complex11.muged_real(), 4, 1.4235);
	__check__(complex11.muged_imag(), 4, 5.3424);

	MUGED_Complex complex12 = complex1.muged_conj();
	__check__(complex12.muged_real(), 0, 1);
	__check__(complex12.muged_imag(), 0, -1);

	MUGED_Complex complex13 = complex10/complex3;
	__check__(complex13.muged_real(), 5, 0.33722);
	__check__(complex13.muged_imag(), 5, -0.25914);

	INFO("--> complex test success");
}

#define EXCLUDE
#ifndef EXCLUDE
int main()
{
	_complex_test_();

	return 0;
}
#endif
