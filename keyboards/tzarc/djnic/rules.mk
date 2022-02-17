MCU = STM32G474

BOOTMAGIC_ENABLE = yes      # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes         # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
DEBUG_ENABLE = yes
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
NKRO_ENABLE = no            # USB Nkey Rollover
UNICODE_ENABLE = no         # Unicode

SPLIT_KEYBOARD = yes

ENCODER_ENABLE = yes

USBPD_ENABLE = yes

EEPROM_DRIVER = spi

USE_FPU = yes
LTO_ENABLE = yes
OPT = 2

DEFAULT_FOLDER = tzarc/djnic/rev2