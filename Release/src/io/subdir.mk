################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/io/AbstractFile.cpp \
../src/io/Closeable.cpp \
../src/io/Directory.cpp \
../src/io/FailedToOpenFileException.cpp \
../src/io/File.cpp \
../src/io/IOException.cpp \
../src/io/IllegalStreamException.cpp \
../src/io/InputStream.cpp \
../src/io/InputStreamReader.cpp \
../src/io/OutputStream.cpp \
../src/io/OutputStreamWriter.cpp \
../src/io/Reader.cpp \
../src/io/ReopenStreamException.cpp \
../src/io/SimultaneousReadWriteException.cpp \
../src/io/Streaming.cpp \
../src/io/Writer.cpp 

OBJS += \
./src/io/AbstractFile.o \
./src/io/Closeable.o \
./src/io/Directory.o \
./src/io/FailedToOpenFileException.o \
./src/io/File.o \
./src/io/IOException.o \
./src/io/IllegalStreamException.o \
./src/io/InputStream.o \
./src/io/InputStreamReader.o \
./src/io/OutputStream.o \
./src/io/OutputStreamWriter.o \
./src/io/Reader.o \
./src/io/ReopenStreamException.o \
./src/io/SimultaneousReadWriteException.o \
./src/io/Streaming.o \
./src/io/Writer.o 

CPP_DEPS += \
./src/io/AbstractFile.d \
./src/io/Closeable.d \
./src/io/Directory.d \
./src/io/FailedToOpenFileException.d \
./src/io/File.d \
./src/io/IOException.d \
./src/io/IllegalStreamException.d \
./src/io/InputStream.d \
./src/io/InputStreamReader.d \
./src/io/OutputStream.d \
./src/io/OutputStreamWriter.d \
./src/io/Reader.d \
./src/io/ReopenStreamException.d \
./src/io/SimultaneousReadWriteException.d \
./src/io/Streaming.d \
./src/io/Writer.d 


# Each subdirectory must supply rules for building sources it contributes
src/io/%.o: ../src/io/%.cpp src/io/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++17 -I"/home/yoolatbec/workspace/cpp/ToolLibrary/include" -O3 -Wall -c -fmessage-length=0 -fPIC -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


