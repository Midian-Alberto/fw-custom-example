include $(BOARD_DIR)/firmware/firmware.mk

BOARDINC += $(BOARD_DIR)/generated/controllers/generated

# defines SHORT_BOARD_NAME
include $(BOARD_DIR)/meta-info.env

# MCU defines
DDEFS += -DSTM32F407xx

# this would save some flash while being unable to update WBO controller firmware
DDEFS += -DEFI_WIDEBAND_FIRMWARE_UPDATE=TRUE

DDEFS += -DSTM32_ADC_USE_ADC3=TRUE
DDEFS += -DEFI_SOFTWARE_KNOCK=TRUE 

# Hardware serial port on UART 2 -> PD5/PD6
DDEFS += -DSTM32_UART_USE_USART2=TRUE
DDEFS += -DTS_PRIMARY_UxART_PORT=UARTD2
DDEFS += -DEFI_CONSOLE_TX_BRAIN_PIN=Gpio::D5 -DEFI_CONSOLE_RX_BRAIN_PIN=Gpio::D6

# assign critical LED to a non-existent pin if you do not have it on your board
# good old PD14 is still the default value
# DDEFS += -DLED_CRITICAL_ERROR_BRAIN_PIN=Gpio::I15



# EGT chip
#un-comment to enable
#DDEFS += -DEFI_MAX_31855=TRUE

#see main repo for details on this any many other optional subsystems. We have too many, one has to choose what fits into his choice of stm32
#DDEFS += -DEFI_ONBOARD_MEMS=TRUE
