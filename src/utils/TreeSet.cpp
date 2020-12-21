/*
 * TreeSet.cpp
 *
 *  Created on: Nov, 11, 2020
 *      Author: Yoolatbec
 */

#include "TreeSet.h"
#include "LinkedList.h"

namespace tl {
namespace utils {

TreeSet::TreeSet(hash_t type)
	:Set(type){
	// TODO Auto-generated constructor stub
	mHash = (mHash & INSTANCE_MASK) + CLASS_HASH;

	root = Reference(nullptr);
}

TreeSet::~TreeSet() {
	// TODO Auto-generated destructor stub
}

TreeSet::TreeNode::TreeNode(const Reference& ref){
	mHash = (mHash & INSTANCE_MASK) + CLASS_HASH;

	mValue = ref;
	mWeight = ref.getEntity()->mHash;
	mHeight = 0;
	mLeft = Reference();
	mRight = Reference();
}

tlint TreeSet::TreeNode::getHeight(const Reference& ref){
	TreeNode* node = dynamic_cast<TreeNode*>(ref.getEntity());
	if(node == nullptr){
		return -1;
	}

	return node->mHeight;
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

	LinkedList* stack = new LinkedList(TreeNode::getType());
	Reference currentNode = root;
	while(!currentNode.isNull()){
		stack->addLast(currentNode);
		TreeNode* node = dynamic_cast<TreeNode*>(currentNode.getEntity());
		if(node->mValue.getEntity()->mHash == ref.getEntity()->mHash){
			return false;
		}

		if(node->mValue.getEntity()->mHash < ref.getEntity()->mHash){
			currentNode = node->mLeft;
		} else {
			currentNode = node->mRight;
		}
	}

	currentNode = Reference(new TreeNode(ref));
	stack->addLast(currentNode);
	while(stack->size() > 1){
		Reference child = stack->getLast();
		stack->removeLast();
		TreeNode* parent = dynamic_cast<TreeNode*>(stack->getLast().getEntity());

	}

	return true;
}

} /* namespace utils */
} /* namespace tl */
