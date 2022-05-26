#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * print_binary - a function that prints the binary equivalent
 * @arg_p: the variable argument pointer
 * Return: the number of characters printed
 */ 
int print_binary(va_list arg_p)
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

	print_bi(n, &char_count);
	return (char_count);
}


/**
 * print_bi - a function that prints the binary equivalent using recursion
 * @num: the decimal number to be converted and printed
 * @char_count: pointer to the counting variable
 * Return: the number of characters printed
 */ 
int print_bi(int num, int *char_count)
{
	if (num)
	{
		print_bi(num / 2, char_count);
		_putchar(num % 2 + '0');
		(*char_count)++;
	}
	return (0);
}
