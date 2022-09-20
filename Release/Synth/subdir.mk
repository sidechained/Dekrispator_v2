################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Synth/MIDI_application.c \
../Synth/audio_conf.c \
../Synth/main.c \
../Synth/random.c \
../Synth/soundGen.c \
../Synth/stm32f4xx_it.c \
../Synth/system_stm32f4xx.c \
../Synth/timers.c \
../Synth/usbh_conf.c 

S_UPPER_SRCS += \
../Synth/startup_stm32f407xx.S 

OBJS += \
./Synth/MIDI_application.o \
./Synth/audio_conf.o \
./Synth/main.o \
./Synth/random.o \
./Synth/soundGen.o \
./Synth/startup_stm32f407xx.o \
./Synth/stm32f4xx_it.o \
./Synth/system_stm32f4xx.o \
./Synth/timers.o \
./Synth/usbh_conf.o 

S_UPPER_DEPS += \
./Synth/startup_stm32f407xx.d 

C_DEPS += \
./Synth/MIDI_application.d \
./Synth/audio_conf.d \
./Synth/main.d \
./Synth/random.d \
./Synth/soundGen.d \
./Synth/stm32f4xx_it.d \
./Synth/system_stm32f4xx.d \
./Synth/timers.d \
./Synth/usbh_conf.d 


# Each subdirectory must supply rules for building sources it contributes
Synth/%.o: ../Synth/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	$(ARM_PATH)arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O3 -ffunction-sections -fdata-sections -fsingle-precision-constant -flto -Wunused -Wuninitialized -Wall -Wconversion -Wshadow -Wfloat-equal -D__FPU_USED=1 -DHSE_VALUE=8000000 -DUSE_HAL_DRIVER -DUSE_STM32F4_DISCO -DSTM32F407xx -I.././drivers/STM32_USB_Host_Library/Core/Inc -I../drivers/BSP -I../drivers/cmsis -I../drivers/STM32F4xx_HAL_Driver/Inc -I../Synth -I../drivers/USBH_midi_class/Inc -std=c11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Synth/%.o: ../Synth/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU Assembler'
	$(ARM_PATH)arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O3 -ffunction-sections -fdata-sections -fsingle-precision-constant -flto -Wunused -Wuninitialized -Wall -Wconversion -Wshadow -Wfloat-equal -x assembler-with-cpp -DSTM32F40_41xxx -D__FPU_USED=1 -DHSE_VALUE=8000000 -DSTM32F407VG -DUSE_HAL_DRIVER -DUSE_STM32F4_DISCO -DSTM32F407xx -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


