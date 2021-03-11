/*
 * MatrixFactory.cpp
 *
 *  Created on: Jan 7, 2021
 *      Author: yoolatbec
 */

#include <advanced/math/IncompatibleMatrixTypeException.h>
#include <advanced/math/MatrixFactory.h>
#include <advanced/math/MatrixType.h>
#include <advanced/math/VectorType.h>
#include <lang/Math.h>
#include <lang/IllegalArgumentTypeException.h>
#include <lang/UnacceptableArgumentException.h>
#include <lang/UndefinedException.h>

namespace tl {
namespace advanced {
namespace math {

using lang::Reference;
using lang::IllegalArgumentTypeException;
using lang::UnacceptableArgumentException;
using lang::UndefinedException;

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
	dismissNull(v);
	dismissNull(u);
	argumentTypeCheck(v, Vector::type());
	argumentTypeCheck(u, Vector::type());

	Vector *vector_v = dynamic_cast<Vector*>(v.getEntity());
	Vector *vector_u = dynamic_cast<Vector*>(u.getEntity());

	if (vector_v->vectorType() != vector_u->vectorType()) {
		throw UnacceptableArgumentException();
	}

	float product = 0;
	for (tlint index = vector_v->minIndex(); index <= vector_v->maxIndex();
		index++) {
		product += (vector_v->get(index) * vector_u->get(index));
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
	dismissNull(ref);
	argumentTypeCheck(ref, AbstractMatrix::type());

	if (ref.getEntity()->instanceof(Matrix::type())) {
		return mScale0(ref, a);
	} else {
		return vScale0(ref, a);
	}
}

Reference MatrixFactory::mScale0(Reference ref, float a) {
	Matrix *m = dynamic_cast<Matrix*>(ref.getEntity());
	Reference r = newMatrix(m->matrixType());
	Matrix *n = dynamic_cast<Matrix*>(r.getEntity());

	for (tlint index = m->minRowIndex(); index <= m->maxRowIndex(); index++) {
		n->setRow(index, vScale0(m->getRow(index), a));
	}

	return r;
}

Reference MatrixFactory::vScale0(Reference ref, float a) {
	Vector *v = dynamic_cast<Vector*>(ref.getEntity());
	ref = newVector(v->vectorType());
	Vector *u = dynamic_cast<Vector*>(ref.getEntity());

	for (tlint index = v->minIndex(); index <= v->maxIndex(); index++) {
		u->set(index, v->get(index) * a);
	}

	return ref;
}

Reference MatrixFactory::cross(Reference v, Reference u) {
	dismissNull(v);
	dismissNull(u);
	argumentTypeCheck(v, Vector::type());
	argumentTypeCheck(u, Vector::type());

	if (v.getEntity()->instanceof(Vec3::type())
		&& u.getEntity()->instanceof(Vec3::type())) {
		Vec3 *v1 = dynamic_cast<Vec3*>(v.getEntity());
		Vec3 *u1 = dynamic_cast<Vec3*>(u.getEntity());

		vec3 v2 = v1->values();
		vec3 u2 = u1->values();

		vec3 result = cross_vec3(v2, u2);
		return Reference(new Vec3(result));
	}

	if (v.getEntity()->instanceof(Vec4::type())
		&& u.getEntity()->instanceof(Vec4::type())) {
		Vec4 *v1 = dynamic_cast<Vec4*>(v.getEntity());
		Vec4 *u1 = dynamic_cast<Vec4*>(u.getEntity());

		vec4 v2 = v1->values();
		vec4 u2 = u1->values();

		vec3 result = cross_vec3(to_cartesian(v2), to_cartesian(u2));

		return Reference(new Vec3(result));
	}

	throw UndefinedException();
}

vec3 MatrixFactory::cross_vec3(vec3 v, vec3 u) {
	return {v.y * u.z - v.z * u.y, -(v.x * u.z - v.z * u.x), v.x
		* u.y - v.y * u.x};
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
		throw UnacceptableArgumentException();
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
		throw UnacceptableArgumentException();
	}

