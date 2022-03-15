#include "main.h"

/**
 * handle_spec_u - Function to get and output next uint variable argument
 * @ptr: Pointer to general data structure
 * Return: 0 if no error
 */
int	handle_spec_u(void *ptr)
{
	format_t		*data;
	unsigned long	nb;
	char			*str;

	data = (format_t *)ptr;
	data->is_sign = 0;
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
	str = printf_numbers(nb, 10, data);
	if (!str)
		return (-1);
	write_buffer(str, _strlen(str), data);
	free(str);
	return (0);
}


/**
 * handle_spec_o - Function to get and output next octal int variable argument
 * @ptr: Pointer to general data structure
 * Return: 0 if no error
 */
int	handle_spec_o(void *ptr)
{
	format_t		*data;
	unsigned long	nb;
	char			*str;

	data = (format_t *)ptr;
	data->is_sign = 0;
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
	str = printf_numbers(nb, 8, data);
	if (!str)
		return (-1);
	write_buffer(str, _strlen(str), data);
	free(str);
	return (0);
}


/**
 * handle_spec_x - Function to get and output next hex int variable argument
 * @ptr: Pointer to general data structure
 * Return: 0 if no error
 */
int	handle_spec_x(void *ptr)
{
	format_t		*data;
	unsigned long	nb;
	char			*str;

	data = (format_t *)ptr;
	data->is_sign = 0;
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
	str = printf_numbers(nb, 16, data);
	if (!str)
		return (-1);
	write_buffer(str, _strlen(str), data);
	free(str);
	return (0);
}


/**
 * handle_spec_X - Function to get and output next hex int variable argument
 * @ptr: Pointer to general data structure
 * Return: 0 if no error
 */
int	handle_spec_X(void *ptr)
{
	format_t		*data;
	unsigned long	nb;
	char			*str;

	data = (format_t *)ptr;
	data->is_sign = 0;
	data->upcase_flag = 1;
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
	str = printf_numbers(nb, 16, data);
	if (!str)
		return (-1);
	write_buffer(str, _strlen(str), data);
	free(str);
	return (0);
}

/**
 * handle_spec_p - Function to get and output next pointer variable argument
 * @ptr: Pointer to general data structure
 * Return: 0 if no error
 */
int	handle_spec_p(void *ptr)
{
	format_t		*data;
	void			*addr;
	char			*str;

	data = (format_t *)ptr;
	data->is_sign = 0;
	data->nb_bytes = 8;
	data->hash_flag = 1;
	addr = va_arg(data->args, void *);
	if (!addr)
	{
		write_buffer("(nil)", 4, data);
		return (0);
	}
	str = printf_numbers((unsigned long)addr, 16, data);
	if (!str)
		return (-1);
	write_buffer(str, _strlen(str), data);
	free(str);
	return (0);
}
