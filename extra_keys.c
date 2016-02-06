#include "ft_select.h"

void		ft_select_all(t_elem *l, char *termtype)
{
	t_elem *tmp;

	tmp = l;
	while(l)
	{
		if(l->select == 0)
			l->select = 1;
		l = l->next;
	}
	display_list(tmp, termtype);
}

void		ft_unselect_all(t_elem *l, char *termtype)
{
	t_elem *tmp;

	tmp = l;
	while(l)
	{
		if(l->select == 1)
			l->select = 0;
		l = l->next;
	}
	display_list(tmp, termtype);
}