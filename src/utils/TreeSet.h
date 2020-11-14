/*
 * TreeSet.h
 *
 *  Created on: Nov, 11, 2020
 *      Author: Yoolatbec
 */

#ifndef SRC_UTILS_TREESET_H_
#define SRC_UTILS_TREESET_H_

#include "Set.h"
#include "LinkedList.h"

namespace tl {
namespace utils {

class TreeSet: public Set {
private:
	const static hash_t CLASS_HASH = 501L << 32;

	class TreeNode: public Object{
		friend class TreeSet;
	private:
		const static hash_t CLASS_HASH = 502L << 32;
		Reference mValue;
		tlint mHeight;
		Reference mLeft;
		Reference mRight;
		TreeNode(const Reference& ref){
			mValue = ref;
			mHeight = 0;
		}
	};

	Reference root;
public:
	TreeSet(hash_t);
	virtual ~TreeSet();
	TreeSet(const TreeSet &other) = delete;
	TreeSet& operator=(const TreeSet &other) = delete;
	bool add(const Reference&);
	bool addAll(const Reference&);
	bool contains(const Reference&) const;
	bool containsAll(const Reference&) const;
	bool empty() const;
	Iterator iterator();
	ConstantIterator constantIterator();
	bool remove(const Reference&);
	bool removeAll(const Reference&);
	bool instanceof(hash_t) const;
	hash_t getElementType() const;
	static hash_t getType();
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_TREESET_H_ */
