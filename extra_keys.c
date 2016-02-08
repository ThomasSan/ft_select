/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <tsanzey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:20:37 by tsanzey           #+#    #+#             */
/*   Updated: 2016/02/08 16:21:42 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_select_all(t_elem *l)
{
	t_elem	*tmp;
	int		i;

	tmp = l;
	i = ft_list_len(l);
	while (i--)
	{
		if (l->select == 0)
			l->select = 1;
		l = l->next;
	}
	ft_display_size(tmp);
}

void		ft_unselect_all(t_elem *l)
{
	t_elem	*tmp;
	int		i;

	tmp = l;
	i = ft_list_len(l);
	while (i--)
	{
		if (l->select == 1)
			l->select = 0;
		l = l->next;
	}
	ft_display_size(tmp);
}

void		ft_go_toend(t_elem *l)
{
	t_elem	*tmp;
	int		i;

	tmp = l;
	i = ft_list_len(l);
	while (i--)
	{
		if (l->cursor)
			l->cursor = 0;
		l = l->next;
	}
	tmp->prev->cursor = 1;
	ft_display_size(tmp);
}

void		ft_go_home(t_elem *l)
{
	t_elem	*tmp;
	int		i;

	tmp = l;
	i = ft_list_len(l);
	while (i--)
	{
		if (l->cursor)
			l->cursor = 0;
		l = l->next;
	}
	tmp->cursor = 1;
	ft_display_size(tmp);
}
