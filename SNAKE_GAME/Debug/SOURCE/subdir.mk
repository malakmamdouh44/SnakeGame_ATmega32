################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SOURCE/7_SEGMENT_PROGRAM.c \
../SOURCE/BUZZER_PROGRAM.c \
../SOURCE/DIO_PROGRAM.c \
../SOURCE/FUNCTION.c \
../SOURCE/LCD_LM044L_PROGARM.c \
../SOURCE/MAIN.c 

OBJS += \
./SOURCE/7_SEGMENT_PROGRAM.o \
./SOURCE/BUZZER_PROGRAM.o \
./SOURCE/DIO_PROGRAM.o \
./SOURCE/FUNCTION.o \
./SOURCE/LCD_LM044L_PROGARM.o \
./SOURCE/MAIN.o 

C_DEPS += \
./SOURCE/7_SEGMENT_PROGRAM.d \
./SOURCE/BUZZER_PROGRAM.d \
./SOURCE/DIO_PROGRAM.d \
./SOURCE/FUNCTION.d \
./SOURCE/LCD_LM044L_PROGARM.d \
./SOURCE/MAIN.d 


# Each subdirectory must supply rules for building sources it contributes
SOURCE/%.o: ../SOURCE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


