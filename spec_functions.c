#include "main.h"

int		handle_spec_c(const char *format, void *ptr)
{
	format_t	*data;
	char		c;

	(void)format;
	data = (format_t*)ptr;
	c = va_arg(data->args, int);
	write(1, &c, 1);
	return (0);
}
