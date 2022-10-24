ARM_PATH=/Applications/ArmGNUToolchain/11.3.rel1/arm-none-eabi/bin/
FAUST_PATH=/Applications/Faust-2.41.1/
# ../drivers/STM32_USB_Host_Library/Core/Src/
# ../drivers/STM32F4xx_HAL_Driver/Src/
# ../drivers/BSP/
# ../Synth/

INCS = \
-I.././drivers/STM32_USB_Host_Library/Core/Inc \
-I../drivers/BSP \
-I../drivers/cmsis \
-I../drivers/STM32F4xx_HAL_Driver/Inc \
-I../drivers \
-I../drivers/USBH_midi_class/Inc \
-I../Synth \
-I$(FAUST_PATH)include/faust/gui

# DRIVERS - Root

S_UPPER_SRCS += \
../drivers/startup_stm32f407xx.S 

C_SRCS += \
../drivers/usbh_conf.c \
../drivers/stm32f4xx_it.c \
../drivers/system_stm32f4xx.c \
../drivers/timers.c \

OBJS += \
./drivers/usbh_conf.o \
./drivers/stm32f4xx_it.o \
./drivers/system_stm32f4xx.o \
./drivers/startup_stm32f407xx.o \
./drivers/timers.o \

S_UPPER_DEPS += \
./drivers/startup_stm32f407xx.d 

C_DEPS += \
./drivers/usbh_conf.d \
./drivers/stm32f4xx_it.d \
./drivers/system_stm32f4xx.d \
./drivers/timers.d \

drivers/%.o: ../drivers/%.c
	$(ARM_PATH)arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O3 -ffunction-sections -fdata-sections -fsingle-precision-constant -flto -Wunused -Wuninitialized -Wall -Wconversion -Wshadow -Wfloat-equal -D__FPU_USED=1 -DHSE_VALUE=8000000 -DUSE_HAL_DRIVER -DUSE_STM32F4_DISCO -DSTM32F407xx $(INCS) -std=c11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"

drivers/%.o: ../drivers/%.S
	$(ARM_PATH)arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O3 -ffunction-sections -fdata-sections -fsingle-precision-constant -flto -Wunused -Wuninitialized -Wall -Wconversion -Wshadow -Wfloat-equal -x assembler-with-cpp -DSTM32F40_41xxx -D__FPU_USED=1 -DHSE_VALUE=8000000 -DSTM32F407VG -DUSE_HAL_DRIVER -DUSE_STM32F4_DISCO -DSTM32F407xx -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"

# DRIVERS - USBH_midi_class
C_SRCS += ../drivers/USBH_midi_class/Src/usbh_MIDI.c 
OBJS += ./drivers/USBH_midi_class/Src/usbh_MIDI.o 
C_DEPS += ./drivers/USBH_midi_class/Src/usbh_MIDI.d 

drivers/USBH_midi_class/Src/%.o: ../drivers/USBH_midi_class/Src/%.c
	$(ARM_PATH)arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O3 -ffunction-sections -fdata-sections -fsingle-precision-constant -flto -Wunused -Wuninitialized -Wall -Wconversion -Wshadow -Wfloat-equal -D__FPU_USED=1 -DHSE_VALUE=8000000 -DUSE_HAL_DRIVER -DUSE_STM32F4_DISCO -DSTM32F407xx $(INCS) -std=c11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"

# DRIVERS - STM32_USB_Host_Library
C_SRCS += \
../drivers/STM32_USB_Host_Library/Core/Src/usbh_core.c \
../drivers/STM32_USB_Host_Library/Core/Src/usbh_ctlreq.c \
../drivers/STM32_USB_Host_Library/Core/Src/usbh_ioreq.c \
../drivers/STM32_USB_Host_Library/Core/Src/usbh_pipes.c 

