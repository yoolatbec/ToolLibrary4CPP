/*
 * BarrierAttribute.h
 *
 *  Created on: Mar 21, 2021
 *      Author: yoolatbec
 */

#ifndef THREAD_BARRIERATTRIBUTE_H_
#define THREAD_BARRIERATTRIBUTE_H_

#include <tl/lang/Object.h>
#include <pthread.h>

namespace tl {
namespace thread {

class BarrierAttribute: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 2458;

	pthread_barrierattr_t mAttribute;
public:
	BarrierAttribute();
	virtual ~BarrierAttribute();
	BarrierAttribute(const BarrierAttribute &other) = delete;
	BarrierAttribute& operator=(const BarrierAttribute &other) = delete;
	pthread_barrierattr_t* getAttribute();
	void setShared(bool);
	bool isShared();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace thread */
} /* namespace tl */

#endif /* THREAD_BARRIERATTRIBUTE_H_ */
