#include "main.h"


/**
 * read_flags_p2 - Parses flags after '%' character, before type specifier
 * @format: String to parse
 * @data: Pointer to structure containing general data
 * @len: Current index on format string
 * Orders to read flags : '-', '+', space, '#', '0', width,
 *						precision, length, specifier
 * Return: Length of all flags combined
 */
size_t		read_flags_p2(const char *format, format_t *data, int len)
{
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
 * read_flags - Parses flags after '%' character, before type specifier
 * @format: String to parse
 * @data: Pointer to structure containing general data
 * Orders to read flags : '-', '+', space, '#', '0', width,
 *						precision, length, specifier
 * Return: Length of all flags combined
 */
size_t		read_flags(const char *format, format_t *data)
{
	int		len;

	len = 0;
	while (format[len] == '-' || format[len] == '+' || format[len] == ' '
		|| format[len] == '0' || format[len] == '#')
	{
		if (format[len] == '-')
			data->minus_flag = 1;
		if (format[len] == '+')
			data->plus_flag = 1;
		if (format[len] == ' ')
			data->space_flag = 1;
		if (format[len] == '0')
			data->zero_flag = 1;
		if (format[len] == '#')
			data->hash_flag = 1;
		len++;
	}
	if (_isdigit(format[len]))
	{
		data->width_flag = _atoi(format + len);
		if (data->width_flag < 0)
			data->width_flag = 0;
		while (_isdigit(format[len]))
			len++;
	}
	else if (format[len] == '*')
	{
		data->width_flag = va_arg(data->args, int);
		if (data->width_flag < 0)
			data->width_flag = 0;
		len++;
	}
	return (read_flags_p2(format, data, len));
}
