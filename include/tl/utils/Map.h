/*
 * Map.h
 *
 *  Created on: Apr 18, 2021
 *      Author: yoolatbec
 */

#ifndef TL_UTILS_MAP_H_
#define TL_UTILS_MAP_H_

#include <tl/lang/Reference.h>

namespace tl {
namespace utils {

using lang::Reference;

class Map: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 1037;
protected:
	type_t mKeyType;
	type_t mValueType;
	tlint mSize;

	Map(type_t keyType, type_t valueType);
public:
	class Entry: public virtual lang::Object {
	private:
		const static type_t CLASS_SERIAL = 1038;
	protected:
		type_t mKeyType;
		type_t mValueType;
		Reference mKey;
		Reference mValue;
	public:
		Entry(type_t, Reference, type_t, Reference);
		Entry(const Entry&) = delete;
		Entry& operator=(const Entry&) = delete;
		~Entry();
		Reference key();
		type_t keyType();
		Reference setValue(Reference);
		Reference value();
		type_t valueType();
		static type_t type();
		bool instanceof(type_t);
	};

	virtual ~Map();
	Map(const Map &other) = delete;
	Map& operator=(const Map &other) = delete;
	virtual void clear() = 0;
	virtual bool contains(Reference, Reference) = 0;
	virtual bool containsKey(Reference) = 0;
	virtual bool containsValue(Reference) = 0;
	virtual Reference entrySet() = 0;
	virtual Reference get() = 0;
	bool isEmpty();
	type_t keyType();
	virtual Reference keySet() = 0;
	virtual Reference put(Reference k, Reference v) = 0;
	virtual void putAll(Reference) = 0;
	virtual Reference putIfAbsent(Reference, Reference) = 0;
	virtual Reference remove(Reference) = 0;
	virtual Reference remove(Reference, Reference) = 0;
	tlint size();
	virtual Reference values() = 0;
	type_t valueType();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace utils */
} /* namespace tl */

#endif /* TL_UTILS_MAP_H_ */
