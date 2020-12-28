/*
 * Set.h
 *
 *  Created on: Nov, 11, 2020
 *      Author: Yoolatbec
 */

#ifndef SRC_UTILS_SET_H_
#define SRC_UTILS_SET_H_

#include "Collection.h"

namespace tl {
namespace utils {

class Set: public Collection {
private:
	const static type_t CLASS_SERIAL = 500;
protected:
	class Entry: public Object{
	private:
		const static type_t CLASS_SERIAL = 81;
	public:
		Reference mValue;
		Entry();
	};
public:
	Set(type_t);
	virtual ~Set();
	Set(const Set &other) = delete;
	Set& operator=(const Set &other) = delete;
	virtual bool instanceof(type_t);
	static type_t type();
};


} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_SET_H_ */
