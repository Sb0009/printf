#include "main.h"

/**
 * handle_spec_c - Function to get and output next char variable argument
 * @ptr: Pointer to general data structure
 * Return: 0 if no error
 */
int		handle_spec_c(void *ptr)
{
	format_t	*data;
	char		c[2];

	data = (format_t *)ptr;
	c[0] = va_arg(data->args, int);
	c[1] = '\0';
	write_buffer(c, 1, data);
	return (0);
}

/**
 * handle_spec_s - Function to get and output next string variable argument
 * @ptr: Pointer to general data structure
 * Return: 0 if no error
 */
int		handle_spec_s(void *ptr)
{
	format_t	*data;
	char		*s;

	data = (format_t *)ptr;
	s = va_arg(data->args, char *);
	if (!s)
		s = "(null)";
	write_buffer(s, _strlen(s), data);
	return (0);
}

/**
 * handle_spec_di - Function to get and output next int variable argument
 * @ptr: Pointer to general data structure
 * Return: 0 if no error
 */
int	handle_spec_di(void *ptr)
{
	format_t	*data;
	long		nb;
	char		*str;

	data = (format_t *)ptr;
	if (data->long_flag == 1)
		nb = (long)va_arg(data->args, long);
	else if (data->short_flag == 1)
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

/**
 * handle_spec_b - Function to get and output next binary int variable argument
 * @ptr: Pointer to general data structure
 * Return: 0 if no error
 */
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
 * handle_spec_perc - Function to get and output next char variable given to printf
 * @ptr: Pointer to general data structure
 * Return: 0 if no error
 */
int		handle_spec_perc(void *ptr)
{
	format_t	*data;
	char		perc[2];

	data = (format_t *)ptr;
	c[0] = va_arg(data->args, int);
	c[1] = '\0';
	write_buffer("%%", 1, data);
	return (0);
}
