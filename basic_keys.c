/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <tsanzey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:23:10 by tsanzey           #+#    #+#             */
/*   Updated: 2016/02/08 16:24:22 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			if (l->prev)
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
	display_list(tmp);
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
	display_list(tmp);
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
	display_list(tmp);
}

void	ft_enter(t_elem *l)
{
	ft_display_selected(l);
	ft_exit_canon();
}

t_elem	*ft_delete(t_elem *l)
{
	int i;

	i = ft_list_len(l);
	if (i == 2)
	{
		i = ft_special_case(l, i);
		if (i != -3)
		{
			l = l->next;
			display_list(l);
			return (l);
		}
	}
	i = ft_del_one(l);
	if (i == -1)
		l = l->next;
	if (i == -2)
	{
		tputs(tgetstr("cl", NULL), 1, int_char);
		ft_unset_canon();
	}
	display_list(l);
	return (l);
}
