# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#

CONVERT_TO_PROTON_C = yes

BOOTMAGIC_ENABLE        = no
MOUSEKEY_ENABLE         = no
CONSOLE_ENABLE          = yes
DEBUG_ENABLE			= yes
COMMAND_ENABLE          = no
AUTO_SHIFT_ENABLE = yes

BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality

OLED_DRIVER_ENABLE= no     # OLED display

RGBLIGHT_ENABLE         = no
RGB_MATRIX_ENABLE       = WS2812
RGB_MATRIX_FRAMEBUFFER_EFFECTS = yes

#RGB_MATRIX_ENABLE		= no
SPLIT_TRANSPORT         = mirror
