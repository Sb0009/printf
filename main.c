#include "main.h"

int		main(void)
{
	_printf("Bonjour %c%c%c%c%c\n", 'm', 'o', 'n', 'd', 'e');

	_printf("Bonjour %s\n", "monde");

	_printf("Bonjour %d  %i\n", 123, -254);

	_printf("Bonjour %b \n", 123);
	return (0);
}
