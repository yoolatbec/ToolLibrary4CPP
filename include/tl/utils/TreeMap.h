/*
 * TreeMap.h
 *
 *  Created on: Apr 18, 2021
 *      Author: yoolatbec
 */

#ifndef TL_UTILS_TREEMAP_H_
#define TL_UTILS_TREEMAP_H_

#include <tl/utils/SortedMap.h>

namespace tl {
namespace utils {

class TreeMap: public virtual SortedMap {
private:
	const static type_t CLASS_SERIAL = 1039;

	class TreeNode: public virtual Map::Entry {
	private:
		const static type_t CLASS_SERIAL = 1040;
		Reference mParent;
		Reference mLeft;
		Reference mRight;

	public:
		TreeNode(type_t, Reference, type_t, Reference);
		TreeNode(const TreeNode&) = delete;
		TreeNode& operator=(const TreeNode&) = delete;
		~TreeNode();
		Reference getParent();
		void setParent(Reference);
		Reference getLeft();
		void setLeft(Reference);
		Reference getRight();
		void setRight(Reference);
		static type_t type();
		bool instanceof(type_t);
	};

	Reference mRoot;

	void clear0(Reference);
	void add0(Reference, Reference);
	void remove0(Reference, Reference);
	Reference successor0(Reference);
	Reference predecessor0(Reference);
public:
	TreeMap(type_t, type_t, Reference);
	virtual ~TreeMap();
	TreeMap(const TreeMap &other) = delete;
	TreeMap& operator=(const TreeMap &other) = delete;
	Reference ceilingEntry(Reference);
	Reference ceilingKey(Reference);
	void clear();
	bool containsKey(Reference);
	bool containsValue(Reference);
	bool contains(Reference, Reference);
	Reference entrySet();
	Reference firstEntry();
	Reference firstKey();
	Reference floorEntry(Reference);
	Reference floorKey(Reference);
	Reference get(Reference);
	Reference higherEntry(Reference);
	Reference higherKey(Reference);
	Reference keySet();
	Reference lastEntry();
	Reference lastKey();
	Reference lowerEntry(Reference);
	Reference lowerKey(Reference);
	Reference pollFirstEntry();
	Reference pollLastEntry();
	Reference put(Reference, Reference);
	void putAll(Reference);
	Reference putIfAbsent(Reference, Reference);
	Reference remove(Reference);
	Reference remove(Reference, Reference);
	Reference sortedKeySet();
	Reference values();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace utils */
} /* namespace tl */

#endif /* TL_UTILS_TREEMAP_H_ */
