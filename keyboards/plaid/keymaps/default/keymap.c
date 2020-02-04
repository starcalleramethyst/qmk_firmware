
/* Copyright 2019 Takuya Urakawa (dm9records.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
To-do:
- input custom keycodes into map
- create numpad layer for right handed number entry 
- for 2 above, utilize the existing top-row number section for custom keycodes
- do more investigation into rgb
- make gaming layer that can be toggled on and off (or just change the layout of the f-keys to something useable)
*/

#include QMK_KEYBOARD_H

enum custom_keycodes {
    S_H = SAFE_RANGE, // slack here
    S_H_P, // slack here + paste
    T_H_B, // ticket header bike
    T_H_T, // ticket header tread
    E_OP, // email open
    E_CL, // email close
    E_FU, // email follow up
    E_SS, // email service schedule
    SCRN_C, // screen clip
    ZD_STAT_P, // zendesk status pending
    ZD_STAT_O, // zendesk status open
    ZD_STAT_S, // zendesk status solved + close tab
};

enum plaid_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ESC  | RAlt | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_plaid_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_ESC, KC_RALT, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_plaid_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_plaid_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Reset |      |      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  RGB |RGBMOR|      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_plaid_grid(
    RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______,  _______, _______,  _______,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//Set leds to saved state during powerup
void keyboard_post_init_user(void) {
  // Call the post init code.

rgblight_setrgb(20, 10, 45);

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    
      //custom keycodes below

       case S_H:
        if (record->event.pressed) {
            SEND_STRING("@HERE");
        }
        break;

    case S_H_P:
        if (record->event.pressed) {
            SEND_STRING("@HERE" SS_TAP(X_SPC) SS_LCTL("v"));
        }
        break;

    case T_H_B:
        if (record->event.pressed) {
            SEND_STRING("Your Peloton Bike - ");
        }
        break;

    case T_H_T:
        if (record->event.pressed) {
            SEND_STRING("Your Peloton Tread - ");
        }
        break;

    case E_OP:
        if (record->event.pressed) {
            // when keycode E_OP is pressed
            SEND_STRING("Hi , " SS_TAP(X_ENTER) SS_TAP(X_ENTER) "Thank you for contacting Peloton." SS_TAP(X_ENTER) SS_TAP(X_ENTER));
        }
        break;

    case E_CL:
        if (record->event.pressed) {
            SEND_STRING("Please let me know if you have any other questions." SS_TAP(X_ENTER) SS_TAP(X_ENTER) "Thank you for being the best part of Peloton.");
        }
        break;

    case E_FU:
        if (record->event.pressed) {
            SEND_STRING("I will be personally watching this issue and will reach out to you after this is complete to make sure everything went smoothly." SS_TAP(X_ENTER) SS_TAP(X_ENTER));
        }
        break;

    case E_SS:
        if (record->event.pressed) {
            SEND_STRING("Please click here to schedule your service." SS_TAP(X_ENTER) SS_TAP(X_ENTER));
        }
        break;

    case SCRN_C:
        if (record->event.pressed) {
            tap_code16(C(S(KC_F5)));
        }
        break;

        case ZD_STAT_P:
        if (record->event.pressed) {
            tap_code16(C(A(KC_P))); //send ctrl+alt+P
        }
        break;

    case ZD_STAT_O:
        if (record->event.pressed) {
            tap_code16(C(A(KC_O))); //send ctrl+alt+O
        }
        break;

    case ZD_STAT_S:
        if (record->event.pressed) {
            tap_code16(C(A(KC_S))); // send ctrl+alt+S
            wait_ms(5000); // wait 5 sec
            tap_code16(C(A(KC_W))); // send ctrl+alt+W
        }
        break;
  }
  return true;
}