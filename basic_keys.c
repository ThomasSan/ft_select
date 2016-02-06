#include "ft_select.h"

void	ft_up(t_elem *l)
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
	ft_display_size(tmp);
}

void	ft_down(t_elem *l)
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
	ft_display_size(tmp);
}

void	ft_space(t_elem *l)
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
	ft_display_size(tmp);
}

void	ft_enter(t_elem *l, char *termtype, struct termios term)
{
	ft_display_selected(l, termtype);
	ft_unset_canon(term);
}

void	ft_delete()
{
	
}