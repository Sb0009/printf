#include "main.h"
#include <limits.h>
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


	printf("|u:|{%d}\n", _printf("%u", -1));
	printf("|u:|{%d}\n", printf("%u", -1));

	printf("|u:|{%d}\n", _printf("%u", 0));
	printf("|u:|{%d}\n", printf("%u", 0));

	printf("|u:|{%d}\n", _printf("%u", 4285798235));
	printf("|u:|{%d}\n", printf("%u", 4285798235));


	printf("|o:|{%d}\n", _printf("%o", -1));
	printf("|o:|{%d}\n", printf("%o", -1));

	printf("|o:|{%d}\n", _printf("%o", 0));
	printf("|o:|{%d}\n", printf("%o", 0));

	printf("|o:|{%d}\n", _printf("%o", 4285798235));
	printf("|o:|{%d}\n", printf("%o", 4285798235));


	printf("|x:|{%d}\n", _printf("%x", -1));
	printf("|x:|{%d}\n", printf("%x", -1));

	printf("|x:|{%d}\n", _printf("%x", 0));
	printf("|x:|{%d}\n", printf("%x", 0));

	printf("|x:|{%d}\n", _printf("%x", 4285798235));
	printf("|x:|{%d}\n", printf("%x", 4285798235));

	printf("|X:|{%d}\n", _printf("%X", -1));
	printf("|X:|{%d}\n", printf("%X", -1));

	printf("|X:|{%d}\n", _printf("%X", 0));
	printf("|X:|{%d}\n", printf("%X", 0));

	printf("|X:|{%d}\n", _printf("%X", 4285798235));
	printf("|X:|{%d}\n", printf("%X", 4285798235));

	printf("|p:|{%d}\n", _printf("%p", 0x0));
	printf("|p:|{%d}\n", printf("%p", 0x0));


	printf("|p:|{%d}\n", _printf("%p", (void*)0x21951));
	printf("|p:|{%d}\n", printf("%p", (void*)0x21951));


	printf("|p:|{%d}\n", _printf("%p", (void*)-1));
	printf("|p:|{%d}\n", printf("%p", (void*)-1));


	printf("|hd:|{%d}\n", _printf("%hd", 65537));
	printf("|hd:|{%d}\n", printf("%hd", 65537));


	printf("|ld:|{%d}\n", _printf("%ld", 2147483647));
	printf("|ld:|{%d}\n", printf("%ld", 2147483647));


	printf("|%%l:|{%d}\n", _printf("%l"));
	printf("|%%l:|{%d}\n", printf("%l"));

	printf("|%%h:|{%d}\n", _printf("%h"));
	printf("|%%h:|{%d}\n", printf("%h"));

	printf("|%%lr:|{%d}\n", _printf("%lr"));
	printf("|%%lr:|{%d}\n", printf("%lr"));

	printf("|%%hr:|{%d}\n", _printf("%hr"));
	printf("|%%hr:|{%d}\n", printf("%hr"));


	printf("|%%ld:|{%d}\n", _printf("%li", 0UL));
	printf("|%%ld:|{%d}\n", printf("%li", 0UL));
	return (0);
}
