#include "main.h"
/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * prt_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int prt_unsigned(va_list types, char buff[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
num = convert_size_unsgnd(num, size);
if (num == 0)
buff[i--] = '0';
buff[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buff[i--] = (num % 10) + '0';
num /= 10;
}
i++;
return (write_unsgnd(0, i, buff, flags, width, precision, size));
}
/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * prt_octal - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int prt_octal(va_list types, char buff[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;
UNUSED(width);
num = convert_size_unsgnd(num, size);
if (num == 0)
buff[i--] = '0';
buff[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buff[i--] = (num % 8) + '0';
num /= 8;
}
if (flags & F_HASH && init_num != 0)
buff[i--] = '0';
i++;
return (write_unsgnd(0, i, buff, flags, width, precision, size));
}
/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * prt_hexa_lower - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int prt_hexa_lower(va_list types, char buff[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789abcdef", buff,
flags, 'x', width, precision, size));
}
/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * prt_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int prt_hexa_upper(va_list types, char buff[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789ABCDEF", buff,
flags, 'X', width, precision, size));
}
