/*
 * mat_def.h
 *
 *  Created on: Feb 15, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_ADVANCED_MATH_MAT_DEF_H_
#define INCLUDE_ADVANCED_MATH_MAT_DEF_H_

#include <advanced/math/vec_def.h>

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

struct mat2x1 {
	vec r0;
	vec r1;
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

struct mat3x1 {
	vec r0;
	vec r1;
	vec r2;
};

struct mat3x2 {
	vec2 r0;
	vec2 r1;
	vec2 r2;
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

struct mat4x1 {
	vec r0;
	vec r1;
	vec r2;
	vec r3;
};

struct mat4x2 {
	vec2 r0;
	vec2 r1;
	vec2 r2;
	vec2 r3;
};

struct mat4x3 {
	vec3 r0;
	vec3 r1;
	vec3 r2;
	vec3 r3;
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

#endif /* INCLUDE_ADVANCED_MATH_MAT_DEF_H_ */
