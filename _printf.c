#include "main.h"
void print_buffer(char buff[], int *buf_indx);
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)

{

int indx = 0, prt_type = 0, cuont_chars = 0;

int flags, width, precision, size, buf_indx = 0;

va_list list;

char buff[BUFF_SIZE];

if (format == NULL)

return (-1);


va_start(list, format);

for (i = 0; format && format[indx] != '\0'; indx++)

{

if (format[indx] !=  '%')

{

buff[buf_ind++] = format[indx];

if (buf_indx == BUFF_SIZE)

print_buffer(buff, &buf_indx);

/* write(1, &format[indx], 1);*/

count_chars++;

indx++;

}

else

{

print_buffer(buff, &buf_indx);

flags = get_flags(format, &indx);

width = get_width(format, &indx, list);

precision = get_precision(format, &indx, list);

size = get_size(format, &indx);

++indx;

prt_type = handle_print(format, &indx, list, buff,

flags, width, precision, size);

if (prt_type == -1)

return (-1);

count_chars += prt_type;

}

}



print_buffer(buff, &buf_indx);



va_end(list);



return (count_chars);

}



/**
* print_buffer-Prints the contents of the buffer if it exist
* @buff:Array of chars
* @buf_indx:Index at which to add next char, represents the length.
*
*/

void print_buffer(char buff[], int *buf_indx)

{

if (*buf_indx > 0)

write(1, &buff[0], *buf_indx);



*buf_indx = 0;

}
