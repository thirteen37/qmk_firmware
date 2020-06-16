#include "thirteen37.h"
#include "leds.h"

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
        caps_lock_led(!led_state.caps_lock);
        num_lock_led(!led_state.num_lock);
        scroll_lock_led(!led_state.scroll_lock);
        return true;
    } else {
        return false;
    }
}

void keyboard_pre_init_kb(void) {
    init_leds();
    keyboard_pre_init_user();
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

    keyboard_post_init_user();
}
