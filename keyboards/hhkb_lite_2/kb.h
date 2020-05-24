#ifndef KB_H
#define KB_H

#include "quantum.h"

#define KEYMAP( \
	K000, K001, K002,       K004, K005, K006,             K009, K010, K011,             \
	K100,       K102, K103, K104, K105, K106, K107, K108, K109,                         \
	K200,       K202, K203, K204, K205, K206, K207, K208, K209,                         \
	K300,       K302, K303, K304, K305, K306,             K309,       K311,       K313, \
	K400,       K402, K403, K404, K405, K406, K407, K408, K409,                   K413, \
	            K502,             K505, K506,             K509,             K512,       \
	K600,             K603,       K605, K606, K607, K608, K609,       K611,       K613, \
	            K702,             K705, K706,                               K712, K713  \
) { \
	{ K000,  K001,  K002,  KC_NO, K004,  K005,  K006,  KC_NO, KC_NO, K009,  K010,  K011,  KC_NO, KC_NO }, \
	{ K100,  KC_NO, K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  KC_NO, KC_NO, KC_NO, KC_NO }, \
	{ K200,  KC_NO, K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  KC_NO, KC_NO, KC_NO, KC_NO }, \
	{ K300,  KC_NO, K302,  K303,  K304,  K305,  K306,  KC_NO, KC_NO, K309,  KC_NO, K311,  KC_NO, K313 }, \
	{ K400,  KC_NO, K402,  K403,  K404,  K405,  K406,  K407,  K408,  K409,  KC_NO, KC_NO, KC_NO, K413 }, \
	{ KC_NO, KC_NO, K502,  KC_NO, KC_NO, K505,  K506,  KC_NO, KC_NO, K509,  KC_NO, KC_NO, K512,  KC_NO }, \
	{ K600,  KC_NO, KC_NO, K603,  KC_NO, K605,  K606,  K607,  K608,  K609,  KC_NO, K611,  KC_NO, K613 }, \
	{ KC_NO, KC_NO, K702,  KC_NO, KC_NO, K705,  K706,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, K712,  K713 }  \
}

#endif