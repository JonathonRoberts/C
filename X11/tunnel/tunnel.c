#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Global X variables */
Display *dis;
int screen;
Window win;
GC gc;

XGCValues gr_values;
XColor color,dummy;
XFontStruct *fontinfo;

void init_x();
void close_x();
void redraw();
void changecoln(char *col);
void changecolrgb(unsigned short r,unsigned short g,unsigned short b);
void changeffontsize(char *font);


int main () {

	XEvent event;
	KeySym key;
	char text[255];

	init_x();

	while(1) {

		changeffontsize("-*-helvetica-*-r-*-*-24-*-*-*-*-*-*-*");
		changecoln("black");

		int i;
		double si;
		unsigned short r,g,b = 0;
		for(i=0;i<800;i++){
			changecolrgb(i,i*1000,-1);
			XDrawArc( dis, win, gc, 320-i/2, 240 -20-i/2, i, i, 0, 360*64);
			usleep(1);
		}
		for(i=0;i<800;i++){
			changecolrgb(i*1000,-1,i);
			XDrawArc( dis, win, gc, 320-i/2, 240 -20-i/2, i, i, 0, 360*64);
			usleep(1);
		}
		for(i=0;i<800;i++){
			changecolrgb(-1,i,i*1000);
			XDrawArc( dis, win, gc, 320-i/2, 240 -20-i/2, i, i, 0, 360*64);
			usleep(1);
		}


	}
}

void init_x() {
/* get the colors black and white */
	unsigned long black,white;

	dis=XOpenDisplay((char *)0);
	if (dis == NULL){
		fprintf(stderr, "Cannot open display\n");
		exit (1);
	}
   	screen=DefaultScreen(dis);
	black=BlackPixel(dis,screen),
	white=WhitePixel(dis, screen);
   	win=XCreateSimpleWindow(dis,DefaultRootWindow(dis),0,0,
		640, 480, 5,black, white);
	XSetStandardProperties(dis,win,"XLib Demo","Demo",None,NULL,0,NULL);
	XSelectInput(dis, win, ExposureMask|ButtonPressMask|KeyPressMask);
        gc=XCreateGC(dis, win, 0,0);
	XSetBackground(dis,gc,white);
	XSetForeground(dis,gc,black);
	XClearWindow(dis, win);
	XMapRaised(dis, win);
};

void close_x() {
	XFreeGC(dis, gc);
	XDestroyWindow(dis,win);
	XCloseDisplay(dis);
	exit(1);
};

void redraw() {
	XClearWindow(dis, win);
};

void changecoln(char *col){
	XAllocNamedColor(dis, DefaultColormap(dis,screen),col,&color,&dummy);
	gr_values.foreground = color.pixel;
	gc = XCreateGC(dis,win,GCFont+GCForeground, &gr_values);
}
void changecolrgb(unsigned short r,unsigned short g,unsigned short b){
	color.red=r;
	color.green=g;
	color.blue=b;
	XAllocColor(dis, DefaultColormap(dis,screen),&color);
	gr_values.foreground = color.pixel;
	gc = XCreateGC(dis,win,GCFont+GCForeground, &gr_values);
}
void changeffontsize(char *font){
	fontinfo = XLoadQueryFont(dis,font);
	gr_values.font = fontinfo->fid;
	gc = XCreateGC(dis,win,GCFont+GCForeground, &gr_values);
}
