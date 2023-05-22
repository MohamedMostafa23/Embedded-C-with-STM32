################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/src/7-seg.c \
../Drivers/src/adc.c \
../Drivers/src/delay.c \
../Drivers/src/gpio.c \
../Drivers/src/interupt.c \
../Drivers/src/lcd.c 

OBJS += \
./Drivers/src/7-seg.o \
./Drivers/src/adc.o \
./Drivers/src/delay.o \
./Drivers/src/gpio.o \
./Drivers/src/interupt.o \
./Drivers/src/lcd.o 

C_DEPS += \
./Drivers/src/7-seg.d \
./Drivers/src/adc.d \
./Drivers/src/delay.d \
./Drivers/src/gpio.d \
./Drivers/src/interupt.d \
./Drivers/src/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/src/%.o: ../Drivers/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F401CCUx -DDEBUG -DSTM32F401xx -I"C:/Users/bedox/workspace/ADC/Drivers/include" -I"C:/Users/bedox/workspace/ADC/inc" -I"C:/Users/bedox/workspace/ADC/CMSIS/device" -I"C:/Users/bedox/workspace/ADC/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


