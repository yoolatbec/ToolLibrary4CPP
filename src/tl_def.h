/*
 * tl_def.h
 *
 *  Created on: Sep 4, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_TL_DEF_H_
#define SRC_TL_DEF_H_

#include <stddef.h>

typedef char byte;
typedef short word;
typedef int tlint;
typedef long long tlint64;
typedef unsigned int tluint;
typedef unsigned long long tluint64;
typedef unsigned long long hash_t;
typedef unsigned int type_t;

#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) > (y)) ? (y) : (x))

#endif /* SRC_TL_DEF_H_ */
