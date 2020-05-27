TARGET = 01-blink
CUBEMX = ../CubeMX/default

HOST_UART2_PORT = /dev/ttyACM0
HOST_UART2_BAUD = 115200

C_SOURCES =  \
main.c \
$(CUBEMX)/Src/stm32f4xx_it.c \
$(CUBEMX)/Src/stm32f4xx_hal_msp.c \
$(CUBEMX)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spi.c \
$(CUBEMX)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c \
$(CUBEMX)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c \
$(CUBEMX)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c \
$(CUBEMX)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c \
$(CUBEMX)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c \
$(CUBEMX)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c \
$(CUBEMX)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c \
$(CUBEMX)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c \
$(CUBEMX)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c \
$(CUBEMX)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c \
$(CUBEMX)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c \
$(CUBEMX)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c \
$(CUBEMX)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c \
$(CUBEMX)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c \
$(CUBEMX)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c \
$(CUBEMX)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c \
$(CUBEMX)/Src/system_stm32f4xx.c  

C_INCLUDES =  \
-I$(CUBEMX)/Inc \
-I$(CUBEMX)/Drivers/STM32F4xx_HAL_Driver/Inc \
-I$(CUBEMX)/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy \
-I$(CUBEMX)/Drivers/CMSIS/Device/ST/STM32F4xx/Include \
-I$(CUBEMX)/Drivers/CMSIS/Include \
-I$(CUBEMX)/Drivers/CMSIS/Include

include ../build.mk

