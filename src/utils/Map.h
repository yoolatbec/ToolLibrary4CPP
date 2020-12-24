/*
 * Map.h
 *
 *  Created on: Nov, 11, 2020
 *      Author: Yoolatbec
 */

#ifndef SRC_UTILS_MAP_H_
#define SRC_UTILS_MAP_H_

#include "../lang/Reference.h"
#include "Set.h"

namespace tl {
namespace utils {

using lang::Reference;
class Map: virtual public lang::Object {
private:
	const static type_t CLASS_SERIAL = 73;
protected:
	const type_t mKeyType;
	const type_t mValueType;
	size_t mSize;
	class Entry: public Object{
		private:
			const static type_t CLASS_SERIAL = 74;
		public:
			Entry(Reference key, Reference value = Reference());
			const hash_t mWeight;
			const Reference mKey;
			Reference mValue;
		};
public:
	Map(type_t, type_t);
	virtual ~Map();
	Map(const Map &other) = delete;
	Map& operator=(const Map &other) = delete;
	bool containsKey(Reference) = 0;
	bool containsValue(Reference) = 0;
	void clear() = 0;
	Set keySet() = 0;
	Set values() = 0;
	Reference get(Reference) = 0;
	Reference put(Reference, Reference) = 0;
	Reference putIfAbsent(Reference, Reference) = 0;
	Reference replace(Reference, Reference) = 0;
	Reference remove(Reference) = 0;
	size_t size();
	bool isEmpty();
	bool instanceof(type_t);
	static type_t type();
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_MAP_H_ */
