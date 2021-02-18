/*
 * MatrixFactory.cpp
 *
 *  Created on: Jan 7, 2021
 *      Author: yoolatbec
 */

#include "MatrixFactory.h"

namespace tl {
namespace advanced {
namespace math {

MatrixFactory::MatrixFactory() {
	// TODO Auto-generated constructor stub
}

float MatrixFactory::dot_vec4(vec4 v, vec4 u) {
	return v.x * u.x + v.y * u.y + v.z * u.z + v.w * u.w;
}

float MatrixFactory::dot_vec3(vec3 v, vec3 u) {
	return v.x * u.x + v.y * u.y + v.z * u.z;
}

float MatrixFactory::dot_vec2(vec2 v, vec2 u) {
	return v.x * u.x + v.y * u.y;
}

float MatrixFactory::dot_vec(vec v, vec u) {
	return v.x * u.x;
}

float MatrixFactory::dot(Reference v, Reference u) {
	if (!v.getEntity()->instanceof(Vector::type())
		|| !u.getEntity()->instanceof(Vector::type())) {
		//cast an exception
	}

	Vector *vector_v = dynamic_cast<Vector*>(v.getEntity());
	Vector *vector_u = dynamic_cast<Vector*>(u.getEntity());

	if (vector_v->vectorType() != vector_u->vectorType()) {
		//cast an exception
	}

	float product;
	switch (vector_v->vectorType()) {
	case Vector::VECTOR_1:
		Vec *v1 = vector_v;
		Vec *u1 = vector_u;
		product = dot_vec(v1->values(), u1->values());
		break;
	case Vector::VECTOR_2:
		Vec2 *v2 = vector_v;
		Vec2 *u2 = vector_u;
		product = dot_vec2(v2->values(), u2->values());
		break;
	case Vector::VECTOR_3:
		Vec3 *v3 = vector_v;
		Vec3 *u3 = vector_u;
		product = dot_vec3(v3->values(), u3->values());
		break;
	case Vector::VECTOR_4:
		Vec4 *v4 = vector_v;
		Vec4 *u4 = vector_u;
		product = dot_vec4(v4->values(), u4->values());
		break;
	default:
		//cast an exception
	}

	return product;
}

vec4 MatrixFactory::add0(vec4 v, vec4 u) {
	vec4 w;
	w.x = v.x + u.x;
	w.y = v.y + u.y;
	w.z = v.z + u.z;
	w.w = v.w + u.w;

	return w;
}

vec3 MatrixFactory::add0(vec3 v, vec3 u) {
	vec4 w = add0(make_vec4(v), make_vec4(u));

	return make_vec3(w);
}

vec2 MatrixFactory::add0(vec2 v, vec2 u) {
	vec4 w = add0(make_vec4(v), make_vec4(u));

	return make_vec2(w);
}

vec MatrixFactory::add0(vec v, vec u) {
	vec4 w = add0(make_vec4(v), make_vec4(u));

	return make_vec(w);
}

vec4 MatrixFactory::negate0(vec4 v) {
	vec4 u;
	u.x = -v.x;
	u.y = -v.y;
	u.z = -v.z;
	u.w = -v.w;

	return u;
}

vec3 MatrixFactory::negate0(vec3 v) {
	vec4 u = negate0(make_vec4(v));
	return make_vec3(u);
}

vec2 MatrixFactory::negate0(vec2 v) {
	vec4 u = negate0(make_vec4(v));
	return make_vec2(u);
}

vec MatrixFactory::negate0(vec v) {
	vec4 u = negate0(make_vec4(v));
	return make_vec(u);
}

vec4 MatrixFactory::multiply0(vec4 v, float a) {
	vec4 u;
	u.x = v.x * a;
	u.y = v.y * a;
	u.z = v.z * a;
	u.w = v.w * a;

	return u;
}

vec3 MatrixFactory::multiply0(vec3 v, float a) {
	vec4 u = multiply0(make_vec4(v), a);
	return make_vec3(u);
}

vec2 MatrixFactory::multiply0(vec2 v, float a) {
	vec4 u = multiply0(make_vec4(v), a);
	return make_vec2(u);
}

vec MatrixFactory::multiply0(vec v, float a) {
	vec4 u = multiply0(make_vec4(v), a);
	return make_vec(u);
}

Reference MatrixFactory::newMatrix(tlint i, tlint j){

}

type_t MatrixFactory::type() {
	return CLASS_SERIAL;
}

bool MatrixFactory::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
