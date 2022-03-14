#include "main.h"


/**
 * handle_specialchar - Calls fonction corresponding to specifier in format string
 * @format: Pointer to format string
 * @data: Pointer to structure containing general data
 * Return: -1 if error, 0 if none
 */
int		handle_specialchar(const char **format, format_t *data)
{
	int			i;

	(*format)++;
	/**
	 * Add format handling here
	 */

	for (i = 0; i < SPEC_LAST; i++)
	{
		if (**format && **format == data->fct_tab[i].spec)
		{
			(*format)++;
			if (data->fct_tab[i].fct)
				return (data->fct_tab[i].fct((void*)data));
			else
			{
				printf("Function not available yet\n");
				return (-1);
			}
		}
		/* code */
	}
	return (-1);
}

/**
 * init_struct - Initializes funtion pointers array
 * @data: Struct containing array
 */
void	init_struct(format_t *data)
{
	data->nb_written_bytes = 0;
	data->buffer[0] = '\0';
	data->bufferlen = 0;
	data->fct_tab[SPEC_c].spec = 'c';
	data->fct_tab[SPEC_s].spec = 's';
	data->fct_tab[SPEC_perc].spec = '%';
	data->fct_tab[SPEC_d].spec = 'd';
	data->fct_tab[SPEC_i].spec = 'i';
	data->fct_tab[SPEC_b].spec = 'b';
	data->fct_tab[SPEC_u].spec = 'u';
	data->fct_tab[SPEC_o].spec = 'o';
	data->fct_tab[SPEC_x].spec = 'x';
	data->fct_tab[SPEC_X].spec = 'x';
	data->fct_tab[SPEC_S].spec = 'S';
	data->fct_tab[SPEC_p].spec = 'p';
	data->fct_tab[SPEC_r].spec = 'r';
	data->fct_tab[SPEC_R].spec = 'R';
	data->fct_tab[SPEC_LAST].spec = '\0';
	data->fct_tab[SPEC_c].fct = handle_spec_c;
	data->fct_tab[SPEC_s].fct = handle_spec_s;
	data->fct_tab[SPEC_perc].fct = NULL;
	data->fct_tab[SPEC_d].fct = handle_spec_di;
	data->fct_tab[SPEC_i].fct = handle_spec_di;
	data->fct_tab[SPEC_b].fct = NULL;
	data->fct_tab[SPEC_u].fct = NULL;
	data->fct_tab[SPEC_o].fct = NULL;
	data->fct_tab[SPEC_x].fct = NULL;
	data->fct_tab[SPEC_X].fct = NULL;
	data->fct_tab[SPEC_S].fct = NULL;
	data->fct_tab[SPEC_p].fct = NULL;
	data->fct_tab[SPEC_r].fct = NULL;
	data->fct_tab[SPEC_R].fct = NULL;
	data->fct_tab[SPEC_LAST].fct = NULL;
}

/**
 * _printf - Imitates the existing function printf
 * @format: String to parse and print
 * Return: The number of characters printed
 */
int		_printf(const char *format, ...)
{
	format_t	data;
	int			ret;
	int			len;

	va_start(data.args, format);
	init_struct(&data);
	while (*format)
	{
		ret = 1;
		if (*format == '%')
		{
			ret = handle_specialchar(&format, &data);
		}
		if (ret)
		{
			len = _strclen(format, '%');
			write_buffer(format, len, &data);
			format += len;
		}
	}
	write_buffer(NULL, 0, &data);
	return (data.nb_written_bytes);
}
