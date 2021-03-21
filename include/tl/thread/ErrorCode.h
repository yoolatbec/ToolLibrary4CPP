/*
 * ErrorCode.h
 *
 *  Created on: Mar 15, 2021
 *      Author: yoolatbec
 */

#ifndef TL_THREAD_ERRORCODE_H_
#define TL_THREAD_ERRORCODE_H_

#include <pthread.h>
#include <asm/errno.h>

namespace tl{
namespace thread{

enum ErrorCode{
	SUCCESS = 0,
	INVALID_ARGUMENT = EINVAL,
	PERMANENT = EPERM,
	NO_SUCH_PROCESS = ESRCH,
	DEADLOCK = EDEADLK,
	AGAIN = EAGAIN,
	OUT_OF_MEMORY = ENOMEM
};

}
}



#endif /* TL_THREAD_ERRORCODE_H_ */
