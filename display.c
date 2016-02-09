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
	char			buff[5];
	int				flag;

	flag = 0;
	tgetent(NULL, getenv("TERM"));
	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &term);
	tputs(tgetstr("vi", NULL), 1, int_char);
	control_size(l);
	while (42)
	{
		ft_bzero(buff, 5);
		read(0, buff, 4);
		if ((buff[0] == 27 && buff[1] == 0) || buff[0] == 4)
			ft_unset_canon();
		if (control_size(l))
			l = ft_get_input(buff, l, &flag);
		else
			flag = 1;
	}
}

void	display_list(t_elem *l)
{
	int		i;
	char	*termtype;

	termtype = getenv("TERM");
	tgetent(NULL, termtype);
	i = ft_list_len(l);
	tputs(tgetstr("cl", NULL), 1, int_char);
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
	int		lin;

	termtype = getenv("TERM");
	if (!termtype)
		ft_env_error();
	tgetent(NULL, termtype);
	tputs(tgetstr("cl", NULL), 1, int_char);
	lin = tgetnum("li");
	l->len = ft_list_len(l);
	if (l->len > lin - 1)
	{
		tputs(tgetstr("cl", NULL), 1, int_char);
		ft_putendl_red("Please Resize window");
		return (0);
	}
	else
	{
		tputs(tgetstr("cl", NULL), 1, int_char);
		display_list(l);
	}
	return (1);
}
