/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 12:57:20 by tsanzey           #+#    #+#             */
/*   Updated: 2016/02/08 12:19:38 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <signal.h>
# include "libft/libft.h"
# include "get_next_line.h"
# include <termcap.h>
# include "libft.h"

typedef struct		s_elem
{
	char			*name;
	int				select;
	int				cursor;
	int				isdir;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

t_elem				*ft_push_back(t_elem **l, char *s);
t_elem				*ft_list_circl(t_elem *l);
t_elem				*ft_stock(t_elem *l, int i);
int					ft_del_one(t_elem *l);
void				ft_go_toend(t_elem *l);
void				ft_go_home(t_elem *l);

t_elem				*ft_get_input(char *s, t_elem *l);
void				display_list(t_elem *l, char *s);
void				ft_unset_canon();
void				ft_handle_sig(int sig);
void				ft_stop_canon(struct termios term);
void				ft_set_canon(struct termios term);
void				ft_signal(void);
void				ft_display_selected(t_elem *l);
void				ft_display_menu(t_elem *l);
void				ft_env_error(void);

void				ft_send_to_print(t_elem *l);
void				ft_putendl_green(char *s);
void				ft_reverse_green(char *s);
void				ft_reverse_blue(char *s);
void				ft_putendl_blue(char *s);
void				ft_underl_blue(char *s);
void				ft_putendl_red(char *s);
void				ft_reversegreen(char *s);
void				ft_print_reverse(void);
void				ft_selected_blue(char *s);
void				ft_putendl_reverse(char *s);
void				ft_clear_print(void);

void				ft_display_size(t_elem *l);

int					ft_list_len(t_elem *l);
int					int_char(int c);
int					control_size(t_elem *l);
int					ft_fill_buff(t_elem *l);

void				ft_up(t_elem *l);
void				ft_down(t_elem *l);
void				ft_space(t_elem *l);
void				ft_enter(t_elem *l);
void				ft_select_all(t_elem *l);
void				ft_unselect_all(t_elem *l);
t_elem				*ft_delete(t_elem *l);

#endif
