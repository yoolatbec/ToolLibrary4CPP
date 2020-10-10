/*
 * String.h
 *
 *  Created on: Sep 9, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_STRING_H_
#define SRC_LANG_STRING_H_

#include "../utils/List.h"

namespace tl {
namespace lang {

using tl::utils::List;
class String : public Object{
private:
	byte* mStr;
	size_t mLength;
	hash_t genHash();
public:
	String();
	explicit String(const byte*);
	String(size_t, byte);
	String(const String &other);
	virtual ~String();
	String* append(const String&) const;
	String* append(byte) const;
	String* append(tlint) const;
	String* append(tlint64) const;
	String* append(double) const;
	char charAt(size_t) const;
	String* substring(size_t) const;
	String* substring(size_t, size_t) const;
	List* split(byte) const;
	List* split(const String&) const;
	const char* getCharacters() const;
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_STRING_H_ */
