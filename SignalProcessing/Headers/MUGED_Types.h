/**
 * @file MUGED_Types.h
 * @date 2011-12-31
 * @author Kamil Sorokosz
 *
 * @brief File contains scalar, array, matrix types definitions
 */

#ifndef _MUGED_TYPES_H_
#define _MUGED_TYPES_H_

#include "MUGED_Complex.h"

/**
 * @typedef muged_scalar
 * @brief Scalar complex type
 */
typedef MUGED_Complex muged_scalar;

/**
 * @struct _muged_array_
 * Array for scalars - 1D signal
 */
struct _muged_array_
{
	muged_scalar* array;
	size_t length;
};

/**
 * @struct _muged_matrix_
 * 2D array for 2D signals
 */
struct _muged_matrix_
{
	muged_scalar** matrix;
	size_t rows;
	size_t cols;
};

/**
 * @typedef muged_array
 * @brief 1D array type
 */
typedef _muged_array_  muged_array;

/**
 * @typedef muged_matrix
 * @brief 2D array type
 */
typedef _muged_matrix_ muged_matrix;


#endif /* _MUGED_TYPES_H_ */
