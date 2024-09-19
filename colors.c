#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include "colors.h"

int cvfprintf(c_rgb fg, c_rgb bg, FILE *out, char *format, va_list args){
	int done;
	done = fprintf(out, "\033[38;2;%u;%u;%u;48;2;%u;%u;%um", fg.r, fg.g, fg.b, bg.r, bg.g, bg.b) & INT_MIN;
	done |= vfprintf(out, format, args);
	done |= fprintf(out, "\033[0m") & INT_MIN;
	return done;
}

int cfprintf(c_rgb fg, c_rgb bg, FILE *out, char *format, ...){
	va_list args;
	va_start(args, format);
	int done = cvfprintf(fg, bg, out, format, args);
	va_end(args);
	return done;
}

int cprintf(c_rgb fg, c_rgb bg, char *format, ...){
	va_list args;
	va_start(args, format);
	int done = cvfprintf(fg, bg, stdout, format, args);
	va_end(args);
	return done;
}

