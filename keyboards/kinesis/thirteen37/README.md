# Kinesis Advantage thirteen37 firmware

This is the firmware for the QMK Proton C-based replacement controller
board, found at
[thirteen37/Kinesis_Advantage-Proton_C](https://github.com/thirteen37/Kinesis_Advantage-Proton_C).

It is intended for [Kinesis (Original) Advantage
(KB500USB)](https://kinesis-ergo.com/support/advantage/) keyboards.

The code enables the following functionality:

* All four LEDs: Caps, Num, Scroll locks and Keypad
* Audio if you have installed the optional speaker

## Keymap

The recommended keymap is `thirteen37`, which tries to replicate as
much of the functionality of the newer [Advantage
2](https://kinesis-ergo.com/support/advantage2/) keyboards and more:

* QWERTY and Dvorak base layouts persisted to EEPROM.
* Embedded numpa, multimedia controls on keypad layer.
* Windows, Mac, and PC thumb clusters, which can be used in
  combination with any base layout. They are also persisted in EEPROM.
* Audible key clicks which can be toggled persistently.
* Audible mode changes (base layout, caps/num/scroll lock, etc) which
  can be toggled persistently.

Differences and extras:

* Additional Colemak and Workman layouts also persisted to EEPROM
* QMK dynamic macros, in place of Kinesis's macros

To build the firmware with this keymap:

    qmk compile -kb kinesis/thirteen37 -km thirteen37

The firmware should also work with the `default` keymap:

    qmk compile -kb kinesis/thirteen37 -km default
