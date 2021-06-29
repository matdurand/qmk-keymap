#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"
#include "config.h"
#include "string.h"

enum custom_keycodes {
  CUSTOM_TG_FR_LAYER = AP2_SAFE_RANGE,
  //Row 1
  CUSTOM_GRV,
  CUSTOM_KC_2,
  CUSTOM_KC_3,
  //Row2
  CUSTOM_TILDE,
  CUSTOM_KC_LBRK,
  CUSTOM_KC_RBRK,
  CUSTOM_KC_BSLS,
  //Row 3
  CUSTOM_KC_QUOTE,
  //Row 4
  CUSTOM_KC_COMMA,
  CUSTOM_KC_DOT,
  CUSTOM_KC_SLASH,
  //FR mode
  CUSTOM_FR_ECUTE,
  CUSTOM_FR_GRAVE,
  CUSTOM_FR_CCED,
  CUSTOM_FR_CIRC,
  CUSTOM_FR_QUOTE,
  CUSTOM_FR_AGRV,
};

enum anne_pro_layers {
  _BASE_LAYER,
  _LINUX_LAYER,
  _FR_LAYER,
  _FN1_LAYER,
  _FN2_LAYER,
};

enum {
    FN2_TAP_DANCE,
    ACCENT_TAP_DANCE
};

// Define a type for as many tap dance states as you need
enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    TRIPLE_TAP,
    TRIPLE_HOLD
};

typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

#define FR_CA_LBRC  ALGR(KC_LBRC) // [
#define FR_CA_RBRC  ALGR(KC_RBRC) // ]
#define FR_CA_LACC  ALGR(KC_QUOT) // {
#define FR_CA_RACC  ALGR(KC_BSLS) // }
#define FR_CA_AT    ALGR(KC_2)    // @
#define FR_CA_BSLS  ALGR(KC_GRV) //
#define FR_CA_GRV   S(KC_QUOT) // `
#define FR_CA_GRV_D KC_QUOT // ` (dead)
#define FR_CA_EACU  KC_SLSH // É
#define FR_CA_CIRC  KC_LBRC // ^ (dead)
#define FR_CA_CED   KC_RBRC // ¸ (dead)
#define FR_CA_DIAE  S(KC_RBRC) // ¨ (dead)
#define FR_CA_QUOTE S(KC_COMM) // '
#define FR_CA_EXLM  S(KC_1)   // !
#define FR_CA_DQUO  S(KC_2)   // "
#define FR_CA_SLSH  S(KC_3) // /
#define FR_CA_QMARK S(KC_6) // ?
#define FR_CA_HASH  KC_GRV  // #
#define FR_CA_LT    KC_BSLS // <
#define FR_CA_GT    S(KC_BSLS) // >
#define FR_CA_PIPE  S(KC_GRV)
#define FR_CA_TILDE ALGR(KC_SCLN)

