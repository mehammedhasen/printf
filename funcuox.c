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
/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buff: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of written chars.
 */
int write_unsgnd(int is_sign, int ind,
char buff[], int flags, int width, int precision, int size)
{
/* The number is stored at the bufer's right and starts at position i */
int length = BUFF_SIZE - ind - 1, i = 0;
char padd = ' ';
UNUSED(is_sign);
UNUSED(size);
if (precision == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0')
return (0); /* printf(".0d", 0)  no char is printed */
if (precision > 0 && precision < length)
padd = ' ';
while (precision > length)
{
buff[--ind] = '0';
length++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (width > length)
{
for (i = 0; i < width - length; i++)
buff[i] = padd;
buff[i] = '\0';
if (flags & F_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
{
return (write(1, &buff[ind], length) + write(1, &buff[0], i));
}
else /* Asign extra char to left of padding [padd>buff]*/
{
return (write(1, &buff[0], i) + write(1, &buff[ind], length));
}
}
return (write(1, &buff[ind], length));
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
return (prt_hexa(types, "0123456789abcdef", buff,
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
return (prt_hexa(types, "0123456789ABCDEF", buff,
flags, 'X', width, precision, size));
}
/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * prt_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int prt_hexa(va_list types, char map_to[], char buff[],
int flags, char flag_ch, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsign ed long int init_num = num;
/*UNUSED(width);*/
num = convert_size_unsgnd(num, size);
if (num == 0)
buff[i--] = '0';
buff[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buff[i--] = map_to[num % 16];
num /= 16;
}
if (flags & F_HASH && init_num != 0)
{
buff[i--] = flag_ch;
buff[i--] = '0';
}
return (write_unsgnd(0, i, buff, flags, width, precision, size));
}
