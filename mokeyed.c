// Created by Edney O. S. Filho

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

void moveMyMouse(int x, int y){
 
  Display *dpy;
  Window root_window;

  dpy = XOpenDisplay(0);

  root_window = XRootWindow(dpy, 0);
  XSelectInput(dpy, root_window, KeyReleaseMask);
  XWarpPointer(dpy, None, root_window, 0, 0, 0, 0, x, y);

  XGrabPointer(dpy, root_window, True, ButtonPressMask, GrabModeAsync,GrabModeAsync, None, None, CurrentTime);

  XFlush(dpy);

  return;
}

int main(int argc, char *argv[]){
 
  for(int i = 0 ; i < 500 ; i++){ 
  
    moveMyMouse(180+i, 500+i);
    usleep(1000);

  }

  return 0;
}
