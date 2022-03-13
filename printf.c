#include "printf.h"


int		handle_specialchar(const char *format)
{
	// do something
}

int		_printf(const char *format, ...)
{
	int		i;

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
			handle_specialchar(format + i + 1);
		else
			_putchar(format[i]);
	}
	return (0);
}
