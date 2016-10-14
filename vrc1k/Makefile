#TOOLCHAIN
CROSS_COMPILE  ?= arm-none-eabi-
AS              = $(CROSS_COMPILE)as
LD              = $(CROSS_COMPILE)ld
CC              = $(CROSS_COMPILE)gcc
CPP             = $(CC) -E
AR              = $(CROSS_COMPILE)ar
NM              = $(CROSS_COMPILE)nm
STRIP           = $(CROSS_COMPILE)strip
OBJCOPY         = $(CROSS_COMPILE)objcopy
OBJDUMP         = $(CROSS_COMPILE)objdump
SIZE			= $(CROSS_COMPILE)size

#UPLOAD VARIABLES
PORT?=/dev/ttyUSB0
UPLOAD_TOOL=stm32flash

#SHELL COMMANDS
$(shell mkdir -p bin)
PWD = $(shell pwd)

#TARGETs
TARGET			= main
SRC_TARGET	 	= src/$(TARGET).c
BUILD_TARGET 	= src/$(TARGET).o
BIN_TARGET		= bin/$(TARGET)


#PATH TO STM StdPeriph_Lib
STM_SPL_PATH=Libraries

# C AND ASM FLAGS
INCLUDES += -I$(PWD)/inc/ \
						-ILibraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/ \
						-ILibraries/CMSIS/CM3/CoreSupport/ \
						-ILibraries/STM32F10x_StdPeriph_Driver/inc/ \
						-ILibraries/MDIN3xx/inc/  \
						-ILibraries/MDIN3xx/common/  	\
						-ILibraries/ADV7611/  		\
						-ILibraries/ADV7611/RX/  		\
						-ILibraries/ADV7611/RX/HAL/  		\
						-ILibraries/ADV7611/RX/HAL/5G/  		\
						-ILibraries/ADV7611/RX/HAL/5G/ADV7611/HAL/  		\
						-ILibraries/ADV7611/RX/HAL/5G/ADV7612/HAL/  		\
						-ILibraries/ADV7611/RX/HAL/5G/ADV7612/MACROS/  		\
						-ILibraries/ADV7611/RX/LIB/	


STM_DEFS = -DUSE_STM3210E_EVAL -DSTM32F10X_HD -DUSE_STDPERIPH_DRIVER 
DEBUG= 
DEFINES=
ASFLAGS=-mcpu=cortex-m3 -mthumb 
#CFLAGS=$(INCLUDES) $(STM_DEFS) -Os -Wall -c -fmessage-length=0 -MMD -mcpu=cortex-m3 -mthumb -march=armv7-m $(DEBUG)
CFLAGS=$(INCLUDES) $(STM_DEFS) -Os -Wall -c -fmessage-length=0 -MMD -mcpu=cortex-m3 -mthumb $(DEBUG)

# LINKER SCRIPTS
#LD_SCRIPT=$(STM_SPL_PATH)/stm32_flash.ld
STM_lib=STM32F10x_StdPeriph_Lib
STM_lib_name=lib$(STM_lib).a
LDFLAGS=-T$(LD_SCRIPT) 

#TEST LINKER SCRIPTS
LD_SCRIPT=$(STM_SPL_PATH)/stm32f10x_flash_hd.ld

#OBJECTS FOR CMSIS
C_OBJ += $(STM_SPL_PATH)/CMSIS/CM3/CoreSupport/core_cm3.o
C_OBJ += $(STM_SPL_PATH)/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.o
#C_OBJ += $(STM_SPL_PATH)/CMSIS/CM3/DeviceSupport/ST/STM32F10x/startup/gcc_ride7/startup_stm32f10x_hd.o

#TEST OBJECTS FOR CMSIS
C_OBJ += $(STM_SPL_PATH)/CMSIS/CM3/DeviceSupport/ST/STM32F10x/startup/startup_stm32f10x_hd.o

