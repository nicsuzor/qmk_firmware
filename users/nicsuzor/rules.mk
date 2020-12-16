SRC += nic.c

# Common flags
SPACE_CADET_ENABLE      = no
LTO_ENABLE              = yes
EXTRAKEY_ENABLE         = yes
UNICODE_ENABLE          = yes
NKRO_ENABLE             = yes
EXTRAKEY_ENABLE         = yes
LEADER_ENABLE           = no
TAP_DANCE_ENABLE        = no
INDICATOR_LIGHTS		= no
RGB_MATRIX_FRAMEBUFFER_EFFECTS  = yes



ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
    SRC += tap_dances.c
endif

#ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
#    SRC += oled.c
#endif

ifeq ($(strip $(LEADER_ENABLE)), yes)
    SRC += leader.c
endif


RGB_MATRIX_ENABLE ?= no
ifneq ($(strip $(RGB_MATRIX_ENABLE)), no)
    SRC += rgb_matrix_user.c
else

endif

ifdef CONSOLE_ENABLE
    ifeq ($(strip $(KEYLOGGER_ENABLE)), yes)
        OPT_DEFS += -DKEYLOGGER_ENABLE
    endif
endif

ifeq ($(strip $(MAKE_BOOTLOADER)), yes)
    OPT_DEFS += -DMAKE_BOOTLOADER
endif

# At least until build.mk or the like drops, this is here to prevent
# VUSB boards from enabling NKRO, as they do not support it. Ideally
# this should be handled per keyboard, but until that happens ...
ifeq ($(strip $(PROTOCOL)), VUSB)
    NKRO_ENABLE       = no
endif
