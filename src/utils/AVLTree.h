/*
 * AVLTree.h
 *
 *  Created on: Oct 15, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_UTILS_AVLTREE_H_
#define SRC_UTILS_AVLTREE_H_

#include "../lang/Object.h"
#include "../lang/Reference.h"
#include "../lang/Comparable.h"

namespace tl {
namespace utils {

using tl::lang::Reference;
using tl::lang::Comparable;
class AVLTree: public lang::Object {
private:
	class Node {
	private:
		const static tlint ALLOW_IMBALANCE;
		Reference mValue;
		tlint mHeight;
		Node *mLeft;
		Node *mRight;
		static Reference findMininum(Node*);
	public:
		Node(const Reference&);
		Node(const Reference&, Node*, Node*);
		static tlint getHeight(Node*);
		static Node* balance(Node*);
		static Node* leftRotate(Node*);
		static Node* rightRotate(Node*);
		static Node* leftRightRotate(Node*);
		static Node* rightLeftRotate(Node*);
		static Node* insert(Node*, const Reference&);
		static Node* remove(Node*, const Reference&);
		Reference& getValue();
	};
public:
	AVLTree();
	~AVLTree();
	AVLTree(const AVLTree &other) = delete;
	void contains(const Reference&);
	void insert(const Reference&);
	void remove(const Reference&);
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_AVLTREE_H_ */
