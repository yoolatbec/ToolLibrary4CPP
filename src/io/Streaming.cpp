/*
 * Streaming.cpp
 *
 *  Created on: Mar 25, 2021
 *      Author: yoolatbec
 */

#include <tl/io/Streaming.h>

namespace tl {
namespace io {

Streaming::Streaming() {
	// TODO Auto-generated constructor stub

}

Streaming::~Streaming() {
	// TODO Auto-generated destructor stub
}

type_t Streaming::type() {
	return CLASS_SERIAL;
}

bool Streaming::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace io */
} /* namespace tl */
