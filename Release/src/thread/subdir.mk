################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/thread/Condition.cpp \
../src/thread/ErrorChecker.cpp \
../src/thread/FailedToExecuteException.cpp \
../src/thread/Function.cpp \
../src/thread/IllegalOperationException.cpp \
../src/thread/Key.cpp \
../src/thread/Mutex.cpp \
../src/thread/MutexAttribute.cpp \
../src/thread/Thread.cpp \
../src/thread/ThreadAttribute.cpp \
../src/thread/ThreadException.cpp \
../src/thread/ThreadOnceController.cpp 

OBJS += \
./src/thread/Condition.o \
./src/thread/ErrorChecker.o \
./src/thread/FailedToExecuteException.o \
./src/thread/Function.o \
./src/thread/IllegalOperationException.o \
./src/thread/Key.o \
./src/thread/Mutex.o \
./src/thread/MutexAttribute.o \
./src/thread/Thread.o \
./src/thread/ThreadAttribute.o \
./src/thread/ThreadException.o \
./src/thread/ThreadOnceController.o 

CPP_DEPS += \
./src/thread/Condition.d \
./src/thread/ErrorChecker.d \
./src/thread/FailedToExecuteException.d \
./src/thread/Function.d \
./src/thread/IllegalOperationException.d \
./src/thread/Key.d \
./src/thread/Mutex.d \
./src/thread/MutexAttribute.d \
./src/thread/Thread.d \
./src/thread/ThreadAttribute.d \
./src/thread/ThreadException.d \
./src/thread/ThreadOnceController.d 


# Each subdirectory must supply rules for building sources it contributes
src/thread/%.o: ../src/thread/%.cpp src/thread/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++17 -I"/home/yoolatbec/workspace/cpp/ToolLibrary/include" -O3 -Wall -c -fmessage-length=0 -fPIC -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


