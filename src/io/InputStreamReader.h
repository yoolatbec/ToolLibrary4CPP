/*
 * InputStreamReader.h
 *
 *  Created on: Apr 9, 2021
 *      Author: yoolatbec
 */

#ifndef IO_INPUTSTREAMREADER_H_
#define IO_INPUTSTREAMREADER_H_

#include "Reader.h"

namespace tl {
namespace io {

class InputStreamReader: public virtual Reader {
public:
	InputStreamReader();
	virtual ~InputStreamReader();
	InputStreamReader(const InputStreamReader &other) = delete;
	InputStreamReader& operator=(const InputStreamReader &other) = delete;
};

} /* namespace io */
} /* namespace tl */

#endif /* IO_INPUTSTREAMREADER_H_ */
