#include QMK_KEYBOARD_H

/* Layer definitions */
#define QWERT  0 /* Base QWERTY */
#define DVORK  1 /* Base Dvorak */
#define TH_WIN 2 /* Thumb Win */
#define TH_MAC 3 /* Thumb Mac */
#define TH_PC  4 /* Thumb PC */
#define EMBED  5 /* "Embedded" layer */
#define PROG   6 /* "Program" layer */
#define PROGS  7 /* Shifted "program" layer */

#define TH_LAYER_MASK ((1UL<<TH_WIN) | (1UL<<TH_MAC) | (1UL<<TH_PC))

/* Custom keycodes */
enum custom_keycodes { QWERTY = SAFE_RANGE, DVORAK, WIN, MAC, PC };

/* Custom audio */
#ifdef AUDIO_ENABLE
#define KEYPAD_ON_SOUND E__NOTE(_A4), E__NOTE(_B4),
#define KEYPAD_OFF_SOUND E__NOTE(_B4), E__NOTE(_A4),
float keypad_on_song[][2] = SONG(KEYPAD_ON_SOUND);
float keypad_off_song[][2] = SONG(KEYPAD_OFF_SOUND);
#define THUMB_WIN_SOUND E__NOTE(_GS5), E__NOTE(_A5), S__NOTE(_REST), E__NOTE(_E6), E__NOTE(_D6),
#define THUMB_MAC_SOUND E__NOTE(_GS5), E__NOTE(_A5), S__NOTE(_REST), E__NOTE(_GS5), E__NOTE(_A6),
#define THUMB_PC_SOUND E__NOTE(_GS5), E__NOTE(_A5), S__NOTE(_REST), Q__NOTE(_D6),
float thumb_win_song[][2] = SONG(THUMB_WIN_SOUND);
float thumb_mac_song[][2] = SONG(THUMB_MAC_SOUND);
float thumb_pc_song[][2] = SONG(THUMB_PC_SOUND);
#endif

/* EEPROM */
typedef union {
  uint32_t raw;
  struct {
    uint8_t thumb_state :8;
  };
} user_config_t;

user_config_t user_config;

