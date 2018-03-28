################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Lab\ 1B.cpp 

OBJS += \
./src/Lab\ 1B.o 

CPP_DEPS += \
./src/Lab\ 1B.d 


# Each subdirectory must supply rules for building sources it contributes
src/Lab\ 1B.o: ../src/Lab\ 1B.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Lab 1B.d" -MT"src/Lab\ 1B.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


