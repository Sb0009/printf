#include "Include/main.h"
#include <stdlib.h>
/**
* print_String - Print a string.
* @arg: String address.
* Return: integer.
*/

int print_String(va_list arg)
{

	char *str = va_arg(arg, char *);
	int i = 0;

	if (str == NULL)
	str = "(null)";

	for (str[i]; i++)
	_putchar(str[i]);
	return (i);
}
