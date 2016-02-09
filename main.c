/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <tsanzey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 11:57:33 by tsanzey           #+#    #+#             */
/*   Updated: 2016/02/02 11:57:38 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int ac, char **av)
{
	t_elem	*list;
	int		i;

	i = 0;
	list = NULL;
	ft_signal();
	if (ac == 1)
	{
		ft_putendl_fd("usage: ./ft_select [files ...]", 2);
		return (0);
	}
	while (i++ < ac - 1)
		list = ft_push_back(&list, av[i]);
	list = ft_list_circl(list);
	ft_display_menu(list);
	return (0);
}
