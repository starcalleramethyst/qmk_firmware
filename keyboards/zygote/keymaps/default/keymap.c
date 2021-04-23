#include "zygote.h"
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layers
{
	_QWERTY,
	_LOWER,
	_RAISE
};

enum custom_keycodes
{
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST
};

// Fillers to make layering more clear
#define XXXXXXX KC_NO
#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,         KC_NO,    KC_NO,           KC_Y,    KC_U,    KC_I,    KC_O  ,       KC_P,  \
  KC_A,    KC_S,    KC_D,    KC_F,      KC_G,         KC_NO,    KC_NO,           KC_H,    KC_J,    KC_K,    KC_L  ,    KC_SCLN,  \
  KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,       KC_QUOT,  KC_PIPE,           KC_N,    KC_M,    KC_COMM, KC_DOT,    KC_SLSH,  \
  KC_ESC,  KC_TAB,  KC_LGUI, KC_LSFT,   KC_BSPC,    KC_LCTL,  KC_LALT,         KC_SPC,   LOWER,    KC_MINS,  RAISE,     KC_ENT   \
),


[_LOWER] = LAYOUT_ortho_4x12( \
  KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_NO,        KC_NO  ,    KC_CIRC,   KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  \
   KC_DEL,  KC_F1,   KC_F2,   KC_F3,     KC_F4,     KC_NO,        KC_NO  ,    KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,    \
  KC_HOME,  KC_F5,   KC_F6,   KC_F7,      KC_8,  KC_TILD,        KC_PGUP, S(KC_NUHS),S(KC_NUBS),_______, _______, _______,   \
  KC_END , KC_F9,  KC_F10,  KC_F11,    KC_F12,     KC_INS,        KC_PGDN,    _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY    \
),         

[_RAISE] = LAYOUT_ortho_4x12( \
  KC_1,     KC_2,    KC_3,   KC_4,    KC_5,     KC_NO,         KC_NO,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_NO,         KC_NO,     KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,  \
  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,        KC_F12,  KC_NUHS, KC_NUBS, _______, _______,    KC_DEL,    \
  _______, _______, _______, _______, _______, _______,       _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
)

};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;

    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;


  }
  return true;
}

void matrix_scan_user(void) {
		return;
};
