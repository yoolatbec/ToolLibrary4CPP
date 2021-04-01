/*
 * TextStreaming.h
 *
 *  Created on: Mar 26, 2021
 *      Author: yoolatbec
 */

#ifndef TL_IO_TEXTSTREAMING_H_
#define TL_IO_TEXTSTREAMING_H_

#include <tl/io/Streaming.h>

namespace tl {
namespace io {

class TextStreaming: public virtual Streaming {
private:
	const static type_t CALSS_SERIAL = 598;
	TextStreaming();
public:
	virtual ~TextStreaming();
	TextStreaming(const TextStreaming &other) = delete;
	TextStreaming& operator=(const TextStreaming &other) = delete;
	virtual Reference getReader();
	virtual Reference getWriter();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace io */
} /* namespace tl */

#endif /* TL_IO_TEXTSTREAMING_H_ */