OBJS += \
./drivers/STM32_USB_Host_Library/Core/Src/usbh_core.o \
./drivers/STM32_USB_Host_Library/Core/Src/usbh_ctlreq.o \
./drivers/STM32_USB_Host_Library/Core/Src/usbh_ioreq.o \
./drivers/STM32_USB_Host_Library/Core/Src/usbh_pipes.o 

C_DEPS += \
./drivers/STM32_USB_Host_Library/Core/Src/usbh_core.d \
./drivers/STM32_USB_Host_Library/Core/Src/usbh_ctlreq.d \
./drivers/STM32_USB_Host_Library/Core/Src/usbh_ioreq.d \
./drivers/STM32_USB_Host_Library/Core/Src/usbh_pipes.d 

drivers/STM32_USB_Host_Library/Core/Src/%.o: ../drivers/STM32_USB_Host_Library/Core/Src/%.c
	$(ARM_PATH)arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O3 -ffunction-sections -fdata-sections -fsingle-precision-constant -flto -Wunused -Wuninitialized -Wall -Wconversion -Wshadow -Wfloat-equal -D__FPU_USED=1 -DHSE_VALUE=8000000 -DUSE_HAL_DRIVER -DUSE_STM32F4_DISCO -DSTM32F407xx $(INCS) -std=c11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"

# DRIVERS - STM32F4xx_HAL_Driver
C_SRCS += \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc_ex.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_can.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_crc.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cryp.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cryp_ex.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dac.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dac_ex.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dcmi.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma2d.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_eth.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_hash.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_hash_ex.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_hcd.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c_ex.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2s.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2s_ex.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_irda.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_iwdg.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_ltdc.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_msp_template.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_nand.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_nor.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pccard.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd_ex.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rng.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rtc.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rtc_ex.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sai.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sd.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sdram.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_smartcard.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spi.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sram.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_usart.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_wwdg.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fmc.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fsmc.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_sdmmc.c \
../drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usb.c 

OBJS += \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc_ex.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_can.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_crc.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cryp.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cryp_ex.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dac.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dac_ex.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dcmi.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma2d.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_eth.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_hash.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_hash_ex.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_hcd.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c_ex.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2s.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2s_ex.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_irda.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_iwdg.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_ltdc.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_msp_template.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_nand.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_nor.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pccard.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd_ex.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rng.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rtc.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rtc_ex.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sai.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sd.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sdram.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_smartcard.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spi.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sram.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_usart.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_wwdg.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fmc.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fsmc.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_sdmmc.o \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usb.o 

C_DEPS += \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc_ex.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_can.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_crc.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cryp.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cryp_ex.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dac.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dac_ex.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dcmi.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma2d.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_eth.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_hash.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_hash_ex.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_hcd.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c_ex.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2s.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2s_ex.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_irda.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_iwdg.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_ltdc.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_msp_template.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_nand.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_nor.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pccard.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd_ex.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rng.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rtc.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rtc_ex.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sai.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sd.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sdram.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_smartcard.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spi.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sram.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_usart.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_wwdg.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fmc.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fsmc.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_sdmmc.d \
./drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usb.d 

drivers/STM32F4xx_HAL_Driver/Src/%.o: ../drivers/STM32F4xx_HAL_Driver/Src/%.c
	$(ARM_PATH)arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O3 -ffunction-sections -fdata-sections -fsingle-precision-constant -flto -Wunused -Wuninitialized -Wall -Wconversion -Wshadow -Wfloat-equal -D__FPU_USED=1 -DHSE_VALUE=8000000 -DUSE_HAL_DRIVER -DUSE_STM32F4_DISCO -DSTM32F407xx $(INCS) -std=c11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"

# DRIVERS - BSP
C_SRCS += \
../drivers/BSP/cs43l22.c \
../drivers/BSP/lis302dl.c \
../drivers/BSP/lis3dsh.c \
../drivers/BSP/stm32f4_discovery.c \
../drivers/BSP/stm32f4_discovery_accelerometer.c \
../drivers/BSP/stm32f4_discovery_audio.c 

