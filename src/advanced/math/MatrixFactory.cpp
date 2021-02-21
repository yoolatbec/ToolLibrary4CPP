/*
 * MatrixFactory.cpp
 *
 *  Created on: Jan 7, 2021
 *      Author: yoolatbec
 */

#include "MatrixFactory.h"
#include "MatrixType.h"
#include "VectorType.h"

namespace tl {
namespace advanced {
namespace math {

using lang::Reference;

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
	case VECTOR_1:
		Vec *v1 = vector_v;
		Vec *u1 = vector_u;
		product = dot_vec(v1->values(), u1->values());
		break;
	case VECTOR_2:
		Vec2 *v2 = vector_v;
		Vec2 *u2 = vector_u;
		product = dot_vec2(v2->values(), u2->values());
		break;
	case VECTOR_3:
		Vec3 *v3 = vector_v;
		Vec3 *u3 = vector_u;
		product = dot_vec3(v3->values(), u3->values());
		break;
	case VECTOR_4:
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

vec4 MatrixFactory::scale0(vec4 v, float a) {
	vec4 u;
	u.x = v.x * a;
	u.y = v.y * a;
	u.z = v.z * a;
	u.w = v.w * a;

	return u;
}

vec3 MatrixFactory::scale0(vec3 v, float a) {
	vec4 u = scale0(make_vec4(v), a);
	return make_vec3(u);
}

vec2 MatrixFactory::scale0(vec2 v, float a) {
	vec4 u = scale0(make_vec4(v), a);
	return make_vec2(u);
}

vec MatrixFactory::scale0(vec v, float a) {
	vec4 u = scale0(make_vec4(v), a);
	return make_vec(u);
}

Reference MatrixFactory::scale(Reference ref, float a) {
	if (!ref.getEntity()->instanceof(AbstractMatrix::type())) {
		//cast an exception
	}

	if (ref.getEntity()->instanceof(Matrix::type())) {
		return matrixScale(ref, a);
	} else {
		return vectorScale(ref, a);
	}
}

Reference MatrixFactory::matrixScale(Reference ref, float a) {
	Matrix *m = dynamic_cast<Matrix*>(ref.getEntity());
	Reference r = newMatrix(m->matrixType());
	Matrix *n = dynamic_cast<Matrix*>(r.getEntity());

	for (tlint index = m->minRowIndex(); index <= m->maxRowIndex(); index++) {
		n->setRow(index, vectorScale(m->getRow(index), a));
	}

	return r;
}

Reference MatrixFactory::vectorScale(Reference ref, float a) {
	Vector *v = dynamic_cast<Vector*>(ref.getEntity());
	ref = newVector(v->vectorType());
	Vector *u = dynamic_cast<Vector*>(ref.getEntity());

	for (tlint index = v->minIndex(); index <= v->maxIndex(); index++) {
		u->set(index, v->get(index) * a);
	}

	return ref;
}

Reference MatrixFactory::newMatrix(tlint i, tlint j) {
	MATRIX_TYPE type = MATRIX_MAP[i][j];
	return MatrixFactory::newMatrix(type);
}

Reference MatrixFactory::newMatrix(MATRIX_TYPE type) {
	Reference ref;
	switch (type) {
	case MATRIX_1X1:
		ref = Reference(new Mat1x1());
		break;
	case MATRIX_1X2:
		ref = Reference(new Mat1x2());
		break;
	case MATRIX_1X3:
		ref = Reference(new Mat1x3());
		break;
	case MATRIX_1X4:
		ref = Reference(new Mat1x4());
		break;
	case MATRIX_2X1:
		ref = Reference(new Mat2x1());
		break;
	case MATRIX_2X2:
		ref = Reference(new Mat2x2());
		break;
	case MATRIX_2X3:
		ref = Reference(new Mat2x3());
		break;
	case MATRIX_2X4:
		ref = Reference(new Mat2x4());
		break;
	case MATRIX_3X1:
		ref = Reference(new Mat3x1());
		break;
	case MATRIX_3X2:
		ref = Reference(new Mat3x2());
		break;
	case MATRIX_3X3:
		ref = Reference(new Mat3x3());
		break;
	case MATRIX_3X4:
		ref = Reference(new Mat3x4());
		break;
	case MATRIX_4X1:
		ref = Reference(new Mat4x1());
		break;
	case MATRIX_4X2:
		ref = Reference(new Mat4x2());
		break;
	case MATRIX_4X3:
		ref = Reference(new Mat4x3());
		break;
	case MATRIX_4X4:
		ref = Reference(new Mat4x4());
		break;
	default:
		// cast an exception
	}

	return ref;
}

Reference MatrixFactory::newVector(tlint i) {
	Reference ref;
	switch (i) {
	case 1:
		ref = Reference(new Vec());
		break;
	case 2:
		ref = Reference(new Vec2());
		break;
	case 3:
		ref = Reference(new Vec3());
		break;
	case 4:
		ref = Reference(new Vec4());
		break;
	default:
		//cast an exception
	}

	return ref;
}

Reference MatrixFactory::newVector(VECTOR_TYPE type) {
	Reference ref;
	switch (type) {
	case VECTOR_1:
		ref = Reference(new Vec());
		break;
	case VECTOR_2:
		ref = Reference(new Vec2());
		break;
	case VECTOR_3:
		ref = Reference(new Vec3());
		break;
	case VECTOR_4:
		ref = Reference(new Vec4());
		break;
	default:
		//cast an exception
	}

	return ref;
}

Reference MatrixFactory::multiply(Reference m1, Reference m2) {
	if (!(m1.getEntity()->instanceof(AbstractMatrix::type())
		&& m2.getEntity()->instanceof(AbstractMatrix::type()))) {
		//cast an exception
	}

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
