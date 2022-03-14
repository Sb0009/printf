#include "main.h"

/**
 * _strlen - counts size of a string
 * @str: string to check size of
 * Return: returns size of str
 */
int	_strlen(char *str)
{
	int	i;

	for (i = 0; str[i]; i++)
		;
	return (i);
}

/**
 * _strncat - concatenates two strings, up to n characters from src
 * @dest: string to append to
 * @src: string to append to dest
 * @n: number of characters to append
 * Return: dest
 */

char	*_strncat(char *dest, const char *src, int n)
{
	char	*str;

	str = dest;
	while (*dest)
		dest++;
	while (n-- && *src)
		*dest++ = *src++;
	if (n)
		*dest = '\0';
	return (str);
}

/**
 * _strcpy - copy string's content into another
 * @dest: string to copy into
 * @src: string to copy from
 * Return: returns string where content was pasted
 */
char	*_strcpy(char *dest, const char *src)
{
	int	i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strncpy - copies from one string to another, up to n characters
 * @dest: string to copy to
 * @src: string to copy from
 * @n: number of characters to copy;
 * Return: str
 */
char	*_strncpy(char *dest, const char *src, int n)
{
	char	*str;

	str = dest;
	while (*src && n)
	{
		*dest++ = *src++;
		n--;
	}
	while (n--)
		*dest++ = '\0';
	return (str);
}


/**
 * _strclen - Counts size of a string till specific character or eos
 * @str: String to check size of
 * @c: Separator character
 * Return: Seturns size of str till @c
 */
int		_strclen(const char *str, char c)
{
	int	i;

	for (i = 0; str[i] && str[i] != c; i++)
		;
	return (i);
}

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
