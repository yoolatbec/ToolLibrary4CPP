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

class TreeMap: public virtual Map {
private:
	const static type_t CLASS_SERIAL = 54;
	class TreeEntry: public Entry{
	private:
		const static type_t CLASS_SERIAL = 55;
	public:
		Reference mLeft, mRight;
		size_t mHeight;
		TreeEntry(Reference, Reference);
		static type_t type();
		bool instanceof(type_t);
		static TreeEntry add(Reference, Reference);
		static TreeEntry remove(Reference);
		static TreeEntry replace(Reference, Reference);
		static bool containsKey(Reference);
		static bool containsValue(Reference);
	};
	Reference mRootEntry;

public:
	TreeMap(type_t, type_t);
	virtual ~TreeMap();
	TreeMap(const TreeMap &other) = delete;
	TreeMap& operator=(const TreeMap &other) = delete;
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_TREEMAP_H_ */
