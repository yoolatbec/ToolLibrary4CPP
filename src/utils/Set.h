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

class Set: public virtual Collection {
private:
	const static type_t CLASS_SERIAL = 500;
protected:
	class SetIterator: public Iterator {
	private:
		const static type_t CLASS_SERIAL = 501;
		Reference mSet;
	public:
		SetIterator(Reference);
		bool hasNext() = 0;
		bool hasPrevious() = 0;
		virtual Reference next() = 0;
		virtual Reference previous() = 0;
		void remove();
	};

	class Entry: public Object {
	private:
		const static type_t CLASS_SERIAL = 81;
		Reference mValue;
	public:
		Entry();
		Reference value();
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
