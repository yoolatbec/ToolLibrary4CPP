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
//typedef short word;
typedef int tlint;
typedef long long tlint64;
typedef unsigned int tluint;
typedef unsigned long long tluint64;
typedef unsigned long long hash_t;
typedef unsigned long long type_t;

//typedef struct{
//	short: 16;
//} word;
//
//typedef struct{
//	int: 32;
//} tlint;
//
//typedef struct{
//	unsigned int: 32;
//} tluint;
//
//typedef struct{
//	signed long long: 64;
//} tlint64;
//
//typedef struct{
//	unsigned long long: 64;
//} tluint64;

#endif /* INCLUDE_TL_DEF_H_ */