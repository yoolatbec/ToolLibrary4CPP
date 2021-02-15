/*
 * mat_def.h
 *
 *  Created on: Feb 15, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_ADVANCED_MATH_MAT_DEF_H_
#define SRC_ADVANCED_MATH_MAT_DEF_H_

#include "vec_def.h"

namespace tl {
namespace advanced {
namespace math {

struct mat1x1 {
	vec r0;
};

struct mat1x2 {
	vec2 r0;
};

struct mat1x3 {
	vec3 r0;
};

struct mat1x4 {
	vec4 r0;
};

struct mat2x2 {
	vec2 r0;
	vec2 r1;
};

struct mat2x3 {
	vec3 r0;
	vec3 r1;
};

struct mat2x4 {
	vec4 r0;
	vec4 r1;
};

struct mat3x3 {
	vec3 r0;
	vec3 r1;
	vec3 r2;
};

struct mat3x4 {
	vec4 r0;
	vec4 r1;
	vec4 r2;
};

struct mat4x4 {
	vec4 r0;
	vec4 r1;
	vec4 r2;
	vec4 r3;
};

}  //namespace math
}  //namespace advanced
}  //namespace tl

#endif /* SRC_ADVANCED_MATH_MAT_DEF_H_ */
