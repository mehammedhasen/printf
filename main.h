#ifndef _MAIN_H
#define _MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _utchar(char c);

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#endif
