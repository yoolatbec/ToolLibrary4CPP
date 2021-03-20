/*
 * ConditionAttribute.h
 *
 *  Created on: Mar 20, 2021
 *      Author: yoolatbec
 */

#ifndef TL_THREAD_CONDITIONATTRIBUTE_H_
#define TL_THREAD_CONDITIONATTRIBUTE_H_

#include <tl/lang/Object.h>
#include <pthread.h>

namespace tl {
namespace thread {

using lang::Reference;

class ConditionAttribute: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 244;

	pthread_condattr_t mAttribute;
public:
	ConditionAttribute();
	virtual ~ConditionAttribute();
	ConditionAttribute(const ConditionAttribute &other) = delete;
	ConditionAttribute& operator=(const ConditionAttribute &other) = delete;
	void setShared(bool);
	bool isShared();
	pthread_condattr_t* getValue();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace thread */
} /* namespace tl */

#endif /* TL_THREAD_CONDITIONATTRIBUTE_H_ */
