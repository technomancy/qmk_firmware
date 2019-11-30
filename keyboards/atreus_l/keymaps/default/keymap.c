#include "atreus_l.h"

#define _SOFT 0 // two-handed "soft dvorak"
#define _FN   1 // two-handed fn layer
#define _L2   2 // two-handed L2

#define _ON 3
#define _RS 4
#define _LW 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_SOFT] = { /* Soft Dvorak */
  {KC_TRNS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   },
  {KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   },
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_GRV },
  {KC_TRNS, KC_ESC, KC_TAB,   KC_LGUI, MO(_FN), KC_BSPC,KC_LCTL }
},
[_FN] = { /* Fn (soft) */
  {KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_GRV,  },
  {KC_LCTL, KC_LPRN, KC_LEFT, KC_UP,   KC_RGHT, KC_RPRN, },
  {KC_LSFT, KC_MINS, KC_EQUAL,KC_DOWN, KC_UNDS, KC_PLUS, KC_CIRC, },
  {KC_TRNS, TO(_L2), KC_INS,  KC_LGUI, KC_TRNS, KC_BSPC, KC_LCTL, }
},
[_L2] = { /* [> LOWER <] */
  {KC_TRNS, KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP},
  {KC_LCTL, KC_DELT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN},
  {KC_LSFT, KC_TRNS, KC_VOLU, KC_NO,   KC_NO,   KC_NO,    TO(_ON)},
  {RESET,   KC_NO,   KC_VOLD, KC_LGUI, TO(_SOFT),KC_BSPC, KC_LCTL}
},


[_ON] = { /* one-handed */
  {KC_TRNS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, },
  {KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G, },
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ENT},
   {KC_ESC, KC_LGUI, KC_LALT, KC_BSPC, MO(_LW), MO(_RS), KC_SPC, }
},
[_RS] = { /* [> RAISE <] */
  {KC_TRNS, KC_MINS, KC_7 ,   KC_8   , KC_9  ,  KC_UP   },
  {KC_LCTL, KC_EQL , KC_4   , KC_5 ,   KC_6   , KC_DOWN },
  {KC_LSFT, KC_LBRC, KC_1    ,KC_2   , KC_3   , KC_LEFT, KC_RGHT},
    {RESET, KC_RBRC, KC_LALT, KC_BSPC, KC_TRNS, KC_TRNS, KC_SPC, }
},
[_LW] = { /* [> LOWER <] */
  {KC_TRNS, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, },
  {KC_LCTL, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, },
  {KC_LSFT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT },
  {KC_BSLS, KC_LGUI, KC_LALT, KC_BSPC, KC_TRNS, KC_TRNS, KC_SPC, }
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
