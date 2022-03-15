#include "main.h"

/**
 * write_spec_S - Copies s into s2, writing non-printable chars in hex value
 * @s: string to copy from
 * @s2: string to write to
 */
void	write_spec_S(char *s, char *s2)
{
	int	i, j;

	j = 0;
	for (i = 0; s[i]; i++)
	{
		if (!_isprint(s[i]))
		{
			s2[j++] = '\\';
			s2[j++] = 'x';
			s2[j] = s[i] / 16;
			if (s2[j] >= 10)
				s2[j] += 'A' - 10;
			else
				s2[j] += '0';
			j++;
			s2[j] = s[i] % 16;
			if (s2[j] >= 10)
				s2[j] += 'A' - 10;
			else
				s2[j] += '0';
			j++;
		}
		else
			s2[j++] = s[i];
	}
}

/**
 * handle_spec_S - Function to get and output next string variable argument
 * also shows non-printable characters in hexa
 * @ptr: Pointer to general data structure
 * Return: 0 if no error
 */
int		handle_spec_S(void *ptr)
{
	format_t	*data;
	char		*s, *s2, *s3;
	int			i, count, s2len;

	data = (format_t *)ptr;
	s = va_arg(data->args, char *);
	if (!s)
		s = "(null)";
	count = 0;
	for (i = 0; s[i]; i++)
		if (!_isprint(s[i]))
			count++;
	s2len = i + count * 3;
	s2 = malloc(sizeof(char) * (s2len + 1));
	if (!s2)
		return (-1);
	for (i = 0; i < s2len; i++)
		s2[i] = '\0';
	write_spec_S(s, s2);
	s3 = format_string(s2);
	free(s2);
	write_buffer(s2, s2len, data);
	free(s3);
	return (0);
}


/**
 * handle_spec_r - Function to get, reverse, and output next string argument
 * @ptr: Pointer to general data structure
 * Return: 0 if no error
 */
int		handle_spec_r(void *ptr)
{
	format_t	*data;
	char		*s, *dup;

	dup = NULL;
	data = (format_t *)ptr;
	s = va_arg(data->args, char *);
	if (!s)
		dup = "(llun)";
	else
	{
		dup = _strdup(s);
		if (!dup)
			return (-1);
		rev_string(dup);
	}
	write_buffer(dup, _strlen(dup), data);
	free(dup);
	return (0);
}

/**
 * handle_spec_R - Function to get, rot13, and output next string argument
 * @ptr: Pointer to general data structure
 * Return: 0 if no error
 */
int		handle_spec_R(void *ptr)
{
	format_t	*data;
	char		*s, *dup;

	data = (format_t *)ptr;
	s = va_arg(data->args, char *);
	if (!s)
		dup = "(ahyy)";
	else
	{
		dup = _strdup(s);
		if (!dup)
			return (-1);
		rot13(dup);
	}
	write_buffer(dup, _strlen(dup), data);
	free(dup);
	return (0);
}
