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
	char		*s;
	size_t		len;

	data = (format_t *)ptr;
	c[0] = va_arg(data->args, int);
	c[1] = '\0';
	s = format_string(c, data, 0);
	if (!s)
		return (-1);
	len = _strlen(s);
	if (!c[0])
		len = 1;
	write_buffer(s, len, data);
	free(s);
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
	s = format_string(s, data, 0);
	if (!s)
		return (-1);
	write_buffer(s, _strlen(s), data);
	free(s);
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
	data->is_sign = 1;
	if (data->long_flag == 1)
	{
		nb = (long)va_arg(data->args, long);
		data->nb_bytes = 8;
	}
	else if (data->short_flag == 1)
	{
		data->nb_bytes = 2;
		nb = (short)va_arg(data->args, int);
	}
	else
	{
		data->nb_bytes = 4;
		nb = va_arg(data->args, int);
	}
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
	data->nb_bytes = 4;
	data->is_sign = 0;
	data->plus_flag = 0;
	data->space_flag = 0;
	if (data->long_flag == 1)
	{
		nb = (unsigned long)va_arg(data->args, unsigned long);
		data->nb_bytes = 8;
	}
	else if (data->short_flag == 1)
	{
		data->nb_bytes = 2;
		nb = (unsigned short)va_arg(data->args, int);
	}
	else
	{
		data->nb_bytes = 4;
		nb = va_arg(data->args, unsigned int);
	}
	str = printf_numbers(nb, 2, data);
	if (!str)
		return (-1);
	write_buffer(str, _strlen(str), data);
	free(str);
	return (0);
}

/**
 * handle_spec_perc - Function to output '%' char
 * @ptr: Pointer to general data structure
 * Return: 0 if no error
 */
int		handle_spec_perc(void *ptr)
{
	format_t	*data;

	data = (format_t *)ptr;
	write_buffer("%", 1, data);
	return (0);
}
