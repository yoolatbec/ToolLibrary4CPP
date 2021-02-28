################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/net/Inet4Address.cpp \
../src/net/InetAddress.cpp \
../src/net/Socket.cpp \
../src/net/TCPServer.cpp \
../src/net/TCPSocket.cpp \
../src/net/UDPSocket.cpp 

OBJS += \
./src/net/Inet4Address.o \
./src/net/InetAddress.o \
./src/net/Socket.o \
./src/net/TCPServer.o \
./src/net/TCPSocket.o \
./src/net/UDPSocket.o 

CPP_DEPS += \
./src/net/Inet4Address.d \
./src/net/InetAddress.d \
./src/net/Socket.d \
./src/net/TCPServer.d \
./src/net/TCPSocket.d \
./src/net/UDPSocket.d 


# Each subdirectory must supply rules for building sources it contributes
src/net/%.o: ../src/net/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -fPIC -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


