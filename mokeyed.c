// Created by Edney O. S. Filho

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

int main(int argc, char *argv[]){
  
  Display *dpy;
  Window root_window;

  dpy = XOpenDisplay(0);

  root_window = XRootWindow(dpy, 0);
  XSelectInput(dpy, root_window, KeyReleaseMask);
  XWarpPointer(dpy, None, root_window, 0, 0, 0, 0, 180, 500);

  XGrabPointer(dpy, root_window, True, ButtonPressMask, GrabModeAsync,GrabModeAsync, None, None, CurrentTime);

  XFlush(dpy);

  return 0;
}
