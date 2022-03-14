#include "main.h"

void	get_signed_number(char *str, long nb, short base, format_t *data)
{
	int		nb_digits;
	long	cpy;
	int		digit;

	nb_digits = 1;
	cpy = nb;
	while (cpy >= base)
	{
		cpy /= base;
		nb_digits++;
	}
	cpy = nb;
	while (nb_digits > 0)
	{
		digit = nb % base;
		if (digit < 0)
			digit = -digit;
		str[nb_digits - 1] = digit + '0';
		nb /= base;
		nb_digits--;
	}
}

void	get_unsigned_number(char *str, unsigned long nb, short base,
		format_t *data)
{
	int				nb_digits;
	unsigned long	cpy;
	int				digit;

	nb_digits = 1;
	cpy = nb;
	while (cpy >= base)
	{
		cpy /= base;
		nb_digits++;
	}
	cpy = nb;
	while (nb_digits > 0)
	{
		digit = nb % base;
		str[nb_digits - 1] = digit + '0';
		nb /= base;
		nb_digits--;
	}
}

char	*format_number(char *str, long nb, short base, format_t *data)
{
	char	*buff;
	size_t	i, len, nblen;

	nblen = _strlen(str);
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
	if (base == 10 && nb < 0)
		buff[0] = '-';
	if (data->hash_flag == 1)
	{
		if (base == 2 || base == 8 || base == 16)
			buff[0] = '0';
		if (base == 2)
			buff[1] = 'b' + data->uppercase_flag ? -32 : 0;
		if (base == 16)
			buff[1] = 'x' + data->uppercase_flag ? -32 : 0;
	}
	/**
	 * Add flags formatting here
	 */
	_strcat(buff, str);
	return (buff);
}

char	*printf_numbers(long nb, short base, format_t *data)
{
	char	str[64];
	int		i;

	if (base < 2 || base > 16)
		return (NULL);
	for (i = 0; i < 64; i++)
		str[i] = '\0';
	if (base == 10 && nb < 0)
		get_signed_number(str, nb, base, data);
	else
		get_unsigned_number(str, (unsigned long)nb, base, data);
	return (format_number(str, nb, base, data))
}
