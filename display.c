#include "ft_select.h"

void	ft_display_selected(t_elem *l)
{
	char *termtype;

	termtype = getenv("TERM");
	tgetent(NULL, termtype);
	tputs(tgetstr("cl", NULL), 1, int_char);
	while (l)
	{
		if (l->select)
		{
			ft_putstr(l->name);
			ft_putchar(' ');
		}
		l = l->next;
	}
	ft_putchar('\n');
}

void	ft_display_menu(t_elem *l)
{
	struct termios	term;
	char			buff[4];
	char			*termtype;

	termtype = getenv("TERM");
	tgetent(NULL, termtype);
 	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &term);
	ft_display_size(l);
	while (42)
	{
		ft_bzero(buff, 4);
		read(0, buff, 4);
		ft_get_input(buff, l, term);
	}
}

void	ft_display_size(t_elem *l)
{
	char	*termtype;
	int i;
	int lin;
	
	termtype = getenv("TERM");
	tgetent(NULL, termtype);
	tputs(tgetstr("cl", NULL), 1, int_char);
	i = ft_list_len(l);
	lin = tgetnum("li");
	if (i >= lin)
		ft_putendl_red("Please Resize window");
	while (i >= lin)
	{
		termtype = getenv("TERM");
		tgetent(NULL, termtype);
		i = ft_list_len(l);
		lin = tgetnum("li");
	}
	tputs(tgetstr("cl", NULL), 1, int_char);
	display_list(l, termtype);
}

void	display_list(t_elem *l, char *termtype)
{
	termtype = getenv("TERM");
	if (!termtype)
		ft_env_error();
	tgetent(NULL, termtype);
	tputs(tgetstr("cl", NULL), 1, int_char);
	tputs(tgetstr("vi", NULL), 1, int_char);
	while (l)
	{
		if (l->cursor)
			tputs(tgetstr("us", NULL), 1, int_char);
		if (l->select)
			tputs(tgetstr("mr", NULL), 1, int_char);
		if (l->isdir)
			ft_putendl_blue(l->name);
		else
			ft_putendl(l->name);
		tputs(tgetstr("ue", NULL), 1, int_char);
		tputs(tgetstr("me", NULL), 1, int_char);
		l = l->next;
	}
}

int		control_size(t_elem *l)
{
	char	*termtype;
	int i;
	int lin;
	
	termtype = getenv("TERM");
	tgetent(NULL, termtype);
	tputs(tgetstr("cl", NULL), 1, int_char);
	i = ft_list_len(l);
	lin = tgetnum("li");
	if (i < lin)
	{
		tputs(tgetstr("cl", NULL), 1, int_char);
		display_list(l, termtype);
		return (1);
	}
	else
	{
		tputs(tgetstr("cl", NULL), 1, int_char);
		ft_putendl_red("Please Resize window");
		return (0);
	}
}