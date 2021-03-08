/*
 * Exception.cpp
 *
 *  Created on: Sep 18, 2020
 *      Author: yoolatbec
 */

#include <lang/Exception.h>

namespace tl {
namespace lang {

using lang::Reference;

Exception::Exception() {
	// TODO Auto-generated constructor stub

	mHashCode = genHashCode(CLASS_SERIAL);
}

Exception::Exception(Reference ref) {

}

Exception::~Exception() {
	// TODO Auto-generated destructor stub
}

} /* namespace lang */
} /* namespace tl */
