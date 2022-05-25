#ifndef GUARD
#define GUARD
#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_int(va_list arg_p);
int print_str(va_list arg_p);
int print_char(va_list arg_p);
int print_bi(int num, int *char_count);
int print_binary(va_list arg_p);
void reverse_print(int n, int *);
int (*_func_selector(char c))(va_list);

#endif
