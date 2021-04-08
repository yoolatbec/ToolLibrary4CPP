################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/net/DatagramPacket.cpp \
../src/net/Inet4Address.cpp \
../src/net/InetAddress.cpp \
../src/net/NetworkException.cpp \
../src/net/Socket.cpp \
../src/net/SocketException.cpp \
../src/net/TCPServer.cpp \
../src/net/TCPSocket.cpp \
../src/net/UDPSocket.cpp \
../src/net/UnableToOpenSocketException.cpp \
../src/net/UnableToRecognizeAddressException.cpp 

OBJS += \
./src/net/DatagramPacket.o \
./src/net/Inet4Address.o \
./src/net/InetAddress.o \
./src/net/NetworkException.o \
./src/net/Socket.o \
./src/net/SocketException.o \
./src/net/TCPServer.o \
./src/net/TCPSocket.o \
./src/net/UDPSocket.o \
./src/net/UnableToOpenSocketException.o \
./src/net/UnableToRecognizeAddressException.o 

CPP_DEPS += \
./src/net/DatagramPacket.d \
./src/net/Inet4Address.d \
./src/net/InetAddress.d \
./src/net/NetworkException.d \
./src/net/Socket.d \
./src/net/SocketException.d \
./src/net/TCPServer.d \
./src/net/TCPSocket.d \
./src/net/UDPSocket.d \
./src/net/UnableToOpenSocketException.d \
./src/net/UnableToRecognizeAddressException.d 


# Each subdirectory must supply rules for building sources it contributes
src/net/%.o: ../src/net/%.cpp src/net/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++17 -I"/home/yoolatbec/workspace/cpp/ToolLibrary/include" -O3 -Wall -c -fmessage-length=0 -fPIC -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


