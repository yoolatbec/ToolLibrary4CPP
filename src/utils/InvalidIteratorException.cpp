/*
 * InvalidIteratorException.cpp
 *
 *  Created on: Feb 26, 2021
 *      Author: yoolatbec
 */

#include <utils/InvalidIteratorException.h>

namespace tl {
namespace utils {

using lang::Reference;
using lang::Exception;

InvalidIteratorException::InvalidIteratorException() {
	// TODO Auto-generated constructor stub

}

InvalidIteratorException::InvalidIteratorException(Reference ref)
	: Exception(ref) {

}

InvalidIteratorException::~InvalidIteratorException() {
	// TODO Auto-generated destructor stub
}

} /* namespace utils */
} /* namespace tl */