#OBJECTS FOR STM StdPeriph_Driver (uncomment only what you need)
STMLIB_C_SRCS += misc.c 
STMLIB_C_SRCS += stm32f10x_adc.c
STMLIB_C_SRCS += stm32f10x_bkp.c 
STMLIB_C_SRCS += stm32f10x_can.c 
STMLIB_C_SRCS += stm32f10x_cec.c 
STMLIB_C_SRCS += stm32f10x_crc.c 
STMLIB_C_SRCS += stm32f10x_dac.c 
STMLIB_C_SRCS += stm32f10x_dbgmcu.c
STMLIB_C_SRCS += stm32f10x_dma.c
STMLIB_C_SRCS += stm32f10x_exti.c
STMLIB_C_SRCS += stm32f10x_flash.c
STMLIB_C_SRCS += stm32f10x_fsmc.c
STMLIB_C_SRCS += stm32f10x_gpio.c
STMLIB_C_SRCS += stm32f10x_i2c.c
STMLIB_C_SRCS += stm32f10x_iwdg.c
STMLIB_C_SRCS += stm32f10x_pwr.c
STMLIB_C_SRCS += stm32f10x_rcc.c
STMLIB_C_SRCS += stm32f10x_rtc.c
STMLIB_C_SRCS += stm32f10x_sdio.c
STMLIB_C_SRCS += stm32f10x_spi.c
STMLIB_C_SRCS += stm32f10x_tim.c
STMLIB_C_SRCS += stm32f10x_usart.c
STMLIB_C_SRCS += stm32f10x_wwdg.c 
STMLIB_C_SRCS += stm32f10x_systick.c 

#OBJECTS FOR MDIN3xx_Driver (uncomment only what you need)
MDIN3XX_C_SRCS += mdin3xx.c 
MDIN3XX_C_SRCS += mdinaux_case2.c 
MDIN3XX_C_SRCS += mdinbus.c 
MDIN3XX_C_SRCS += mdincoef.c 
MDIN3XX_C_SRCS += mdindly.c 
MDIN3XX_C_SRCS += mdinfrmt.c 
MDIN3XX_C_SRCS += mdingac.c 
MDIN3XX_C_SRCS += mdinhtx_case2.c 
MDIN3XX_C_SRCS += mdini2c.c 
MDIN3XX_C_SRCS += mdinipc.c 
MDIN3XX_C_SRCS += mdinosd.c 

#OBJECTS FOR ADV7611_Driver  (uncomment only what you need)
ADV7611_C_SRCS = Wrapper.c
ADV7611_C_SRCS += RX/LIB/rx_cdec.c
ADV7611_C_SRCS += RX/LIB/rx_cec.c 
ADV7611_C_SRCS += RX/LIB/rx_cp.c 
ADV7611_C_SRCS += RX/LIB/rx_dpp_csc.c 
ADV7611_C_SRCS += RX/LIB/rx_gen.c 
ADV7611_C_SRCS += RX/LIB/rx_hdmi.c 
ADV7611_C_SRCS += RX/LIB/rx_isr.c 
ADV7611_C_SRCS += RX/LIB/rx_multi.c 
ADV7611_C_SRCS += RX/LIB/rx_sdp.c 
ADV7611_C_SRCS += RX/LIB/rx_vdp.c 
ADV7611_C_SRCS += RX/HAL/rx_afe_hal.c 
ADV7611_C_SRCS += RX/HAL/rx_cp_hal.c 
ADV7611_C_SRCS += RX/HAL/rx_hal.c 
ADV7611_C_SRCS += RX/HAL/rx_hdmi_hal.c 
ADV7611_C_SRCS += RX/HAL/rx_sdp_hal.c 
ADV7611_C_SRCS += RX/HAL/rx_sdp_vdp_hal.c 
ADV7611_C_SRCS += RX/HAL/rx_vdp_hal.c 
ADV7611_C_SRCS += RX/HAL/5G/rx_5g_cp_hal.c 
ADV7611_C_SRCS += RX/HAL/5G/rx_5g_gen_hal.c 
ADV7611_C_SRCS += RX/HAL/5G/rx_5g_hdmi_hal.c 
ADV7611_C_SRCS += RX/HAL/5G/rx_5g_no_supp_hal.c 

