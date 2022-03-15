#include "main.h"

/**
 * format_string - Outputs string formatted with flags
 * @str: String to format
 * @data: Pointer to general data structure
 * @freeable: Tells if str is a literal
 * Return: Formatted string
 */
char	*format_string(char *str, format_t *data, char freeable)
{
	int		i, len;
	char	*result;

	len = _strlen(str);
	if (data->width_flag <= 0 || data->width_flag <= len)
	{
		if (!freeable)
			return (_strdup(str));
		return (str);
	}
	result = malloc(sizeof(char) * (data->width_flag + 1));
	if (!result)
	{
		if (freeable)
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
	{
		for (i = 0; i < data->width_flag - len; i++)
			result[i] = ' ';
		_strcpy(result + i, str);
	}
	if (freeable)
		free(str);
	return (result);
}