// Key symbols are based on QMK. Use them to remap your keyboard
/*
* Layer _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* | esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* | Caps    |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift/UP    |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  Alt   |  GUI  |              space             |  FN1  | LEFT | DOWN |  RIGHT  |
* \-----------------------------------------------------------------------------------------/
* Layer TAP in _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
* |-----------------------------------------------------------------------------------------+
* |         |     |     |     |     |     |     |     |     |     |     |     |             |
* |-----------------------------------------------------------------------------------------+
* |            |     |     |     |     |     |     |     |     |     |     |   Shift/UP     |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |                                 |       |  LEFT | DOWN  | RIGHT |
* \-----------------------------------------------------------------------------------------/
*/
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE_LAYER] = KEYMAP( /* Base */
    KC_ESC, KC_1, CUSTOM_KC_2, CUSTOM_KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, CUSTOM_KC_LBRK, CUSTOM_KC_RBRK, CUSTOM_KC_BSLS,
    TD(FN2_TAP_DANCE), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, CUSTOM_KC_QUOTE, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, CUSTOM_KC_COMMA, CUSTOM_KC_DOT, CUSTOM_KC_SLASH, RSFT_T(KC_UP),
    KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, MO(_FN1_LAYER), KC_LEFT, KC_DOWN, KC_RGHT
 ),

  //_LINUX_LAYER is the same as _BASE_MAC_LAYER, but with CTRL and GUI swapped
 [_LINUX_LAYER] = KEYMAP( /* Base */
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_LGUI, KC_LALT, KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
 ),

 [_FR_LAYER] = KEYMAP( /* Base */
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, CUSTOM_FR_CIRC, CUSTOM_FR_CCED, CUSTOM_FR_AGRV,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, CUSTOM_FR_GRAVE, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, CUSTOM_FR_QUOTE, KC_TRNS, CUSTOM_FR_ECUTE, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
 ),

  /*
  * Layer _FN1_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |           |
  * |-----------------------------------------------------------------------------------------+
  * |  ~  |  MUTE | VOL- | VOL+ |    |     |     |     |     |     |  PS | HOME | END |       |
  * |-----------------------------------------------------------------------------------------+
  * |     | PREV | STOP | NEXT |     |     |     |     |     |     |  PGUP | PGDN |           |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |     |     |     | INSRT | DEL |     UP       |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |                                 |       |  LEFT | DOWN  | RIGHT |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FN1_LAYER] = KEYMAP( /* Base */
    CUSTOM_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS,
    CUSTOM_TILDE, KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_HOME, KC_END, CUSTOM_KC_SLASH,
    KC_TRNS, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_DEL, KC_UP,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT
 ),
  /*
  * Layer _FN2_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |           |
  * |-----------------------------------------------------------------------------------------+
  * |     |  BT1  | BT2  |  BT3  |  BT4  |    |    |     |     |     |     |      |     |     |
  * |-----------------------------------------------------------------------------------------+
  * |     |  FR  |      |       |      |      |      |      |      |LINUX|     |     |        |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |     |     |     |     |     |     | MAC |     |     |     |                |
  * |-----------------------------------------------------------------------------------------+
  * |        |        |      |                               |       | LEDOF | LEDON | LEDSTR |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FN2_LAYER] = KEYMAP( /* Base */
    CUSTOM_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS,
    KC_TRNS, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, CUSTOM_KC_SLASH,
    KC_TRNS, TG(_FR_LAYER), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(_LINUX_LAYER), KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_AP_LED_OFF, KC_AP_LED_ON, KC_AP_LED_NEXT_INTENSITY
 ),
};

const uint16_t keymaps_size = sizeof(keymaps);

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
uint8_t cur_dance(qk_tap_dance_state_t *state);

// Functions associated with individual tap dances
void fn2_layer_finished(qk_tap_dance_state_t *state, void *user_data);
void fn2_layer_reset(qk_tap_dance_state_t *state, void *user_data);

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

// Code to run after initializing the keyboard
void keyboard_post_init_user(void) {
    // Here are two common functions that you can use. For more LED functions, refer to the file "qmk_ap2_led.h"

    // annepro2-shine disables LEDs by default. Uncomment this function to enable them at startup.
    // annepro2LedEnable();

    // Additionally, it also chooses the first LED profile by default. Refer to the "profiles" array in main.c in
    // annepro2-shine to see the order. Replace "i" with the index of your preferred profile. (i.e the RED profile is index 0)
    // annepro2LedSetProfile(i);
}

bool process_custom_fr_ca_key(uint16_t normal_key, uint16_t shift_key) {
    bool lshift = get_mods() & MOD_BIT(KC_LSHIFT);
    bool rshift = get_mods() & MOD_BIT(KC_RSHIFT);

    unregister_code(KC_LSFT);
    unregister_code(KC_RSFT);

    if (lshift || rshift) {
        tap_code16(shift_key);
    } else {
        tap_code16(normal_key);
    }

    if (lshift) register_code(KC_LSFT);
    if (rshift) register_code(KC_RSFT);

    return false;
}

