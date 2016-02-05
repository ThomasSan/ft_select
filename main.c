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

t_elem	*ft_push_back(t_elem **l, char *s)
{
	t_elem	*new;
	t_elem	*tmp;

	tmp = *l;
	if (!(new = (t_elem*)malloc(sizeof(t_elem))))
		return (NULL);
	new->name = ft_strdup(s);
	new->select = 0;
	new->next = NULL;
	new->prev = NULL;
	if (*l == NULL)
	{
		new->cursor = 1;
		*l = new;
	}
	else
	{
		new->cursor = 0;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	return (*l);
}

void	ft_display_selected(t_elem *l, char *termtype)
{
	termtype = getenv("TERM");
	tgetent(NULL, termtype);
	tputs(tgetstr("cl", NULL), 1, int_char);
	while (l)
	{
		if (l->select)
		{
			ft_putstr(l->name);
			ft_putchar(' ');
		}
		l = l->next;
	}
}

void	ft_display_menu(t_elem *l)
{
	char	*line;
	struct termios	term;
	int		lin;
	int		col;
	char	*termtype;

	termtype = NULL;
 	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &term);
	if (!(line = (char *)malloc(sizeof(char) * 4)))
		return ;
	display_list(l, termtype);
	while (42)
	{
		termtype = getenv("TERM");
		tgetent(NULL, termtype);
		lin = tgetnum("li");
		col = tgetnum("co");
		ft_bzero(line, ft_strlen(line));
		while (read(0, line, 4) == -1)
		{
		}
		ft_get_input(line, l, termtype, term);
	}
}

void	display_list(t_elem *l, char *termtype)
{
	int		i;

	i = ft_list_len(l);
	termtype = getenv("TERM");
	tgetent(NULL, termtype);
	tputs(tgetstr("cl", NULL), 1, int_char);
	tputs(tgetstr("vi", NULL), 1, int_char);
	while (i--)
	{
		if (l->cursor)
			tputs(tgetstr("us", NULL), 1, int_char);
		if (l->select)
		{
			tputs(tgetstr("mr", NULL), 1, int_char);
		}
		ft_putendl(l->name);
		tputs(tgetstr("ue", NULL), 1, int_char);
		tputs(tgetstr("me", NULL), 1, int_char);
		l = l->next;
	}
}
int		main(int ac, char **av)
{
	t_elem	*list;
	int		i;

	i = 0;
	list = NULL;
	// if (signal(SIGINT, ft_handle_sig) == SIG_ERR)
	// 	ft_putendl("Error");
	while (i++ < ac - 1)
		list = ft_push_back(&list, av[i]);
	ft_display_menu(list);
	return (0);
}
