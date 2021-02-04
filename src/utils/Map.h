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
	tlint mSize;
public:
	class Entry: public Object{
		private:
			const static type_t CLASS_SERIAL = 74;
		protected:
			const Reference mKey;
			Reference mValue;
		public:
			Entry(Reference key, Reference value = Reference());
			Reference key();
			Reference value();
			void setValue(Reference);
		};

	Map(type_t, type_t);
	virtual ~Map();
	Map(const Map &other) = delete;
	Map& operator=(const Map &other) = delete;
	virtual bool containsKey(Reference) = 0;
	virtual bool containsValue(Reference) = 0;
	virtual void clear() = 0;
	virtual Reference get(Reference) = 0;
	virtual Reference put(Reference, Reference) = 0;
	virtual void putAll(Reference) = 0;
	virtual Reference putIfAbsent(Reference, Reference) = 0;
	virtual Reference replace(Reference, Reference) = 0;
	virtual Reference remove(Reference) = 0;
	virtual Reference entrySet() = 0;
	tlint size();
	bool isEmpty();
	bool instanceof(type_t);
	static type_t type();
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_MAP_H_ */
