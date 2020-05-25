#include QMK_KEYBOARD_H

// Helpful defines
#define GRAVE_MODS  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT)|MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI)|MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *  You can use _______ in place for KC_TRNS (transparent)   *
 *  Or you can use XXXXXXX for KC_NO (NOOP)                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// Each layer gets a name for readability.
// The underscores don't mean anything - you can
// have a layer called STUFF or any other name.
// Layer names don't all need to be of the same
// length, and you can also skip them entirely
// and just use numbers.
#define _BL 0
#define _FN 1
#define _RS 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BL] = LAYOUT(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_ESC, \
        KC_TAB,    KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,   KC_LBRC, KC_RBRC,    KC_BSPC, \
        KC_LGUI,       KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L,     KC_SCLN, KC_QUOT,    KC_ENT, \
        KC_LSFT,         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M,    KC_COMM, KC_DOT, KC_SLSH,   KC_RSFT, \
                MO(_FN), KC_LALT, KC_LCTL,              KC_SPC,                KC_RCTL, KC_RALT, \
                                                                                                  KC_UP, \
                                                                                         KC_LEFT, KC_DOWN, KC_RGHT \
           ),
	[_FN] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  RESET, \
        KC_CAPS,      _______, _______, _______, _______, _______, _______, KC_MUTE, KC_PSCR, KC_BRMD, KC_BRMU, KC_UP,  KC_NO,        _______, \
        _______,          _______, _______, _______, _______, _______, _______, KC_VOLU, KC_HOME, KC_PGUP, KC_LEFT, KC_RIGHT,         _______, \
        _______,               _______, _______, _______, _______, _______, _______, KC_VOLD, KC_END, KC_PGDN, KC_DOWN,          _______, \
                 _______, _______, _______,                        TG(_RS),                   _______, _______, \
                                                                                                                             KC_PGUP, \
                                                                                                                    KC_HOME, KC_PGDN, KC_END \
           ),
	[_RS] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, KC_TAB,  KC_NLCK, KC_PSLS, KC_PAST, _______, _______, _______, \
        _______,      _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, _______,     _______, \
        _______,          _______, _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS,          _______, \
        _______,               _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,              _______, \
                 TO(_BL), _______, _______,                        _______,                   KC_P0,   KC_PDOT, \
                                                                                                                             _______, \
                                                                                                                    _______, _______, _______ \
           ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	/* keyevent_t event = record->event; */

	switch (id) {

	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}
