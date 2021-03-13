/*
 * tl_def.h
 *
 *  Created on: Sep 4, 2020
 *      Author: yoolatbec
 */

#ifndef INCLUDE_TL_DEF_H_
#define INCLUDE_TL_DEF_H_

#ifdef __linux__

#include <stddef.h>

#endif

#ifdef _WIN32

typedef unsigned int size_t

#endif

typedef signed char byte;
typedef int tlint;
typedef long long tlint64;
typedef unsigned int tluint;
typedef unsigned long long tluint64;
typedef unsigned long long hash_t;
typedef unsigned long long type_t;

#endif /* INCLUDE_TL_DEF_H_ */
