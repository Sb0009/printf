#include "main.h"

void	print_buffer(format_t *data, const char *str, size_t len)
{
	data->nb_written_bytes += len;
	write(1, str, len);
}

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
