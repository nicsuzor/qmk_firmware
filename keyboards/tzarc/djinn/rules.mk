MCU = STM32G474
BOOTLOADER = stm32-dfu
PROTOCOL_CHIBIOS = YES

BOOTMAGIC_ENABLE = yes      # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes         # Console for debug
COMMAND_ENABLE = yes         # Commands for debug and configuration
DEBUG_ENABLE = yes
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
NKRO_ENABLE = no            # USB Nkey Rollover
UNICODE_ENABLE = no         # Unicode
WPM_ENABLE = yes

SPLIT_KEYBOARD = yes

ENCODER_ENABLE = yes

USBPD_ENABLE = yes

BACKLIGHT_ENABLE = no
BACKLIGHT_DRIVER = pwm

WS2812_DRIVER = pwm
CIE1931_CURVE = yes

RGBLIGHT_ENABLE = no
RGBLIGHT_DRIVER = WS2812

DRIVER_LED_TOTAL = 86
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812

AUDIO_ENABLE = yes
AUDIO_DRIVER = pwm_software
AUDIO_PIN = A5
AUDIO_PIN_ALT = A4

QUANTUM_PAINTER_ENABLE = no

USE_FPU = yes
LTO_ENABLE = yes
OPT = 2

# List of all the board related files.
BOARDSRC = $(CHIBIOS)/os/hal/boards/ST_NUCLEO64_G474RE/board.c

# Required include directories
BOARDINC = $(CHIBIOS)/os/hal/boards/ST_NUCLEO64_G474RE

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)

DEFAULT_FOLDER = tzarc/djinn/rev2
