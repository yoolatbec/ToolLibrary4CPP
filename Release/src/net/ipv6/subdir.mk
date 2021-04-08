################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/net/ipv6/Inet6Address.cpp \
../src/net/ipv6/TCPServer.cpp \
../src/net/ipv6/TCPSocket.cpp \
../src/net/ipv6/UDPSocket.cpp 

OBJS += \
./src/net/ipv6/Inet6Address.o \
./src/net/ipv6/TCPServer.o \
./src/net/ipv6/TCPSocket.o \
./src/net/ipv6/UDPSocket.o 

CPP_DEPS += \
./src/net/ipv6/Inet6Address.d \
./src/net/ipv6/TCPServer.d \
./src/net/ipv6/TCPSocket.d \
./src/net/ipv6/UDPSocket.d 


# Each subdirectory must supply rules for building sources it contributes
src/net/ipv6/%.o: ../src/net/ipv6/%.cpp src/net/ipv6/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++17 -I"/home/yoolatbec/workspace/cpp/ToolLibrary/include" -O3 -Wall -c -fmessage-length=0 -fPIC -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


