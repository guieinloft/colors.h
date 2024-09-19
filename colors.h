#ifndef _COLORS_
#define _COLORS_

#include <stdarg.h>
#include <stdlib.h>

typedef struct c_rgb {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} c_rgb;

int cvfprintf(c_rgb fg, c_rgb bg, FILE *out, char *format, ...);
int cfprintf(c_rgb fg, c_rgb bg, FILE *out, char *format, ...);
int cprintf(c_rgb fg, c_rgb bg, char *format, ...);

#endif
