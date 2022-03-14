#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#define BUFF_SIZE 1024

enum format_spec
{
	SPEC_c = 0,
	SPEC_s,
	SPEC_perc,
	SPEC_d,
	SPEC_i,
	SPEC_b,
	SPEC_u,
	SPEC_o,
	SPEC_x,
	SPEC_X,
	SPEC_S,
	SPEC_p,
	SPEC_r,
	SPEC_R,
	SPEC_LAST
};

/**
 * struct format_function_s - Structure associating specifier to a function
 * @spec: Specifier character
 * @fct: Pointer to function corresponding to specifier
 */

typedef struct	format_functions_s
{
	char	spec;
	int		(*fct)(void *ptr);
}				format_functions_t;


/**
 * struct format_s - Structure containg general data relevant to the function
 * @args: List of arguments
 * @minus_flag: Indicates if the flag '-' is currently used and its value
 * @plus_flag: Indicates if the flag '+' is currently used and its value
 * @zero_flag: Indicates if the flag '0' is currently used and its value
 * @space_flag: Indicates if the flag ' ' is currently used and its value
 * @width_flag: Indicates if the width flag is currently used and its value
 * @precision_flag: Indicates if the precision flag is currently used and its value
 * @fct_tab: Array of pointers to structure referencing a specifier function
 * @buffer: Buffer where content is written before being outputted to stdout
 * @buffer_len: Current length of the buffer
 * @nb_written_bytes: Number of currently written characters
 */

typedef struct	format_s
{
	va_list				args;
	unsigned char		minus_flag;
	unsigned char		plus_flag;
	unsigned char		space_flag;
	unsigned char		zero_flag;
	unsigned char		width_flag;
	unsigned char		hash_flag;
	unsigned char		precision_flag;
	unsigned char		uppercase_flag;
	format_functions_t	fct_tab[15];
	char				buffer[BUFF_SIZE];
	size_t				bufferlen;
	size_t				nb_written_bytes;
}				format_t;

int		_printf(const char *format, ...);
int		write_buffer(const char *str, size_t len, format_t *data);
void	print_buffer(format_t *data, const char *str, size_t len);
char	*printf_numbers(long nb, short base, format_t *data);


int		handle_spec_c(void *ptr);
int		handle_spec_s(void *ptr);
int		handle_spec_di(void *ptr);


int		_strlen(char *str);
char	*_strncat(char *dest, const char *src, int n);
char	*_strcpy(char *dest, const char *src);
char	*_strncpy(char *dest, const char *src, int n);
int		_strclen(const char *str, char c);
char	*_strdup(char *str);
char	*_strcat(char *dest, char *src);

int print_string(va_list argument);
int _putchar(char c);
int print_s(va_list arg);
int print_S(va_list arg);
int print_b(va_list arg);
int print_r(va_list arg);
int print_p(va_list arg);
int print_u(va_list arg);
int print_x(va_list arg);
int print_X(va_list arg);
int print_o(va_list arg);
#endif /* __MAIN_H__ */
