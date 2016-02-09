/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colored_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <tsanzey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:23:01 by tsanzey           #+#    #+#             */
/*   Updated: 2016/02/08 16:23:06 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_underl_blue(char *s)
{
	ft_putstr_fd("\033[1;36m", 2);
	tgetent(NULL, getenv("TERM"));
	tputs(tgetstr("us", NULL), 1, int_char);
	ft_putendl_fd(s, 2);
	ft_putstr_fd("\033[0m", 2);
}

void	ft_putendl_green(char *s)
{
	tgetent(NULL, getenv("TERM"));
	ft_putstr_fd("\033[1;32m", 2);
	tputs(tgetstr("us", NULL), 1, int_char);
	ft_putendl_fd(s, 2);
	ft_putstr_fd("\033[0m", 2);
}

void	ft_putendl_blue(char *s)
{
	ft_putstr_fd("\033[1;34m", 2);
	ft_putendl_fd(s, 2);
	ft_putstr_fd("\033[0m", 2);
}

void	ft_print_reverse(void)
{
	tgetent(NULL, getenv("TERM"));
	tputs(tgetstr("mr", NULL), 1, int_char);
}

void	ft_clear_print(void)
{
	tgetent(NULL, getenv("TERM"));
	tputs(tgetstr("ue", NULL), 1, int_char);
	tputs(tgetstr("me", NULL), 1, int_char);
}
