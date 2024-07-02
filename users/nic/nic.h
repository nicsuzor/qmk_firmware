#pragma once
#include QMK_KEYBOARD_H
#include "wrappers.h"

/* Define layer names */
enum userspace_layers {
    _QWERTY  = 0,
    _RAISE,
    _LOWER,
    _ADJUST
};

#define LOWER MO(_LOWER) //TL_LOWR //MO(_LOWER)
#define RAISE MO(_RAISE) //TL_UPPR //MO(_RAISE)

