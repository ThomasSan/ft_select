#include "ft_select.h"

void	ft_up(t_elem *l, char *termtype)
{
	t_elem	*tmp;

	tmp = l;
	while (l)
	{
		if (l->cursor)
		{
			if(l->prev)
			{
				l->cursor = 0;
				l->prev->cursor = 1;
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
			if (l->next)
			{
				l->cursor = 0;
				l->next->cursor = 1;
			}
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
			if (l->next && l->select)
			{
				l->cursor = 0;
				l->next->cursor = 1;
			}
			break ;
		}
		l = l->next;
	}
	display_list(tmp, termtype);
}

void	ft_enter(t_elem *l, char *termtype)
{
	ft_display_selected(l, termtype);
	ft_unset_canon();
}

void	ft_get_input(char *s, t_elem *l, char *termtype)
{
		if (s[0] == 27 && s[2] == 'A')
			ft_up(l, termtype);
		if (s[0] == 27 && s[2] == 'B')
			ft_down(l, termtype);
		if (s[0] == 27 && s[2] == 'C')
			printf("right\n");
		if (s[0] == 27 && s[2] == 'D')
			printf("left\n");
		if (s[0] == 27 && s[2] == '3')
			printf("delete\n");
		if (s[0] == 32)
			ft_space(l, termtype);
		if (s[0] == 27 && s[1] == 0)
			ft_unset_canon();
		if (s[0] == '\n')
			ft_enter(l, termtype);
		if (s[0] == 8 || s[0] == 127)
			printf("Backspace\n");
}

int		int_char(int c)
{
	ft_putchar(c);
	return (0);
}
