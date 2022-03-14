#include "main.h"

/**
 * print_buffer - Prints given string and adds its length to counter
 * @data: Pointer to structure containing general data
 * @str: String to print
 * @len: Length of @s
 */
void	print_buffer(format_t *data, const char *str, size_t len)
{
	data->nb_written_bytes += len;
	write(1, str, len);
}

/**
 * handle_buffer_overflow - Print buffer handler for longer strings
 * @str: String to print
 * @len: Length of @str
 * @data: Pointer to structure containing general data
 * Return: 0 if no error
 */
int		handle_buffer_overflow(const char *str, size_t len, format_t *data)
{
	while (len)
	{
		if (len > BUFF_SIZE - 1)
		{
			print_buffer(data, str, BUFF_SIZE - 1);
			len -= BUFF_SIZE - 1;
			str += BUFF_SIZE - 1;
		}
		else
		{
			_strcpy(data->buffer, str);
			data->bufferlen = _strlen(data->buffer);
			len = 0;
		}
	}
	return (0);
}

/**
 * write_buffer - Writes data into buffer, and prints and empties it when full
 * @str: String to add to buffer
 * @len: Size of @str
 * @data: Pointer to structure containing general data
 * Return: 0 if no error
 */
int		write_buffer(const char *str, size_t len, format_t *data)
{
	size_t	i;

	if (!str)
	{
		print_buffer(data, data->buffer, data->bufferlen);
		data->buffer[0] = '\0';
		data->bufferlen = 0;
	}
	if (len + data->bufferlen >= BUFF_SIZE - 1)
	{
		for (i = 0; i < len && i + data->bufferlen < BUFF_SIZE - 1; i++)
			data->buffer[data->bufferlen + i] = str[i];
		data->buffer[data->bufferlen + i] = '\0';
		data->bufferlen += i;
		print_buffer(data, data->buffer, data->bufferlen);
		data->buffer[0] = '\0';
		data->bufferlen = 0;
		handle_buffer_overflow(str + i, len - i, data);
	}
	else
	{
		for (i = 0; i < len && i + data->bufferlen < BUFF_SIZE - 1; i++)
			data->buffer[data->bufferlen + i] = str[i];
		data->buffer[data->bufferlen + i] = '\0';
		data->bufferlen += i;
	}
	return (0);
}
