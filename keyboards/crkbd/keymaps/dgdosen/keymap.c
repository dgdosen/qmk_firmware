#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _DIGITS 1
#define _FUNCTIONS 2
#define _SYMBOLS 3
#define _BRACES 4
#define _WINDOWS 5
#define _ARROWS 6
#define _GAPS 7
#define _ADJUST 8
#define _RAISE 9
#define _LOWER 10

#define DESK_1 ACTION_MODS_KEY(MOD_LALT | MOD_LGUI | KC_1)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  DIGITS,
  FUNCTIONS,
  SYMBOLS,
  BRACES,
  WINDOWS,
  ARROWS,
  GAPS,
  ADJUST,
  LOWER,
  RAISE,
  BACKLIT,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q, LT(_WINDOWS, KC_W), KC_E, KC_R, KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LCTL_T(KC_TAB), LT(_ARROWS, KC_A), LT(_SYMBOLS, KC_S), LT(_DIGITS, KC_D), LT(_FUNCTIONS, KC_F), LT(_GAPS, KC_G),   KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V, LT(_BRACES, KC_B),               KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, RSFT_T(KC_ENT),\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,   KC_LGUI, KC_ENT,  KC_SPC,  KC_SPC,  KC_BSPC \
                                      //`--------------------------'  `--------------------------'

  ),

  [_DIGITS] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_GRV,    KC_7,    KC_8,    KC_9, KC_ASTR, KC_SLSH,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_DOT,    KC_4,    KC_5,    KC_6, KC_PLUS, KC_MINS,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_0,    KC_1,    KC_2,    KC_3, KC_EQL , KC_ENT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,  KC_LGUI, KC_ENT,   KC_SPC, KC_SPC,  KC_BSPC \
                                      //`--------------------------'  `--------------------------'

  ),

  [_FUNCTIONS] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,   KC_F7,   KC_F8,   KC_F9, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,   KC_F4,   KC_F5,   KC_F6, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,   KC_F1,   KC_F2,   KC_F3, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,   KC_LGUI, KC_ENT,  KC_RALT,  KC_SPC,  KC_BSPC \
                                      //`--------------------------'  `--------------------------'

  ),

  [_SYMBOLS] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_TILD,   KC_AMPR,   KC_ASTR,   KC_LPRN, KC_RPRN, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_GRV,   KC_DLR,   KC_PERC,   KC_CIRC, KC_PIPE, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_RPRN, KC_EXLM,   KC_AT, KC_HASH, KC_BSLS, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,   KC_LGUI, KC_ENT,  KC_RALT,  KC_SPC,  KC_BSPC \
                                      //`--------------------------'  `--------------------------'

  ),

  [_BRACES] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_TILD, KC_LABK, KC_RABK, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_GRV,  KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,   KC_LGUI, KC_ENT,  KC_RALT,  KC_SPC,  KC_BSPC \
                                      //`--------------------------'  `--------------------------'

  ),

  [_WINDOWS] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, LCAG(KC_7), LCAG(KC_8), LCAG(KC_9), XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, LCAG(KC_4), LCAG(KC_5), LCAG(KC_6), XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      LCAG(KC_0), LCAG(KC_1), LCAG(KC_2), LCAG(KC_3), XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,   KC_LGUI, KC_ENT,  KC_RALT,  KC_SPC,  KC_BSPC \
                                      //`--------------------------'  `--------------------------'

  ),

  [_ARROWS] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,   KC_LGUI, KC_ENT,  KC_RALT,  KC_SPC,  KC_BSPC \
                                      //`--------------------------'  `--------------------------'

  ),
  [_GAPS] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_UNDS, KC_MINS,  KC_EQL,  KC_GRV, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,   KC_LGUI, KC_ENT,  KC_RALT,  KC_SPC,  KC_BSPC \
                                      //`--------------------------'  `--------------------------'

  )

  /* [_LOWER] = LAYOUT( \ */
  /* //,-----------------------------------------------------.                    ,-----------------------------------------------------. */
  /*      KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6, KC_PGDN, KC_PGUP,    KC_9,    KC_0, KC_BSPC,\ */
  /* //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------| */
  /*     KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,\ */
  /* //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------| */
  /*     KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_HOME,  KC_END, XXXXXXX, XXXXXXX, XXXXXXX,\ */
  /* //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------| */
  /*                                         KC_LGUI,   LOWER,  KC_SPC,     KC_ENT,   RAISE, KC_RALT \ */
  /*                                     //`--------------------------'  `--------------------------' */
  /*   ), */

  /* [_RAISE] = LAYOUT( \ */
  /* //,-----------------------------------------------------.                    ,-----------------------------------------------------. */
  /*      KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,\ */
  /* //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------| */
  /*     KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR, KC_PIPE,  KC_GRV,\ */
  /* //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------| */
  /*     KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD,\ */
  /* //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------| */
  /*                                         KC_LGUI,   LOWER,  KC_SPC,     KC_ENT,   RAISE, KC_RALT \ */
  /*                                     //`--------------------------'  `--------------------------' */
  /* ) */

};

int RGB_current_mode;

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
  // Host Keyboard Layer Status
  oled_write_P(PSTR("DGD Layer: "), false);
  switch (get_highest_layer(layer_state)) {
    case _QWERTY:
      oled_write_P(PSTR("Default\n"), false);
      break;
    case _BRACES:
      oled_write_P(PSTR("Braces\n"), false);
      break;
    case _GAPS:
      oled_write_P(PSTR("Gaps\n"), false);
      break;
    case _ARROWS:
      oled_write_P(PSTR("Arrows\n"), false);
      break;
    case _WINDOWS:
      oled_write_P(PSTR("Windows\n"), false);
      break;
    case _SYMBOLS:
      oled_write_P(PSTR("Symbols\n"), false);
      break;
    case _DIGITS:
      oled_write_P(PSTR("Digits\n"), false);
      break;
    case _FUNCTIONS:
      oled_write_P(PSTR("Functions\n"), false);
      break;
    default:
      // Or use the write_ln shortcut over adding '\n' to the end of your string
      oled_write_ln_P(PSTR("PressMe\n"), false);
  }

  // Host Keyboard LED Status
  uint8_t led_usb_state = host_keyboard_leds();
  oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
  oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
  oled_write_P(led_usb_state & (1<<USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    /* case LOWER: */
    /*   if (record->event.pressed) { */
    /*     layer_on(_LOWER); */
    /*     update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST); */
    /*   } else { */
    /*     layer_off(_LOWER); */
    /*     update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST); */
    /*   } */
    /*   return false; */
    /* case RAISE: */
    /*   if (record->event.pressed) { */
    /*     layer_on(_RAISE); */
    /*     update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST); */
    /*   } else { */
    /*     layer_off(_RAISE); */
    /*     update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST); */
    /*   } */
    /*   return false; */
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
 return true;
}
