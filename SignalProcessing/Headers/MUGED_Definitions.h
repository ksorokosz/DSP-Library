/**
 * @file MUGED_Definitions.h
 * @date 2011-12-31
 * @author Kamil Sorokosz
 *
 */

#ifndef _MUGED_DEFINITIONS_H_
#define _MUGED_DEFINITIONS_H_

#include <cmath>
#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

#define INIT 0

#ifdef DEBUG
#define INFO(pattern,args...)   fprintf(stderr,"%25s:%3u | " pattern "\n", __FILE__, __LINE__, ##args)
#else
#define INFO(dummy,args...)
#endif

#define ERR_NOT_IMPLEMENTED "This method is not implemented yet"

#endif /* _MUGED_DEFINITIONS_H_ */
