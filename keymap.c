#include QMK_KEYBOARD_H
#include "capsword.c"
#include "keymap.h"
#include "sendstring_uk.h"
#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
    HM_A,    HM_R,    HM_S,    HM_T,    KC_G,    KC_M,    HM_N,    HM_E,    HM_I,    HM_O,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                               LTHUMB2, LTHUMB1, RTHUMB1, RTHUMB2
  ),
  [RAISE] = LAYOUT(
    XXXXXXX, KC_HOME, KC_UP,   KC_END,  XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX,
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


// Specify combos that must be held for the duration of COMBO_TERM before
// triggering (to prevent misfires when typing quickly):
bool get_combo_must_hold(uint16_t index, combo_t *combo) {
  switch (index) {
    case paste:
      return true;
  }
  return false;
}

// Tune timings for combos
uint16_t get_combo_term(uint16_t index, combo_t *combo) {
  switch(index) {
    case paste:
      return 30; // tune the COMBO_MUST_HOLD
    case push_to_talk:
    case fullscreen:
    case overview:
    case quit:
    case word_back:
    case word_forward:
      return 100; // give myself more time for these ones
    default:
      return COMBO_TERM;
  }
}

// Tune timings for tap/hold keys
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

// Allow certain tap-hold keys to repeat
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case HM_LEFT:
    case HM_DOWN:
    case HM_RGHT:
    case LTHUMB1:
    case LTHUMB2:
    case RTHUMB1:
    case RTHUMB2:
      return false;
    default:
      return true;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CAPSWORD:
      if (record->event.pressed) {
        return false;
      } else {
        caps_word_toggle();
        return false;
      }
  }
  process_caps_word(keycode, record);
  return true;
}
