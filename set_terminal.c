#include "ft_select.h"

void	ft_set_canon(struct termios term)
{
	t_elem			*l;

	l = NULL;
	l = ft_stock(l, 1);
 	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &term);
	ft_display_menu(l);
}

void	ft_unset_canon(struct termios term)
{
	char			*termtype;
	t_elem			*l;

	l = NULL;
	l = ft_stock(l, 1);
	termtype = getenv("TERM");
	tgetent(NULL, termtype);
	tputs(tgetstr("ve", NULL), 1, int_char);
	if (tcgetattr(0, &term) == -1)
		ft_putendl("c get error");
	term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, 0, &term))
		ft_putendl("c set error");
	exit(0);
}

void	ft_stop_canon(struct termios term)
{
	char			*termtype;
	char			*curs;

	termtype = getenv("TERM");
	tgetent(NULL, termtype);
	curs = tgetstr("ve", NULL);
	tputs(curs, 1, int_char);
	if (tcgetattr(0, &term) == -1)
		ft_putendl("c get error");
	term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, 0, &term))
		ft_putendl("c set error");
}

void	ft_env_error(void)
{
	struct termios	term;

	ft_putendl("Please Specify a valid Terminal/Environement");
	ft_unset_canon(term);
}