#include "game.h"

#include <graph.h>
#include <kbd.h>

void hello_world() {
    ClrScr();
    FontSetSys(F_8x10);
    DrawStr(3, 3, "Hello world!", A_NORMAL);
    ngetchx();
}
