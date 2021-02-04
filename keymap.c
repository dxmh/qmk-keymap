#include QMK_KEYBOARD_H

#include "keymap.h"
#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DEF] = LAYOUT(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
    HOME_A,  HOME_R,  HOME_S,  HOME_T,  KC_G,    KC_M,    HOME_N,  HOME_E,  HOME_I,  HOME_O,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                               CORNR_L, THUMB_L, THUMB_R, CORNR_R
  ),
  [NAV] = LAYOUT(
    XXXXXXX, KC_HOME, KC_UP,   KC_END,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, KC_LGUI, KC_LSFT, KC_LCTL, KC_LALT,
    XXXXXXX, KC_PGUP, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               _______, _______, _______, _______
  ),
  [NUM] = LAYOUT(
    XXXXXXX, XXXXXXX, MO(FN2), MO(FN1), RESET,   XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX,
    KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    KC_0,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX,
                               _______, _______, _______, _______
  ),
  [FN1] = LAYOUT(
    _______, _______, _______, _______, _______, _______, KC_F7,   KC_F8,   KC_F9,   _______,
    _______, _______, _______, _______, _______, _______, KC_F4,   KC_F5,   KC_F6,   KC_F10,
    _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   _______,
                               _______, _______, _______, _______
  ),
  [FN2] = LAYOUT(
    _______, _______, _______, _______, _______, _______, KC_F17,  KC_F18,  KC_F19,  _______,
    _______, _______, _______, _______, _______, _______, KC_F14,  KC_F15,  KC_F16,  KC_F20,
    _______, _______, _______, _______, _______, _______, KC_F11,  KC_F12,  KC_F13,  _______,
                               _______, _______, _______, _______
  ),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case HOME_O:
    case HOME_A:
      return TAPPING_TERM + 60;
    default:
      return TAPPING_TERM;
  }
};
