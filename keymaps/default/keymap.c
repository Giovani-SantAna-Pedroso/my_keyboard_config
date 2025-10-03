/*
   Copyright 2012 Jun Wako <wakojun@gmail.com>
   Copyright 2015 Jack Humbert

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
   */

#include QMK_KEYBOARD_H
#include "keymap_brazilian_abnt2.h"


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define ONE_GRV LT(1,KC_GRAVE)
#define CTL_Z LCTL_T(KC_Z)
#define ALT_SHFT LALT(KC_LSFT)
#define ALT_MENU LALT_T(KC_MENU)
#define LG_QUOT LGUI_T(KC_QUOT)
#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_SLS LCTL_T(KC_SLSH)
#define LT2_COL LT(_RAISE, KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Layer default
    [_QWERTY] = LAYOUT_6x6(


            // I mess up, the wiring the 6 first entry in every row must be inverted
            // row 0
            BR_T,  BR_R  , BR_E,  BR_W    ,BR_Q  , BR_QUOT ,
            BR_Y   , BR_U  , BR_I  , BR_O  , BR_P  ,BR_LBRC,

            // row 1
            BR_G , BR_F ,  BR_D ,   BR_S , BR_A    ,   KC_TAB,
            BR_H   , BR_J  , BR_K  , BR_L  ,BR_CCED,BR_RBRC,

            //row 2
            BR_B,  BR_V, BR_C ,BR_X    , CTL_Z  ,KC_LSFT   ,
            BR_N   , BR_M  ,BR_COMM, BR_DOT, BR_SCLN, KC_RSFT,

            // row 3
            KC_SPC, KC_ESC  ,TT(_LOWER)   ,  _______ , _______  , _______  ,
            KC_ENT   , KC_BSPC  , TT(_LOWER)  , KC_8  , KC_9  ,KC_0,

            // I dont use this row, my key board is a 4x3 wit 3 tumb cluster btns
            // I will remove this in the future
            // row 4
            ONE_GRV,KC_QUOT,ALT_SHFT,KC_LEFT,KC_RGHT,KC_SPC ,
            KC_ENT , KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC,TT(_LOWER),

            // row 5
            KC_BSPC,ALT_MENU,KC_LGUI,       KC_RALT,CTL_ESC,KC_TAB ,
            KC_HOME,        KC_PGUP,
            KC_END ,        KC_PGDN
                ),

            // Laywer 1
    [_LOWER] = LAYOUT_6x6(

            _______ ,_______  ,_______  ,_______  ,_______  ,_______  ,
            _______ ,KC_7  ,KC_8  ,KC_9  ,KC_MINUS ,_______ ,

            _______ ,_______ ,_______  ,_______ ,_______ ,_______,
            _______ ,KC_4  ,KC_5  ,KC_6  ,KC_0,_______ ,

            _______ ,_______ ,_______  ,_______ ,_______ ,_______,
            KC_DOWN,KC_3  ,KC_2  ,KC_1  ,KC_EQUAL,_______,

            _______ ,_______ ,_______  ,_______ ,_______ ,_______,
            KC_AMPR,KC_P1  ,KC_P2  ,KC_P3  ,KC_PSLS,_______,

            QK_BOOT  ,_______,_______,_______,_______,_______,
            _______,_______,KC_PDOT,KC_P0  ,KC_PEQL,_______,

            _______,_______,_______,       _______,_______,_______,
                    _______,       _______,
                    _______,       _______
                    ),
    // Layer 2
    [_RAISE] = LAYOUT_6x6(
                    _______,_______,_______,_______,_______,_______,                                       _______,_______,_______,_______,_______,_______,
                    _______,_______,_______,MS_UP,  _______,_______,                                       _______,_______,_______,_______,_______,_______,
                    _______,_______,MS_LEFT,MS_DOWN,MS_RGHT,_______,                                       _______,_______,_______,_______,_______,KC_MPLY,
                    _______,_______,_______,_______,_______,_______,                                       _______,_______,KC_MPRV,KC_MNXT,_______,_______,
                    QK_BOOT  ,_______,_______,MS_BTN1,MS_BTN2,_______,                                       KC_WBAK,KC_VOLU,KC_VOLD,KC_MUTE,_______,_______,
                    _______,_______,_______,       _______,_______,_______,
                    _______,       _______,
                    _______,       _______
                    )
};
