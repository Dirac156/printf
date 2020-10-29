#include <stdarg.h>
#include <unistd.h>
#include "holberton.h"
/**
 *_strlen- Gets the length of a string
 *@s: string
 *
 *return:Length of a string
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
 *pr_str- A function that prints a string
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
 *_printf- Prints anything to output
 *@format:Parameter 1
 *@...:Variable number of arguements
 *Return: Length
 */

int _printf(const char *format, ...)
{
int i = 0;
int length = 0;
char char_arg;
va_list arguments;
int j;

va_start(arguments, format);
if (format == NULL)
return (-1);
while (*(format + i))
{
if ((*(format + i)) != '%')
{
if (write(1, format + i, 1) == -1)
return (-1);
length++;
}
else
{
i += 1;
switch (*(format + i))
{
case 'c':
char_arg = va_arg(arguments, int);

j = write(1, &char_arg, 1);
if (j == -1)
return (-1);
length++;
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
}
}
i++;
}
return (length);
}