	return ref;
}

Reference MatrixFactory::multiply(Reference m1, Reference m2) {
	dismissNull(m1);
	dismissNull(m2);
	argumentTypeCheck(m1, AbstractMatrix::type());
	argumentTypeCheck(m2, AbstractMatrix::type());

	if (m1.getEntity()->instanceof(Vector::type())) {
		if (m2.getEntity()->instanceof(Vector::type())) {
			return Reference(new Vec(dot(m1, m2)));
		}

		if (m2.getEntity()->instanceof(Matrix::type())) {
			return vmMultiply0(m1, m2);
		}
	}

	if (m1.getEntity()->instanceof(Matrix::type())) {
		if (m2.getEntity()->instanceof(Vector::type())) {
			return mvMultiply0(m1, m2);
		}

		if (m2.getEntity()->instanceof(Matrix::type())) {
			return mmMultiply0(m1, m2);
		}
	}

	//cast an exception
	throw UndefinedException();
}

Reference MatrixFactory::mmMultiply0(Reference m, Reference n) {
	Matrix *m0 = dynamic_cast<Matrix*>(m.getEntity());
	Matrix *n0 = dynamic_cast<Matrix*>(n.getEntity());

	if (m0->maxColumnIndex() != n0->maxRowIndex()) {
		throw IncompatibleMatrixTypeException();
	}

	Reference result = newMatrix(m0->maxRowIndex(), n0->maxColumnIndex());
	Matrix *r = dynamic_cast<Matrix*>(result.getEntity());
	for (tlint row = m0->minRowIndex(); row <= m0->maxRowIndex(); row++) {
		for (tlint col = n0->minColumnIndex(); col <= n0->maxColumnIndex();
			col++) {
			r->set(row, col, dot(m0->getRow(row), n0->getColumn(col)));
		}
	}

	return result;
}

Reference MatrixFactory::mvMultiply0(Reference m, Reference v) {
	Matrix *m0 = dynamic_cast<Matrix*>(m.getEntity());
	Vector *v0 = dynamic_cast<Vector*>(v.getEntity());

	if (m0->maxColumnIndex() != v0->maxIndex()) {
		throw IncompatibleMatrixTypeException();
	}

	Reference result = newVector(m0->maxRowIndex());
	Vector *r = dynamic_cast<Vector*>(result.getEntity());
	for (tlint index = m0->minRowIndex(); index <= m0->maxRowIndex(); index++) {
		r->set(index, dot(m0->getRow(index), v));
	}

	return result;
}

Reference MatrixFactory::vmMultiply0(Reference v, Reference m) {
	Vector *v0 = dynamic_cast<Vector*>(v.getEntity());
	Matrix *m0 = dynamic_cast<Matrix*>(m.getEntity());

	if (v0->maxIndex() != m0->maxColumnIndex()) {
		throw IncompatibleMatrixTypeException();
	}

	Reference result = newVector(m0->maxColumnIndex());
	Vector *r = dynamic_cast<Vector*>(result.getEntity());

	for (tlint index = r->minIndex(); index <= r->maxIndex(); index++) {
		r->set(index, dot(m0->getColumn(index), v));
	}

	return result;
}

Reference MatrixFactory::add(Reference m1, Reference m2) {
	dismissNull(m1);
	dismissNull(m2);
	argumentTypeCheck(m1, AbstractMatrix::type());
	argumentTypeCheck(m2, AbstractMatrix::type());

	if (m1.getEntity()->instanceof(Matrix::type())
		&& m2.getEntity()->instanceof(Matrix::type())) {
		return mAdd0(m1, m2);
	}

	if (m1.getEntity()->instanceof(Vector::type())
		&& m2.getEntity()->instanceof(Vector::type())) {
		return vAdd0(m1, m2);
	}

	throw UnacceptableArgumentException();
}

Reference MatrixFactory::vAdd0(Reference v, Reference u) {
	Vector *v0 = dynamic_cast<Vector*>(v.getEntity());
	Vector *u0 = dynamic_cast<Vector*>(u.getEntity());

	if (v0->vectorType() != u0->vectorType()) {
		throw IncompatibleMatrixTypeException();
	}

	Reference result = newVector(v0->vectorType());
	Vector *r = dynamic_cast<Vector*>(result.getEntity());
	for (tlint index = v0->minIndex(); index <= v0->maxIndex(); index++) {
		r->set(index, v0->get(index) + u0->get(index));
	}

	return result;
}

Reference MatrixFactory::mAdd0(Reference m, Reference n) {
	Matrix *m0 = dynamic_cast<Matrix*>(m.getEntity());
	Matrix *n0 = dynamic_cast<Matrix*>(n.getEntity());

	if (m0->matrixType() != n0->matrixType()) {
		throw IncompatibleMatrixTypeException();
	}

	Reference result = newMatrix(m0->matrixType());
	Matrix *r = dynamic_cast<Matrix*>(result.getEntity());

	for (tlint row = m0->minRowIndex(); row <= m0->maxRowIndex(); row++) {
		r->setRow(row, vAdd0(m0->getRow(row), n0->getRow(row)));
	}

	return result;
}

Reference MatrixFactory::minus(Reference m1, Reference m2) {
	dismissNull(m1);
	dismissNull(m2);
	argumentTypeCheck(m1, AbstractMatrix::type());
	argumentTypeCheck(m2, AbstractMatrix::type());

	if (m1.getEntity()->instanceof(Matrix::type())
		&& m2.getEntity()->instanceof(Matrix::type())) {
		return mMinus0(m1, m2);
	}

	if (m1.getEntity()->instanceof(Vector::type())
		&& m2.getEntity()->instanceof(Vector::type())) {
		return vMinus0(m1, m2);
	}

	throw UnacceptableArgumentException();
}

Reference MatrixFactory::vMinus0(Reference v, Reference u) {
	Vector *v0 = dynamic_cast<Vector*>(v.getEntity());
	Vector *u0 = dynamic_cast<Vector*>(u.getEntity());

	if (v0->vectorType() != u0->vectorType()) {
		throw IncompatibleMatrixTypeException();
	}

	Reference result = newVector(v0->vectorType());
	Vector *r = dynamic_cast<Vector*>(result.getEntity());
	for (tlint index = r->minIndex(); index <= r->maxIndex(); index++) {
		r->set(index, v0->get(index) - u0->get(index));
	}

	return result;
}

Reference MatrixFactory::mMinus0(Reference m, Reference n) {
	Matrix *m0 = dynamic_cast<Matrix*>(m.getEntity());
	Matrix *n0 = dynamic_cast<Matrix*>(n.getEntity());

	if (m0->matrixType() != n0->matrixType()) {
		throw IncompatibleMatrixTypeException();
	}

	Reference result = newMatrix(m0->matrixType());
	Matrix *r = dynamic_cast<Matrix*>(result.getEntity());
	for (tlint index = r->minRowIndex(); index <= r->maxRowIndex(); index++) {
		r->setRow(index, vMinus0(m0->getRow(index), n0->getRow(index)));
	}

	return result;
}

Reference MatrixFactory::normalize(Reference m) {
	dismissNull(m);
	argumentTypeCheck(m, Vector::type());

	Vector *v = dynamic_cast<Vector*>(m.getEntity());
	float mod = 0;
	for (tlint index = v->minIndex(); index <= v->maxIndex(); index++) {
		mod += (v->get(index) * v->get(index));
	}
	mod = lang::Math::sqrt(mod);
	return scale(m, 1.0 / mod);
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
