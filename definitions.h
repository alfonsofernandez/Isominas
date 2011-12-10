/**
 *   Copyright 2011 (c) Francisco José Gallego Durán <fgallego@byterealms.com>
 *   Copyright 2011 (c) ByteRealms <info@byterealms.com>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; version 3 of the License.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 */
#pragma once
#include <ncurses.h>

namespace STDP {

    // Definiciones de Colores
    //----------------------------------
    enum Color {
        CBLACK     = COLOR_BLACK,
        CRED       = COLOR_RED,
        CGREEN     = COLOR_GREEN,
        CYELLOW    = COLOR_YELLOW,
        CBLUE      = COLOR_BLUE,
        CMAGENTA   = COLOR_MAGENTA,
        CCYAN      = COLOR_CYAN,
        CWHITE     = COLOR_WHITE
    };

    // Definiciones de atributos
    //-----------------------------------
    enum Attribute {
        AALTCHARS = A_ALTCHARSET,
        ANORMAL   = A_NORMAL,
        AREVERSE  = A_REVERSE,
        ABLINK    = A_BLINK,
        ABOLD     = A_BOLD,
        ADIM      = A_DIM,
        AINVIS    = A_INVIS,
        APROTECT  = A_PROTECT,
        ASTDOUT   = A_STANDOUT,
        AUNDERLINE= A_UNDERLINE
    };

    // Definiciones de teclas
    //-----------------------------------
    enum Key {
        KESCAPE = 27,
        KENTER  = 13,
        KUP     = KEY_UP,
        KDOWN   = KEY_DOWN,
        KLEFT   = KEY_LEFT,
        KRIGHT  = KEY_RIGHT
    };
}
