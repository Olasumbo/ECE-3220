################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Lab\ 1C.cpp 

OBJS += \
./src/Lab\ 1C.o 

CPP_DEPS += \
./src/Lab\ 1C.d 


# Each subdirectory must supply rules for building sources it contributes
src/Lab\ 1C.o: ../src/Lab\ 1C.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Lab 1C.d" -MT"src/Lab\ 1C.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


