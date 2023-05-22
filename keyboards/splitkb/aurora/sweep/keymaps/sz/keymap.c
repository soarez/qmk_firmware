#include QMK_KEYBOARD_H


// Home row mods
#define A_LCTL    LCTL_T(KC_A)
#define S_LOPT    LOPT_T(KC_S)
#define D_LCMD    LCMD_T(KC_D)
#define F_LSFT    LSFT_T(KC_F)
#define T_CAG     LCAG_T(KC_T)
#define Y_CAG     RCAG_T(KC_Y)
#define J_RSFT    RSFT_T(KC_J)
#define K_RCMD    RCMD_T(KC_K)
#define L_ROPT    ROPT_T(KC_L)
#define SCLN_RCTL RCTL_T(KC_SCLN)

// MacOS stuff
#undef KC_BRIU
#define KC_BRIU KC_PAUSE
#undef KC_BRID
#define KC_BRID KC_SCROLL_LOCK
#undef KC_UNDO
#define KC_UNDO LGUI(KC_Z)
#undef KC_CUT
#define KC_CUT LGUI(KC_X)
#undef KC_COPY
#define KC_COPY LGUI(KC_C)
#undef KC_PASTE
#define KC_PASTE LGUI(KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* [0] = LAYOUT( */
/*     RGB_TOG  , RGB_HUI , RGB_SAI , RGB_VAI     , RGB_SPI     , RGB_TOG  , RGB_HUI , RGB_SAI , RGB_VAI     , RGB_SPI     , */
/*     RGB_MOD  , XXXXXXX , XXXXXXX , XXXXXXX     , XXXXXXX     , RGB_MOD  , XXXXXXX , XXXXXXX , XXXXXXX     , XXXXXXX     , */
/*     RGB_RMOD , RGB_HUD , RGB_SAD , RGB_VAD     , RGB_SPD     , RGB_RMOD , RGB_HUD , RGB_SAD , RGB_VAD     , RGB_SPD     , */
/*                                    LT(3,KC_ESC), LT(1,KC_SPC), LT(2,KC_SPC), LT(4,KC_ENT) */
/* ), */
[0] = LAYOUT(
    KC_Q        , KC_W        , KC_E        , KC_R      , T_CAG    , Y_CAG  , KC_U      , KC_I           , KC_O          , KC_P           ,
    A_LCTL      , S_LOPT      , D_LCMD      , F_LSFT    , KC_G     , KC_H   , J_RSFT    , K_RCMD         , L_ROPT        , SCLN_RCTL      ,
    KC_Z        , KC_X        , KC_C        , KC_V      , KC_B     , KC_N   , KC_M      , KC_COMM        , KC_DOT        , KC_SLSH        ,
                                        LT(3,KC_ESC), LT(1,KC_SPC), LT(2,KC_SPC), LT(4,KC_ENT)
),
[1] = LAYOUT(
    KC_TILD  , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_DEL  ,
    KC_TAB   , KC_PERC , KC_CIRC , KC_AMPR , KC_ASTR , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , KC_TRNS ,
    XXXXXXX  , XXXXXXX , XXXXXXX , KC_UNDS , KC_ENT  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,
                                   MO(7)   , KC_NO   , KC_TRNS , KC_TRNS
),

[2] = LAYOUT(
    KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_DQUO , KC_LPRN , KC_RPRN , XXXXXXX , KC_BSPC ,
    KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_QUOT , KC_LCBR , KC_RCBR , XXXXXXX , KC_BSLS ,
    KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , XXXXXXX , KC_LBRC , KC_RBRC , XXXXXXX , XXXXXXX ,
                                  XXXXXXX , XXXXXXX , KC_NO   , MO(8)
),
[3] = LAYOUT(
    KC_GRV  , KC_TRNS , KC_UP   , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX , KC_LEFT , KC_DOWN , KC_RGHT , KC_BSPC , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    KC_UNDO , KC_CUT  , KC_COPY , KC_PASTE, KC_ENT  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
                                  KC_NO   , MO(5)   , XXXXXXX , XXXXXXX
),
[4] = LAYOUT(
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_PLUS , KC_1  , KC_2 , KC_3 , KC_DEL  ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_EQL  , KC_4  , KC_5 , KC_6 , KC_PIPE ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_MINS , KC_7  , KC_8 , KC_9 , KC_0    ,
                                  XXXXXXX , XXXXXXX , MO(6)   , KC_NO
),
[5] = LAYOUT(
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , QK_BOOT , KC_F1  , KC_F2  , KC_F3  , KC_F4   , KC_F5   ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , QK_MAKE , KC_F6  , KC_F7  , KC_F8  , KC_F9   , KC_F10  ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_SLEP , KC_F10 , KC_F11 , KC_F12 , XXXXXXX , XXXXXXX ,
                                  KC_NO   , KC_NO   , XXXXXXX , XXXXXXX
),
[6] = LAYOUT(
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_PPLS , KC_P1 , KC_P2 , KC_P3 , KC_PAST   ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_PMNS , KC_P4 , KC_P5 , KC_P6 , KC_PSLS   ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_P0   , KC_P7 , KC_P8 , KC_P9 , KC_KP_DOT ,
                                  XXXXXXX , XXXXXXX , KC_NO   , KC_NO
),
[7] = LAYOUT(
    KC_MFFD , XXXXXXX , KC_MUTE , XXXXXXX , XXXXXXX , KC_WH_U , XXXXXXX , KC_MS_U , XXXXXXX , KC_ACL2 ,
    KC_MRWD , KC_BRIU , KC_VOLU , XXXXXXX , XXXXXXX , KC_WH_D , KC_MS_L , KC_MS_D , KC_MS_R , KC_ACL1 ,
    KC_MPLY , KC_BRID , KC_VOLD , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_ACL0 ,
                                  KC_NO   , KC_NO   , KC_BTN1 , KC_BTN2
),
[8] = LAYOUT(
    RGB_TOG , RGB_HUI , RGB_SAI , RGB_VAI , RGB_SPI , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    RGB_MOD , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    RGB_RMOD, RGB_HUD , RGB_SAD , RGB_VAD , RGB_SPD , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
                                  XXXXXXX , XXXXXXX , KC_NO   , KC_NO
)
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case S_LOPT:
        case L_ROPT:
            return TAPPING_TERM + 40;
        case T_CAG:
        case Y_CAG:
            return TAPPING_TERM + 200;
        default:
            return TAPPING_TERM;
    }
}
