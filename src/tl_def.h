/*
 * tl_def.h
 *
 *  Created on: Sep 4, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_TL_DEF_H_
#define SRC_TL_DEF_H_

#ifdef __linux__

#include <stddef.h>

#endif

#ifdef _WIN32

typedef unsigned int size_t

#endif

typedef signed char byte;
typedef short word;
typedef int tlint;
typedef long long tlint64;
typedef unsigned int tluint;
typedef unsigned long long tluint64;
typedef unsigned long long hash_t;
typedef unsigned int type_t;

#endif /* SRC_TL_DEF_H_ */
