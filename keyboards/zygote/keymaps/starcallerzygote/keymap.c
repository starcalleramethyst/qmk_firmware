#include "zygote.h"
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layers
{
  _BASE,
  _NUM_SYM,
  _NAV,
  _GAME
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
#define KC_SF LSFT_T(KC_F) /* the F key is SHIFT when held and F when tapped */
#define KC_SJ RSFT_T(KC_J) /* the J key is SHIFT when held and J when tapped */
#define KC_NUM_SPC LT(_NUM_SYM, KC_SPC) /* the right space is the num sym layer when held and space when tapped*/
#define KC_NAV_ENT LT(_NAV, KC_ENT) /* the left space is nav layer when held or enter when tapped */

enum combo_events {
  COMBO_BSPC,
  COMBO_NUMBAK,
  COMBO_TAB,
  COMBO_ESC,
  COMBO_DEL,
  COMBO_ENT, 
  COMBO_NAV_ENT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_ortho_4x12( \
  KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,         KC_NO,    KC_NO,           KC_Y,    KC_U,    KC_I,    KC_O  ,       KC_P,  \
  KC_A,    KC_S,    KC_D,    KC_SF,      KC_G,         KC_NO,    KC_NO,           KC_H,    KC_SJ,    KC_K,    KC_L  ,    KC_SCLN,  \
  KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,       KC_QUOT,  KC_PIPE,           KC_N,    KC_M,    KC_COMM, KC_DOT,    KC_SLSH,  \
  KC_ESC,  KC_TAB,  KC_LGUI, KC_LSFT,   KC_NAV_ENT,    KC_LCTL,  KC_LALT,         KC_NUM_SPC,   KC_NO,    KC_MINS,  KC_NO,     KC_ENT   \
),


[_NUM_SYM] = LAYOUT_ortho_4x12( \
     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,          KC_NO,    KC_NO,           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  \
   KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,   KC_PIPE,     KC_NO,    KC_NO,    KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,    \
  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,   KC_BSLS,  KC_TILD,        KC_PGUP, S(KC_NUHS),S(KC_NUBS),_______, _______, _______,   \
  KC_END , KC_F9,  KC_F10,  KC_F11,    KC_F12,     KC_INS,        KC_PGDN,    _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY    \
),         

[_NAV] = LAYOUT_ortho_4x12( \
  KC_EXLM, KC_AT,  KC_HASH,  KC_DLR,   KC_PERC,     KC_NO,         KC_NO,      KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN, KC_RPRN,    \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_NO,         KC_NO,     KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT, KC_QUOT,  \
  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,        KC_F12,  KC_NUHS, KC_NUBS, _______, _______,    KC_DEL,    \
  _______, _______, _______, _______, _______, _______,       _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
)

};

void matrix_scan_user(void) {
		return;
};

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_bspc[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_numbak[] = {KC_0, KC_9, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_E, KC_W, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_MINS, KC_EQL, COMBO_END};
const uint16_t PROGMEM combo_ent[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM combo_nav_ent[] = {KC_DOT, KC_GRV, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_BSPC] = COMBO(combo_bspc,KC_BSPC),
  [COMBO_NUMBAK] = COMBO(combo_numbak,KC_BSPC),
  [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
  [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
  [COMBO_DEL] = COMBO(combo_del,KC_DEL),
  [COMBO_ENT] = COMBO(combo_ent,KC_ENT),
  [COMBO_NAV_ENT] = COMBO(combo_nav_ent,KC_NAV_ENT),

};
#endif
