//
// Created by nic on 31/10/2020.
//

// Defines names for use in layer keycodes and the keymap
enum part_layer_names {
    _QWER = 0,
    _ASDF,
    _ZXCV,
    _1234,
    _YUIO,
    _HJKL,
    _NM,
    _6789
};

#define ARRAY_CONCAT(TYPE, A, An, B, Bn) \
  (TYPE *)array_concat((const void *)(A), (An), (const void *)(B), (Bn), sizeof(TYPE));

void *array_concat(const void *a, size_t an,
                   const void *b, size_t bn, size_t s)
{
    char *p = malloc(s * (an + bn));
    memcpy(p, a, an*s);
    memcpy(p + an*s, b, bn*s);
    return p;
}

/* I use a common set of keys across each keyboard; the major
 * differences are in the modifiers only. Here, we declare the
 * common keys, and in the keyboard specific keymap, we concat
 * the custom with the generic layouts. */
const uint16_t nic_base[9][6] =
    {
        [_1234] = {KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5},
        [_QWER] = {KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T},
        [_ASDF] = {KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G},
        [_ZXCV] = {KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B},
        [_6789] = {KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC},
        [_YUIO] = {KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL},
        [_HJKL] = {KC_H, KC_J, KC_K, KC_L, KC_QUOT, KC_ENT},
        [_NM] = {KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT}

    };

const uint16_t nic_lower[9][6] =
    {
        [_1234] = {KC_NO, KC_NO, KC_NO, LCTL(KC_PGUP), LCTL(KC_PGDN), KC_NO},
        [_QWER] = {KC_TAB, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_BSPC},
        [_ASDF] = {KC_ESC, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_ENT},
        [_ZXCV] = {KC_LSFT, KC_NO, KC_LCTL, KC_NO, KC_NO, KC_DEL},
        [_6789] = {KC_CIRC, KC_AMPR, KC_ASTR, KC_AT, KC_HASH, KC_BSPC},
        [_YUIO] = {KC_UNDS, KC_LBRC, KC_RBRC, KC_PIPE, KC_GRV, KC_DEL},
        [_HJKL] = {KC_MINS, KC_LPRN, KC_RPRN, KC_SCLN, KC_EQL, KC_ENT},
        [_NM] = {KC_NO, KC_PPLS, KC_LCBR, KC_RCBR, KC_COLN, KC_BSLS, TO(0)}

    };

const uint16_t nic_raise[9][6] =
    {
        [_1234] = {KC_GRV, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO},
        [_QWER] = { KC_TAB, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5},
        [_ASDF] = { KC_ESC, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10 },
        [_ZXCV] = {KC_LSFT, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO},

        [_6789] = {KC_NO, KC_NO, KC_NO, KC_NO,KC_NO, KC_BSPC},
        [_YUIO] = {KC_PEQL, KC_4, KC_5, KC_6, KC_PAST, KC_ENT },
        [_HJKL] = {KC_H, KC_J, KC_K, KC_L, KC_QUOT, KC_ENT},
        [_NM] = {KC_PPLS, KC_P0, KC_P0, KC_PDOT, KC_COLN, TO(0)}

    };

const uint16_t nic_adjust[9][6] = {
    [_1234] = {KC_ESC, KC_PSCR, KC_NO, KC_NO, LALT(KC_F4), LCTL(LSFT(KC_ESC))},
    [_QWER] = { LCA(KC_DEL), KC_NO, KC_NO, KC_NO, KC_NO, RESET},
    [_ASDF] = { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO },
    [_ZXCV] = {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO},

    [_6789] = {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO},
    [_YUIO] = {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO },
    [_HJKL] = {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO},
    [_NM] = {RGB_TOG, RGB_SPD, RGB_VAD, RGB_VAI, RGB_SPI, TO(0)}

};