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
    writePinHigh(B12);
    writePinHigh(B13);
    writePinHigh(B14);
    writePinHigh(B15);
}
