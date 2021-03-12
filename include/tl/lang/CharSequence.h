/*
 * CharSequence.h
 *
 *  Created on: Mar 8, 2021
 *      Author: yoolatbec
 */

#ifndef TL_LANG_CHARSEQUENCE_H_
#define TL_LANG_CHARSEQUENCE_H_

#include <tl/lang/Reference.h>

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


	hash_t genHashCode(type_t);

	void indexBoundCheck(tlint);
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

#endif /* TL_LANG_CHARSEQUENCE_H_ */
