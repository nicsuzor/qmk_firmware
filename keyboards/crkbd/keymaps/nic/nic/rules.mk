# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
MCU = STM32F303
BOARD = QMK_PROTON_C
BOOTLOADER = stm32-dfu

SPLIT_KEYBOARD = yes

# SERIAL_DRIVER = bitbang

# API_SYSEX_ENABLE = no

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend
