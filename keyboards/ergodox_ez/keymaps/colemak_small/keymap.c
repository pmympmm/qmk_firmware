#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define PMM_SYMB 1 // symbols
#define PMM_VIM 2 // vim
#define PMM_NAV 3 // navigation keys
#define PMM_NUMBER 4 // numbers keys
#define PMM_BRACKETS 5 // brackets keys
#define PMM_WORDS 6 // words keys


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |explode | dull |bright|   `  |  up  | down | sound|           | undo |cut   | copy |paste | m(4) |  m(5)|  -
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | caps   |   Q  |   W  |   F  |   P  |   G  | ctl  |           | ctl  |   J  |   L  |   U  |   Y  |   ;  |  del   |
 * |--------+------+------+------+------+------| left |           | rght |------+------+------+------+------+--------|
 * | LGUI    |   A  |  R   | S/BKT| T/NUM|   D  |------|           |------|   H  | N/VIM|   E  |   I  |O/SHFT|  lalt   |
 * |--------+------+------+------+------+------|LGui  |           | LGui |------+------+------+------+------+--------|
 * | Shift  |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  | ./hcmd |//Ctrl| RShift|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |    L1|  @   |  |   | Left | Right|                                       |  Down  | Up |   [  |   ]  |  L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  Esc | Alt  |       | Alt `| lAlt |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |  nav   | sym  |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        LCTL(KC_UP),         KC_F1,         KC_F2,   KC_GRV,   KC_VOLD,   KC_VOLU,   KC__MUTE,
        KC_CAPS,        KC_Q,         KC_W,   KC_F,   KC_P,   KC_G,   LCTL(KC_LEFT),
        KC_LGUI,       KC_A,         KC_R,   LT(PMM_BRACKETS, KC_S),   LT(PMM_NUMBER, KC_T),   KC_D,
        KC_LSFT,        CTL_T(KC_Z),  GUI_T(KC_X),   KC_C,   KC_V,   KC_B,   KC_LGUI,
        KC_FN1,         KC_AT,      KC_PIPE,  KC_LEFT, KC_RGHT,
                                              KC_ESC,  KC_LALT,
                                                              KC_HOME,
                                               KC_SPC, KC_BSPC,KC_END,
        // right hand
             LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), M(4), M(5),            KC_MINS,
             RCTL(KC_RGHT),    KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,          KC_DELT,
                          KC_H,   LT(PMM_VIM, KC_N),   LT(PMM_WORDS, KC_E),   KC_I,   KC_O,   KC_LALT,
             KC_LGUI, KC_K,   KC_M,   KC_COMM,GUI_T(KC_DOT), CTL_T(KC_SLSH),   KC_RSFT,
                                  KC_DOWN,  KC_UP,KC_LBRC,KC_RBRC,          KC_FN1,
             LALT(KC_GRV), KC_RALT,
             KC_PGUP,
             KC_PGDN, LT(PMM_NAV, KC_TAB), LT(PMM_SYMB,KC_ENT)
    ),
