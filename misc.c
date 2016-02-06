#include "ft_select.h"

int		int_char(int c)
{
	ft_putchar(c);
	return (0);
}

void	ft_putendl_blue(char *s)
{
	ft_putstr("\033[1;34m");
	ft_putendl(s);
	ft_putstr("\033[0m");
}