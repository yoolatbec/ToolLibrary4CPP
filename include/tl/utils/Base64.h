/*
 * Base64.h
 *
 *  Created on: Feb 17, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_UTILS_BASE64_H_
#define INCLUDE_UTILS_BASE64_H_

#include <tl/lang/Reference.h>

namespace tl {
namespace utils {

using lang::Reference;

class Base64: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 1035;
	const static constexpr byte ENCODE_TABLE[] =
		{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
			'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a',
			'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
			'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0',
			'1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/' };
	const static constexpr byte DECODE_TABLE[] =
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, 62, -1, -1, -1, -1, 63, 52, 53, 54,
			55, 56, 57, 58, 59, 60, 61, -1, -1, -1, 64, -1, -1, -1, 0, 1, 2, 3,
			4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21,
			22, 23, 24, 25, -1, -1, -1, -1, -1, -1, 26, 27, 28, 29, 30, 31, 32,
			33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
			50, 51, -1, -1, -1, -1, -1 };
	const static tlint ENCODE_SEGMENT_SIZE = 3;
	const static tlint DECODE_SEGMENT_SIZE = 4;

	Base64();

	void decodeCheck(byte);
public:
	virtual ~Base64();
	Base64(const Base64 &other) = delete;
	Base64& operator=(const Base64 &other) = delete;
	static Reference encode(Reference);
	static Reference decode(Reference);
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace utils */
} /* namespace tl */

#endif /* INCLUDE_UTILS_BASE64_H_ */
