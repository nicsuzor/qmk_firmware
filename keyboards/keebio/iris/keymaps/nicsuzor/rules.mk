RGBLIGHT_ENABLE = yes
BACKLIGHT_ENABLE = no
AUTO_SHIFT_ENABLE = no
RGBLIGHT_SPLIT = yes
RGBLIGHT_ANIMATIONS = no
RGBLIGHT_LAYERS = no
#TAP_DANCE_ENABLE = yes
#MOUSEKEY_ENABLE = no
NKRO_ENABLE = yes            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work

# https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/
#EXTRAFLAGS += -flto
#AUDIO_ENABLE = yes
SRC += nic.c
