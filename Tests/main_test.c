#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    len = _printf("Length:[%d, %i]\n", len, len);
    len2 = printf("Length:[%d, %i]\n", len2, len2);
    if (len != len2)
        printf("Diff - len:%d | len2:%d\n");
    len = _printf("Negative:[%d]\n", -762534);
    len2 = printf("Negative:[%d]\n", -762534);

    if (len != len2)
        printf("Diff - len:%d | len2:%d\n");
    len = _printf("Unsigned:[%u]\n", ui);
    len2 = printf("Unsigned:[%u]\n", ui);
    if (len != len2)
        printf("Diff - len:%d | len2:%d\n");
    len = _printf("Unsigned octal:[%o]\n", ui);
    len2 = printf("Unsigned octal:[%o]\n", ui);
    if (len != len2)
        printf("Diff - len:%d | len2:%d\n");
    len = _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    len2 = printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    if (len != len2)
        printf("Diff - len:%d | len2:%d\n");
    len = _printf("Character:[%c]\n", 'H');
    len2 = printf("Character:[%c]\n", 'H');
    if (len != len2)
        printf("Diff - len:%d | len2:%d\n");
    len = _printf("String:[%s]\n", "I am a string !");
    len2 = printf("String:[%s]\n", "I am a string !");
    if (len != len2)
        printf("Diff - len:%d | len2:%d\n");
    len = _printf("Address:[%p]\n", addr);
    len2 = printf("Address:[%p]\n", addr);
    if (len != len2)
        printf("Diff - len:%d | len2:%d\n");
    len = _printf("Percent:[%%]\n");
    len2 =printf("Percent:[%%]\n");
    if (len != len2)
        printf("Diff - len:%d | len2:%d\n");
    len = _printf("Len:[%d]\n", len);
    len2 = printf("Len:[%d]\n", len2);
    if (len != len2)
        printf("Diff - len:%d | len2:%d\n");
    len = _printf("Unknown:[%r]\n");
    len2 = printf("Unknown:[%r]\n");
    if (len != len2)
        printf("Diff - len:%d | len2:%d\n");
    return (0);
}
alex@ubuntu:~/c/printf$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c
alex@ubuntu:~/c/printf$ ./printf
Let's try to printf a simple sentence.
Let's try to printf a simple sentence.
Length:[39, 39]
Length:[39, 39]
Negative:[-762534]
Negative:[-762534]
Unsigned:[2147484671]
Unsigned:[2147484671]
Unsigned octal:[20000001777]
Unsigned octal:[20000001777]
Unsigned hexadecimal:[800003ff, 800003FF]
Unsigned hexadecimal:[800003ff, 800003FF]
Character:[H]
Character:[H]
String:[I am a string !]
String:[I am a string !]
Address:[0x7ffe637541f0]
Address:[0x7ffe637541f0]
Percent:[%]
Percent:[%]
Len:[12]
Len:[12]
Unknown:[%r]
Unknown:[%r]
