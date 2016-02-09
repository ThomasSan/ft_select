/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <tsanzey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:13:23 by tsanzey           #+#    #+#             */
/*   Updated: 2016/02/08 16:13:24 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		int_char(int c)
{
	ft_putchar_fd(c, 2);
	return (0);
}

int		ft_special_case(t_elem *l, int i)
{
	t_elem	*tmp;
	t_elem	*swap1;

	tmp = l;
	while (i--)
	{
		if (l->cursor)
		{
			if (l != tmp)
				return (-3);
			swap1 = l->next;
			swap1->prev = swap1;
			swap1->next = swap1;
			swap1->cursor = 1;
			free(l->name);
			free(l);
			return (i);
		}
		l = l->next;
	}
	return (i);
}
