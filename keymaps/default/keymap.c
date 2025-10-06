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
#define _NUM 1
#define _AUX 2

#define AUX MO(_AUX)
#define NUM MO(_NUM)

#define ONE_GRV LT(1,KC_GRAVE)
#define CTL_Z LCTL_T(KC_Z)
#define ALT_SHFT LALT(KC_LSFT)
#define ALT_MENU LALT_T(KC_MENU)
#define LG_QUOT LGUI_T(KC_QUOT)
#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_SLS LCTL_T(KC_SLSH)
#define LT2_COL LT(_AUX, KC_SCLN)

/* Its not working i will fix later
 */
/* // Tap Dance declarations */
/* enum { */
/*     TD_Q_ESC    , */
/*     TD_BSPC_ESC    , */
/* }; */
/**/
/* // Tap Dance definitions */
/* tap_dance_action_t tap_dance_actions[] = { */
/*     // Tap once for Escape, twice for Caps Lock */
/*     [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(BR_Q, KC_ESC), */
/* }; */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Layer default
    [_QWERTY] = LAYOUT_6x6(//OK


            // I mess up, the wiring the 6 first entry in every row must be inverted
            // row 0
            BR_T,  BR_R  , BR_E,  BR_W    ,BR_Q  , XXXXXXX ,
            BR_Y   , BR_U  , BR_I  , BR_O  , BR_P  ,XXXXXXX,

            // row 1 - home row - I added the mods on this row
            BR_G , MT(MOD_LSFT, BR_F) , MT(MOD_LCTL, BR_D ), MT(MOD_LALT, BR_S ),  MT(MOD_LGUI, BR_A   ) ,XXXXXXX,
            BR_H , MT(MOD_RSFT, BR_J) , MT(MOD_RCTL, BR_K ), MT(MOD_RALT, BR_L ) , MT(MOD_RGUI, BR_CCED) ,XXXXXXX,


            //row 2
            BR_B,  BR_V, BR_C ,BR_X    , BR_Z  ,XXXXXXX  ,
            BR_N   , BR_M  ,BR_COMM, BR_DOT, BR_SCLN, XXXXXXX,

            //* */ row 3 tumb cluster
            LT(_NUM, KC_TAB), KC_BSPC  ,XXXXXXX ,  XXXXXXX , XXXXXXX  , XXXXXXX  ,
            LT(_AUX, KC_ENT), KC_SPC   , XXXXXXX, XXXXXXX  , XXXXXXX  ,XXXXXXX,

            // I dont use this row, my key board is a 4x3 wit 3 tumb cluster btns
            // I will remove this in the future row 4
            XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX ,
            XXXXXXX , XXXXXXX  ,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,

            // row 5
            XXXXXXX,XXXXXXX,XXXXXXX,       XXXXXXX,XXXXXXX,XXXXXXX ,
            XXXXXXX,        XXXXXXX,
            XXXXXXX ,       XXXXXXX
                ),

            // Laywer Numbers
    [_NUM] = LAYOUT_6x6(

            KC_5 ,  KC_4,  KC_3  ,KC_2,KC_1  ,XXXXXXX  ,
            KC_6 ,KC_7  ,KC_8  ,KC_9  ,KC_0 ,XXXXXXX ,


            LGUI(KC_T), MT(MOD_LSFT, XXXXXXX) , MT(MOD_RCTL, XXXXXXX ), MT(MOD_LALT, XXXXXXX ),  MT(MOD_LGUI, BR_QUOT   ) ,XXXXXXX,
            XXXXXXX, MT(MOD_RSFT, BR_MINS) , MT(MOD_LCTL, BR_EQL ), MT(MOD_RALT, BR_TILD ) , MT(MOD_RGUI, BR_LBRC) ,XXXXXXX,

            LSG(KC_Q) ,LCTL(KC_V) ,LCTL(KC_C)  ,LCTL(KC_Z) ,BR_BSLS ,XXXXXXX,
            XXXXXXX,  BR_ACUT,XXXXXXX  ,BR_SLSH  ,BR_RBRC,XXXXXXX,

            XXXXXXX ,XXXXXXX ,XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX,
            XXXXXXX,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX,XXXXXXX,

            XXXXXXX  ,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
            XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX  ,XXXXXXX,XXXXXXX,

            XXXXXXX,XXXXXXX,XXXXXXX,       XXXXXXX,XXXXXXX,XXXXXXX,
                    XXXXXXX,       XXXXXXX,
                    XXXXXXX,       XXXXXXX
                    ),
    // Layer 2 moviment
    [_AUX] = LAYOUT_6x6(
            KC_F5,KC_F4,KC_F3,KC_F2,KC_F1,XXXXXXX,
            KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,XXXXXXX,

            XXXXXXX,KC_ESC,KC_DEL,XXXXXXX,KC_CAPS,XXXXXXX,
            KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_F11,XXXXXXX,

            KC_MUTE,KC_MEDIA_NEXT_TRACK,KC_MEDIA_PREV_TRACK,KC_MEDIA_STOP,KC_MEDIA_PLAY_PAUSE,XXXXXXX,
            XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_F12,

            KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
            XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,

            XXXXXXX  ,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
            XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,

            XXXXXXX,XXXXXXX,XXXXXXX,       XXXXXXX,XXXXXXX,XXXXXXX,
            XXXXXXX,       XXXXXXX,
            XXXXXXX,       XXXXXXX
            )
};
