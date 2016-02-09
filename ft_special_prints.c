/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_prints.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <tsanzey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:19:06 by tsanzey           #+#    #+#             */
/*   Updated: 2016/02/08 16:20:02 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_putendl_red(char *s)
{
	ft_putstr_fd("\033[1;31m", 2);
	ft_print_reverse();
	ft_putendl_fd(s, 2);
	ft_putstr_fd("\033[0m", 2);
}

void	ft_reverse_green(char *s)
{
	ft_print_reverse();
	ft_putendl_green(s);
}

void	ft_reverse_blue(char *s)
{
	ft_print_reverse();
	ft_putendl_blue(s);
}

void	ft_putendl_reverse(char *s)
{
	ft_print_reverse();
	ft_putendl_fd(s, 2);
}

void	ft_selected_blue(char *s)
{
	ft_print_reverse();
	tputs(tgetstr("us", NULL), 1, int_char);
	ft_underl_blue(s);
}
