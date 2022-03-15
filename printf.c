#include "main.h"

/**
 * reset_flags - Resets flags for struct format_s for next variable parsing
 * @data: Pointer to structure containing general data
 */
void	reset_flags(format_t *data)
{
	data->is_sign = 1;
	data->nb_bytes = 4;
	data->minus_flag = 0;
	data->plus_flag = 0;
	data->space_flag = 0;
	data->zero_flag = 0;
	data->width_flag = 0;
	data->hash_flag = 0;
	data->precision_flag = 0;
	data->precision_value = 0;
	data->upcase_flag = 0;
	data->long_flag = 0;
	data->short_flag = 0;
}

/**
 * read_flags -
 *
 */

size_t		read_flags(const char *format, format_t *data)
{
	int		len;
	/**
	 * Order: '-', '+', space, '#', '0', width, precision, length, specifier
	 *
	 */
	len = 0;
	if (format[len] == '-')
	{
		data->minus_flag = 1;
		len++;
	}
	if (format[len] == '+')
	{
		data->minus_flag = 1;
		len++;
	}
	if (format[len] == ' ')
	{
		data->space_flag = 1;
		len++;
	}
	if (format[len] == '0')
	{
		data->zero_flag = 1;
		len++;
	}
	if (_isdigit(format[len]))
	{
		data->width_flag = _atoi(format + len);
		if (data->width_flag < 0)
			data->width_flag = 0;
		len++;
	}
	else if (format[len] == '*')
	{
		data->width_flag = va_arg(data->args, int);
		if (data->width_flag < 0)
			data->width_flag = 0;
		while (_isdigit(format[len]))
			len++;
	}
	if (format[len] == '.')
	{
		data->precision_flag = 1;
		len++;
		if (_isdigit(format[len + 1]))
		{
			data->precision_value = _atoi(format + len);
			if (data->precision_value < 0)
				data->precision_value = 0;
		}
		else if (format[len + 1] == '*')
		{
			data->precision_value = va_arg(data->args, int);
			if (data->precision_value < 0)
			{
				data->precision_flag = 0;
				data->precision_value = 0;
			}
		}
		else
			data->precision_value = 0;
		while (_isdigit(format[len]))
			len++;
	}
	if (format[len] == 'l')
	{
		data->long_flag = 1;
		len++;
	}
	else if (format[len] == 'h')
	{
		data->short_flag = 1;
		len++;
	}
	return (len);
}

/**
 * handle_specialchar - Calls fonction corresponding to specifier in string
 * @format: Pointer to format string
 * @data: Pointer to structure containing general data
 * Return: -1 if error, 0 if none
 */
int		handle_specialchar(const char **format, format_t *data)
{
	int			i;
	size_t		len, clen;

	reset_flags(data);
	(*format)++;
	len = read_flags(*format, data);
	*format += len;
	for (i = 0; i < SPEC_LAST; i++)
	{
		if (**format && **format == data->fct_tab[i].spec)
		{
			if (data->fct_tab[i].fct)
			{
				(*format)++;
				return (data->fct_tab[i].fct((void *)data));
			}
			if (!*format)
			{
				printf("Function not available yet\n");
				return (-1);
			}
		}
	}
	if (**format)
	{
		if (data->long_flag)
		{
			clen = _strclen(*format - len - 1, 'l');
			write_buffer((*format) - len - 1, clen, data);
			write_buffer((*format), 1, data);
			(*format)++;
			return (len);
		}
		if (data->short_flag)
		{
			clen = _strclen(*format - len - 1, 'h');
			write_buffer((*format) - len - 1, clen, data);
			write_buffer((*format), 1, data);
			(*format)++;
			return (len);
		}
		write_buffer((*format) - len - 1, len + 1, data);
	}
	return (-1);
}

/**
 * init_struct - Initializes funtion pointers array
 * @data: Struct containing array
 */
void	init_struct(format_t *data)
{
	data->nb_written_bytes = 0;
	data->buffer[0] = '\0';
	data->bufferlen = 0;
	data->fct_tab[SPEC_c].spec = 'c';
	data->fct_tab[SPEC_s].spec = 's';
	data->fct_tab[SPEC_perc].spec = '%';
	data->fct_tab[SPEC_d].spec = 'd';
	data->fct_tab[SPEC_i].spec = 'i';
	data->fct_tab[SPEC_b].spec = 'b';
	data->fct_tab[SPEC_u].spec = 'u';
	data->fct_tab[SPEC_o].spec = 'o';
	data->fct_tab[SPEC_x].spec = 'x';
	data->fct_tab[SPEC_X].spec = 'X';
	data->fct_tab[SPEC_S].spec = 'S';
	data->fct_tab[SPEC_p].spec = 'p';
	data->fct_tab[SPEC_r].spec = 'r';
	data->fct_tab[SPEC_R].spec = 'R';
	data->fct_tab[SPEC_LAST].spec = '\0';
	data->fct_tab[SPEC_c].fct = handle_spec_c;

	data->fct_tab[SPEC_s].fct = handle_spec_s;

	data->fct_tab[SPEC_perc].fct = handle_spec_perc;
	data->fct_tab[SPEC_d].fct = handle_spec_di;
	data->fct_tab[SPEC_i].fct = handle_spec_di;
	data->fct_tab[SPEC_b].fct = handle_spec_b;
	data->fct_tab[SPEC_u].fct = handle_spec_u;
	data->fct_tab[SPEC_o].fct = handle_spec_o;
	data->fct_tab[SPEC_x].fct = handle_spec_x;
	data->fct_tab[SPEC_X].fct = handle_spec_X;
	data->fct_tab[SPEC_S].fct = NULL;
	data->fct_tab[SPEC_p].fct = handle_spec_p;
	data->fct_tab[SPEC_r].fct = NULL;
	data->fct_tab[SPEC_R].fct = NULL;
	data->fct_tab[SPEC_LAST].fct = NULL;
}

/**
 * _printf - Imitates the existing function printf
 * @format: String to parse and print
 * Return: The number of characters printed
 */
int		_printf(const char *format, ...)
{
	format_t	data;
	int			ret;
	int			len;

	if (!format)
		return (-1);
	va_start(data.args, format);
	init_struct(&data);
	while (*format)
	{
		ret = 1;
		if (*format == '%')
		{
			ret = handle_specialchar(&format, &data);
			if (!*format && ret == -1)
			{
				write_buffer(NULL, 0, &data);
				return (-1);
			}
		}
		if (ret)
		{
			len = _strclen(format, '%');
			write_buffer(format, len, &data);
			format += len;
		}
	}
	write_buffer(NULL, 0, &data);
	return (data.nb_written_bytes);
}
