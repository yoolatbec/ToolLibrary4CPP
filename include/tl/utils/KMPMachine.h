/*
 * KMPMachine.h
 *
 *  Created on: Mar 7, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_UTILS_KMPMACHINE_H_
#define INCLUDE_UTILS_KMPMACHINE_H_

#include <tl/lang/Reference.h>

namespace tl {
namespace utils {

using lang::Reference;

class KMPMachine: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 2450;

	Reference mPattern;
	tlint mLength;
	tlint* mTable[256];

	KMPMachine(Reference);

	void generateTable();
	tlint match0(Reference, tlint);
	tlint matchLast0(Reference, tlint);
public:
	virtual ~KMPMachine();
	KMPMachine(const KMPMachine &other) = delete;
	KMPMachine& operator=(const KMPMachine &other) = delete;
	static Reference newInstance(Reference);
	tlint matchLast(Reference, tlint = 0);
	tlint match(Reference, tlint = 0);
	Reference getPattern();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace utils */
} /* namespace tl */

#endif /* INCLUDE_UTILS_KMPMACHINE_H_ */
