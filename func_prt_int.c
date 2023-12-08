#include "main.h"
/************************* PRINT INT *************************/
/**
 * prt_int - Print int
 * @types: Lista of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int prt_int(va_list types, char buff[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
int is_sign = 0;
long int n = va_arg(types, long int);
unsigned long int num;
n = convert_size_number(n, size);
if (n == 0)
	buff[i--] = '0';
buff[BUFF_SIZE - 1] = '\0';
num = (unsigned long int)n;
if (n < 0)
{
	num = (unsigned long int)((-1) * n);
	is_sign = 1;
}
while (num > 0)
{
	buff[i--] = (num % 10) + '0';
	num /= 10;
}
i++;
return (write_prefix(is_sign, i, buff, flags, width, precision, size));
}

/************************* WRITE NUMBER *************************/
/**
 * write_prefix - Prints a string
 * @is_sign: Lista of arguments
 * @ind: char types.
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */

int write_prefix(int is_sign, int ind, char buff[],

int flags, int width, int precision, int size)

{

int length = BUFF_SIZE - ind - 1;

char padd = ' ', extra_ch = 0;



UNUSED(size);



if ((flags & F_ZERO) && !(flags & F_MINUS))

padd = '0';

if (is_sign)

extra_ch = '-';

else if (flags & F_PLUS)

extra_ch = '+';

else if (flags & F_SPACE)

extra_ch = ' ';



return (write_num(ind, buff, flags, width, precision,
	length, padd, extra_ch));
}
/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buff: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */

int write_num(int ind, char buff[], int flags, int width, int prec,
int length, char padd, char extra_c)
{
int i, padd_start = 1;
if (prec == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0' && width == 0)
return (0); /* printf(".0d", 0)  no char is printed */
if (prec == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0')
buff[ind] = padd = ' '; /* width is displayed with padding ' ' */
if (prec > 0 && prec < length)
padd = ' ';
while (prec > length)
buff[--ind] = '0', length++;
if (extra_c != 0)
length++;
if (width > length)
{
for (i = 1; i < width - length + 1; i++)
buff[i] = padd;
buff[i] = '\0';
if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
{
if (extra_c)
buff[--ind] = extra_c;
return (write(1, &buff[ind], length) + write(1, &buff[1], i - 1));
}
else if (!(flags & F_MINUS) && padd == ' ')/* extra char to left of buff */
{
if (extra_c)
buff[--ind] = extra_c;
return (write(1, &buff[1], i - 1) + write(1, &buff[ind], length));
}
else if (!(flags & F_MINUS) && padd == '0')/* extra char to left of padd */
{
if (extra_c)
buff[--padd_start] = extra_c;
return (write(1, &buff[padd_start], i - padd_start) +
write(1, &buff[ind], length - (1 - padd_start)));
}
}
if (extra_c)
buff[--ind] = extra_c;
return (write(1, &buff[ind], length));
}
