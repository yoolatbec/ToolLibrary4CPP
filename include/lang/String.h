/*
 * String.h
 *
 *  Created on: Sep 9, 2020
 *      Author: yoolatbec
 */

#ifndef INCLUDE_LANG_STRING_H_
#define INCLUDE_LANG_STRING_H_

#include <lang/CharSequence.h>
#include <lang/Comparable.h>
#include <utils/ArrayList.h>

namespace tl {
namespace lang {

class String : public virtual Comparable, public virtual CharSequence{
private:
	const static type_t CLASS_SERIAL = 9;

	static Reference sBlankString;

	String();
public:
	explicit String(const char*);
	String(tlint, char);
	String(Reference);
	String(const String&) = delete;
	String& operator=(String) = delete;
	~String();
	Reference append(Reference);
	Reference append(char);
	Reference append(tlint);
	Reference append(tlint64);
	Reference append(double);
	tlint compareTo(Reference);
	bool contains(Reference);
	tlint indexOf(Reference, tlint = 0);
	tlint lastIndexOf(Reference, tlint = 0);
//	Reference replace(Reference, Reference);
	Reference replace(char, char);
	Reference substring(tlint length);
	Reference substring(tlint start, tlint length);
	Reference split(char);
	Reference split(Reference);
	Reference toUpperCase();
	Reference toLowerCase();
	Reference toString();
	static Reference blank();
	bool instanceof(type_t);
	static type_t type();
};

} /* namespace lang */
} /* namespace tl */

#endif /* INCLUDE_LANG_STRING_H_ */
