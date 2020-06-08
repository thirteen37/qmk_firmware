#include "thirteen37.h"

#ifdef AUDIO_ENABLE
float caps_on_song[][2] = SONG(CAPS_LOCK_ON_SOUND);
float caps_off_song[][2] = SONG(CAPS_LOCK_OFF_SOUND);
float num_on_song[][2] = SONG(NUM_LOCK_ON_SOUND);
float num_off_song[][2] = SONG(NUM_LOCK_OFF_SOUND);
float scroll_on_song[][2] = SONG(SCROLL_LOCK_ON_SOUND);
float scroll_off_song[][2] = SONG(SCROLL_LOCK_OFF_SOUND);
#endif

bool led_update_kb(led_t led_state) {
#ifdef AUDIO_ENABLE
    static uint8_t caps_state = 0;
    if (caps_state != led_state.caps_lock) {
        if (led_state.caps_lock) PLAY_SONG(caps_on_song); else PLAY_SONG(caps_off_song);
        caps_state = led_state.caps_lock;
    }
    static uint8_t num_state = 0;
    if (num_state != led_state.num_lock) {
        if (led_state.num_lock) PLAY_SONG(num_on_song); else PLAY_SONG(num_off_song);
        num_state = led_state.num_lock;
    }
    static uint8_t scroll_state = 0;
    if (scroll_state != led_state.scroll_lock) {
        if (led_state.scroll_lock) PLAY_SONG(scroll_on_song); else PLAY_SONG(scroll_off_song);
        scroll_state = led_state.scroll_lock;
    }
#endif
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
