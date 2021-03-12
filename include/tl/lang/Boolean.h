/*
 * Boolean.h
 *
 *  Created on: Feb 27, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_LANG_BOOLEAN_H_
#define INCLUDE_LANG_BOOLEAN_H_

#include <tl/lang/Reference.h>

namespace tl {
namespace lang {

class Boolean: public virtual Object {
private:
	const static type_t CLASS_SERIAL = 5;
	static Reference trueValue;
	static Reference falseValue;

	static Reference trueStringValue;
	static Reference falseStringValue;

	const bool mValue;

	Boolean(bool = false);
public:
	virtual ~Boolean();
	Boolean(const Boolean &other) = delete;
	Boolean& operator=(const Boolean &other) = delete;
	bool value();
	Reference valueOf(bool);
	Reference toString();
	static Reference toString(bool);
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* INCLUDE_LANG_BOOLEAN_H_ */
