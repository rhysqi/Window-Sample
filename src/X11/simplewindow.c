
#include <X11/X.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <X11/Xlib.h>

int main(int argc, const char *argv[]){

    Display *Dsp;
    Window Win;
    Dsp = XOpenDisplay(NULL);
    int Scr = DefaultScreen(Dsp);

    XEvent Xe;

    int POSX = 0;
    int POSY = 0;
    int Height = 500;
    int Width = 800;
    int Root = RootWindow(Dsp, Scr);

    int Border_Width = 1;

    unsigned long Border = WhitePixel(Dsp, Scr);
    unsigned long Background_Pixel = WhitePixel(Dsp, Scr);


    unsigned long valuemask = 0;
    valuemask = CWBackPixel | CWBorderPixel | CWEventMask;

    if (Dsp == NULL) {
        fprintf(stderr, "Cannot open display !");
        exit(1);
    }
    
    Win = XCreateSimpleWindow(Dsp, Root, POSX, POSY, Width, Height, Border_Width,
            Border, Background_Pixel);

    XMapWindow(Dsp, Win);

    while (1) {
        XNextEvent(Dsp, &Xe);
    }

    XCloseDisplay(Dsp);

    return 0;
}