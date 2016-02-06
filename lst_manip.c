#include "ft_select.h"

t_elem	*ft_push_back(t_elem **l, char *s)
{
	t_elem	*new;
	t_elem	*tmp;
	DIR		*dirp;

	tmp = *l;
	if (!(new = (t_elem*)malloc(sizeof(t_elem))))
		return (NULL);
	new->name = ft_strdup(s);
	new->select = 0;
	new->next = NULL;
	new->prev = NULL;
	new->cursor = *l ? 0 : 1;
	new->isdir = (dirp = opendir(s)) ? 1 : 0;
	if (dirp)
		closedir(dirp);
	if (*l == NULL)
		*l = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	return (*l);
}

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