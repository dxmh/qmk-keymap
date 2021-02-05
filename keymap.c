#include QMK_KEYBOARD_H
#include "keymap.h"
#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
    HM_A,    HM_R,    HM_S,    HM_T,    KC_G,    KC_M,    HM_N,    HM_E,    HM_I,    HM_O,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                               LTHUMB2, LTHUMB1, RTHUMB1, RTHUMB2
  ),
  [RAISE] = LAYOUT(
    XXXXXXX, KC_HOME, KC_UP,   KC_END,  RESET,   XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX,
    HM_PNKY, HM_LEFT, HM_DOWN, HM_RGHT, MO(FN1), XXXXXXX, HM_4,    HM_5,    HM_6,    HM_0,
    XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, MO(FN2), XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX,
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
  [MOUSE] = LAYOUT(
    XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, KC_LGUI, KC_LCTL, KC_LSFT, KC_LALT,
    XXXXXXX, XXXXXXX, KC_WH_D, KC_WH_U, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               KC_BTN2, KC_BTN1, _______, _______
  ),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LTHUMB1:
    case LTHUMB2:
    case RTHUMB1:
    case RTHUMB2:
      return TAPPING_TERM - 75;
    default:
      return TAPPING_TERM;
  }
};