/* Keymap 4: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |   ^  |   $  |  *   |      |      |           |      |      |   "  |   !  |   %  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  =   |   +  |   -  |  _   |      |------|           |------|      |   '  |   @  |   |  |   \  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   `  |   £  |  #   |      |      |           |      |      |   &  |   ~  |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[PMM_SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_CIRC,KC_DLR,KC_ASTR,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_EQL, LSFT(KC_EQL),KC_MINS,KC_UNDS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_GRV,LALT(KC_3),KC_HASH,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,   KC_DQUO, KC_EXLM, KC_PERC,  KC_TRNS,  KC_TRNS,
                KC_TRNS,   KC_QUOTE, KC_AT, KC_PIPE, KC_BSLS,    KC_TRNS,
       KC_TRNS, KC_TRNS,   KC_AMPR, KC_TILD, KC_TRNS,  KC_TRNS,  KC_TRNS,
                           KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 4: vim Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |alt ` |lgui up|     |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |lgui rgt|lgui lft| : | esc |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |lgui down|   |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[PMM_VIM] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,LALT(KC_GRV), LALT(LCTL(KC_UP)), KC_TRNS,KC_TRNS,
       KC_TRNS,LCTL(KC_LEFT), RCTL(KC_RGHT),KC_COLON,KC_ESC, KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, LALT(LCTL(KC_DOWN)),KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
                KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
                           KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 4: nav Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | cmd+q|cmd+w |      |      |           |      |      | up   | pgup |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |cmd tb|ctl tb|cmd+` |      |------|           |------|      | down | pgdn | home | end  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  cmd alt shft |cmd+alt|cmd r|cmd l  |  |           |      |      | left | rght |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[PMM_NAV] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,LGUI(KC_Q),LGUI(KC_W),KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,LGUI(KC_TAB),LCTL(KC_TAB),LGUI(KC_GRV),KC_TRNS,
       KC_TRNS,LSFT(LGUI(KC_RALT)),LGUI(KC_RALT),LGUI(KC_LEFT),LGUI(KC_RGHT),KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,   KC_UP,  KC_PGUP, KC_TRNS, KC_TRNS,  KC_TRNS,
                KC_TRNS,   KC_DOWN,KC_PGDN, KC_HOME, KC_END,   KC_TRNS,
       KC_TRNS, KC_TRNS,   KC_LEFT,KC_RGHT, KC_TRNS,  KC_TRNS,  KC_TRNS,
                           KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 4: numbers Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|   .  |   4  |   5  |   6  |  0   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[PMM_NUMBER] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,   KC_7,    KC_8,    KC_9,     KC_TRNS,  KC_TRNS,
                KC_DOT,    KC_4,    KC_5,    KC_6,     KC_0,     KC_TRNS,
       KC_TRNS, KC_TRNS,   KC_1,    KC_2,    KC_3,     KC_TRNS,  KC_TRNS,
                           KC_0, KC_0, KC_DOT,  KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 5: brackets Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  [   |  ]   |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |  (   |  )   |  {   |  }   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  <   |  >   |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                `--------------------'       `--------------------'
 */
// BRCKTS
[PMM_BRACKETS] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,   KC_LBRACKET, KC_RBRACKET, KC_TRNS,  KC_TRNS,  KC_TRNS,
                KC_TRNS,   KC_LPRN, KC_RPRN, KC_LCBR,  KC_RCBR,  KC_TRNS,
       KC_TRNS, KC_TRNS,   KC_LABK, KC_RABK, KC_TRNS,  KC_TRNS,  KC_TRNS,
                           KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 6: words Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | bbg  |mcl   |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | ion  | the  | and  |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 *
 */
// SYMBOLS
[PMM_WORDS] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,M(3),M(5),M(4),KC_TRNS,KC_TRNS,
       KC_TRNS,M(6),M(7),M(8),M(9),KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
                KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
                           KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

};

/*
const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB) ,               // FN1 - Momentary Layer 1 (Symbols)
    [2] = ACTION_LAYER_TAP_TOGGLE(VIM)  ,              // FN1 - Momentary Layer 2
    [3] = ACTION_LAYER_TAP_TOGGLE(NAV)  ,              // FN1 - Momentary Layer 3
    [4] = ACTION_LAYER_TAP_TOGGLE(NUMBER),                // FN1 - Momentary Layer 4
    [5] = ACTION_LAYER_TAP_TOGGLE(BRACKETS),                // FN1 - Momentary Layer 5
    [6] = ACTION_LAYER_TAP_TOGGLE(WORDS)                // FN1 - Momentary Layer 6
};
*/

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
          break;
        case 3:
          if (record->event.pressed) {
              SEND_STRING("the.mcloughlin@gmail.com");
          }
          break;
        case 4:
          if (record->event.pressed) {
            return MACRO( D(LSFT), T(M), U(LSFT), T(C), D(LSFT), T(L), U(LSFT),  T(O), T(U), T(G), T(H), T(L), T(I), T(N), END  ); // 
              SEND_STRING("McLoughlin");
          }
          break;
        case 5:
          if (record->event.pressed) {
            return MACRO( D(LSFT), T(B), U(LSFT),  T(L), T(O), T(O), T(M), T(B), T(E), T(R), T(G), END  ); // 
              SEND_STRING("Bloomberg");
          }
          break;
        case 6:
          if (record->event.pressed) {
              SEND_STRING("paul.mcloughlin@orsonsystems.com");
          }
          break;
        case 7:
          if (record->event.pressed) {
              SEND_STRING("pmcloughlin2");
          }
          break;
        case 8:
          if (record->event.pressed) {
              SEND_STRING("Paul McLoughlin");
          }
          break;
        case 9:
          if (record->event.pressed) {
              SEND_STRING("pmcloughlin2@Bloomberg.net");
          }
          break;
      }
    return MACRO_NONE;
};



// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 5:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};
