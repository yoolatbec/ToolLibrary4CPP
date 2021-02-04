/*
 * String.h
 *
 *  Created on: Sep 9, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_STRING_H_
#define SRC_LANG_STRING_H_

#include "../utils/ArrayList.h"
#include "Comparable.h"

namespace tl {
namespace lang {

class String : public Comparable{
private:
	const static type_t CLASS_SERIAL = 9;
	char* mStr;
	size_t mLength;
	hash_t genHashCode();
public:
	String();
	explicit String(const char*);
	String(size_t, char);
	String(Reference);
	String(const String&) = delete;
	String& operator=(String) = delete;
	~String();
	Reference append(Reference);
	Reference append(byte);
	Reference append(tlint);
	Reference append(tlint64);
	Reference append(double);
	tlint charAt(size_t);
	tlint compareTo(Reference);
	Reference substring(size_t length);
	Reference substring(size_t start, size_t length);
	Reference split(byte);
	Reference split(Reference);
	Reference toUpperCase();
	Reference toLowerCase();
	Reference toString();
	Reference valueOf(tlint);
	Reference valueOf(float);
	Reference valueOf(double);
	Reference valueOf(char);
	Reference valueOf(bool);
	Reference valueOf(Reference);
	const byte* bytes();
	bool instanceof(type_t);
	static type_t type();
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_STRING_H_ */
