################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/lang/Array.cpp \
../src/lang/Boolean.cpp \
../src/lang/Byte.cpp \
../src/lang/Cloneable.cpp \
../src/lang/Comparable.cpp \
../src/lang/Double.cpp \
../src/lang/Exception.cpp \
../src/lang/Float.cpp \
../src/lang/FloatArray.cpp \
../src/lang/IllegalArgumentTypeException.cpp \
../src/lang/IntArray.cpp \
../src/lang/Integer.cpp \
../src/lang/Long.cpp \
../src/lang/Math.cpp \
../src/lang/MemoryLimitExceededException.cpp \
../src/lang/NOArray.cpp \
../src/lang/Number.cpp \
../src/lang/Object.cpp \
../src/lang/Pointer.cpp \
../src/lang/Reference.cpp \
../src/lang/Runnable.cpp \
../src/lang/Short.cpp \
../src/lang/String.cpp \
../src/lang/StringBuilder.cpp \
../src/lang/UnacceptableArgumentException.cpp \
../src/lang/UndefinedException.cpp 

OBJS += \
./src/lang/Array.o \
./src/lang/Boolean.o \
./src/lang/Byte.o \
./src/lang/Cloneable.o \
./src/lang/Comparable.o \
./src/lang/Double.o \
./src/lang/Exception.o \
./src/lang/Float.o \
./src/lang/FloatArray.o \
./src/lang/IllegalArgumentTypeException.o \
./src/lang/IntArray.o \
./src/lang/Integer.o \
./src/lang/Long.o \
./src/lang/Math.o \
./src/lang/MemoryLimitExceededException.o \
./src/lang/NOArray.o \
./src/lang/Number.o \
./src/lang/Object.o \
./src/lang/Pointer.o \
./src/lang/Reference.o \
./src/lang/Runnable.o \
./src/lang/Short.o \
./src/lang/String.o \
./src/lang/StringBuilder.o \
./src/lang/UnacceptableArgumentException.o \
./src/lang/UndefinedException.o 

CPP_DEPS += \
./src/lang/Array.d \
./src/lang/Boolean.d \
./src/lang/Byte.d \
./src/lang/Cloneable.d \
./src/lang/Comparable.d \
./src/lang/Double.d \
./src/lang/Exception.d \
./src/lang/Float.d \
./src/lang/FloatArray.d \
./src/lang/IllegalArgumentTypeException.d \
./src/lang/IntArray.d \
./src/lang/Integer.d \
./src/lang/Long.d \
./src/lang/Math.d \
./src/lang/MemoryLimitExceededException.d \
./src/lang/NOArray.d \
./src/lang/Number.d \
./src/lang/Object.d \
./src/lang/Pointer.d \
./src/lang/Reference.d \
./src/lang/Runnable.d \
./src/lang/Short.d \
./src/lang/String.d \
./src/lang/StringBuilder.d \
./src/lang/UnacceptableArgumentException.d \
./src/lang/UndefinedException.d 


# Each subdirectory must supply rules for building sources it contributes
src/lang/%.o: ../src/lang/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -fPIC -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


