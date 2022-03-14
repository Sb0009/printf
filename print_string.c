#include "main.h"
#include <stdlib.h>
/**
* print_S - Print a string.
* @arg: String address.
* Return: integer.
*/
int print_S(va_list arg)
{
char *str = va_arg(arg, char *);
int i = 0;
if (str == NULL)
str = "(null)";
for (; str[i]; i++)
_putchar(str[i]);
return (i);
}
