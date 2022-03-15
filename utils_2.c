#include "main.h"

/**
 * _strdup - Creates a duplicate of a given string
 * @str: String to duplicate
 * Return: Duplicate of @str
 */
char	*_strdup(char *str)
{
	size_t	len;
	char	*dup;

	if (!str)
		return (NULL);
	len = _strlen(str);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	return (_strcpy(dup, str));
}
/**
 * _strcat - concatenates two strings
 * @dest: string to append to
 * @src: string to append to dest
 * Return: dest
 */
char	*_strcat(char *dest, char *src)
{
	char	*str;

	str = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (str);
}
/**
 * _isdigit - Checks if argument is a digit
 *
 * @c: character to use for comparison
 *
 * Return: returns 1 if c is a digit, 0 if not
 */


int		_isdigit(int c)
{
	c = (unsigned char)c;
	return (c >= '0' && c <= '9' ? 1 : 0);
}
/**
 * _atoi - converts string into an integer
 * @s: string to convert
 * Return: integer format of string
 */

int	_atoi(const char *s)
{
	int	sign;
	int	nb;

	nb = 0;
	sign = 1;
	while (*s && (*s < '0' || *s > '9'))
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		if ((nb == -214748364 && *s == '9') || nb < -2141748364)
			break ;
		if ((nb == 214748364 && *s >= '8') || nb > 2141748364)
			break ;
		if (sign == 1)
			nb = nb * 10 + (*s - '0');
		else if (sign == -1)
			nb = nb * 10 - (*s - '0');
		s++;
	}
	return (nb);
}
