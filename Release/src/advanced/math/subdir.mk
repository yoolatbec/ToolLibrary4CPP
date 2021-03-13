################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/advanced/math/AbstractMatrix.cpp \
../src/advanced/math/IncompatibleMatrixTypeException.cpp \
../src/advanced/math/Mat1x1.cpp \
../src/advanced/math/Mat1x2.cpp \
../src/advanced/math/Mat1x3.cpp \
../src/advanced/math/Mat1x4.cpp \
../src/advanced/math/Mat2x1.cpp \
../src/advanced/math/Mat2x2.cpp \
../src/advanced/math/Mat2x3.cpp \
../src/advanced/math/Mat2x4.cpp \
../src/advanced/math/Mat3x1.cpp \
../src/advanced/math/Mat3x2.cpp \
../src/advanced/math/Mat3x3.cpp \
../src/advanced/math/Mat3x4.cpp \
../src/advanced/math/Mat4x1.cpp \
../src/advanced/math/Mat4x2.cpp \
../src/advanced/math/Mat4x3.cpp \
../src/advanced/math/Mat4x4.cpp \
../src/advanced/math/Matrix.cpp \
../src/advanced/math/MatrixFactory.cpp \
../src/advanced/math/SquareMatrix.cpp \
../src/advanced/math/Vec.cpp \
../src/advanced/math/Vec2.cpp \
../src/advanced/math/Vec3.cpp \
../src/advanced/math/Vec4.cpp \
../src/advanced/math/Vector.cpp \
../src/advanced/math/mat_func.cpp \
../src/advanced/math/vec_func.cpp 

OBJS += \
./src/advanced/math/AbstractMatrix.o \
./src/advanced/math/IncompatibleMatrixTypeException.o \
./src/advanced/math/Mat1x1.o \
./src/advanced/math/Mat1x2.o \
./src/advanced/math/Mat1x3.o \
./src/advanced/math/Mat1x4.o \
./src/advanced/math/Mat2x1.o \
./src/advanced/math/Mat2x2.o \
./src/advanced/math/Mat2x3.o \
./src/advanced/math/Mat2x4.o \
./src/advanced/math/Mat3x1.o \
./src/advanced/math/Mat3x2.o \
./src/advanced/math/Mat3x3.o \
./src/advanced/math/Mat3x4.o \
./src/advanced/math/Mat4x1.o \
./src/advanced/math/Mat4x2.o \
./src/advanced/math/Mat4x3.o \
./src/advanced/math/Mat4x4.o \
./src/advanced/math/Matrix.o \
./src/advanced/math/MatrixFactory.o \
./src/advanced/math/SquareMatrix.o \
./src/advanced/math/Vec.o \
./src/advanced/math/Vec2.o \
./src/advanced/math/Vec3.o \
./src/advanced/math/Vec4.o \
./src/advanced/math/Vector.o \
./src/advanced/math/mat_func.o \
./src/advanced/math/vec_func.o 

CPP_DEPS += \
./src/advanced/math/AbstractMatrix.d \
./src/advanced/math/IncompatibleMatrixTypeException.d \
./src/advanced/math/Mat1x1.d \
./src/advanced/math/Mat1x2.d \
./src/advanced/math/Mat1x3.d \
./src/advanced/math/Mat1x4.d \
./src/advanced/math/Mat2x1.d \
./src/advanced/math/Mat2x2.d \
./src/advanced/math/Mat2x3.d \
./src/advanced/math/Mat2x4.d \
./src/advanced/math/Mat3x1.d \
./src/advanced/math/Mat3x2.d \
./src/advanced/math/Mat3x3.d \
./src/advanced/math/Mat3x4.d \
./src/advanced/math/Mat4x1.d \
./src/advanced/math/Mat4x2.d \
./src/advanced/math/Mat4x3.d \
./src/advanced/math/Mat4x4.d \
./src/advanced/math/Matrix.d \
./src/advanced/math/MatrixFactory.d \
./src/advanced/math/SquareMatrix.d \
./src/advanced/math/Vec.d \
./src/advanced/math/Vec2.d \
./src/advanced/math/Vec3.d \
./src/advanced/math/Vec4.d \
./src/advanced/math/Vector.d \
./src/advanced/math/mat_func.d \
./src/advanced/math/vec_func.d 


# Each subdirectory must supply rules for building sources it contributes
src/advanced/math/%.o: ../src/advanced/math/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/yoolatbec/workspace/cpp/ToolLibrary/include" -O3 -Wall -c -fmessage-length=0 -fPIC -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


