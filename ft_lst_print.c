/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <tsanzey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:20:16 by tsanzey           #+#    #+#             */
/*   Updated: 2016/02/08 16:20:25 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_send_to_print(t_elem *l)
{
	if (l->cursor)
		ft_putstr_fd(" ", 2);
	if (l->select)
	{
		if (l->isdir && !l->cursor)
			ft_reverse_blue(l->name);
		else if (!l->isdir && l->cursor)
			ft_reverse_green(l->name);
		else if (l->isdir && l->cursor)
			ft_selected_blue(l->name);
		else
			ft_putendl_reverse(l->name);
	}
	else
	{
		if (l->isdir && !l->cursor)
			ft_putendl_blue(l->name);
		else if (!l->isdir && l->cursor)
			ft_putendl_green(l->name);
		else if (l->isdir && l->cursor)
			ft_underl_blue(l->name);
		else
			ft_putendl_fd(l->name, 2);
	}
}