OBJS += \
./drivers/BSP/cs43l22.o \
./drivers/BSP/lis302dl.o \
./drivers/BSP/lis3dsh.o \
./drivers/BSP/stm32f4_discovery.o \
./drivers/BSP/stm32f4_discovery_accelerometer.o \
./drivers/BSP/stm32f4_discovery_audio.o 

C_DEPS += \
./drivers/BSP/cs43l22.d \
./drivers/BSP/lis302dl.d \
./drivers/BSP/lis3dsh.d \
./drivers/BSP/stm32f4_discovery.d \
./drivers/BSP/stm32f4_discovery_accelerometer.d \
./drivers/BSP/stm32f4_discovery_audio.d 

drivers/BSP/%.o: ../drivers/BSP/%.c
	$(ARM_PATH)arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O3 -ffunction-sections -fdata-sections -fsingle-precision-constant -flto -Wunused -Wuninitialized -Wall -Wconversion -Wshadow -Wfloat-equal -D__FPU_USED=1 -DHSE_VALUE=8000000 -DUSE_HAL_DRIVER -DUSE_STM32F4_DISCO -DSTM32F407xx $(INCS) -std=c11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"

# SYNTH
C_SRCS += \
../Synth/MIDI_application.c \
../Synth/audio_conf.c \
../Synth/main.c \
../Synth/soundGen.c \

OBJS += \
./Synth/MIDI_application.o \
./Synth/audio_conf.o \
./Synth/main.o \
./Synth/soundGen.o \

C_DEPS += \
./Synth/MIDI_application.d \
./Synth/audio_conf.d \
./Synth/main.d \
./Synth/soundGen.d \

Synth/%.o: ../Synth/%.c
	$(ARM_PATH)arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O3 -ffunction-sections -fdata-sections -fsingle-precision-constant -flto -Wunused -Wuninitialized -Wall -Wconversion -Wshadow -Wfloat-equal -D__FPU_USED=1 -DHSE_VALUE=8000000 -DUSE_HAL_DRIVER -DUSE_STM32F4_DISCO -DSTM32F407xx $(INCS) -std=c11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"

# OBJECTS

ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif

all: generateMidiCode Faust2STMSynth.elf Faust2STMSynth.bin Faust2STMSynth.lst Faust2STMSynth.siz

generateMidiCode:
	python ../Synth/midi_mapping_codegen.py

cleanMidiCode:
	rm ../Synth/MIDI_application_CCs.c ../Synth/soundGen_sliderSetters.c

Faust2STMSynth.elf: $(OBJS)
	$(ARM_PATH)arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O3 -ffunction-sections -fdata-sections -fsingle-precision-constant -flto -Wunused -Wuninitialized -Wall -Wconversion -Wshadow -Wfloat-equal -T "../drivers/STM32F407VG_FLASH.ld" -Xlinker --gc-sections -Wl,-Map,"Faust2STMSynth.map" --specs=nosys.specs -o "Faust2STMSynth.elf" $(OBJS) -lm -lc -lg

Faust2STMSynth.bin: Faust2STMSynth.elf
	$(ARM_PATH)arm-none-eabi-objcopy -O binary "Faust2STMSynth.elf"  "Faust2STMSynth.bin"

Faust2STMSynth.lst: Faust2STMSynth.elf
	$(ARM_PATH)arm-none-eabi-objdump --source --all-headers --demangle --line-numbers --wide "Faust2STMSynth.elf" > "Faust2STMSynth.lst"

Faust2STMSynth.siz: Faust2STMSynth.elf
	$(ARM_PATH)arm-none-eabi-size --format=berkeley --totals "Faust2STMSynth.elf"

# Other Targets
clean: cleanMidiCode
	-rm -rf $(OBJS) Faust2STMSynth.bin Faust2STMSynth.lst Faust2STMSynth.siz $(S_UPPER_DEPS)$(C_DEPS) Faust2STMSynth.elf
	
flash:
	st-flash write Faust2STMSynth.bin 0x8000000

.PHONY: all clean dependents