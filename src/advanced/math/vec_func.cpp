/*
 * vec_func.cpp
 *
 *  Created on: Feb 14, 2021
 *      Author: yoolatbec
 */

#include <advanced/math/vec_func.h>

namespace tl {
namespace advanced {
namespace math {

vec4 make_vec4(vec4 input) {
	return input;
}

vec4 make_vec4(vec3 input) {
	vec4 v;
	v.x = input.x;
	v.y = input.y;
	v.z = input.z;
	v.w = 0;

	return v;
}

vec4 make_vec4(vec2 input) {
	vec4 v;
	v.x = input.x;
	v.y = input.y;
	v.z = v.w = 0;

	return v;
}

vec4 make_vec4(vec input) {
	vec4 v;
	v.x = input.x;
	v.y = v.z = v.w = 0;

	return v;
}

vec3 make_vec3(vec4 input) {
	vec3 v;
	v.x = input.x;
	v.y = input.y;
	v.z = input.z;

	return v;
}

vec3 make_vec3(vec3 input) {
	return input;
}

vec3 make_vec3(vec2 input) {
	vec3 v;
	v.x = input.x;
	v.y = input.y;
	v.z = 0;

	return v;
}

vec3 make_vec3(vec input) {
	vec3 v;
	v.x = input.x;
	v.y = v.z = 0;

	return v;
}

vec2 make_vec2(vec4 input) {
	vec2 v;
	v.x = input.x;
	v.y = input.y;

	return v;
}

vec2 make_vec2(vec3 input) {
	vec2 v;
	v.x = input.x;
	v.y = input.y;

	return v;
}

vec2 make_vec2(vec2 input) {
	return input;
}

vec2 make_vec2(vec input) {
	vec2 v;
	v.x = input.x;
	v.y = 0;

	return v;
}

vec make_vec(vec4 input) {
	vec v;
	v.x = input.x;

	return v;
}

vec make_vec(vec3 input) {
	vec v;
	v.x = input.x;

	return v;
}

vec make_vec(vec2 input) {
	vec v;
	v.x = input.x;

	return v;
}

vec make_vec(vec input) {
	return input;
}

vec3 to_homogeneous(vec2 input) {
	vec3 v;
	v.x = input.x;
	v.y = input.y;
	v.z = 1;

	return v;
}

vec4 to_homogeneous(vec3 input) {
	vec4 v;
	v.x = input.x;
	v.y = input.y;
	v.z = input.z;
	v.w = 1;

	return v;
}

vec2 to_cartesian(vec3 input) {
	return {
		input.x / input.z, input.y / input.z
	};
}

vec3 to_cartesian(vec4 input){
	return {
		input.x / input.w, input.y / input.w, input.z / input.w
	};
}

}
}
}
