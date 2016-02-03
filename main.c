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

	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &term);
	while (42)
	{
		printf("%s\n", l->name);
		while (get_next_line(0, &line) == -1)
		{
		}
		if (ft_strcmp(line, UP) == 0)
			printf("up\n");
		if (ft_strcmp(line, DOWN) == 0)
			printf("down\n");
		if (ft_strcmp(line, LEFT) == 0)
			printf("left\n");
		if (ft_strcmp(line, RIGHT) == 0)
			printf("right\n");
		free(line);
	}
}

int		main(int ac, char **av)
{
	t_elem	*list;
	int		i;

	i = 1;
	list = NULL;
	while (i < ac)
	{
		list = ft_push_back(&list, av[i]);
		i++;
	}
	ft_display_menu(list);
	return (0);
}
