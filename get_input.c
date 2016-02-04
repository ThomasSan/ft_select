#include "ft_select.h"

void	ft_up(t_elem *l)
{
	while (l)
	{
		l = l->prev;
	}
}

void	ft_down(t_elem *l, char *termtype)
{
	t_elem	*tmp;
	char 	*clear;

	tmp = l;
	clear = tgetstr("cd", NULL);
	while (l)
	{
		if (l->cursor == 1)
		{
			l->cursor = 0;
			l->next->cursor = 1;
			break ;
		}
		l = l->next;
	}
	display_list(tmp, termtype);
}

void	ft_get_input(char *s, t_elem *l, char *termtype)
{
		if (s[0] == 27 && s[2] == 'A')
			printf("up\n");
		if (s[0] == 27 && s[2] == 'B')
			ft_down(l, termtype);
		if (s[0] == 27 && s[2] == 'C')
			printf("right\n");
		if (s[0] == 27 && s[2] == 'D')
			printf("left\n");
		if (s[0] == 27 && s[2] == '3')
			printf("delete\n");
		if (s[0] == 32)
			printf("space\n");
		if (s[0] == 27 && s[1] == 0)
			ft_unset_canon();
		if (s[0] == '\n')
			printf("enter\n");
		if (s[0] == 8 || s[0] == 127)
			printf("Backspace\n");
}

int		int_char(int c)
{
	ft_putchar(c);
	return (0);
}
