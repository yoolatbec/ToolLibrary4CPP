/*
 * Encryptor.h
 *
 *  Created on: Mar 21, 2021
 *      Author: yoolatbec
 */

#ifndef UTILS_ENCRYPTOR_H_
#define UTILS_ENCRYPTOR_H_

#include <tl/lang/Object.h>

namespace tl {
namespace utils {

class Encryptor: public virtual lang::Object {
public:
	Encryptor();
	virtual ~Encryptor();
	Encryptor(const Encryptor &other) = delete;
	Encryptor& operator=(const Encryptor &other) = delete;
};

} /* namespace utils */
} /* namespace tl */

#endif /* UTILS_ENCRYPTOR_H_ */
