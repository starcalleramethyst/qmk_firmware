#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _NAV
};


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NAV,
  BRK,
  LNCH,
  EOD, 
  LM1,
  MM, 
  AM,
  GM,


};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------.             .-----------------------------------------.
   * | GESC |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |   \  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |CAPS(NAV)|A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------..-----+------+------+------+------+------+------|
   * | Ctrl | GUI  | Alt  |RGBTOG| NAV  |Space |Delete||Enter|Space |  NAV |   -  |   =  | PGUP | PGDN |
   * `------------------------------------------------''-----------------------------------------------'
   */
  [_QWERTY] = LAYOUT( \
    _______,       _______, _______, _______, _______,  _______,                    _______,  _______,  _______, _______, _______,    KC_BSPC, \
    _______,        _______,   _______,   _______, _______, _______,                    _______,  _______,     KC_7,    KC_8,    KC_9,    _______, \
    _______,        EOD,  _______,    _______, _______,  _______,                    _______,  _______,     KC_4,    KC_5,    KC_6,    _______, \
    _______,        BRK, LNCH,_______,   _______,  _______,                    _______,  _______,     KC_1,    KC_2,    KC_3,    _______,  \
    _______,        GM, MM, AM, LM1, _______,  _______,  KC_ENT,   _______, _______,   KC_0,  KC_DOT, _______,       KC_ENT \
  ),

};


void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BRK:
      if (record->event.pressed) {
          SEND_STRING("I am going to break, and will return shortly!" SS_TAP(X_ENTER)) ;
      }
      break;
    case LNCH:
      if (record->event.pressed) {
          SEND_STRING("I am going to lunch, and will return shortly!" SS_TAP(X_ENTER));
      }
      break;
    case EOD:
      if (record->event.pressed) {
          SEND_STRING("@here All right HWSW humans, it has been an amazing day! Thank you for all of your work to support our members. I am out of here for the night at 4 pm! Let me know if there is anything I may do for you before I leave. :stars:" SS_TAP(X_ENTER));
      }
      break;
    case LM1:
      if (record->event.pressed) {
          SEND_STRING("@here Leads are hopping into a 15 minute meeting at 1pm. Please slack us if you need anything during that time!" SS_TAP(X_ENTER));
      }
      break;
    case MM:
      if (record->event.pressed) {
          SEND_STRING("@here Good Morning, morning crew! Please join me for our morning stand-up meeting! https://meet.google.com/vjb-kway-dwq" SS_TAP(X_ENTER));
      }
      break;
    case AM:
      if (record->event.pressed) {
          SEND_STRING("@here Good Afternoon, afternoon crew! Please join me for our afternoon stand-up meeting! https://meet.google.com/fib-zwfr-fwd" SS_TAP(X_ENTER));
      }
      break;
    case GM:
      if (record->event.pressed) {
          SEND_STRING("@here Good Morning everyone! We should all be in live channels at 7:45 CST. Let’s get this day rolling! :fireworks:" SS_TAP(X_ENTER));
      }
      break;
  }
  return true;

}
