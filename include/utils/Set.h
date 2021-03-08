/*
 * Set.h
 *
 *  Created on: Nov, 11, 2020
 *      Author: Yoolatbec
 */

#ifndef INCLUDE_UTILS_SET_H_
#define INCLUDE_UTILS_SET_H_

#include <utils/Collection.h>

namespace tl {
namespace utils {

class Set: public virtual Collection {
private:
	const static type_t CLASS_SERIAL = 500;
//protected:
//	class Entry: public virtual Object {
//	private:
//		const static type_t CLASS_SERIAL = 81;
//	protected:
//		Reference mValue;
//	public:
//		Entry();
//		Entry(const Entry&) = delete;
//		Entry& operator=(const Entry&) = delete;
//		Reference value();
//		static type_t type();
//		bool instanceof(type_t);
//	};
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

#endif /* INCLUDE_UTILS_SET_H_ */
