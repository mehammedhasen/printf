#ifndef MAIN_H

#define MAIN_H

#include <stdarg.h>

#include <stdio.h>

#include <unistd.h>



#define UNUSED(x) (void)(x)

#define BUFF_SIZE 1024



/* FLAGS */

#define F_MINUS 1

#define F_PLUS 2

#define F_ZERO 4

#define F_HASH 8

#define F_SPACE 16



/* SIZES */

#define S_LONG 2

#define S_SHORT 1



/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */

struct fmt

{

char fmt;

int (*fn)(va_list, char[], int, int, int, int);

};




/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */

typedef struct fmt fmt_t;



int _printf(const char *format, ...);

int handle_print(const char *fmt, int *i,

va_list list, char buff[], int flags, int width, int precision, int size);



/****************** FUNCTIONS ******************/



/* Funtions to print chars and strings */

int prt_char(va_list types, char buff[],

int flags, int width, int precision, int size);

int prt_string(va_list types, char buff[],

int flags, int width, int precision, int size);

int prt_percent(va_list types, char buff[],

int flags, int width, int precision, int size);



/* Functions to print numbers */

int prt_int(va_list types, char buff[],

int flags, int width, int precision, int size);

int prt_binary(va_list types, char buff[],

int flags, int width, int precision, int size);

int prt_unsigned(va_list types, char buff[],

int flags, int width, int precision, int size);

int prt_octal(va_list types, char buff[],

int flags, int width, int precision, int size);

int prt_hexa_lower(va_list types, char buff[],

int flags, int width, int precision, int size);

int prt_hexa_upper(va_list types, char buff[],

int flags, int width, int precision, int size);

/* Function to print non printable characters */

int prt_non_printable(va_list types, char buff[],

int flags, int width, int precision, int size);

/* Funcion to print memory address*/

int prt_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);



/* Funciotns to handle other specifiers */

int input_flags(const char *format, int *i);

int input_width(const char *format, int *i, va_list list);

int input_precision(const char *format, int *i, va_list list);

int input_size(const char *format, int *i);



/*Function to print string in reverse*/

int prt_reverse(va_list types, char buff[],


int flags, int width, int precision, int size);



/*Function to print a string in rot 13*/

int prt_rot13string(va_list types, char buff[],

int flags, int width, int precision, int size);



/* width handler */

int write_prefix(int is_positive, int ind, char buff[],

int flags, int width, int precision, int size);

int write_num(int ind, char buff[], int flags, int width, int precision,

int length, char padd, char extra_c);

int write_pointer(char buffer[], int ind, int length,

	int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind,

	char buff[], int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],

char buff[], int flags, char flag_ch, int width, int precision, int size);

/****************** UTILS ******************/

int is_printable(char);
int append_hexa_code(char, char[], int);

int is_digit(char);
long int convert_size_number(long int num, int size);

long int convert_size_unsgnd(unsigned long int num, int size);



#endif
