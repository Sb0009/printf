#include <stdlib.h>

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
