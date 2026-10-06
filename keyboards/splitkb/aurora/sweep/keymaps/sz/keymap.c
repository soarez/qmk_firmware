#include QMK_KEYBOARD_H
#include "macro_text.h"

// The layer tables and get_tapping_term are generated from gil/layout/layout.yaml
// by gil/layout/generate.py, so both keyboards share one layout.

// Right outer thumb: hold for layer 4, or tap then press-and-hold to hold F20
// (push-to-talk in Wispr Flow and superwhisper). A double tap sends one F20
// tap (superwhisper toggle), a triple tap sends two (Wispr Flow toggle).
#define F20_TAP_WINDOW 200

enum custom_keycodes {
    L4_F20 = SAFE_RANGE,
    LCGRIND, // types MACRO_LCGRIND, set at build time
};

// BEGIN GENERATED layers from gil/layout/layout.yaml by layout/generate.py; edit that, not this
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
    KC_Q         , KC_W         , KC_E         , KC_R         , LCAG_T(KC_T) , RCAG_T(KC_Y) , KC_U         , KC_I         , KC_O         , KC_P            ,
    LCTL_T(KC_A) , LOPT_T(KC_S) , LCMD_T(KC_D) , LSFT_T(KC_F) , HYPR_T(KC_G) , HYPR_T(KC_H) , RSFT_T(KC_J) , RCMD_T(KC_K) , ROPT_T(KC_L) , RCTL_T(KC_SCLN) ,
    KC_Z         , KC_X         , KC_C         , KC_V         , KC_B         , KC_N         , KC_M         , KC_COMM      , KC_DOT       , KC_SLSH         ,
                                                 LT(3,KC_ESC) , LT(1,KC_SPC) , LT(2,KC_SPC) , L4_F20
),
// Symbols and arrows
[1] = LAYOUT(
    KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_DEL  ,
    KC_TAB  , KC_PERC , KC_CIRC , KC_AMPR , KC_ASTR , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , KC_TRNS ,
    XXXXXXX , XXXXXXX , XXXXXXX , KC_BSPC , KC_ENT  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,
                                  MO(7)   , XXXXXXX , KC_TRNS , KC_TRNS
),
// Brackets
[2] = LAYOUT(
    KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_DQUO , KC_LPRN , KC_RPRN , XXXXXXX , KC_BSPC ,
    KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_QUOT , KC_LCBR , KC_RCBR , XXXXXXX , KC_BSLS ,
    KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_UNDS , KC_LBRC , KC_RBRC , XXXXXXX , KC_ENT  ,
                                  XXXXXXX , XXXXXXX , XXXXXXX , MO(8)
),
// Navigation and editing
[3] = LAYOUT(
    KC_GRV     , KC_TRNS    , KC_UP      , KC_TRNS    , KC_F20  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,
    CW_TOGG    , KC_LEFT    , KC_DOWN    , KC_RGHT    , KC_BSPC , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,
    LGUI(KC_Z) , LGUI(KC_X) , LGUI(KC_C) , LGUI(KC_V) , KC_ENT  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,
                                           XXXXXXX    , MO(5)   , KC_TRNS , KC_TRNS
),
// Numbers
[4] = LAYOUT(
    KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_PLUS , KC_1 , KC_2 , KC_3 , KC_DEL  ,
    KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_EQL  , KC_4 , KC_5 , KC_6 , KC_PIPE ,
    KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_MINS , KC_7 , KC_8 , KC_9 , KC_0    ,
                                  KC_TRNS , KC_TRNS , MO(6)   , XXXXXXX
),
// Keypad and F-keys
[5] = LAYOUT(
    KC_PPLS   , KC_P1 , KC_P2 , KC_P3 , KC_PAST , KC_F1  , KC_F2  , KC_F3   , KC_F4   , KC_F5   ,
    KC_PMNS   , KC_P4 , KC_P5 , KC_P6 , KC_PSLS , KC_F6  , KC_F7  , KC_F8   , KC_F9   , KC_F10  ,
    KC_KP_DOT , KC_P7 , KC_P8 , KC_P9 , KC_P0   , KC_F11 , KC_F12 , XXXXXXX , XXXXXXX , XXXXXXX ,
                                XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
),
// Text macros
[6] = LAYOUT(
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    LCGRIND , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
                                  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
),
// Media and mouse, the same on both boards. macOS reads Pause and ScrLk as display brightness up and down.
[7] = LAYOUT(
    KC_MFFD , XXXXXXX        , KC_MUTE , XXXXXXX , KC_SLEP , XXXXXXX , KC_WH_D , KC_MS_U , KC_WH_U , KC_BTN1 ,
    KC_MRWD , KC_PAUSE       , KC_VOLU , XXXXXXX , XXXXXXX , XXXXXXX , KC_MS_L , KC_MS_D , KC_MS_R , KC_BTN2 ,
    KC_MPLY , KC_SCROLL_LOCK , KC_VOLD , QK_RBT  , QK_BOOT , QK_BOOT , KC_ACL0 , KC_ACL1 , KC_ACL2 , XXXXXXX ,
                                         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
),
// System, each board's own hardware controls
[8] = LAYOUT(
    RGB_TOG  , RGB_HUI , RGB_SAI , RGB_VAI , RGB_SPI , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    RGB_MOD  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    RGB_RMOD , RGB_HUD , RGB_SAD , RGB_VAD , RGB_SPD , QK_BOOT , QK_RBT  , XXXXXXX , XXXXXXX , XXXXXXX ,
                                   XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
)
};
// END GENERATED layers

// BEGIN GENERATED timing from gil/layout/layout.yaml by layout/generate.py; edit that, not this
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOPT_T(KC_S):
        case ROPT_T(KC_L):
            return 200;
        case LCAG_T(KC_T):
        case RCAG_T(KC_Y):
        case HYPR_T(KC_G):
        case HYPR_T(KC_H):
            return 400;
        default:
            return TAPPING_TERM;
    }
}
// END GENERATED timing

static uint32_t l4_f20_pressed_at;
static uint32_t l4_f20_released_at;
static bool     l4_f20_interrupted; // another key was pressed while the thumb was down
static bool     l4_f20_armed;       // the last press was a clean tap
static bool     l4_f20_holding;     // F20 is down

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == LCGRIND && record->event.pressed) {
        SEND_STRING(MACRO_LCGRIND);
    }
    if (keycode != L4_F20) {
        if (record->event.pressed) {
            l4_f20_interrupted = true;
            l4_f20_armed       = false;
        }
        return true;
    }

    if (record->event.pressed) {
        if (l4_f20_armed && timer_elapsed32(l4_f20_released_at) < F20_TAP_WINDOW) {
            register_code(KC_F20);
            l4_f20_holding = true;
        } else {
            layer_on(4);
        }
        l4_f20_armed       = false;
        l4_f20_interrupted = false;
        l4_f20_pressed_at  = timer_read32();
    } else {
        if (l4_f20_holding) {
            unregister_code(KC_F20);
            l4_f20_holding = false;
        } else {
            layer_off(4);
        }
        // Any short tap arms the next press as F20, so taps after the first
        // pass through live: a triple tap sends a double tap of F20
        l4_f20_armed       = !l4_f20_interrupted && timer_elapsed32(l4_f20_pressed_at) < F20_TAP_WINDOW;
        l4_f20_released_at = timer_read32();
    }
    return false;
}
