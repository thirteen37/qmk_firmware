#include "thirteen37.h"

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  return 600;
}

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
