#include "main.h"

int		main(void)
{
	_printf("%a\n");
	printf("{%d}\n", _printf("Bonjour %c%c%c%c%c\n", 'm', 'o', 'n', 'd', 'e'));
	printf("{%d}\n", printf("Bonjour %c%c%c%c%c\n", 'm', 'o', 'n', 'd', 'e'));

	printf("{%d}\n", _printf("Bonjour %s\n", "monde"));
	printf("{%d}\n", printf("Bonjour %s\n", "monde"));

	printf("{%d}\n", _printf("Bonjour %d  %i\n", 123, -254));
	printf("{%d}\n", printf("Bonjour %d  %i\n", 123, -254));

	printf("{%d}\n", _printf("Bonjour %b \n", 123));
	printf("{%d}\n", printf("Bonjour %b \n", 123));

	printf("{%d}\n", _printf("%%\n"));
	printf("{%d}\n", printf("%%\n"));
	printf("{%d}\n", _printf(NULL));
	printf("{%d}\n", printf(NULL));
	printf("{%d}\n", _printf("%s", (char*)NULL));
	printf("{%d}\n", printf("%s", (char*)NULL));

	printf("{%d}\n", _printf(""));
	printf("{%d}\n", printf(""));

	printf("{%d}\n", _printf("%"));
	printf("{%d}\n", printf("%"));


	printf("{%d}\n", _printf("bijour %"));
	printf("{%d}\n", printf("bijour %"));
	return (0);
}
