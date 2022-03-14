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
	format_t	*data;
	char		*s;

	data = (format_t*)ptr;
	s = va_arg(data->args, char *);
	write_buffer(s, _strlen(s), data);
	return (0);
}

int	handle_spec_di(void *ptr)
{
	format_t	*data;
	long		nb;
	char		*str;

	data = (format_t *)ptr;
	if (data->long_flag = 1)
		nb = (long)va_arg(data->args, long);
	else if (data->short_flag = 1)
		nb = (short)va_arg(data->args, short);
	else
		nb = va_arg(data->args, int);
	str = printf_numbers(nb, 10, data);
	if (!str)
		return (-1);
	write_buffer(str, _strlen(str), data);
	free(str);
	return (0);
}

int	handle_spec_b(void *ptr)
{
	format_t	*data;
	int			nb;
	char		*str;

	data = (format_t *)ptr;
	nb = va_arg(data->args, int);
	str = printf_numbers(nb, 2, data);
	if (!str)
		return (-1);
	write_buffer(str, _strlen(str), data);
	free(str);
	return (0);
}

/**
 * handle_spec_c - Function to get and output next char variable given to printf
 * @ptr: Pointer to general data structure
 * Return: 0 if no error
 */
int		handle_spec_p(void *ptr)
{
	format_t	*data;
	char		p[2];

	data = (format_t*)ptr;
	c[0] = va_arg(data->args, int);
	c[1] = '\0';
	write_buffer(p, 1, data);
	return (0);
}
