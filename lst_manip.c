/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <tsanzey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:14:14 by tsanzey           #+#    #+#             */
/*   Updated: 2016/02/08 16:14:21 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_elem		*ft_push_back(t_elem **l, char *s)
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
	if ((dirp = opendir(s)) != NULL)
		closedir(dirp);
	new->isdir = dirp ? 1 : 0;
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
	t_elem	*tmp;
	int		i;

	i = 1;
	tmp = l;
	l = l->next;
	while (l != tmp)
	{
		l = l->next;
		i++;
	}
	return (i);
}

t_elem		*ft_stock(t_elem *l, int i)
{
	static t_elem *tmp = NULL;

	if (i == 0)
		tmp = l;
	return (tmp);
}

int			ft_del_one(t_elem *l)
{
	t_elem	*tmp;
	t_elem	*swap1;
	int		i;

	tmp = l;
	if ((i = ft_list_len(l)) == 1)
		return (-2);
	while (i--)
	{
		if (l->cursor)
		{
			if (l == tmp)
				i = -1;
			swap1 = l->next;
			swap1->prev = l->prev;
			l->prev->next = swap1;
			swap1->cursor = tmp == swap1 ? 0 : 1;
			swap1->prev->cursor = tmp == swap1 ? 1 : 0;
			free(l->name);
			free(l);
			return (i);
		}
		l = l->next;
	}
	return (i);
}
