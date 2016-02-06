#include "ft_select.h"

void		ft_select_all(t_elem *l)
{
	t_elem *tmp;

	tmp = l;
	while(l)
	{
		if(l->select == 0)
			l->select = 1;
		l = l->next;
	}
	ft_display_size(tmp);
}

void		ft_unselect_all(t_elem *l)
{
	t_elem *tmp;

	tmp = l;
	while(l)
	{
		if(l->select == 1)
			l->select = 0;
		l = l->next;
	}
	ft_display_size(tmp);
}