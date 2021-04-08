################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/lang/Array.cpp \
../src/lang/Boolean.cpp \
../src/lang/BooleanArray.cpp \
../src/lang/Byte.cpp \
../src/lang/ByteArray.cpp \
../src/lang/CharSequence.cpp \
../src/lang/Cloneable.cpp \
../src/lang/Comparable.cpp \
../src/lang/Double.cpp \
../src/lang/DoubleArray.cpp \
../src/lang/Exception.cpp \
../src/lang/Float.cpp \
../src/lang/FloatArray.cpp \
../src/lang/IllegalArgumentException.cpp \
../src/lang/IllegalArgumentTypeException.cpp \
../src/lang/IndexOutOfBoundsException.cpp \
../src/lang/IntArray.cpp \
../src/lang/Integer.cpp \
../src/lang/Long.cpp \
../src/lang/LongArray.cpp \
../src/lang/Math.cpp \
../src/lang/MemoryLimitExceededException.cpp \
../src/lang/NOArray.cpp \
../src/lang/NullPointerException.cpp \
../src/lang/Number.cpp \
../src/lang/Object.cpp \
../src/lang/Pointer.cpp \
../src/lang/Reference.cpp \
../src/lang/Runnable.cpp \
../src/lang/Short.cpp \
../src/lang/ShortArray.cpp \
../src/lang/String.cpp \
../src/lang/StringBuilder.cpp \
../src/lang/System.cpp \
../src/lang/Throwable.cpp \
../src/lang/UndefinedException.cpp \
../src/lang/UnsupportedOperationException.cpp 

OBJS += \
./src/lang/Array.o \
./src/lang/Boolean.o \
./src/lang/BooleanArray.o \
./src/lang/Byte.o \
./src/lang/ByteArray.o \
./src/lang/CharSequence.o \
./src/lang/Cloneable.o \
./src/lang/Comparable.o \
./src/lang/Double.o \
./src/lang/DoubleArray.o \
./src/lang/Exception.o \
./src/lang/Float.o \
./src/lang/FloatArray.o \
./src/lang/IllegalArgumentException.o \
./src/lang/IllegalArgumentTypeException.o \
./src/lang/IndexOutOfBoundsException.o \
./src/lang/IntArray.o \
./src/lang/Integer.o \
./src/lang/Long.o \
./src/lang/LongArray.o \
./src/lang/Math.o \
./src/lang/MemoryLimitExceededException.o \
./src/lang/NOArray.o \
./src/lang/NullPointerException.o \
./src/lang/Number.o \
./src/lang/Object.o \
./src/lang/Pointer.o \
./src/lang/Reference.o \
./src/lang/Runnable.o \
./src/lang/Short.o \
./src/lang/ShortArray.o \
./src/lang/String.o \
./src/lang/StringBuilder.o \
./src/lang/System.o \
./src/lang/Throwable.o \
./src/lang/UndefinedException.o \
./src/lang/UnsupportedOperationException.o 

CPP_DEPS += \
./src/lang/Array.d \
./src/lang/Boolean.d \
./src/lang/BooleanArray.d \
./src/lang/Byte.d \
./src/lang/ByteArray.d \
./src/lang/CharSequence.d \
./src/lang/Cloneable.d \
./src/lang/Comparable.d \
./src/lang/Double.d \
./src/lang/DoubleArray.d \
./src/lang/Exception.d \
./src/lang/Float.d \
./src/lang/FloatArray.d \
./src/lang/IllegalArgumentException.d \
./src/lang/IllegalArgumentTypeException.d \
./src/lang/IndexOutOfBoundsException.d \
./src/lang/IntArray.d \
./src/lang/Integer.d \
./src/lang/Long.d \
./src/lang/LongArray.d \
./src/lang/Math.d \
./src/lang/MemoryLimitExceededException.d \
./src/lang/NOArray.d \
./src/lang/NullPointerException.d \
./src/lang/Number.d \
./src/lang/Object.d \
./src/lang/Pointer.d \
./src/lang/Reference.d \
./src/lang/Runnable.d \
./src/lang/Short.d \
./src/lang/ShortArray.d \
./src/lang/String.d \
./src/lang/StringBuilder.d \
./src/lang/System.d \
./src/lang/Throwable.d \
./src/lang/UndefinedException.d \
./src/lang/UnsupportedOperationException.d 


# Each subdirectory must supply rules for building sources it contributes
src/lang/%.o: ../src/lang/%.cpp src/lang/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++17 -I"/home/yoolatbec/workspace/cpp/ToolLibrary/include" -O3 -Wall -c -fmessage-length=0 -fPIC -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


