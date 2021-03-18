/*
 * Key.h
 *
 *  Created on: Mar 14, 2021
 *      Author: yoolatbec
 */

#ifndef TL_THREAD_KEY_H_
#define TL_THREAD_KEY_H_

#include <tl/lang/Object.h>
#include <pthread.h>

namespace tl {
namespace thread {

using lang::Reference;

class Key: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 809;

	pthread_key_t mKey;

	Key();
	Key(Reference);
public:
	virtual ~Key();
	Key(const Key &other) = delete;
	Key& operator=(const Key &other) = delete;
	static Reference newInstance();
//	static Reference newInstance(Reference);
	void set(Reference);
	Reference get();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace thread */
} /* namespace tl */

#endif /* TL_THREAD_KEY_H_ */
