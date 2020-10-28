/*
 * AVLTree.cpp
 *
 *  Created on: Oct 15, 2020
 *      Author: yoolatbec
 */

#include "AVLTree.h"

namespace tl {
namespace utils {

AVLTree::AVLTree() {
	// TODO Auto-generated constructor stub

}

AVLTree::~AVLTree() {
	// TODO Auto-generated destructor stub
}

const tlint AVLTree::Node::ALLOW_IMBALANCE = 1;

AVLTree::Node::Node(const Reference &v)
		: mValue(v) {
	mHeight = 0;
	mLeft = nullptr;
	mRight = nullptr;
}

AVLTree::Node::Node(const Reference &v, Node *left, Node *right)
		: mValue(v) {
	mLeft = left;
	mRight = right;

	tlint leftHeight = Node::getHeight(mLeft);
	tlint rightHeight = Node::getHeight(mRight);

	mHeight = leftHeight > rightHeight ? (leftHeight + 1) : (rightHeight + 1);
}

AVLTree::Node* AVLTree::Node::insert(Node *n, const Reference &v) {
	if (n == nullptr) {
		return new AVLTree::Node(v);
	}

	Comparable *c1 = (Comparable*)(mValue.getEntity());
	Comparable *c2 = (Comparable*)(v.getEntity());
	if (c2->compareTo(*c1) < 0) {
		Node::insert(n->mLeft, v);
	} else if (c2->compareTo(*c1) > 0) {
		Node::insert(n->mRight, v);
	} else {
		;
	}

	return balance(n);
}

AVLTree::Node* AVLTree::Node::balance(Node *n) {
	if (n == nullptr) {
		return n;
	}

	if (Node::getHeight(n->mLeft) - Node::getHeight(n->mRight)
			> Node::ALLOW_IMBALANCE) {
		if (Node::getHeight(n->mLeft->mLeft)
				> Node::getHeight(n->mLeft->mRight)) {
			n = Node::rightRotate(n);
		} else {
			n = Node::leftRightRotate(n);
		}
	} else if (Node::getHeight(n->mRight) - Node::getHeight(n->mLeft)
			> Node::ALLOW_IMBALANCE) {
		if (Node::getHeight(n->mRight->mRight)
				> Node::getHeight(n->mRight->mLeft)) {
			n = Node::leftRotate(n);
		} else {
			n = Node::rightLeftRotate(n);
		}
	}

	n->mHeight = max(Node::getHeight(n->mRight), Node::getHeight(n->mLeft)) + 1;
	return n;
}

tlint AVLTree::Node::getHeight(Node* n){
	if(n == nullptr){
		return -1;
	}

	return n->mHeight;
}

AVLTree::Node* AVLTree::Node::leftRotate(Node* n){
	Node* leftChild = n->mLeft;
	n->mLeft = leftChild->mRight;
	leftChild->mRight = n;
	n->mHeight = max(Node::getHeight(n->mLeft), Node::getHeight(n->mRight)) + 1;
	leftChild->mHeight = max(Node::getHeight(leftChild->mLeft), n->mHeight);
	return leftChild;
}

AVLTree::Node* AVLTree::Node::rightRotate(Node* n){
	Node* rightChild = n->mRight;
	n->mRight = rightChild->mLeft;
	rightChild->mLeft = n;
	n->mHeight =  max(Node::getHeight(n->mLeft), Node::getHeight(n->mRight)) + 1;
	rightChild->mHeight = max(n->mHeight, Node::getHeight(rightChild->mRight)) + 1;
	return rightChild;
}

AVLTree::Node* AVLTree::Node::leftRightRotate(Node* n){
	n->mLeft = Node::leftRotate(n->mLeft);
	return Node::rightRotate(n);
}

AVLTree::Node* AVLTree::Node::rightLeftRotate(Node* n){
	n->mRight = Node::rightRotate(n->mRight);
	return Node::leftRotate(n);
}

AVLTree::Node* AVLTree::Node::remove(Node* n, const Reference& v){
	if(n == nullptr){
		return n;
	}


}

} /* namespace utils */
} /* namespace tl */
