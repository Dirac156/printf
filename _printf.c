#include <stdarg.h>
#include <unistd.h>
#include "holberton.h"
/**
 *_strlen- Gets the length of a string
 *@s: string
 *
 *Return:Length of a string
 */

int _strlen(char *s)
{

int length = 0;

while (*s)
{
s++;
length++;
}
return (length);
}

/**
 *print_str- A function that prints a string
 *@arg:The string
 *Return: number of strings
 */
int print_str(va_list arg)
{
char *s;
int i = 0;
s = va_arg(arg, char *);
if (s == NULL)
{
s = "(null)";
}
while (s[i] != '\0')
{
_putchar(s[i]);
i++;
}
return (i);
}

/**
 *print_char- A function that prints a character
 *@arg:The list that hold the character
 *Return: number of strings
 */
int print_char(va_list arg)
{
char c;
c = va_arg(arg, int);
_putchar(c);
return (1);
}

/**
 *print_number- A function that prints integer
 *@arg: The integer
 *Return: number of integer
 */
int print_number(va_list arg)
{
int d = va_arg(arg, int);
int number;
int lastdigit = d % 10;
int one_dig;
int mult = 1;
int i = 1;

d = d / 10;
number = d;

if (lastdigit < 0)
{
_putchar('-');
number = -number;
d = -d;
lastdigit = -lastdigit;
i++;
}
if (number > 0)
{
while (number / 10 != 0)
{
mult = mult * 10;
number = number / 10;
}
number = d;
while (mult > 0)
{
one_dig = number / mult;
_putchar(one_dig + '0');
number = number - (one_dig *mult);
mult = mult / 10;
i++;
}
}
_putchar(lastdigit + '0');

return (i);
}

/**
 *_printf- Prints anything to output
 *@format:Parameter 1
 *@...:Variable number of arguements
 *Return: Length
 */

int _printf(const char *format, ...)
{
int length = 0;
va_list arguments;
int j;
va_start(arguments, format);
if (format == NULL)
return (-1);
while (*(format))
{
if (*format != '%')
{
if (write(1, format, 1) == -1)
return (-1);
length++;
}
else
{
format++;
if (!*(format))
return (-1);
switch (*format)
{
case 'c':
length += print_char(arguments);
break;
case 's':
length += print_str(arguments);
break;
case '%':
j = write(1, &("%"), 1);
if (j == -1)
return (-1);
length++;
break;
case 'd':
length += print_number(arguments);
break;
case 'i':
length += print_number(arguments);
break;
}
}
format++;
}
return (length);
}
