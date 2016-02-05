#include "ft_select.h"

t_elem		*ft_list_circl(t_elem *l)
{
	t_elem	*tmp;

	tmp = l;
	while (l->next)
		l = l->next;
	l->next = tmp;
	tmp->prev = l;
	return (tmp);
}

int			ft_list_len(t_elem *l)
{
	int i;

	i = 0;
	while (l)
	{
		l = l->next;
		i++;
	}
	return (i);
}