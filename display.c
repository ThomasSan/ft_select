/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <tsanzey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:21:46 by tsanzey           #+#    #+#             */
/*   Updated: 2016/02/08 16:22:47 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_display_selected(t_elem *l)
{
	int i;
	int x;

	x = 0;
	i = ft_list_len(l);
	tgetent(NULL, getenv("TERM"));
	tputs(tgetstr("cl", NULL), 1, int_char);
	while (i--)
	{
		if (l->select)
		{
			ft_putstr(l->name);
			ft_putchar(' ');
			x++;
		}
		l = l->next;
	}
	if (x != 0)
		ft_putchar('\n');
}

void	ft_display_menu(t_elem *l)
{
	struct termios	term;
	char			buff[4];

	tgetent(NULL, getenv("TERM"));
	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &term);
	tputs(tgetstr("vi", NULL), 1, int_char);
	ft_display_size(l);
	while (42)
	{
		ft_bzero(buff, 4);
		read(0, buff, 4);
		l = ft_get_input(buff, l);
	}
}

void	ft_display_size(t_elem *l)
{
	int		i;
	int		lin;
	char	*termtype;

	termtype = getenv("TERM");
	if (!termtype)
		ft_env_error();
	tgetent(NULL, termtype);
	tputs(tgetstr("cl", NULL), 1, int_char);
	i = ft_list_len(l);
	lin = tgetnum("li");
	if (i >= lin)
		ft_putendl_red("Please Resize window");
	while (i >= lin)
	{
		tgetent(NULL, getenv("TERM"));
		i = ft_list_len(l);
		lin = tgetnum("li");
	}
	tputs(tgetstr("cl", NULL), 1, int_char);
	display_list(l, getenv("TERM"));
}

void	display_list(t_elem *l, char *termtype)
{
	int		i;

	tgetent(NULL, termtype);
	i = ft_list_len(l);
	while (i--)
	{
		ft_send_to_print(l);
		ft_clear_print();
		l = l->next;
	}
}

int		control_size(t_elem *l)
{
	char	*termtype;
	int		i;
	int		lin;

	termtype = getenv("TERM");
	tgetent(NULL, termtype);
	tputs(tgetstr("cl", NULL), 1, int_char);
	i = ft_list_len(l);
	lin = tgetnum("li");
	if (i - 2 < lin)
	{
		tputs(tgetstr("cl", NULL), 1, int_char);
		ft_display_size(l);
		return (1);
	}
	else
	{
		tputs(tgetstr("cl", NULL), 1, int_char);
		ft_display_size(l);
		return (0);
	}
}
