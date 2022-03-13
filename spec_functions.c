#include "main.h"

int		handle_spec_c(void *ptr)
{
	format_t	*data;
	char		c[2];

	data = (format_t*)ptr;
	c[0] = va_arg(data->args, int);
	c[1] = '\0';
	write_buffer(c, 1, data);
	return (0);
}

