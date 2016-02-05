#include "ft_select.h"

void	ft_up(t_elem *l, char *termtype)
{
	t_elem	*tmp;

	tmp = l;
	while (l)
	{
		if (l->cursor)
		{
			l->cursor = 0;
			if(l->prev)
				l->prev->cursor = 1;
			else if (!l->prev)
			{
				while (l->next)
					l = l->next;
				l->cursor = 1;
			}
			break ;
		}
		l = l->next;
	}
	display_list(tmp, termtype);
}

void	ft_down(t_elem *l, char *termtype)
{
	t_elem	*tmp;

	tmp = l;
	while (l)
	{
		if (l->cursor)
		{
			l->cursor = 0;
			if (l->next)
				l->next->cursor = 1;
			else if (!l->next)
				tmp->cursor = 1;
			break ;
		}
		l = l->next;
	}
	display_list(tmp, termtype);
}

void	ft_space(t_elem *l, char *termtype)
{	
	t_elem	*tmp;

	tmp = l;
	while (l)
	{
		if (l->cursor)
		{
			if (l->select == 0)
				l->select = 1;
			else
				l->select = 0;
				l->cursor = 0;
			if (l->next)
				l->next->cursor = 1;
			else if (!l->next)
				tmp->cursor = 1;
			break ;
		}
		l = l->next;
	}
	display_list(tmp, termtype);
}

void	ft_enter(t_elem *l, char *termtype, struct termios term)
{
	ft_display_selected(l, termtype);
	ft_unset_canon(term);
}

void	ft_get_input(char *s, t_elem *l, char *termtype, struct termios term)
{
		if (s[0] == 27 && s[2] == 'A')
			ft_up(l, termtype);
		if (s[0] == 27 && s[2] == 'B')
			ft_down(l, termtype);
		if (s[0] == 27 && s[2] == 'C')
			printf("right\n");
		if (s[0] == 27 && s[2] == 'D')
			printf("left\n");
		if (s[0] == 32)
			ft_space(l, termtype);
		if (s[0] == 27 && s[1] == 0)
			ft_unset_canon(term);
		if (s[0] == '\n')
			ft_enter(l, termtype, term);
		if (s[0] == 4)
			ft_unset_canon(term);
		if (s[0] == 8 || s[0] == 127 || (s[0] == 27 && s[2] == '3'))
			printf("Backspace Or Del\n");
}
