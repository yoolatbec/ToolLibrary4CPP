/*
 * CharSequence.h
 *
 *  Created on: Mar 8, 2021
 *      Author: yoolatbec
 */

#ifndef LANG_CHARSEQUENCE_H_
#define LANG_CHARSEQUENCE_H_

#include <lang/Reference.h>

namespace tl {
namespace lang {

using lang::Reference;

class CharSequence: public virtual Object {
private:
	const static type_t CLASS_SERIAL = 20;

protected:
	/*
	 * terminator not included
	 */
	tlint mLength;
	char *mSequence;

	void indexBoundCheck(tlint);
	CharSequence();
	CharSequence(tlint);
public:
	virtual ~CharSequence();
	CharSequence(const CharSequence &other) = delete;
	CharSequence& operator=(const CharSequence &other) = delete;
	tlint length();
	char charAt(tlint);
	virtual Reference toString();
	const char* toCharArray();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* LANG_CHARSEQUENCE_H_ */
