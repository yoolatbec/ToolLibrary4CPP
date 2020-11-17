/*
 * TreeSet.cpp
 *
 *  Created on: Nov, 11, 2020
 *      Author: Yoolatbec
 */

#include "TreeSet.h"

namespace tl {
namespace utils {

TreeSet::TreeSet(hash_t type)
	:Set(type){
	// TODO Auto-generated constructor stub
	mSize = 0;
}

TreeSet::~TreeSet() {
	// TODO Auto-generated destructor stub
}

TreeSet::TreeNode::TreeNode(const Reference& ref){
	mValue = ref;
	mHeight = 0;
	mLeft = Reference();
	mRight = Reference();
}

bool TreeSet::add(const Reference& ref){
	if(ref.isNull()){
		return false;
	}

	if(!ref.instanceof(mElementType)){
		return false;
	}

	if(root.isNull()){
		root = Reference(new TreeNode(ref));
		return true;
	}

	Reference node = Reference(new TreeNode(ref));
}

} /* namespace utils */
} /* namespace tl */
