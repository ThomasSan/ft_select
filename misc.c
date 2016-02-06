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

void	ft_putendl_red(char *s)
{
	char		*termtype;

	termtype = getenv("TERM");
	tgetent(NULL, termtype);
	ft_putstr("\033[1;31m ");
	tputs(tgetstr("mr", NULL), 1, int_char);
	ft_putendl_fd(s, 2);
	ft_putstr("\033[0m");
}