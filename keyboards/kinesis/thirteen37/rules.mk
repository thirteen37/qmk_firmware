SRC += leds.c

EXTRA_FLAGS =

# This board has issues with the "full" Bootmagic
COMMAND_ENABLE = yes        # Commands for debug and configuration
NKRO_ENABLE = yes           # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
AUDIO_ENABLE = yes          # Audio output on port C6
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.
