#include QMK_KEYBOARD_H

enum layers {
    COLEMAKDH,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // #ifdef CONSOLE_ENABLE
    //     uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    // #endif

    return true;
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode(RGB_MATRIX_BAND_PINWHEEL_SAT);
}

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L','L','L','L','L','L',              'R','R','R','R','R','R',
        'L','L','L','L','L','L',              'R','R','R','R','R','R',
        'L','L','L','L','L','L',              'R','R','R','R','R','R',
        'L','L','L','L','L','L','L',      'R','R','R','R','R','R','R',
                        'L','L','L',      'R','R','R'
);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [COLEMAKDH] = LAYOUT(
        QK_GESC , KC_1 ,         KC_2 ,         KC_3 ,          KC_4 ,          KC_5 ,                       KC_6 , KC_7 , KC_8 , KC_9 , KC_0    , KC_NO,
        KC_NO   , KC_Q ,         KC_W ,         KC_F ,          KC_P ,          KC_B ,                       KC_J , KC_L , KC_U , KC_Y , KC_SCLN , KC_NO,
        KC_NO   , LGUI_T(KC_A) , LALT_T(KC_R) , LCTL_T(KC_S)  , LSFT_T(KC_T)  , KC_G ,                       KC_M , RSFT_T(KC_N) , RCTL_T(KC_E) , RALT_T(KC_I) , RGUI_T(KC_O) , KC_NO,
        KC_NO , KC_Z , KC_X , KC_C , KC_D , KC_V , RM_TOGG ,     KC_MUTE , KC_K , KC_H , KC_COMM , KC_DOT , KC_SLSH , KC_NO,
                                KC_TAB , DB_TOGG , KC_SPC ,                       KC_BSPC , KC_NO , KC_ENT
    )

};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [COLEMAKDH] = {
        ENCODER_CCW_CW(KC_PGDN, KC_PGUP),
        ENCODER_CCW_CW(KC_PGDN, KC_PGUP),
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
    },
};
