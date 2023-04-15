#pragma once

#include "../config.h"

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 12

/* key matrix pins */
#define MATRIX_ROW_PINS { A0, A1, A2, A6, A7, A8, A9, A10 }
#define MATRIX_COL_PINS { A13, A14, A15, B0, B1, B2, B3, B4, B5, B6, B7, B8 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

#define DAC_SAMPLE_MAX 65535U

#define AUDIO_PIN A4
#define AUDIO_PIN_ALT A5
#define AUDIO_PIN_ALT_AS_NEGATIVE

#define LAYER_STATE_32BIT
