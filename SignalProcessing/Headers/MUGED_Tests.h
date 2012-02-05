/**
 * @file MUGED_Tests.h
 * @date 05-02-2012
 * @author Kamil Sorokosz
 *
 */

#ifndef _MUGED_TESTS_H_
#define _MUGED_TESTS_H_

#include <cassert>

inline void __check__(double tested_value, int precision, double reference_value)
{
	double value = INIT;
	if (reference_value >= 0)
		value = (int)(tested_value * pow(10,precision) + 0.5)/(pow(10,precision));
	else
		value = (int)(tested_value * pow(10,precision) - 0.5)/(pow(10,precision));

	assert(value == reference_value);
}

void _complex_test_();


#endif /* _MUGED_TESTS_H_ */
