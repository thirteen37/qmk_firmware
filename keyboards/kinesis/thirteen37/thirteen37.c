#include "thirteen37.h"

bool led_update_kb(led_t led_state) {
    if (led_update_user(led_state)) {
        writePin(B12, !led_state.caps_lock);
        writePin(B13, !led_state.num_lock);
        writePin(B14, !led_state.scroll_lock);
    }
    return true;
}

void keyboard_post_init_kb(void) {
    /* Setup LEDs */
    setPinOutput(B12);
    setPinOutput(B13);
    setPinOutput(B14);
    setPinOutput(B15);
    writePinLow(B12);
    wait_ms(50);
    writePinLow(B13);
    wait_ms(50);
    writePinHigh(B12);
    writePinLow(B14);
    wait_ms(50);
    writePinHigh(B13);
    writePinLow(B15);
    wait_ms(50);
    writePinHigh(B14);
    wait_ms(50);
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
