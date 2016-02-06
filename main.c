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
	if (signal(SIGINT, ft_handle_sig) == SIG_ERR)
		ft_putendl("Error");
	if (ac == 1)
	{
		ft_putendl("usage: ./ft_select [files ...]");
		return (0);
	}
	while (i++ < ac - 1)
		list = ft_push_back(&list, av[i]);
	ft_display_menu(list);
	return (0);
}
