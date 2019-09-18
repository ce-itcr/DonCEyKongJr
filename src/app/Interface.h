
#ifndef DONCEYKONGJR_INTERFACE_H
#define DONCEYKONGJR_INTERFACE_H

#include <gtk/gtk.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

void loadInterface();
void placeSend(int coordsx, int coordsy);

struct Element{
    int x;
    int y;
    int object;  //object 0: fruit  object 1: crocodile
    int type;  //type 0: red  type 1: blue
};

#endif //DONCEYKONGJR_INTERFACE_H
