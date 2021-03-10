/*
 * StringBuilder.h
 *
 *  Created on: Jan 18, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_LANG_STRINGBUILDER_H_
#define INCLUDE_LANG_STRINGBUILDER_H_

#include <lang/CharSequence.h>
#include <lang/Object.h>

namespace tl {
namespace lang {

class StringBuilder: public virtual Object, public virtual CharSequence {
public:
	StringBuilder();
	virtual ~StringBuilder();
	StringBuilder(const StringBuilder &other) = delete;
	StringBuilder& operator=(const StringBuilder &other) = delete;
	Reference append(Reference);
	Reference append(char);
	Reference append(tlint);
	Reference append(double);
	Reference append(tlint64);
	Reference append(bool);
	Reference append(const char*, tlint);
	Reference insert(tlint, Reference);
	Reference insert(tlint, char);
	Reference insert(tlint, tlint);
	Reference insert(tlint, double);
	Reference insert(tlint, tlint64);
	Reference insert(tlint, const char*, tlint);
	Reference replace(Reference, Reference);
	Reference replace(char, char);
	Reference reverse();
	void setCharAt(tlint, char);
	Reference substring();
	Reference substring(tlint, tlint);
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* INCLUDE_LANG_STRINGBUILDER_H_ */
