################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/thread/Condition.cpp \
../src/thread/Mutex.cpp \
../src/thread/Thread.cpp \
../src/thread/ThreadAttribute.cpp 

OBJS += \
./src/thread/Condition.o \
./src/thread/Mutex.o \
./src/thread/Thread.o \
./src/thread/ThreadAttribute.o 

CPP_DEPS += \
./src/thread/Condition.d \
./src/thread/Mutex.d \
./src/thread/Thread.d \
./src/thread/ThreadAttribute.d 


# Each subdirectory must supply rules for building sources it contributes
src/thread/%.o: ../src/thread/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -fPIC -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


