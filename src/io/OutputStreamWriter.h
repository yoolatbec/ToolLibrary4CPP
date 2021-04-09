/*
 * OutputStreamWriter.h
 *
 *  Created on: Apr 9, 2021
 *      Author: yoolatbec
 */

#ifndef IO_OUTPUTSTREAMWRITER_H_
#define IO_OUTPUTSTREAMWRITER_H_

#include "Writer.h"

namespace tl {
namespace io {

class OutputStreamWriter: public virtual Writer {
public:
	OutputStreamWriter();
	virtual ~OutputStreamWriter();
	OutputStreamWriter(const OutputStreamWriter &other) = delete;
	OutputStreamWriter& operator=(const OutputStreamWriter &other) = delete;
};

} /* namespace io */
} /* namespace tl */

#endif /* IO_OUTPUTSTREAMWRITER_H_ */
