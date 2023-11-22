
#include <X11/X.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <X11/Xlib.h>

int main(int argc, const char *argv[]){

    Display *Dsp;
    Window Win;
    Dsp = XOpenDisplay(NULL);
    int Scr = DefaultScreen(Dsp);
    XSetWindowAttributes Attr;
    XEvent Xe;

    int POSX = 0;
    int POSY = 0;
    int Height = 500;
    int Width = 800;
    int Root = RootWindow(Dsp, Scr);

    int Border_Width = 1;

    if (Dsp == NULL) {
        fprintf(stderr, "Cannot open display !");
        exit(1);
    }
    
    // Window background color
    const char *Win_Color = "#343541";
    Colormap ColMap = DefaultColormap(Dsp, Scr);
    XColor WColor, Exact_Color;

    XAllocNamedColor(Dsp, ColMap, Win_Color, &WColor, &Exact_Color);

    Attr.background_pixel = WColor.pixel;
    Attr.border_pixel = XWhitePixel(Dsp, 1);
    Attr.event_mask = ExposureMask;

    unsigned long valuemask = 0;
    valuemask = CWBackPixel | CWBorderPixel | CWEventMask;

    Visual *visual = CopyFromParent;

    // Create window
    Win = XCreateWindow(
            Dsp, Root, POSX, POSY, Width, Height, Border_Width,
            CopyFromParent, InputOutput, CopyFromParent, valuemask,
            &Attr
            );
    
    XMapWindow(Dsp, Win);
    while (1) {
        XNextEvent(Dsp, &Xe);
    }

    XCloseDisplay(Dsp);

    return 0;
}