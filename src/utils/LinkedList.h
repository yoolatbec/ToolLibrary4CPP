/*
 * LinkedList.h
 *
 *  Created on: Apr 11, 2021
 *      Author: yoolatbec
 */

#ifndef UTILS_LINKEDLIST_H_
#define UTILS_LINKEDLIST_H_

#include "List.h"

namespace tl {
namespace utils {

class LinkedList: public virtual List {
public:
	LinkedList();
	virtual ~LinkedList();
	LinkedList(const LinkedList &other) = delete;
	LinkedList& operator=(const LinkedList &other) = delete;
};

} /* namespace utils */
} /* namespace tl */

#endif /* UTILS_LINKEDLIST_H_ */
