include $(BOARD_DIR)/firmware/firmware.mk

BOARDINC += $(BOARD_DIR)/generated/controllers/generated

# defines SHORT_BOARD_NAME
include $(BOARD_DIR)/meta-info.env

# MCU defines
DDEFS += -DSTM32F407xx

# this would save some flash while being unable to update WBO controller firmware
DDEFS += -DEFI_WIDEBAND_FIRMWARE_UPDATE=TRUE

DDEFS += -DSTM32_ADC_USE_ADC3=TRUE
DDEFS += -DEFI_SOFTWARE_KNOCK=TRUE -DSTM32_ADC_USE_ADC3=TRUE

# we do not have much Lua RAM, let's drop some fancy functions
DDEFS += -DWITH_LUA_CONSUMPTION=FALSE
DDEFS += -DWITH_LUA_PID=FALSE
DDEFS += -DWITH_LUA_STOP_ENGINE=FALSE

DDEFS += $(PRIMARY_COMMUNICATION_PORT_USART2)

# assign critical LED to a non-existent pin if you do not have it on your board
# good old PD14 is still the default value
# DDEFS += -DLED_CRITICAL_ERROR_BRAIN_PIN=Gpio::I15

# CAND1
DDEFS += -DBOOT_COM_CAN_CHANNEL_INDEX=0
DDEFS += -DOPENBLT_CAN_RX_PORT=GPIOD
DDEFS += -DOPENBLT_CAN_RX_PIN=0
DDEFS += -DOPENBLT_CAN_TX_PORT=GPIOD
DDEFS += -DOPENBLT_CAN_TX_PIN=1

# EGT chip
#un-comment to enable
#DDEFS += -DEFI_MAX_31855=TRUE

#see main repo for details on this any many other optional subsystems. We have too many, one has to choose what fits into his choice of stm32
#DDEFS += -DEFI_ONBOARD_MEMS=TRUE
