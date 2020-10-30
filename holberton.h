#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
int _putchar(char c);
int _strlen(char *s);
int _printf(const char *format, ...);
int print_str(va_list arg);
int print_char(va_list arg);
int print_number(va_list arg);
int handle_switch(char format, va_list arguments);
#endif
