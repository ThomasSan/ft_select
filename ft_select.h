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
#include <termcap.h>

typedef struct		s_elem
{
	char			*name;
	int				select;
	int				cursor;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

void				ft_get_input(char *s, t_elem *l, char *termtype,struct termios term);
int					int_char(int c);
void				display_list(t_elem *l, char *s);
void				ft_unset_canon(struct termios term);
t_elem				*ft_list_circl(t_elem *l);
int					ft_list_len(t_elem *l);
void				ft_handle_sig(int sig);
void				ft_display_selected(t_elem *l, char *termtype);

#endif
