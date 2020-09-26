/*
 * String.h
 *
 *  Created on: Sep 9, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_STRING_H_
#define SRC_LANG_STRING_H_

#include "Reference.h"

namespace tl {
namespace lang {

class String : public Object{
private:
	char* mStr;
	size_t mLength;
	hash_t genHash();
public:
	String();
	explicit String(const char*);
	String(size_t, char);
	String(const String &other);
	virtual ~String();
	String append(const String&) const;
	String append(char) const;
	String append(int) const;
	String append(double) const;
	char charAt(size_t) const;
	String substring(size_t) const;
	String substring(size_t, size_t) const;
	Reference split(char) const;
	Reference split(const String&) const;
	const char* getCharacters() const;
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_STRING_H_ */
