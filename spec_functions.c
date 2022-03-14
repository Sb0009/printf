#include "main.h"

/**
 * handle_spec_c - Function to get and output next char variable given to printf
 * @ptr: Pointer to general data structure
 * Return: 0 if no error
 */
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

/**
 * handle_spec_s - Function to get and output string variable given to printf
 * @ptr: Pointer to general data structure
 * Return: 0 if no error
 */
int		handle_spec_s(void *ptr)
{
	format_s	*data;
	string		s[11];

	data = (format_s*)ptr;
	s[0] = va_arg(data->args, int);
	s[11] = '\0';
	write_buffer(s, 11, data);
	return (0);
}