#USER SUPPLIED OBJECTS
C_SRCS += $(SRC_TARGET)
C_SRCS += src/stm32f10x_it.c
C_SRCS += src/stm32f10x_system.c
C_SRCS += src/newlib_stubs.c
C_SRCS += src/i2c.c
C_SRCS += src/osd.c
C_SRCS += src/nvp6011.c
C_SRCS += src/nvp6114.c
C_SRCS += src/video380_case2.c
C_SRCS += src/gac3xx.c

C_SRCS += $(addprefix $(STM_SPL_PATH)/MDIN3xx/src/,$(MDIN3XX_C_SRCS))
C_SRCS += $(addprefix $(STM_SPL_PATH)/STM32F10x_StdPeriph_Driver/src/,$(STMLIB_C_SRCS))
C_SRCS += $(addprefix $(STM_SPL_PATH)/ADV7611/,$(ADV7611_C_SRCS)) src/adv7611.c

C_OBJ += $(C_SRCS:.c=.o)

#default rule to build .c
%c.o:

all: binaries
	@echo "/*------------------------------------*/"
	@echo "Creating HEX executable"
	$(OBJDUMP) -h -S $(BIN_TARGET).elf > $(BIN_TARGET).lst
	$(SIZE)	--format=berkeley $(BIN_TARGET).elf
	$(OBJCOPY) -O ihex $(BIN_TARGET).elf $(BIN_TARGET).hex
	@echo "/*------------------------------------*/"
	@echo

binaries: $(C_OBJ) 
	@echo "/*------------------------------------*/"
	@echo "Linking..."
	$(CC) $(LDFLAGS) -nostartfiles -mcpu=cortex-m3 -mthumb  $(C_OBJ) -o $(BIN_TARGET).elf
	@echo "/*------------------------------------*/"
	@echo

libclean: clean
	-rm $(C_OBJ)


clean: 
	-rm bin/*
	-rm src/*.o src/*.d
	-rm $(STM_SPL_PATH)/MDIN3xx/src/*.o $(STM_SPL_PATH)/MDIN3xx/src/*.d
	-rm $(STM_SPL_PATH)/CMSIS/CM3/CoreSupport/*.o $(STM_SPL_PATH)/CMSIS/CM3/CoreSupport/*.d
	-rm $(STM_SPL_PATH)/CMSIS/CM3/DeviceSupport/ST/STM32F10x/*.o $(STM_SPL_PATH)/CMSIS/CM3/DeviceSupport/ST/STM32F10x/*.d
	-rm $(STM_SPL_PATH)/STM32F10x_StdPeriph_Driver/src/*.o $(STM_SPL_PATH)/STM32F10x_StdPeriph_Driver/src/*.d
	-rm $(STM_SPL_PATH)/ADV7611/*.o $(STM_SPL_PATH)/ADV7611/*.d
	-rm $(STM_SPL_PATH)/ADV7611/RX/LIB/*.o $(STM_SPL_PATH)/ADV7611/RX/LIB/*.d
	-rm $(STM_SPL_PATH)/ADV7611/RX/HAL/*.o $(STM_SPL_PATH)/ADV7611/RX/HAL/*.d
	-rm $(STM_SPL_PATH)/ADV7611/RX/HAL/5G/*.o $(STM_SPL_PATH)/ADV7611/RX/HAL/5G/*.d



flash: all upload
upload: 
	$(UPLOAD_TOOL) -w $(BIN_TARGET).hex -v -g 0x0 $(PORT)
	
.PHONY : all binaries clean binclean upload
