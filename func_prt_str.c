#include "main.h"
/************************* PRINT CHAR *************************/
/**
 * prt_char - Prints a char
 * @types: List a of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int prt_char(va_list types, char buff[],
int flags, int width, int precision, int size)
{

char c = va_arg(types, int);
int i = 0;
char padd = ' ';
UNUSED(precision);
UNUSED(size);
if (flags & F_ZERO)
	padd = '0';
buff[i++] = c;
buff[i] = '\0';
if (width > 1)
{
	buff[BUFF_SIZE - 1] = '\0';
	for (i = 0; i < width - 1; i++)
	buff[BUFF_SIZE - i - 2] = padd;
	if (flags & F_MINUS)
	{
		write(1, &buff[0], 1);
		write(1, &buff[BUFF_SIZE - i - 1], width - 1);
	}
	else
	{
		write(1, &buff[BUFF_SIZE - i - 1], width - 1);
		write(1, &buff[0], 1);
	}

}

return (write(1, &buff[0], 1));
}
/************************* PRINT A STRING *************************/
/**
 * prt_string - Prints a string
 * @types: List a of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int prt_string(va_list types, char buff[],
int flags, int width, int precision, int size)
{
int length = 0, i;
char *str = va_arg(types, char *);
UNUSED(buff);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (str == NULL)
{
str = "(null)";
if (precision >= 6)
str = "      ";
}
while (str[length] != '\0')
length++;
if (precision > 0 && precision < length)
length = precision;
if (width > length)
{
if (flags & F_MINUS)
{
write(1, &str[0], length);
for (i = width - length; i > 0; i--)
write(1, " ", 1);
return (width);
}
else
{
for (i = width - length; i > 0; i--)
write(1, " ", 1);
write(1, &str[0], length);
return (width);
}
}
return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * prt_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int prt_percent(va_list types, char buff[],
int flags, int width, int precision, int size)
{
char c = va_arg(types, int);
c = '%';
UNUSED(types);
UNUSED(buff);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
return (write(1, &c, 1));
}
/************************* PRINT BINARY *************************/
/**
 * prt_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int prt_binary(va_list types, char buff[],
int flags, int width, int precision, int size)
{
unsigned int n, m, i, sum;
unsigned int a[32];
int count;
UNUSED(buff);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
n = va_arg(types, unsigned int);
m = 2147483648; /* (2 ^ 31) */
a[0] = n / m;
for (i = 1; i < 32; i++)
{
m /= 2;
a[i] = (n / m) % 2;
}
for (i = 0, sum = 0, count = 0; i < 32; i++)
{
sum += a[i];
if (sum || i == 31)
{
char z = '0' + a[i];
write(1, &z, 1);
count++;
}
}
return (count);
}
