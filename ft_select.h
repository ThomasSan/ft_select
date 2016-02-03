/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 12:57:20 by tsanzey           #+#    #+#             */
/*   Updated: 2016/02/02 11:52:55 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# define UP "\027[A"
# define DOWN "\027[B"
# define LEFT "\027[C"
# define RIGHT "\027[D"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <curses.h>
#include <term.h>
#include <signal.h>
#include "libft/libft.h"
#include "get_next_line.h"

typedef struct		s_elem
{
	char			*name;
	int				select;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

#endif
