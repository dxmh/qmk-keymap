#pragma once

#include QMK_KEYBOARD_H

#define THUMB_L MT(MOD_LCTL, KC_SPC)
#define CORNR_L LT(NUM, KC_ESC)
#define THUMB_R MT(MOD_LSFT, KC_ENT)
#define CORNR_R LT(NAV, KC_BSPC)

#define HOME_A LALT_T(KC_A)
#define HOME_R LCTL_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LGUI_T(KC_T)

#define HOME_N RGUI_T(KC_N)
#define HOME_E RSFT_T(KC_E)
#define HOME_I RCTL_T(KC_I)
#define HOME_O LALT_T(KC_O)

enum layers {
    DEF,
    NAV,
    NUM,
    FN1,
    FN2,
};
