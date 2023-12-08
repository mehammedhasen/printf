#include "main.h"
/**
 * write_unsgnd - Writes an unsigned number
 * @is_sign: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buff: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of written chars.
 */
int write_unsgnd(int is_sign, int ind, char buff[],
	int flags, int width, int precision, int size)
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
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
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
int print_hexa(va_list types, char map_to[], char buff[],
int flags, char flag_ch, int width, int precision, int size)
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
buff[i--] = map_to[num % 16];
num /= 16;
}
if (flags & F_HASH && init_num != 0)
{
buff[i--] = flag_ch;
buff[i--] = '0';
}
i++;
return (write_unsgnd(0, i, buff, flags, width, precision, size));
}
/**
 * write_pointer - Write a memory address
 * @buff: Arrays of chars
 * @indx: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: width specifier
 * @flags: Flags specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 * Return: write content
 */
int write_pointer(char buff[], int indx, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
int i;
if (width > length)
{
for (i = 3; i < width - length + 3; i++)
buff[i] = padd;
buff[i] = '\0';
if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
{
buff[--indx] = 'x';
buff[--indx] = '0';
if (extra_c)
buff[--indx] = extra_c;
return (write(1, &buff[indx], length) + write(1, &buff[3], i - 3));
}
else if (!(flags & F_MINUS) && padd == ' ')/* extra char to left of buffer */
{
buff[--indx] = 'x';
buff[--indx] = '0';
if (extra_c)
buff[--indx] = extra_c;
return (write(1, &buff[3], i - 3) + write(1, &buff[indx], length));
}
else if (!(flags & F_MINUS) && padd == '0')/* extra char to left of padd */
{
if (extra_c)
buff[--padd_start] = extra_c;
buff[1] = '0';
buff[2] = 'x';
return (write(1, &buff[padd_start], i - padd_start) +
write(1, &buff[indx], length - (1 - padd_start) - 2));
}
}
buff[--indx] = 'x';
buff[--indx] = '0';
if (extra_c)
buff[--indx] = extra_c;
return (write(1, &buff[indx], BUFF_SIZE - indx - 1));
}
