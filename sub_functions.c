#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * print_int - a function that prints an integer using putchar
 * @arg_p: a pointer to access elements of variable argument list
 * Return: The number of characters printed out
 */

int print_int(va_list arg_p)
{
	/* we have to print the number R - L */
	int n = va_arg(arg_p, int), char_count = 0;
	/* let's handle negative numbers noting that putchar only works */
	/* with 0 - 127 i.e no negative */

	if (n < 0)
	{
		_putchar('-');
		char_count++;
		n = -n; /* make n positive */
	}
	reverse_print(n, &char_count);
	return (char_count);
}

/**
 * print_str - a function that prints a string using putchar
 * @arg_p: a pointer to access elements of variable argument list
 * Return: The number of characters printed out
 */

int print_str(va_list arg_p)
{
	int j = 0, char_count = 0;
	char *str = va_arg(arg_p, char *);

	while (str[j] != '\0')
	{
		_putchar(str[j]);
		j++;
		char_count++;
	}
	return (char_count);
}

/**
 * print_char - a function that prints a character using putchar
 * @arg_p: a pointer to access elements of variable argument list
 * Return: The number of characters printed out
 */

int print_char(va_list arg_p)
{
	int char_count = 0;

	_putchar(va_arg(arg_p, int));
	char_count++;
	return (char_count);
}

/**
 * reverse_print - a function that recursively prints a number from R-l
 * @n: the integer number to be printed
 * @num: pointer to a count variable
 */

void reverse_print(int n, int *num)
{
	if ((n / 10) != 0)
		reverse_print(n / 10, num);
	_putchar((n % 10) + '0');
	(*num)++;
}

/**
 * _func_selector - a function that selects the ideal function based on the i/p
 * @c: the format specifier that determines the function to be returned
 * Return: a pointer to a func that takes in a "va_list" arg and returns an int
 */

int (*_func_selector(char c))(va_list)
{
	if (c == 'c')
		return (&print_char);
	if (c == 's')
		return (&print_str);
	if (c == 'd')
		return (&print_int);
	if (c == 'b')
		return (&print_binary);
	return (NULL);
}
