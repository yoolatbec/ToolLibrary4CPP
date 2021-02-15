/*
 * vector.h
 *
 *  Created on: Feb 14, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_ADVANCED_MATH_VEC_DEF_H_
#define SRC_ADVANCED_MATH_VEC_DEF_H_

namespace tl {
namespace advanced {
namespace math {

struct vec4 {
	float x;
	float y;
	float z;
	float w;
};

struct alignas(16) vec3 {
	float x;
	float y;
	float z;
};

struct vec2 {
	float x;
	float y;
};

struct vec {
	float x;
};

}  //namespace math
}  //namespace advanced
}  //namespace tl

#endif /* SRC_ADVANCED_MATH_VEC_DEF_H_ */
