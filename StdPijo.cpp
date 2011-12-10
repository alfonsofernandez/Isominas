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
#include "StdPijo.h"
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>

namespace STDP {

    // Pa inicializar la pantalla...
    void StdPijo::init ()
    {
        // Preinicializacion de N-Curses
        m_win = initscr();        // Inicializar N-curses
        keypad(stdscr, TRUE);   // Mapeo de teclado
        nodelay(stdscr,TRUE);   // Lectura no bloqueante
        notimeout(stdscr,TRUE);
        timeout (0);	           // Para que no se espere en la lectura...
        nonl();                 // NL no es CR/NL a la salida
        cbreak();               // Disponibilidad inmediata de teclas pulsadas
        noecho();               // Eliminamos el echo al terminal
        curs_set(0);            // Cursor invisible
        leaveok(stdscr,TRUE);   // Cursor siempre en 0,0 tras refresh()
        scrollok(stdscr,FALSE); // No hacer scroll vertical automatico
        if (has_colors())
            start_color();       // Inicializa los colores
        refresh();              // Borramos la pantalla

        // Colocamos el cursor arriba
        move(0,0);

        // Inicializamos los pares de colores
        int p = 0;
        int c [8] = { COLOR_BLACK, COLOR_RED, COLOR_GREEN, COLOR_YELLOW,
            COLOR_BLUE, COLOR_MAGENTA, COLOR_CYAN, COLOR_WHITE };
        for (int i=0; i<8; i++)
        {
            for (int j=0; j<8; j++)
            {
                m_color[i][j] = p;
                init_pair(p++, c[i], c[j]);
            }
        }
    }

    // Pa poner el cursor por ahi...
    void StdPijo::setCursor (int x, int y)
    {
        if (x >= 0 && x < getmaxx(m_win) && y >= 0 && y < getmaxy(m_win))
            move (y, x);
    }

    // Pa poner colorines pijos...
    void StdPijo::setColor (Attribute Atr, Color CT, Color CF) {
        // Establecemos color para borrar atributos y luego el atr q toca
        attrset(COLOR_PAIR(m_color[CT][CF]));
        attron (Atr);
    }
}
