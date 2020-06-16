#include QMK_KEYBOARD_H
#include "leds.h"

void init_leds(void) {
    setPinOutput(B12);
    setPinOutput(B13);
    setPinOutput(B14);
    setPinOutput(B15);
}

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

void caps_lock_led_on(void) {
    caps_lock_led(0);
}

void num_lock_led_on(void) {
    num_lock_led(0);
}

void scroll_lock_led_on(void) {
    scroll_lock_led(0);
}

void keypad_led_on(void) {
    keypad_led(0);
}

void caps_lock_led_off(void) {
    caps_lock_led(1);
}

void num_lock_led_off(void) {
    num_lock_led(1);
}

void scroll_lock_led_off(void) {
    scroll_lock_led(1);
}

void keypad_led_off(void) {
    keypad_led(1);
}

void caps_lock_led(int level) {
    writePin(B12, level);
}

void num_lock_led(int level) {
    writePin(B13, level);
}

void scroll_lock_led(int level) {
    writePin(B14, level);
}

void keypad_led(int level) {
    writePin(B15, level);
}
