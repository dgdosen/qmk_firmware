// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY    0
#define _COLEMAK   1
#define _DVORAK    2
#define _ADJUST    16
#define _DIGITS    20
#define _FUNCTIONS 21
#define _SYMBOLS   22
#define _BRACES    23
#define _WINDOWS   24

#define EV_D    100
#define EV_S    101
#define EV_B    102
#define EV_F    103
#define EV_W    104

#define EV_L    110
#define EV_C    111

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ct/T |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Bksp  |    Space    |Enter | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_ESC,  KC_Q,    F(EV_W),    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {F(EV_C), KC_A,   F(EV_S), F(EV_D), F(EV_F),    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V, F(EV_B),    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    KC_RSFT},
  {F(EV_L), KC_LCTL, KC_LALT, KC_LGUI, KC_BSPC,   KC_SPC,  KC_SPC,  KC_ENT,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Digits
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |   7  |   8  |   9  |  /   |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   4  |   5  |   6  |  *   |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   1  |   2  |   3  |  -   |  =   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |             |   0  |  00  |   .  |  +   |Enter |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 */
[_DIGITS] = {
  {_______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_SLSH, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_4,    KC_5,    KC_6,    KC_ASTR, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    KC_MINS, KC_EQL },
  {_______, _______, _______, _______, _______, _______, _______, KC_0,    KC_0,    KC_DOT,  KC_PLUS, KC_ENT }
},

/* Functions
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |  F7  |  F8  |  F9  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  F4  |  F5  |  F6  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  F1  |  F2  |  F3  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |             |  F10 | F11  | F12  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 */
[_FUNCTIONS] = {
  {_______, _______, _______, _______, _______, _______, _______, KC_F7,   KC_F8,   KC_F9,   _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_F4,   KC_F5,   KC_F6,   _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_F10,  KC_F11,  KC_F12,  _______, _______}
},

/* Symbols
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |  &   |  *   |  (   |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  $   |  %   |  ^   |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  !   |  @   |  #   |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |             |  )   |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 */
[_SYMBOLS] = {
  {_______, _______, _______, _______, _______, _______, _______, KC_AMPR, KC_ASTR, KC_LPRN, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_DLR,  KC_PERC, KC_CIRC, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_EXLM, KC_AT,   KC_HASH, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_RPRN, _______, _______, _______, _______}
},

/* Braces
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |  ~   |  `   |  _   |  =   |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  {   |  }   |  |   |  \   |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  [   |  ]   |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 */
[_BRACES] = {
  {_______, _______, _______, _______, _______, _______, _______, KC_TILD, KC_GRV,  KC_UNDS, KC_EQL , _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, KC_PIPE, KC_BSLS, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Windows (Desktops)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |  D7  |  D8  |  D9  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  D4  |  D5  |  D6  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  D1  |  D2  |  D3  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |             |  D10 |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 */
[_WINDOWS] = {
  {_______, _______, _______, _______, _______, _______, _______, F(27),   F(28),  F(29),   _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, F(24),   F(25),  F(26),   _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, F(21),   F(22),  F(23),   _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, F(20),  _______, _______, _______, _______}
},

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Bksp  |    Space    |Enter | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
  {KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {F(EV_L), KC_LCTL, KC_LALT, KC_LGUI, KC_BSPC,   KC_SPC,  KC_SPC,  KC_ENT,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Bksp  |    Space    |Enter | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC},
  {KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH},
  {KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT },
  {F(EV_L), KC_LCTL, KC_LALT, KC_LGUI, KC_BSPC,   KC_SPC,  KC_SPC,  KC_ENT,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL},
  {_______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _QWERTY,  _COLEMAK, _DVORAK,  _______,  _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_MODS_KEY(MOD_LSFT, KC_1),             // !
  [2] = ACTION_MODS_KEY(MOD_LSFT, KC_2),             // @
  [3] = ACTION_MODS_KEY(MOD_LSFT, KC_3),             // #
  [4] = ACTION_MODS_KEY(MOD_LSFT, KC_4),             // $
  [5] = ACTION_MODS_KEY(MOD_LSFT, KC_5),             // %
  [6] = ACTION_MODS_KEY(MOD_LSFT, KC_6),             // ^
  [7] = ACTION_MODS_KEY(MOD_LSFT, KC_7),             // &
  [8] = ACTION_MODS_KEY(MOD_LSFT, KC_8),             // *
  [9] = ACTION_MODS_KEY(MOD_LSFT, KC_9),             // (
  [10] = ACTION_MODS_KEY(MOD_LSFT, KC_0),             // )
  [20] = ACTION_MODS_KEY(MOD_LCTL | MOD_LALT | MOD_LGUI, KC_0),  // mac desktop
  [21] = ACTION_MODS_KEY(MOD_LCTL | MOD_LALT | MOD_LGUI, KC_1),  // mac desktop
  [22] = ACTION_MODS_KEY(MOD_LCTL | MOD_LALT | MOD_LGUI, KC_2),  // mac desktop
  [23] = ACTION_MODS_KEY(MOD_LCTL | MOD_LALT | MOD_LGUI, KC_3),  // mac desktop
  [24] = ACTION_MODS_KEY(MOD_LCTL | MOD_LALT | MOD_LGUI, KC_4),  // mac desktop
  [25] = ACTION_MODS_KEY(MOD_LCTL | MOD_LALT | MOD_LGUI, KC_5),  // mac desktop
  [26] = ACTION_MODS_KEY(MOD_LCTL | MOD_LALT | MOD_LGUI, KC_6),  // mac desktop
  [27] = ACTION_MODS_KEY(MOD_LCTL | MOD_LALT | MOD_LGUI, KC_7),  // mac desktop
  [28] = ACTION_MODS_KEY(MOD_LCTL | MOD_LALT | MOD_LGUI, KC_8),  // mac desktop
  [29] = ACTION_MODS_KEY(MOD_LCTL | MOD_LALT | MOD_LGUI, KC_9),  // mac desktop
  [EV_D]  =  ACTION_LAYER_TAP_KEY(_DIGITS, KC_D),    // _DIGITS or D
  [EV_S]  =  ACTION_LAYER_TAP_KEY(_SYMBOLS, KC_S),   // _SYMBOLS or S
  [EV_B]  =  ACTION_LAYER_TAP_KEY(_BRACES, KC_B),    // _BRACES or B
  [EV_F]  =  ACTION_LAYER_TAP_KEY(_FUNCTIONS, KC_F), // _FUNCTIONS or F
  [EV_W]  =  ACTION_LAYER_TAP_KEY(_WINDOWS, KC_W),   // _WINDOWS or W

  [EV_L]  =  ACTION_BACKLIGHT_STEP(),                 //
  [EV_C]  =  ACTION_MODS_TAP_KEY(MOD_LCTL, KC_TAB )   //
};

