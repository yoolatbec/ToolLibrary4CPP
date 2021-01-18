/*
 * StringBuilder.h
 *
 *  Created on: Jan 18, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_STRINGBUILDER_H_
#define SRC_LANG_STRINGBUILDER_H_

#include "Object.h"

namespace tl {
namespace lang {

class StringBuilder: public Object {
public:
	StringBuilder();
	virtual ~StringBuilder();
	StringBuilder(const StringBuilder &other) = delete;
	StringBuilder& operator=(const StringBuilder &other) = delete;
	Reference append(Reference);
	Reference append(tlint);
	Reference append(float);
	Reference append(double);
	Reference append(tlint64);
	Reference append(bool);
	Reference prepend(Reference);
	Reference prepend(tlint);
	Reference prepend(float);
	Reference prepend(double);
	Reference prepend(bool);
	Reference prepend(tlint64);
	Reference toString();
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_STRINGBUILDER_H_ */
