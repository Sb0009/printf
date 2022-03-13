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
