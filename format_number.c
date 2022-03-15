#include "main.h"

/**
 * format_number_width - Outputs number string formatted with width flag
 * @str: Unformatted number string
 * @nb: Number
 * @data: Pointer to general data structure
 * @result: Output string
 * @len: length of unformatted string
 * Return: Formatted number
 */
char	*format_number_width(char *str, long nb, format_t *data, char *result,
							int len)
{
	int	i, start;

	if (!_isdigit(str[0]) && data->zero_flag)
	{
		result[0] = str[0];
		start = 1;
	}
	else if (data->hash_flag && nb && data->zero_flag && !_isdigit(str[1]))
	{
		result[0] = '0';
		result[1] = str[1];
		start = 2;
	}
	else
		start = 0;
	i = start;
	while (i < data->width_flag - len + start)
	{
		if (data->zero_flag)
			result[i] = '0';
		else
			result[i] = ' ';
		i++;
	}
	_strcpy(result + i, str + start);
	return (result);
}

/**
 * format_number_p2 - Outputs formatted number string corresponding to flags
 * @str: Unformatted number string
 * @nb: Number
 * @data: Pointer to general data structure
 * Return: Formatted number
 */
char	*format_number_p2(char *str, long nb, format_t *data)
{
	int		len;
	char	*result;

	len = _strlen(str);
	if (data->width_flag <= 0 || data->width_flag <= len)
		return (str);
	result = malloc(sizeof(char) * (data->width_flag + 1));
	if (!result)
	{
		free(str);
		return (NULL);
	}
	if (data->minus_flag)
	{
		_strcpy(result, str);
		while (len < data->width_flag)
			result[len++] = ' ';
		result[len] = '\0';
	}
	else
		format_number_width(str, nb, data, result, len);
	free(str);
	return (result);
}
/**
 * format_number - Outputs formatted number string corresponding to flags
 * @str: Unformatted number string
 * @nb: Number
 * @base: Base of number
 * @data: Pointer to general data structure
 * Return: Formatted number
 */
char	*format_number(char *str, long nb, short base, format_t *data)
{
	char	*buff;
	int		i, len;

	len = _strlen(str) + (nb < 0 && base == 10 ? 1 : 0);
	if (data->hash_flag == 1)
	{
		if (base == 2 || base == 16)
			len += 2;
		else
			len++;
	}
	if (len < data->width_flag)
		len = data->width_flag;
	buff = malloc(sizeof(char) * (len + 1));
	if (!buff)
		return (NULL);
	for (i = 0; i <= len; i++)
		buff[i] = '\0';
	if (base == 10 && nb < 0 && data->is_sign)
		buff[0] = '-';
	else if (data->plus_flag || data->space_flag)
	{
		buff[0] = data->plus_flag ? '+' : ' ';
		i = i;
	}
	if (data->hash_flag == 1 && nb)
	{
		if (base == 2 || base == 8 || base == 16)
			buff[0] = '0';
		if (base == 2)
			buff[1] = 'b' + (data->upcase_flag ? -32 : 0);
		if (base == 16)
			buff[1] = 'x' + (data->upcase_flag ? -32 : 0);
	}
	_strcat(buff, str);
	return (format_number_p2(buff, nb, data));
}
