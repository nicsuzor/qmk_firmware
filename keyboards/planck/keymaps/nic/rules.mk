# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
# MCU name
MCU = STM32F303

# Bootloader selection
BOOTLOADER = stm32-dfu


# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend

BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = no        # Audio control and System control
CONSOLE_ENABLE = yes         # Console for debug
DEBUG_ENABLE	= yes
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = yes           # Audio output on port C6
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE = no       # Enable WS2812 RGB underlight.
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
OLED_DRIVER_ENABLE= no     # OLED display
SSD1306OLED= no
KEYLOG = no
TAP_DANCE_ENABLE = no
LTO_ENABLE = no


CUSTOM_MATRIX = yes

SRC += muse.c

RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = no
AUTO_SHIFT_ENABLE = no

#ifeq ($(strip $(KEYBOARD)), planck/rev6)
#RGB_MATRIX_ENABLE = yes #WS2812
#endif