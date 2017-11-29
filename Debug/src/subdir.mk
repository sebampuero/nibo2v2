################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/display.c \
../src/drive.c \
../src/helloMotors.c \
../src/main.c \
../src/n2switchS3.c \
../src/nibo_leds.c \
../src/uart0.c \
../src/xbee.c 

OBJS += \
./src/display.o \
./src/drive.o \
./src/helloMotors.o \
./src/main.o \
./src/n2switchS3.o \
./src/nibo_leds.o \
./src/uart0.o \
./src/xbee.o 

C_DEPS += \
./src/display.d \
./src/drive.d \
./src/helloMotors.d \
./src/main.d \
./src/n2switchS3.d \
./src/nibo_leds.d \
./src/uart0.d \
./src/xbee.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I/home/defaultuser/nibolib/include -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -D_NIBO_2_ -DNIBO_USE_NDS3 -mmcu=atmega128 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


