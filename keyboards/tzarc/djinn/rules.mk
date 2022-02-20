MCU = STM32G474

# Bootloader selection
BOOTLOADER = stm32-dfu
PROTOCOL_CHIBIOS = YES
BOOTMAGIC_ENABLE = yes      # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes         # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
DEBUG_ENABLE = yes
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
NKRO_ENABLE = no            # USB Nkey Rollover
UNICODE_ENABLE = no         # Unicode
AUDIO_ENABLE = yes           # Audio output

AUDIO_DRIVER = pwm_software
AUDIO_PIN = A4
AUDIO_PIN_ALT = A5

CFLAGS += -g$(DEBUG)
SPLIT_KEYBOARD = yes
OPT_DEFS += -O0

ENCODER_ENABLE = yes

USBPD_ENABLE = yes
EEPROM_DRIVER = vendor
# EEPROM_DRIVER = spi

USE_FPU = yes
LTO_ENABLE = yes
OPT = 2

DEFAULT_FOLDER = tzarc/djinn/rev2