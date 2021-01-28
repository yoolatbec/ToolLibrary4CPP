/*
 * TreeMap.h
 *
 *  Created on: Nov 16, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_UTILS_TREEMAP_H_
#define SRC_UTILS_TREEMAP_H_

#include "Map.h"

namespace tl {
namespace utils {

using lang::Reference;
class TreeMap: public virtual Map {
private:
	const static type_t CLASS_SERIAL = 54;
	class TreeEntry: public Entry{
	private:
		const static type_t CLASS_SERIAL = 55;
		const static tlint ALLOWED_IMBALANCE = 1;
		Reference mLeft, mRight;
		tlint mWeight;
		tlint mHeight;
	public:
		TreeEntry(Reference, Reference);
		static type_t type();
		bool instanceof(type_t);
		static Reference add(Reference, Reference, Reference);
		static Reference remove(Reference ref, Reference keyRef);
		static Reference replace(Reference, Reference, Reference);
		static bool containsKey(Reference ref, Reference keyRef);
		static bool containsValue(Reference ref, Reference valueRef);
		static Reference balance(Reference);
		static tlint height(Reference);
		static void clear(Reference);
		static Reference minEntry(Reference);
		static Reference maxEntry(Reference);
		static Reference ceilEntry(Reference ref, Reference keyRef);
		static Reference floorEntry(Reference ref, Reference keyRef);
		static Reference rightRotate(Reference);
		static Reference leftRotate(Reference);
		static Reference rightLeftRotate(Reference);
		static Reference leftRightRotate(Reference);
		static Reference get(Reference, Reference);
		static void keys(Reference, Reference);
		static void values(Reference, Reference);
		Reference getLeft();
		Reference getRight();
		tlint getHeight();
	};

	Reference mRootEntry;
	void typeCheck(Reference, type_t);
	void typeCheck(type_t, type_t);
	Reference put0(Reference, Reference);


public:
	TreeMap(type_t, type_t);
	virtual ~TreeMap();
	TreeMap(const TreeMap &other) = delete;
	TreeMap& operator=(const TreeMap &other) = delete;
	Reference get(Reference);
	Reference put(Reference, Reference);
	Reference remove(Reference);
	Reference putIfAbsent(Reference, Reference);
	void putAll(Reference);
	Reference replace(Reference, Reference);
	Reference firstEntry();
	Reference firstKey();
	Reference floorEntry(Reference);
	Reference floorKey(Reference);
	Reference lastEntry();
	Reference lastKey();
	Reference ceilEntry(Reference);
	Reference ceilKey(Reference);
	bool containsKey(Reference);
	bool containsValue(Reference);
	void clear();
	Reference keySet();
	Reference values();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_TREEMAP_H_ */
