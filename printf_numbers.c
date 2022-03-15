#include "main.h"

/**
 * get_signed_number - Writes unformatted number to given string
 * @str: String to write number in
 * @nb: Number
 * @base: Base to write number in
 * @returns {any}
 */
void	get_signed_number(char *str, long nb, short base)
{
	int		nb_digits;
	long	cpy;
	int		digit;

	nb_digits = 1;
	cpy = nb;
	while ((cpy > 0 && cpy >= base) || (cpy < 0 && cpy <= -base))
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

/**
 * get_unsigned_number - Writes unformatted number to given string
 * @str: String to write number in
 * @nb: Number
 * @base: Base to write number in
 * @upper: If base is higher than 10, tells if letters should be uppercase
 */
void	get_unsigned_number(char *str, unsigned long nb, short base, int upper)
{
	int				nb_digits;
	unsigned long	cpy;
	int				digit;

	nb_digits = 1;
	cpy = nb;
	while (cpy >= (unsigned long)base)
	{
		cpy /= base;
		nb_digits++;
	}
	cpy = nb;
	while (nb_digits > 0)
	{
		digit = nb % base;
		if (digit >= 10)
			str[nb_digits - 1] = digit - 10 + 'a' + (upper ? -32 : 0);
		else
			str[nb_digits - 1] = digit + '0';
		nb /= base;
		nb_digits--;
	}
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
			buff[1] = 'b' + (data->upcase_flag ? -32 : 0);
		if (base == 16)
			buff[1] = 'x' + (data->upcase_flag ? -32 : 0);
	}
	/**
	 * Add flags formatting here
	 */
	(void)nblen;
	_strcat(buff, str);
	return (buff);
}

/**
 * printf_numbers - Creates string depending on number, base and given flags
 * @nb: Number to convert to string
 * @base: Numerical base to write the number in
 * @data: Pointer to general data structure
 * Return: Formatted number string
 */
char	*printf_numbers(long nb, short base, format_t *data)
{
	char	str[64];
	int		i;

	if (base < 2 || base > 16)
		return (NULL);
	for (i = 0; i < 64; i++)
		str[i] = '\0';
	if (data->is_sign)
		get_signed_number(str, nb, base);
	else if (data->nb_bytes == 2)
		get_unsigned_number(str, (unsigned short)nb, base, data->upcase_flag);
	else if (data->nb_bytes == 4)
		get_unsigned_number(str, (unsigned int)nb, base, data->upcase_flag);
	else
		get_unsigned_number(str, (unsigned long)nb, base, data->upcase_flag);
	return (format_number(str, nb, base, data));
}
