#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#define BUFF_SIZE 1024

/**
 * enum format_spec - Lists all possible specifiers for the printf project
 * @SPEC_c: char 'c'
 * @SPEC_s: char 's'
 * @SPEC_perc: char 'perc'
 * @SPEC_d: char 'd'
 * @SPEC_i: char 'i'
 * @SPEC_b: char 'b'
 * @SPEC_u: char 'u'
 * @SPEC_u: char 'u'
 * @SPEC_o: char 'o'
 * @SPEC_x: char 'x'
 * @SPEC_X: char 'X'
 * @SPEC_S: char 'S'
 * @SPEC_p: char 'p'
 * @SPEC_r: char 'r'
 * @SPEC_R: char 'R'
 * @SPEC_LAST: end of enum
 */
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
 * struct format_functions_s - Structure associating specifier to a function
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
 * @nb_bytes: Number of bytes used by variable
 * @is_sign: Tells is number is signed or unsigned
 * @args: List of arguments
 * @minus_flag: Tells state of flag '-'
 * @plus_flag: Tells state of flag '+'
 * @zero_flag: Tells state of flag '0'
 * @space_flag: Tells state of flag ' '
 * @width_flag: Tells state of width flag
 * @hash_flag: Tells state of hash flag
 * @precision_flag: Tells state of precision flag
 * @upcase_flag: Tells state of uppercase flag
 * @long_flag: Tells state of long flag
 * @short_flag: Tells state of short flag
 * @fct_tab: Array of pointers to structure referencing a specifier function
 * @buffer: Buffer where content is written before being outputted to stdout
 * @bufferlen: Current length of the buffer
 * @nb_written_bytes: Number of currently written characters
 */
typedef struct	format_s
{
	va_list				args;
	unsigned char		is_sign;
	int					nb_bytes;
	unsigned char		minus_flag;
	unsigned char		plus_flag;
	unsigned char		space_flag;
	unsigned char		zero_flag;
	int					width_flag;
	unsigned char		hash_flag;
	unsigned char		precision_flag;
	int					precision_value;
	unsigned char		upcase_flag;
	unsigned char		long_flag;
	unsigned char		short_flag;
	format_functions_t	fct_tab[15];
	char				buffer[BUFF_SIZE];
	size_t				bufferlen;
	size_t				nb_written_bytes;
}				format_t;

int		_printf(const char *format, ...);
int		write_buffer(const char *str, size_t len, format_t *data);
void	print_buffer(format_t *data, const char *str, size_t len);
char	*printf_numbers(long nb, short base, format_t *data);
size_t	read_flags(const char *format, format_t *data);
char	*format_string(char *str, format_t *data, char freeable);
char	*format_number(char *str, long nb, short base, format_t *data);


int		handle_spec_c(void *ptr);
int		handle_spec_s(void *ptr);
int		handle_spec_di(void *ptr);
int		handle_spec_b(void *ptr);
int		handle_spec_p(void *ptr);
int		handle_spec_perc(void *ptr);
int		handle_spec_u(void *ptr);
int		handle_spec_o(void *ptr);
int		handle_spec_x(void *ptr);
int		handle_spec_X(void *ptr);
int		handle_spec_p(void *ptr);
int		handle_spec_S(void *ptr);
int		handle_spec_r(void *ptr);
int		handle_spec_R(void *ptr);

int		_strlen(char *str);
char	*_strncat(char *dest, const char *src, int n);
char	*_strcpy(char *dest, const char *src);
char	*_strncpy(char *dest, const char *src, int n);
int		_strclen(const char *str, char c);
char	*_strdup(char *str);
char	*_strcat(char *dest, char *src);
int		_isdigit(int c);
int		_atoi(const char *s);
int		_isprint(char c);
void	rev_string(char *s);
char	*rot13(char *s);

#endif /* __MAIN_H__ */
