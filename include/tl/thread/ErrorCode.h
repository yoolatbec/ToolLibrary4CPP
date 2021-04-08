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
	PERMISSION = EPERM,
	NO_SUCH_THREAD = ESRCH,
	DEADLOCK = EDEADLK,
	LIMIT_EXCEEDED = EAGAIN,
	OUT_OF_MEMORY = ENOMEM,
	TIMEDOUT =  ETIMEDOUT,
	DEAD_OWNER = EOWNERDEAD,
	IRRECOVERABLE = ENOTRECOVERABLE,
};

}
}



#endif /* TL_THREAD_ERRORCODE_H_ */
