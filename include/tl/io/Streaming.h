/*
 * Streaming.h
 *
 *  Created on: Mar 25, 2021
 *      Author: yoolatbec
 */

#ifndef TL_IO_STREAMING_H_
#define TL_IO_STREAMING_H_

#include <tl/lang/Reference.h>

namespace tl {
namespace io {

using lang::Reference;

class Streaming: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 489;
protected:
	Streaming();

	Reference mInputStream;
	Reference mOutputStream;
public:
	virtual ~Streaming();
	Streaming(const Streaming &other) = delete;
	Streaming& operator=(const Streaming &other) = delete;
	virtual Reference openInputStream();
	virtual Reference openOutputStream();
	static type_t type();
	virtual bool instanceof(type_t);
};

} /* namespace io */
} /* namespace tl */

#endif /* TL_IO_STREAMING_H_ */
