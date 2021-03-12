/*
 * StringBuilder.h
 *
 *  Created on: Jan 18, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_LANG_STRINGBUILDER_H_
#define INCLUDE_LANG_STRINGBUILDER_H_

#include <tl/lang/CharSequence.h>
#include <tl/lang/Object.h>

namespace tl {
namespace lang {

class StringBuilder: public virtual Object, public virtual CharSequence {
private:
	const static type_t CLASS_SERIAL = 23;

public:
	StringBuilder();
	virtual ~StringBuilder();
	StringBuilder(const StringBuilder &other) = delete;
	StringBuilder& operator=(const StringBuilder &other) = delete;
	void append(Reference);
	void append(char);
	void append(tlint);
	void append(double);
	void append(tlint64);
	void append(bool);
	void append(const char*, tlint);
	void insert(tlint, Reference);
	void insert(tlint, char);
	void insert(tlint, bool);
	void insert(tlint, tlint);
	void insert(tlint, double);
	void insert(tlint, tlint64);
	void insert(tlint, const char*, tlint);
//	void replace(Reference, Reference);
	void replace(char, char);
	void reverse();
	void setCharAt(tlint, char);
	/*
	 *begin inclusive, end exclusive
	 */
	Reference substring(tlint, tlint);
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* INCLUDE_LANG_STRINGBUILDER_H_ */
