#pragma once

#ifdef COMBO_ENABLE
#    define COMBO_COUNT 7
#    define COMBO_TERM 50
#endif

#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#endif
#define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT