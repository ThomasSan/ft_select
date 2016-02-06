#include "ft_select.h"

void	ft_display_selected(t_elem *l, char *termtype)
{
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
	char	*line;
	char	*termtype;
	int		i;
	int		li;

 	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &term);
	if (!(line = (char *)malloc(sizeof(char) * 4)))
		return ;
	while (42)
	{
		termtype = getenv("TERM");
		tgetent(NULL, termtype);
		li = tgetnum("li");
		i = ft_list_len(l);
		ft_display_size(l);
		ft_bzero(line, ft_strlen(line));
		read(0, line, 4);
		ft_get_input(line, l, termtype, term);
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
		ft_putendl("Please Resize window");
	while (i >= lin)
	{
		termtype = getenv("TERM");
		tgetent(NULL, termtype);
		i = ft_list_len(l);
		lin = tgetnum("li");
	}
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
