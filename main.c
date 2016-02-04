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
		*l = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	return (*l);
}

void	ft_display_lst(t_elem *l)
{
	t_elem	*tmp1;
	t_elem	*tmp2;
	
	tmp1 = l;
	tmp2 = l;
	while (tmp1)
	{
		printf("%s\n", tmp1->name);
		tmp1 = tmp1->next;
	}
	while (tmp2->next)
		tmp2 = tmp2->next;
	while (tmp2)
	{
		printf("tmp2 %s\n", tmp2->name);
		tmp2 = tmp2->prev;
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
		ft_get_input(line);
	}
}

void	display_list(t_elem *l, char *termtype)
{
	char 	*under;

	termtype = getenv("TERM");
	tgetent(NULL, termtype);
	while (l)
	{
		under = tgetstr("us", NULL);
		tputs(under, 1, int_char);
		l = l->next;
	}
}
int		main(int ac, char **av)
{
	t_elem	*list;
	int		i;

	i = 0;
	list = NULL;
	while (i++ < ac - 1)
		list = ft_push_back(&list, av[i]);
	ft_display_menu(list);
	return (0);
}
