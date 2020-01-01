#include "quantum.h"

uint16_t copy_paste_timer;

enum custom_keycodes {
  S_H = SAFE_RANGE, // slack here
  S_H_P,       // slack here + paste 
  T_H_B,         // ticket header bike
  T_H_T,       // ticket header tread 
  E_OP,  	    // email open
  E_CL,		    // email close 
  E_FU,		    // email follow up 
  E_SS,       // email service schedule
  SCRN_C,	    // screen clip 
  DC_C,       // double click + copy
  KC_CCCV,    // one key copy/paste 
  ZD_STAT_P,  // zendesk status pending 
  ZD_STAT_O,  // zendesk status open 
  ZD_STAT_S,  // zendesk status solved + close tab
  ZD_TAB,     // zendesk close tab
  M_ZEN,      // rudimentary sends text string to make keeb

};

enum {
  TD_SPC_DOT = 0
};