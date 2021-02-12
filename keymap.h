#pragma once
#include QMK_KEYBOARD_H
#include "keymap_uk.h"

// Friendly layer names
enum layers {
    BASE,
    RAISE,
    FN1,
    FN2,
    MOUSE,
};

// Keycodes for use in macros
enum custom_keycodes {
  ALT_TAB = SAFE_RANGE,
  SUPER_TAB,
};


// Thumb keys
#define LTHUMB1 LT(RAISE, KC_SPC)
#define LTHUMB2 MT(MOD_LSFT, KC_ESC)
#define RTHUMB1 LT(RAISE, KC_BSPC)
#define RTHUMB2 MT(MOD_RSFT, KC_ENT)

// BASE home row modifiers
#define HM_A LALT_T(KC_A)
#define HM_R LSFT_T(KC_R)
#define HM_S LCTL_T(KC_S)
#define HM_T LGUI_T(KC_T)
#define HM_N RGUI_T(KC_N)
#define HM_E RCTL_T(KC_E)
#define HM_I RSFT_T(KC_I)
#define HM_O LALT_T(KC_O)

// RAISE home row modifiers
#define HM_PNKY KC_LALT
#define HM_LEFT LSFT_T(KC_LEFT)
#define HM_DOWN LCTL_T(KC_DOWN)
#define HM_RGHT LGUI_T(KC_RIGHT)
#define HM_4 RGUI_T(KC_4)
#define HM_5 RCTL_T(KC_5)
#define HM_6 RSFT_T(KC_6)
#define HM_0 LALT_T(KC_0)
