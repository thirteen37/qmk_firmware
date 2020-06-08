#include "thirteen37.h"

bool led_update_kb(led_t led_state) {
    if (led_update_user(led_state)) {
        if (led_state.caps_lock) caps_lock_led_on(); else caps_lock_led_off();
        if (led_state.num_lock) num_lock_led_on(); else num_lock_led_off();
        if (led_state.scroll_lock) scroll_lock_led_on(); else scroll_lock_led_off();
        return true;
    } else {
        return false;
    }
}

void keyboard_pre_init_kb(void) {
    /* Setup LEDs */
    setPinOutput(B12);
    setPinOutput(B13);
    setPinOutput(B14);
    setPinOutput(B15);
}

void keyboard_post_init_kb(void) {
    /* Animate LEDs */
    caps_lock_led_on();
    wait_ms(50);
    num_lock_led_on();
    wait_ms(50);
    caps_lock_led_off();
    scroll_lock_led_on();
    wait_ms(50);
    num_lock_led_off();
    keypad_led_on();
    wait_ms(50);
    scroll_lock_led_off();
    wait_ms(50);
    keypad_led_off();
}

/* LED helpers */

void all_led_off(void) {
    caps_lock_led_off();
    num_lock_led_off();
    scroll_lock_led_off();
    keypad_led_off();
}

void all_led_on(void) {
    caps_lock_led_on();
    num_lock_led_on();
    scroll_lock_led_on();
    keypad_led_on();
}

void num_lock_led_on(void) {
    writePinLow(B13);
}

void caps_lock_led_on(void) {
    writePinLow(B12);
}

void scroll_lock_led_on(void) {
    writePinLow(B14);
}

void keypad_led_on(void) {
    writePinLow(B15);
}

void num_lock_led_off(void) {
    writePinHigh(B13);
}

void caps_lock_led_off(void) {
    writePinHigh(B12);
}

void scroll_lock_led_off(void) {
    writePinHigh(B14);
}

void keypad_led_off(void) {
    writePinHigh(B15);
}
