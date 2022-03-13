#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
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

typedef struct	format_functions_s
{
	char	spec;
	int		(*fct)(void *ptr);
}				format_functions_t;


typedef struct	format_s
{
	va_list				args;
	char				minus_flag;
	char				plus_flag;
	unsigned char		space_flag;
	unsigned char		width_flg;
	char				precision_flg;
	format_functions_t	fct_tab[15];
}				format_t;

int		_printf(const char *format, ...);


int		handle_spec_c(void *ptr);

#endif /* __MAIN_H__ */
