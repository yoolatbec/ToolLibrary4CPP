/*
 * String.h
 *
 *  Created on: Sep 9, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_STRING_H_
#define SRC_LANG_STRING_H_

#include "../utils/List.h"
#include "Comparable.h"

namespace tl {
namespace lang {

using tl::utils::List;
class String : public Comparable{
private:
	const static hash_t CLASS_HASH = 9L << 32;
	byte* mStr;
	size_t mLength;
	hash_t genHash();
public:
	String();
	explicit String(const byte*);
	String(size_t, byte);
	String(const String *other);
	String(const String&) = delete;
	String& operator=(const String&) = delete;
	~String();
	String* append(const String*) const;
	String* append(byte) const;
	String* append(tlint) const;
	String* append(tlint64) const;
	String* append(double) const;
	tlint charAt(size_t) const;
	tlint compareTo(const String*) const;
	String* substring(size_t length) const;
	String* substring(size_t start, size_t length) const;
	List* split(byte) const;
	List* split(const String*) const;
	const byte* bytes() const;
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_STRING_H_ */
