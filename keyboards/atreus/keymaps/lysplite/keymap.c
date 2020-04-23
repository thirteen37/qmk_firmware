#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _RS 1
#define _LW 2
#define _SD 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QW] = LAYOUT( /* Qwerty */
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN ,
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH ,
  KC_ESC, KC_TAB, MO(_RS),  KC_LSFT, KC_BSPC,  KC_LCTL, KC_LALT, KC_SPC,  KC_LGUI, KC_MINS, KC_QUOT, KC_ENT  ),
/*
 *  !       @     [     ]    |        ||      up     7     8     9    *
 *  #       $     (     )    `        ||      dn     4     5     6    +
 *  %       ^     {     }    ~        ||       &     1     2     3    \
 * lower  insert  fn  shift bksp ctrl || alt space  super  .     0    =
 */
[_RS] = LAYOUT( /* [> RAISE <] */
  KC_EXLM, KC_AT,   KC_LBRC, KC_RBRC, KC_PIPE,                   KC_UP,   KC_7,    KC_8,   KC_9, KC_ASTR ,
  KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                    KC_DOWN, KC_4,    KC_5,   KC_6, KC_PLUS ,
  KC_PERC, KC_CIRC, KC_LCBR, KC_RCBR, KC_TILD,                   KC_AMPR, KC_1,    KC_2,   KC_3, KC_BSLS ,
  TG(_LW), KC_INS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DOT, KC_0, KC_EQL  ),
/*
 * insert home   up  end   pgup       ||      up     F7     F8    F9     F10
 *  del   left  down right pgdn       ||     down    F4     F5    F6     F11
 *       volup             reset      ||             F1     F2    F3     F12
 *       voldn   L0  shift bksp  ctrl || alt space  super  prtsc scroll pause
 */
[_LW] = LAYOUT( /* [> LOWER <] */
  KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
  KC_DELT, KC_LEFT, KC_DOWN, KC_RGHT, KC_DOWN,                   KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
  KC_NO,   KC_VOLU, KC_NO,   KC_NO,   RESET,                     KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
  KC_NO,   KC_VOLD, TO(_QW), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS ),
/* Super Duper */
[_SD] = LAYOUT( /* [> Super Duper <] */
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS ,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS ,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS ,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS ),
};


// Super Duper

enum combo_events {
  SUPERDUPER,
};

const uint16_t PROGMEM sd_combo[] = {KC_ESC, KC_TAB, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [SUPERDUPER] = COMBO_ACTION(sd_combo),
};


void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
  case SUPERDUPER:
    if (pressed) {
      layer_on(_SD);
    } else {
      layer_off(_SD);
      unregister_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT)); // Sometimes mods are held, unregister them
    }
    break;
  }
}
