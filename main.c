#include "main.h"
#include <limits.h>
int		main(void)
{

	printf("|%d\n", _printf("%S", "Best\nSchool"));
	printf("|%d\n", _printf("%r", "Best\nSchool"));
	printf("|%d\n", _printf("%R", "Best\nSchool"));
	return (0);
}
