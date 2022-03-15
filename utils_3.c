#include "main.h"

/**
 * _isprint - Tells if character is printable
 * @c: character
 * Return: 1 if printable, 0 if not
 */
int	_isprint(char c)
{
	if ((c > 0 && c < 32) || c >= 127)
		return (0);
	return (1);
}

/**
 * rev_string - reverses string
 * @s: string to reverse
 */
void	rev_string(char *s)
{
	int		i, j;
	char	tmp;

	for (i = 0; s[i]; i++)
		;
	j = 0;
	while (--i > j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		j++;
	}
}

/**
 * rot13 - does a rot13 on given string
 * @s: string to rot13 onto
 * Return: s
 */

char	*rot13(char *s)
{
	char	alpha[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char	alpharot[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	int		i, j;

	for (i = 0; s[i]; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (s[i] == alpha[j])
			{
				s[i] = alpharot[j];
				break;
			}
		}
	}
	return (s);
}
