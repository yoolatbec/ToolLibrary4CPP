/*
 * BalancedTreeMap.h
 *
 *  Created on: Apr 22, 2021
 *      Author: yoolatbec
 */

#ifndef UTILS_BALANCEDTREEMAP_H_
#define UTILS_BALANCEDTREEMAP_H_

#include <tl/utils/SortedMap.h>

namespace tl {
namespace utils {

/**
 * AVL-tree based balance tree
 */
class BalancedTreeMap: public virtual SortedMap {
private:
	const static type_t CLASS_SERIAL = 1040;

	class TreeEntry: public virtual Map::Entry {
	private:
		const static type_t CLASS_SERIAL = 1041;

		Reference mLeft;
		Reference mRight;
		Reference mParent;

		tlint mHeight;
	public:
		TreeEntry(type_t, Reference, type_t, Reference);
		TreeEntry(const TreeEntry&) = delete;
		TreeEntry& operator=(const TreeEntry&) = delete;
		~TreeEntry();
		Reference getLeft();
		void setLeft(Reference);
		Reference getRight();
		void setRight(Reference);
		Reference getParent();
		void setParent(Reference);
		tlint getHeight();
		void setHeight(tlint);
		static type_t type();
		bool instanceof(type_t);
	};
public:
	BalancedTreeMap();
	virtual ~BalancedTreeMap();
	BalancedTreeMap(const BalancedTreeMap &other) = delete;
	BalancedTreeMap& operator=(const BalancedTreeMap &other) = delete;
};

} /* namespace utils */
} /* namespace tl */

#endif /* UTILS_BALANCEDTREEMAP_H_ */
