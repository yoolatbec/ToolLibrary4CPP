/*
 * Base64.cpp
 *
 *  Created on: Feb 17, 2021
 *      Author: yoolatbec
 */

#include <tl/utils/Base64.h>
#include <tl/lang/ByteArray.h>

namespace tl {
namespace utils {

using lang::ByteArray;

Base64::Base64() {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

Base64::~Base64() {
	// TODO Auto-generated destructor stub
}

Reference Base64::encode(Reference input) {
	argumentTypeCheck(input, ByteArray::type());
	ByteArray *array = dynamic_cast<ByteArray*>(input.getEntity());

	tlint inputSize = array->size();
	tlint outputSize = ((inputSize - 1 + ENCODE_SEGMENT_SIZE)
		/ ENCODE_SEGMENT_SIZE) * DECODE_SEGMENT_SIZE;

	Reference output = ByteArray::newInstance(outputSize);
	ByteArray *outputArray = dynamic_cast<ByteArray*>(output.getEntity());

	tlint currentInput = 0;
	tlint currentOutput = 0;

	tlint maxSegment = inputSize / ENCODE_SEGMENT_SIZE;
	byte tmp;
	byte b;
	for (tlint segment = 0; segment < maxSegment; segment++) {
		b = array->get(currentInput);
		currentInput++;
		tmp = b >> 2;
		outputArray->set(currentOutput, (byte)ENCODE_TABLE(tmp));
		currentOutput++;

		tmp = (b << 6) >> 2;
		b = array->get(currentInput);
		currentInput++;
		tmp |= b >> 4;
		outputArray->set(currentOutput, (byte)ENCODE_TABLE(tmp));
		currentOutput++;

		tmp = (b << 4) >> 2;
		b = array->get(currentInput);
		currentInput++;
		tmp |= b >> 6;
		outputArray->set(currentOutput, (byte)ENCODE_TABLE(tmp));
		currentOutput++;

		tmp = (b << 2) >> 2;
		outputArray->set(currentOutput, (byte)ENCODE_TABLE(tmp));
		currentOutput++;
	}

	switch (inputSize - currentInput) {
	case 2:
		b = array->get(currentInput);
		currentInput++;
		tmp = b >> 2;
		outputArray->set(currentOutput, (byte)ENCODE_TABLE(tmp));
		currentOutput++;

		tmp = (b << 6) >> 2;
		b = array->get(currentInput);
		currentInput++;
		tmp |= b >> 4;
		outputArray->set(currentOutput, (byte)ENCODE_TABLE(tmp));
		currentOutput++;

		tmp = (b << 4) >> 2;
		outputArray->set(currentOutput, (byte)ENCODE_TABLE(tmp));
		currentOutput++;

		outputArray->set(currentOutput, (byte)'=');
		break;
	case 1:
		b = array->get(currentInput);
		currentInput++;
		tmp = b >> 2;
		outputArray->set(currentOutput, (byte)ENCODE_TABLE(tmp));
		currentOutput++;

		tmp = (b << 6) >> 2;
		outputArray->set(currentOutput, (byte)ENCODE_TABLE(tmp));
		currentOutput++;

		outputArray->set(currentOutput, (byte)'=');
		currentOutput++;

		outputArray->set(currentOutput, (byte)'=');
		currentOutput++;
		break;
	default:
		break;
	}

	return output;
}

Reference Base64::decode(Reference input) {
	argumentTypeCheck(input, ByteArray::type());

	ByteArray *array = dynamic_cast<ByteArray*>(input.getEntity());
	tlint inputSize = array->size();

	if (inputSize % DECODE_SEGMENT_SIZE != 0) {
		//cast an exception
	}
	tlint maxSegment = inputSize / DECODE_SEGMENT_SIZE;
	tlint outputSize = maxSegment * ENCODE_SEGMENT_SIZE;

	Reference output = ByteArray::newInstance(outputSize, 0);
	ByteArray *outputArray = dynamic_cast<ByteArray*>(output.getEntity());

	tlint currentInput = 0;
	tlint currentOutput = 0;
	byte b;
	byte tmp;
	for (tlint segment = 0; segment < maxSegment; segment++) {
		b = array->get(currentInput);
		currentInput++;
		decodeCheck(b);
		tmp = DECODE_TABLE[b] << 2;

		b = array->get(currentInput);
		currentInput++;
		decodeCheck(b);
		tmp |= (DECODE_TABLE[b] >> 4);
		outputArray->set(currentOutput, tmp);
		currentOutput++;

		tmp = (DECODE_TABLE[b] << 4);
		b = array->get(currentInput);
		currentInput++;
		if (b == (byte)'=') {
			break;
		}
		decodeCheck(b);
		tmp |= (DECODE_TABLE[b] >> 2);
		outputArray->set(currentOutput, tmp);
		currentOutput++;

		tmp = (DECODE_TABLE[b] << 6);
		b = array->get(currentInput);
		if (b == (byte)'=') {
			break;
		}
		decodeCheck(b);
		tmp |= b;
		outputArray->set(currentOutput, tmp);
		currentOutput++;
	}

	return output;
}

void Base64::decodeCheck(byte b){
	if(b < 0 || b >= 64){
		//cast an exception
	}
}

type_t Base64::type() {
	return CLASS_SERIAL;
}

bool Base64::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
