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
#include "definitions.h"

namespace STDP {

    using namespace std;

    class StdPijo
    {
        protected:
            StdPijo() { init(); }

        public:
            ~StdPijo ()         { end(); };
            static StdPijo& p() { static StdPijo p; return p; }
            void init();
            void end()          { endwin(); }

            void setCursor  (int x, int y);
            void setColor   (Attribute ATR, Color CT, Color CF);
            void refreshScr ()                 { refresh();   }
            void clearScreen()                 { erase();     }
            void writeChar  (chtype c)         { addch(c);    }
            void writeStr   (const char *str)  { addstr(str); }
            int  getCursorX ()                 { return getcurx(m_win); }
            int  getCursorY ()                 { return getcury(m_win); }
            int  getSizeX   ()                 { return getmaxx(m_win); }
            int  getSizeY   ()                 { return getmaxy(m_win); }
            int  getKey     ()                 { return getch();        }
            void setGlobalEscapeDelay(unsigned delay) { ESCDELAY = delay; }

        private:
            int m_color[8][8];	 // Vector de colores
            WINDOW* m_win;       // Ventana de ncurses
    };
}
