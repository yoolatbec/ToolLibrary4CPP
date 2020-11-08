/*
 * GenericList.h
 *
 *  Created on: Nov 8, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_UTILS_GENERICLIST_H_
#define SRC_UTILS_GENERICLIST_H_

#include "../lang/Object.h"

namespace tl {
namespace utils {

class GenericList: public virtual lang::Object {
public:
	GenericList();
	virtual ~GenericList();
	GenericList(const GenericList &other) = delete;
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_GENERICLIST_H_ */
