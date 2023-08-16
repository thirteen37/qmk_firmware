// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#define EE_HANDS

#undef TAPPING_TERM
#define TAPPING_TERM 230
#undef QUICK_TAP_TERM
#define QUICK_TAP_TERM 120

// achordion for Atreus
#ifdef KEYBOARD_atreus
bool on_left_hand(keypos_t pos) {
    return (pos.row < 3) && (pos.col < 5);
}

bool on_right_hand(keypos_t pos) {
    return (pos.row < 3) && (pos.col > 5);
}

bool on_thumb(keypos_t pos) {
    return (pos.row > 2);
}

bool atreus_opposite_hands(const keyrecord_t* tap_hold_record,
                           const keyrecord_t* other_record) {
    return on_thumb(tap_hold_record->event.key) ||
        on_thumb(other_record->event.key) ||
        (on_left_hand(tap_hold_record->event.key) ==
         on_right_hand(other_record->event.key));
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  return atreus_opposite_hands(tap_hold_record, other_record);
}
#endif

// Ergodox extended layout
#ifdef KEYBOARD_ergodox_ez
#define MIRYOKU_MAPPING(\
     K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09,\
     K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19,\
     K20, K21, K22, K23, K24,                K25, K26, K27, K28, K29,\
     N30, N31, K32, K33, K34,                K35, K36, K37, N38, N39\
)\
LAYOUT_ergodox_pretty(\
XXX, XXX, XXX, XXX, XXX, XXX, XXX,      XXX, XXX, XXX, XXX, XXX, XXX, XXX,\
XXX, K00, K01, K02, K03, K04, XXX,      XXX, K05, K06, K07, K08, K09, XXX,\
KC_CAPS, K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19, XXX,\
XXX, K20, K21, K22, K23, K24, XXX,      XXX, K25, K26, K27, K28, K29, XXX,\
XXX, XXX, XXX, XXX, K32,                          K37, XXX, XXX, XXX, XXX,\
                         XXX, XXX,      XXX, XXX,\
                              XXX,      XXX,\
                    K33, K34, XXX,      XXX, K35, K36\
)
#endif
