/*
 * Base64.h
 *
 *  Created on: Feb 17, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_UTILS_BASE64_H_
#define INCLUDE_UTILS_BASE64_H_

#include <lang/Reference.h>

namespace tl {
namespace utils {

class Base64: public virtual lang::Object {
public:
	Base64();
	virtual ~Base64();
	Base64(const Base64 &other) = delete;
	Base64& operator=(const Base64 &other) = delete;
};

} /* namespace utils */
} /* namespace tl */

#endif /* INCLUDE_UTILS_BASE64_H_ */
