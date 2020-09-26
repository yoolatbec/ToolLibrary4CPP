/*
 * tl_def.h
 *
 *  Created on: Sep 4, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_TL_DEF_H_
#define SRC_TL_DEF_H_

typedef char byte;
typedef short word;
typedef struct {
	int: 32;
} tlint;
typedef struct{
	long long: 64;
} tlint64;
typedef unsigned int tluint;
typedef unsigned long long tluint64;
typedef unsigned long long size_t;
typedef unsigned long long hash_t;


#endif /* SRC_TL_DEF_H_ */
