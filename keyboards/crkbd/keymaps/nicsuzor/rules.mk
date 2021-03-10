# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
MCU = STM32F303
BOARD = QMK_PROTON_C
#CONVERT_TO_PROTON_C = yes

BOOTMAGIC_ENABLE        = no
MOUSEKEY_ENABLE         = no
CONSOLE_ENABLE          = yes
DEBUG_ENABLE			= yes
COMMAND_ENABLE          = no
AUTO_SHIFT_ENABLE = yes

OLED_DRIVER_ENABLE= no     # OLED display
AUDIO_ENABLE			= no
MIDI_ENABLE        = no

RGBLIGHT_ENABLE         = no
RGB_MATRIX_ENABLE       = no
RGB_MATRIX_FRAMEBUFFER_EFFECTS = no
SPLIT_KEYBOARD = yes

RGB_MATRIX_DRIVER = WS2812
WS2812_DRIVER = pwm
#SPLIT_TRANSPORT = mirror    # for when Split Mirroring drops, it will maintain mirroring functionality

API_SYSEX_ENABLE = no

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend
