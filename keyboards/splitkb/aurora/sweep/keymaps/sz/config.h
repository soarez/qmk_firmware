/* Copyright 2022 splitkb.com <support@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// Should be able to disable oneshot to reduce size,
// but keyboards/splitkb/aurora/sweep/sweep.c:239 depends on it
/* #define NO_ACTION_ONESHOT */

// https://docs.qmk.fm/#/tap_hold?id=ignore-mod-tap-interrupt
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#define TAPPING_TERM 300

// Not yet available in `keymap.json` format
#ifdef RGB_MATRIX_ENABLE
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#    define RGB_MATRIX_KEYPRESSES
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#    define ENABLE_RGB_MATRIX_SOLID_SPLASH
#    define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#    define ENABLE_RGB_MATRIX_ALPHAS_MODS
#    define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
/* #    define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT */
/* #    define ENABLE_RGB_MATRIX_BREATHING */
/* #    define ENABLE_RGB_MATRIX_BAND_SAT */
/* #    define ENABLE_RGB_MATRIX_BAND_VAL */
/* #    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT */
/* #    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL */
/* #    define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT */
/* #    define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL */
#    define ENABLE_RGB_MATRIX_CYCLE_ALL
/* #    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT */
#    define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
/* #    define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON */
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
/* #    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL */
#    define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
/* #    define ENABLE_RGB_MATRIX_CYCLE_SPIRAL */
/* #    define ENABLE_RGB_MATRIX_DUAL_BEACON */
#    define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#    define ENABLE_RGB_MATRIX_RAINDROPS
#    define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#    define ENABLE_RGB_MATRIX_HUE_BREATHING
/* #    define ENABLE_RGB_MATRIX_HUE_PENDULUM */
#    define ENABLE_RGB_MATRIX_HUE_WAVE
#    define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#    define ENABLE_RGB_MATRIX_PIXEL_FLOW
/* #    define ENABLE_RGB_MATRIX_PIXEL_RAIN */
#    define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#    define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE
/* #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE */
/* #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE */
/* #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS */
/* #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS */
/* #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS */
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#    define ENABLE_RGB_MATRIX_SPLASH
/* #    define ENABLE_RGB_MATRIX_MULTISPLASH */
/* #    define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH */

#endif

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_RGB_TEST
#    define RGBLIGHT_EFFECT_ALTERNATING
#    define RGBLIGHT_EFFECT_TWINKLE
#endif

// Not yet available in `keymap.json` format
#ifdef MOUSEKEY_ENABLE
     // The default is 100
#    define MOUSEKEY_WHEEL_INTERVAL 50
     // The default is 40
#    define MOUSEKEY_WHEEL_TIME_TO_MAX 100
#endif


