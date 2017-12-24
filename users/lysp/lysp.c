#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "lysp.h"

#define BASE 0 // Default layer
#define FNKY 1 // Fn and media
#define MSNM 2 // Mouse and numpad
#define GAME 3 // Gamepad

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(FNKY)                // FN1 - Momentary Layer 1 (Fn and media)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_ergodox(
		 // Left hand
		 KC_GRV,  KC_1,    KC_2,    KC_3,  KC_4,    KC_5,          KC_ESC,
		 KC_TAB,  KC_Q,    KC_W,    KC_E,  KC_R,    KC_T,          KC_BSLS,
		 KC_CAPS, KC_A,    KC_S,    KC_D,  KC_F,    KC_G,
		 KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,          GUI_T(KC_LGUI),
		 MO(1),   KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
		                                            CTL_T(KC_NO), ALT_T(KC_APP),
		                                                                KC_HOME,
		                                               KC_BSPC, KC_DEL,  KC_END,
		 // Right hand
		     KC_EQL,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
		     KC_LBRC,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RBRC,
		                    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
		     RGUI_T(KC_NO), KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
		                             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, TG(2),
		 RALT_T(KC_NO), RCTL_T(KC_NO),
		 KC_PGUP,
		 KC_PGDN, KC_ENT, KC_SPC
  ),

  [FNKY] = LAYOUT_ergodox(
		 // Left hand
		 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		                                              KC_TRNS, KC_TRNS,
		                                                       KC_TRNS,
		                                     KC_TRNS, KC_INS,  KC_TRNS,
		 // Right hand
		     KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,
		     KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,
		              KC_MPLY, KC_MSTP, KC_MNXT, KC_MPRV, KC_NO,  KC_TRNS,
		     KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO,   KC_NO,  KC_TRNS,
		                       KC_PSCR, KC_SLCK, KC_PAUS, KC_NO,  TG(3),
		 KC_TRNS, KC_TRNS,
		 KC_TRNS,
		 KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [MSNM] = LAYOUT_ergodox(
		 // Left hand
		 KC_TRNS, KC_NO,   KC_BTN3, KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
		 KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_WH_L, KC_TRNS,
		 KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_WH_R,
		 KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
		 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		                                              KC_TRNS, KC_TRNS,
		                                                       KC_TRNS,
		                                     KC_TRNS, KC_TRNS, KC_TRNS,
		 // Right hand
		     KC_TRNS, KC_NO,   KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_BSPC,
		     KC_BTN1, KC_NO,   KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_NO,
		              KC_NO,   KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_NO,
		     KC_BTN2, KC_NO,   KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_TRNS,
		                       KC_P0,   KC_P0,   KC_PDOT, KC_PENT, KC_TRNS,
		 KC_TRNS, KC_TRNS,
		 KC_TRNS,
		 KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [GAME] = LAYOUT_ergodox(
		 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		                                              KC_TRNS, KC_TRNS,
		                                                       KC_TRNS,
		                                     KC_TRNS, KC_SPC,  KC_TRNS,
		     EPRM,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		 KC_TRNS, KC_TRNS,
		 KC_TRNS,
		 KC_TRNS, KC_TRNS, KC_TRNS
  ),
};