/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 | RESET  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Caps   |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   |   \  | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Ctrl | Alt  |         | Gui  | Ctrl |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | BkSp | Del  |------|         |------|Return| Space|
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [QWERT] = LAYOUT_pretty(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,         KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_SLCK,  KC_PAUS,  TG(EMBED),MO(PROG),
    KC_EQL,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                                                      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                                                                      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
    KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                                                                      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                                                                      KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
              KC_GRV,   KC_INS,   KC_LEFT,  KC_RGHT,                                                                                       KC_UP,    KC_DOWN,  KC_LBRC,  KC_RBRC,
                                                      KC_LCTL,  KC_LALT,                                               KC_RGUI,  KC_RCTL,
                                                                KC_HOME,                                               KC_PGUP,
                                            KC_BSPC,  KC_DEL,   KC_END,                                                KC_PGDN,  KC_ENTER, KC_SPC
                          ),

  [DVORK] = LAYOUT_pretty(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,         KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_SLCK,  KC_PAUS,  TG(EMBED),MO(PROG),
    KC_EQL,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                                                      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,
    KC_TAB,   KC_QUOT,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,                                                                      KC_F,     KC_G,     KC_C,     KC_R,     KC_L,     KC_SLSH,
    KC_CAPS,  KC_A,     KC_O,     KC_E,     KC_U,     KC_I,                                                                      KC_D,     KC_H,     KC_T,     KC_N,     KC_S,     KC_BSLS,
    KC_LSFT,  KC_SCLN,  KC_Q,     KC_J,     KC_K,     KC_X,                                                                      KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,     KC_RSFT,
              KC_GRV,   KC_INS,   KC_LEFT,  KC_RGHT,                                                                                       KC_UP,    KC_DOWN,  KC_LBRC,  KC_RBRC,
                                                      KC_LCTL,  KC_LALT,                                               KC_RGUI,  KC_RCTL,
                                                                KC_HOME,                                               KC_PGUP,
                                            KC_BSPC,  KC_DEL,   KC_END,                                                KC_PGDN,  KC_ENTER, KC_SPC
                          ),

  [TH_WIN] = LAYOUT_pretty(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,       _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                                                                   _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                                                                   _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                                                                   _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                                                                   _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,                                                                                       _______,  _______,  _______,  _______,
                                                      KC_LCTL,  KC_LALT,                                               KC_RGUI,  KC_RCTL,
                                                                KC_HOME,                                               KC_PGUP,
                                            KC_BSPC,  KC_DEL,   KC_END,                                                KC_PGDN,  KC_ENTER, KC_SPC
                           ),

  [TH_MAC] = LAYOUT_pretty(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,       _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                                                                   _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                                                                   _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                                                                   _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                                                                   _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,                                                                                       _______,  _______,  _______,  _______,
                                                      KC_LGUI,  KC_LALT,                                               KC_RCTL,  KC_RGUI,
                                                                KC_HOME,                                               KC_PGUP,
                                            KC_BSPC,  KC_DEL,   KC_END,                                                KC_PGDN,  KC_ENTER, KC_SPC
                           ),

  [TH_PC] = LAYOUT_pretty(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,       _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                                                                   _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                                                                   _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                                                                   _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                                                                   _______,  _______,  _______,  _______,  _______,  _______,
              _______,  _______,  _______,  _______,                                                                                       _______,  _______,  _______,  _______,
                                                      KC_LCTL,  KC_LALT,                                               KC_RALT,  KC_RCTL,
                                                                KC_HOME,                                               KC_PGUP,
                                            KC_BSPC,  KC_DEL,   KC_END,                                                KC_PGDN,  KC_ENTER, KC_SPC
                          ),

  [EMBED] = LAYOUT_pretty(
    _______,  KC_LGUI,  KC_RALT,  KC_APP,   KC_MPLY,  KC_MPRV, KC_MNXT,  KC_CALC,   XXXXXXX,       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MUTE,  KC_VOLD,  KC_VOLU,  TG(EMBED),_______,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                                                                   XXXXXXX,  KC_NLCK,  KC_PEQL,  KC_PSLS,  KC_PAST,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                                                                   XXXXXXX,  KC_P7,    KC_P8,    KC_P9,    KC_PMNS,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                                                                   XXXXXXX,  KC_P4,    KC_P5,    KC_P6,    KC_PPLS,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                                                                   XXXXXXX,  KC_P1,    KC_P2,    KC_P3,    KC_PENT,  XXXXXXX,
              _______,  KC_INS,   KC_LEFT,  KC_RIGHT,                                                                                      KC_UP,    KC_DOWN,  KC_PDOT,  KC_PENT,
                                                      _______,  _______,                                               _______,  _______,
                                                                _______,                                               _______,
                                            _______,  _______,  _______,                                               _______,  _______,  _______
                          ),

  [PROG] = LAYOUT_pretty(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  QWERTY,   DVORAK,   WIN,      MAC,      PC,       CK_TOGG,       RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    _______,  _______,  _______,  _______,  _______,  _______,                                                                   _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                                                                   _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                                                                   _______,  _______,  _______,  _______,  _______,  _______,
    MO(PROGS),_______,  _______,  _______,  _______,  _______,                                                                   _______,  _______,  _______,  _______,  _______,MO(PROGS),
              _______,  _______,  _______,  _______,                                                                                       _______,  _______,  _______,  _______,
                                                      _______,  _______,                                               _______,  _______,
                                                                _______,                                               _______,
                                            _______,  _______,  _______,                                               _______,  _______,  _______
                         ),

  [PROGS] = LAYOUT_pretty(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  AU_TOG,        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                                                                   _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                                                                   _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                                                                   _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                                                                   _______,  _______,  _______,  _______,  _______,  _______,
              _______,  _______,  _______,  _______,                                                                                       _______,  _______,  _______,  _______,
                                                      _______,  _______,                                               _______,  _______,
                                                                _______,                                               _______,
                                            _______,  _______,  _______,                                               _______,  _______,  _______
                          ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case QWERTY:
            set_single_persistent_default_layer(QWERT);
            return false;
        case DVORAK:
            set_single_persistent_default_layer(DVORK);
            return false;
        case WIN:
            layer_and(~TH_LAYER_MASK);
            layer_on(TH_WIN);
            return false;
        case MAC:
            layer_and(~TH_LAYER_MASK);
            layer_on(TH_MAC);
            return false;
        case PC:
            layer_and(~TH_LAYER_MASK);
            layer_on(TH_PC);
            return false;
        }
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    /* keypad layer */
    bool keypad_state = layer_state_cmp(state, EMBED);
#ifdef AUDIO_ENABLE
    static bool last_keypad_state = 0;
    if (last_keypad_state != keypad_state) {
        if (keypad_state) PLAY_SONG(keypad_on_song); else PLAY_SONG(keypad_off_song);
        last_keypad_state = keypad_state;
    }
#endif
    if (keypad_state) keypad_led_on(); else keypad_led_off();
    /* persistent thumb cluster toggles */
    layer_state_t thumb_state = TH_WIN;
    if (layer_state_cmp(state, TH_WIN)) {
        thumb_state = TH_WIN;
    } else if (layer_state_cmp(state, TH_MAC)) {
        thumb_state = TH_MAC;
    } else if (layer_state_cmp(state, TH_PC)) {
        thumb_state = TH_PC;
    }
    if (user_config.thumb_state != thumb_state) {
        switch (thumb_state) {
        case TH_WIN:
#ifdef AUDIO_ENABLE
            PLAY_SONG(thumb_win_song);
#endif
            break;
        case TH_MAC:
#ifdef AUDIO_ENABLE
            PLAY_SONG(thumb_mac_song);
#endif
            break;
        case TH_PC:
#ifdef AUDIO_ENABLE
            PLAY_SONG(thumb_pc_song);
#endif
            break;
        }
        user_config.thumb_state = thumb_state;
        eeconfig_update_user(user_config.raw);
    }
    return state;
};

void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();

    /* Set thumb layer */
    layer_on(user_config.thumb_state);
}

void eeconfig_init_user(void) {
    user_config.raw = 0;
    user_config.thumb_state = TH_WIN;
    eeconfig_update_user(user_config.raw);
}
