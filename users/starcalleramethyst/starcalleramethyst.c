#include "quantum.h"
#include "starcalleramethyst.h"
#include "action.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

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
        SEND_STRING("Hi , "SS_TAP(X_ENTER)SS_TAP(X_ENTER)"Thank you for contacting Peloton."SS_TAP(X_ENTER)SS_TAP(X_ENTER));
      }
break;

    case E_CL:
      if (record->event.pressed) {
                SEND_STRING("Please let me know if you have any other questions."SS_TAP(X_ENTER)SS_TAP(X_ENTER)"Thank you for being the best part of Peloton."); 
      }
break;

    case E_FU:
      if (record->event.pressed) {
                SEND_STRING("I will be personally watching this issue and will reach out to you after this is complete to make sure everything went smoothly."SS_TAP(X_ENTER)SS_TAP(X_ENTER)); 
      }
break;

    case E_SS:
      if (record->event.pressed) {
                SEND_STRING("Please click here to schedule your service."SS_TAP(X_ENTER)SS_TAP(X_ENTER)); 
      }
break;

    case SCRN_C:
      if (record->event.pressed) {
                tap_code16(C(S(KC_F5))); 
      }
break;

   case DC_C:
      if (record->event.pressed) {
                tap_code(KC_BTN1);
                tap_code(KC_BTN1);
                tap_code16(C(KC_C)); 
      }
break;
    
    case KC_CCCV:  // One key copy/paste
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {  // Hold, copy
                    tap_code16(C(KC_C));
                } else {  // Tap, paste
                    tap_code16(C(KC_V));
                }
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
                wait_ms(5000);          // wait 5 sec 
                tap_code16(C(A(KC_W))); // send ctrl+alt+W
          }
break;

    case ZD_TAB:
          if (record->event.pressed) {
                tap_code16(C(A(KC_W))); // send ctrl+alt+w
          }
break;

    case M_ZEN:
          if (record->event.pressed) {
              send_string("make rgbkb/zen/rev1:starcalleramethyst" SS_TAP(X_ENTER));
          }

  }
  return true;
};  

qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_SPC_DOT]  = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_PDOT) 
// Other declarations would go here, separated by commas, if you have them
};