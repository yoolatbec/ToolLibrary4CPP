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
	public:
		Reference mLeft, mRight;
		size_t mHeight;
		TreeEntry(Reference, Reference);
		static type_t type();
		bool instanceof(type_t);
		static Reference add(Reference, Reference, Reference);
		static Reference remove(Reference, Reference);
		static Reference replace(Reference, Reference, Reference);
		static bool containsKey(Reference, Reference);
		static bool containsValue(Reference, Reference);
		static Reference balance(Reference);
		static tlint height(Reference);
		static void clear(Reference);
		static Reference rightRotate(Reference);
		static Reference leftRotate(Reference);
		static Reference rightLeftRotate(Reference);
		static Reference leftRightRotate(Reference);
		static Reference findMin(Reference);
		static Reference get(Reference, Reference);
	};
	Reference mRootEntry;

public:
	TreeMap(type_t, type_t);
	virtual ~TreeMap();
	TreeMap(const TreeMap &other) = delete;
	TreeMap& operator=(const TreeMap &other) = delete;
	Reference get(Reference);
	Reference put(Reference, Reference);
	Reference remove(Reference);
	Reference putIfAbsence(Reference, Reference);
	Reference replace(Reference, Reference);
	void clear();
	Set keySet();
	Set values();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_TREEMAP_H_ */
