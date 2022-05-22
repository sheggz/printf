#include "main.h"

/**
 * convert - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 * @params: paramater struct
 * @params: paramater struct
 */

char *convert(long int num, int base, int flags, params_t *params)
{
static char *array;
static char buffer[50];
char sign = 0;
char *ptr;
unsigned long n = num;
(void)params;

if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sign = '-';

}
array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';

do	{
*--ptr = array[n % base];
n /= base;
} while (n != 0);

if (sign)
*--ptr = sign;
return (ptr);
}

/**
 * print_address - prints address
 * @ap: argument pointer
 * @params: the parameters struct
 * Return: bytes printed
 */

int print_address(va_list ap, params_t *params)
{
unsigned long int n = va_arg(ap, unsigned long int);
char *str;

if (!n)
return (_puts("(nil)"));

str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
*--str = 'x';
*--str = '0';
return (print_number(str, params));
}
