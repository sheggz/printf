#include <stdarg.h>
#include <stdlib.h>
#include "main.h"


/**
 * _printf - a function that simulates the standard printf function
 * @format: a pointer to a constant string
 * @...: other variable arguments
 * Return: the number of characters displayed
 */

int _printf(const char *format, ...)
{
	int i, num_displayed = 0;
	va_list arg_ptr;
	char *str_temp;
	int (*func)(va_list);

	va_start(arg_ptr, format);
	/* the write fn in putchar returns 1 on success and -1 in failure) */
	for (i = 0; (*(format + i) != '\0'); i++)
	{
		if (*(format + i) != '%')
		{
			_putchar(*(format + i));
			num_displayed++;
		}
		else
		{
			/* when format[i] == '%' */
			if (*(format + (i + 1)) != '%')
			{
				func = _func_selector(*(format + (i + 1)));
				if (func != NULL)
					num_displayed += func(arg_ptr);
				i++;
			}

			else if (*(format + (i + 1)) == '%')
			{
				_putchar(format[i + 1]);
				i++;
				num_displayed++;
			}
		}
	}
	va_end(arg_ptr);
	return (num_displayed);
}

