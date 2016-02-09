/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <tsanzey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:18:02 by tsanzey           #+#    #+#             */
/*   Updated: 2016/02/08 16:18:50 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_fill_buff(t_elem *l)
{
	char			buff[5];

	ft_bzero(buff, 5);
	read(0, buff, 4);
	if (control_size(l))
	{
		l = ft_get_input(buff, l);
	}
	return (1);
}

t_elem	*ft_get_input(char *s, t_elem *l)
{
	if (s[0] == 27 && s[2] == 'A')
		ft_up(l);
	if (s[0] == 27 && s[2] == 'B')
		ft_down(l);
	if (s[0] == 32)
		ft_space(l);
	if (s[0] == 1)
		ft_select_all(l);
	if (s[0] == 24)
		ft_unselect_all(l);
	if (s[0] == 27 && s[2] == 'F')
		ft_go_toend(l);
	if (s[0] == 27 && s[2] == 'H')
		ft_go_home(l);
	if ((s[0] == 27 && s[1] == 0) || s[0] == 4)
		ft_unset_canon();
	if (s[0] == '\n')
		ft_enter(l);
	if (s[0] == 8 || s[0] == 127 || (s[0] == 27 && s[2] == '3'))
		l = ft_delete(l);
	return (l);
}
