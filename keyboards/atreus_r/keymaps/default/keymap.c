#include "atreus_r.h"

#define _SOFT 0 // two-handed "soft dvorak"
#define _FN   1 // two-handed fn layer
#define _L2   2 // two-handed L2

#define _ON 3 // one-handed use
#define _RS 4
#define _LW 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_SOFT] = { /* Soft Dvorak */
  {KC_TRNS,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P},
  {KC_TRNS,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN , KC_LCTL },
  {KC_BSLS,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH , KC_LSFT },
  {KC_LALT,  KC_SPC,  MO(_FN), KC_QUOT, KC_LBRC, KC_ENT  , KC_LGUI }
},
[_FN] = { /* Fn (soft) */
  {KC_TRNS, KC_PGUP, KC_7,    KC_8,   KC_9, KC_BSPC},
  {KC_TRNS, KC_PGDN, KC_4,    KC_5,   KC_6, KC_BSLS},
  {TO(_L2), KC_ASTR, KC_1,    KC_2,   KC_3, KC_RCBR},
  {KC_LALT, KC_SPC,  KC_TRNS, KC_E,   KC_0, KC_RBRC}
},
[_L2] = { /* [> LOWER <] */
  {KC_TRNS, KC_UP,      KC_F7,     KC_F8,   KC_F9,   KC_F10},
  {KC_TRNS, KC_DOWN,    KC_F4,     KC_F5,   KC_F6,   KC_F11,},
  {KC_TRNS, TO(_ON),    KC_F1,     KC_F2,   KC_F3,   KC_F12},
  {KC_LALT, KC_SPC,     TO(_SOFT), KC_PSCR, KC_SLCK, KC_TRNS, RESET}
},


[_ON] = { /* one-handed */
  {KC_TRNS, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, },
  {KC_TRNS, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_LCTL },
  {KC_LSFT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT },
  {KC_SPC,  MO(_RS), MO(_LW), KC_BSPC, KC_LALT, KC_LGUI, KC_ENT, }
},
[_RS] = { /* [> RAISE <] */
  {KC_TRNS, KC_MINS, KC_7 ,   KC_8   , KC_9  ,  KC_UP   },
  {KC_TRNS, KC_EQL , KC_4   , KC_5 ,   KC_6   , KC_DOWN, KC_LCTL },
  {KC_LSFT, KC_LBRC, KC_1    ,KC_2   , KC_3   , KC_LEFT, KC_RGHT},
  {KC_SPC,  KC_TRNS, KC_TRNS, KC_BSPC, KC_LALT, KC_LGUI, RESET, }
},
[_LW] = { /* [> LOWER <] */
  {KC_TRNS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, },
  {KC_TRNS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LCTL },
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ESC},
  {KC_SPC,  KC_TRNS, KC_TRNS, KC_BSPC, KC_LALT, KC_LGUI, KC_ENT, }
}};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
