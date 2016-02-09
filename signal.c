/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <tsanzey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:13:43 by tsanzey           #+#    #+#             */
/*   Updated: 2016/02/08 16:13:47 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_signal(void)
{
	int i;

	i = 1;
	while (i < 32)
	{
		signal(i, ft_handle_sig);
		i++;
	}
}

void	ft_handle_sig(int sig)
{
	struct termios	term;

	if (sig == SIGINT)
		ft_unset_canon();
	else if (sig == SIGCONT)
		ft_set_canon(term);
	else if (sig == SIGTSTP)
		ft_stop_canon(term);
}
