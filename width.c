#include "main.h"
/**
 * input_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int input_width(const char *format, int *i, va_list list)
{
int curr_i, is_digt;
int width = 0;
for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
{
is_digt = is_digit(format[curr_i]);
if (is_digt)
{
width *= 10;
width += format[curr_i] - '0';
}
else if (format[curr_i] == '*')
{
curr_i++;
width = va_arg(list, int);
break;
}
else
break;
}
*i = curr_i - 1;
return (width);
}