void send_dual_key_seq (uint16_t key1, bool key1_keep_shift, uint16_t key2, bool key2_keep_shift) {
    bool lshift = get_mods() & MOD_BIT(KC_LSHIFT);
    bool rshift = get_mods() & MOD_BIT(KC_RSHIFT);

    if (!key1_keep_shift) {
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
    }

    tap_code16(key1);

    if (key2_keep_shift) {
        if (lshift) register_code(KC_LSFT);
        if (rshift) register_code(KC_RSFT);
    }

    tap_code16(key2);

    if (!key2_keep_shift) {
        if (lshift) register_code(KC_LSFT);
        if (rshift) register_code(KC_RSFT);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        case CUSTOM_KC_2:
            if (record->event.pressed) {
                return process_custom_fr_ca_key(KC_2, FR_CA_AT);
            }
            break;
         case CUSTOM_KC_3:
            if (record->event.pressed) {
                return process_custom_fr_ca_key(KC_3, FR_CA_HASH);
            }
            break;
        case CUSTOM_KC_LBRK:
            if (record->event.pressed) {
                return process_custom_fr_ca_key(FR_CA_LBRC, FR_CA_LACC);
            }
            break;
        case CUSTOM_KC_RBRK:
            if (record->event.pressed) {
                return process_custom_fr_ca_key(FR_CA_RBRC, FR_CA_RACC);
            }
            break;
        case CUSTOM_KC_BSLS:
            if (record->event.pressed) {
                return process_custom_fr_ca_key(FR_CA_PIPE, FR_CA_BSLS);
            }
            break;
        case CUSTOM_KC_QUOTE:
            if (record->event.pressed) {
                return process_custom_fr_ca_key(FR_CA_QUOTE, FR_CA_DQUO);
            }
            break;
        case CUSTOM_KC_COMMA:
            if (record->event.pressed) {
                return process_custom_fr_ca_key(KC_COMM, FR_CA_LT);
            }
            break;
        case CUSTOM_KC_DOT:
            if (record->event.pressed) {
                return process_custom_fr_ca_key(KC_DOT, FR_CA_GT);
            }
            break;
        case CUSTOM_KC_SLASH:
            if (record->event.pressed) {
                return process_custom_fr_ca_key(FR_CA_SLSH, FR_CA_QMARK);
            }
            break;
        case CUSTOM_FR_ECUTE:
            if (record->event.pressed) {
                return process_custom_fr_ca_key(FR_CA_EACU, S(FR_CA_EACU));
            }
            break;
        case CUSTOM_FR_GRAVE:
            if (record->event.pressed) {
                return process_custom_fr_ca_key(FR_CA_GRV_D, FR_CA_GRV_D);
            }
            break;
        case CUSTOM_FR_CIRC:
            if (record->event.pressed) {
                return process_custom_fr_ca_key(FR_CA_CIRC, FR_CA_CIRC);
            }
            break;
        case CUSTOM_FR_QUOTE:
            if (record->event.pressed) {
                return process_custom_fr_ca_key(KC_COMM, FR_CA_QUOTE);
            }
            break;
        case CUSTOM_TILDE:
            if (record->event.pressed) {
                return process_custom_fr_ca_key(FR_CA_TILDE, FR_CA_TILDE);
            }
            break;
        case CUSTOM_GRV:
            if (record->event.pressed) {
                return process_custom_fr_ca_key(FR_CA_GRV, FR_CA_SLSH);
            }
            break;
        case CUSTOM_FR_CCED:
            if (record->event.pressed) {
                send_dual_key_seq(FR_CA_CED, false, KC_C, true);
                return false;
            }
            break;
        case CUSTOM_FR_AGRV:
            if (record->event.pressed) {
                send_dual_key_seq(FR_CA_GRV_D, false, KC_A, true);
                return false;
            }
            break;
        default:
            break;
    }
    return true;
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return state;
}

// Determine the current tap dance state
uint8_t cur_dance(qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (!state->pressed) return SINGLE_TAP;
    else return SINGLE_HOLD;
  } else if (state->count == 2) {
    if (!state->pressed) return DOUBLE_TAP;
    else return DOUBLE_HOLD;
  } else if (state->count == 3) {
    if (!state->pressed) return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }  else return 8;
}

static tap fn2_tap_state = {
  .is_press_action = true,
  .state = 0
};

// Functions that control what our tap dance key does
void fn2_layer_finished(qk_tap_dance_state_t *state, void *user_data) {
  fn2_tap_state.state = cur_dance(state);

  switch (fn2_tap_state.state) {
    case SINGLE_TAP:
      layer_invert(_FR_LAYER);
      break;
    case SINGLE_HOLD:
      layer_on(_FN2_LAYER);
      break;
    case DOUBLE_TAP:
    case DOUBLE_HOLD:
    case TRIPLE_TAP:
    case TRIPLE_HOLD:
      break;
  }
}

void fn2_layer_reset(qk_tap_dance_state_t *state, void *user_data) {
  layer_off(_FN2_LAYER);
  fn2_tap_state.state = 0;
}

// Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
  [FN2_TAP_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, fn2_layer_finished, fn2_layer_reset, 150),
};
