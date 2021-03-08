/*
 * Comparator.h
 *
 *  Created on: 29 Jan 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_UTILS_COMPARATOR_H_
#define INCLUDE_UTILS_COMPARATOR_H_

#include <lang/Reference.h>

namespace tl {
namespace utils {

using lang::Reference;

class Comparator: public lang::Object {
public:
	Comparator();
	virtual ~Comparator();
	Comparator(const Comparator &other) = delete;
	Comparator& operator=(const Comparator &other) = delete;
};

} /* namespace utils */
} /* namespace tl */

#endif /* INCLUDE_UTILS_COMPARATOR_H_ */
