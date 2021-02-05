#pragma once

#include QMK_KEYBOARD_H

#define THUMB_L LT(NAV, KC_SPC)
#define CORNR_L MT(MOD_LSFT, KC_ESC)
#define THUMB_R LT(NUM, KC_BSPC)
#define CORNR_R MT(MOD_RSFT, KC_ENT)

#define HOME_A LALT_T(KC_A)
#define HOME_R LSFT_T(KC_R)
#define HOME_S LCTL_T(KC_S)
#define HOME_T LGUI_T(KC_T)

#define HOME_N RGUI_T(KC_N)
#define HOME_E RCTL_T(KC_E)
#define HOME_I RSFT_T(KC_I)
#define HOME_O LALT_T(KC_O)

enum layers {
    DEF,
    NAV,
    NUM,
    FN1,
    FN2,
    MOUSE,
};
