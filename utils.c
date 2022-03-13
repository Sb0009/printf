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
 * _strcat - concatenates two strings
 * @dest: string to append to
 * @src: string to append to dest
 * Return: dest
 */
char	*_strcat(char *dest, const char *src)
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
