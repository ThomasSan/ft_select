#include "ft_select.h"

void	ft_get_input(char *s, t_elem *l, char *termtype, struct termios term)
{
		if (s[0] == 27 && s[2] == 'A')
			ft_up(l, termtype);
		if (s[0] == 27 && s[2] == 'B')
			ft_down(l, termtype);
		if (s[0] == 27 && s[2] == 'C')
			printf("right\n");
		if (s[0] == 27 && s[2] == 'D')
			printf("left\n");
		if (s[0] == 32)
			ft_space(l, termtype);
		if (s[0] == 1)
			ft_select_all(l, termtype);	
		if (s[0] == 24)
			ft_unselect_all(l, termtype);
		if (s[0] == 18)
			printf("ctrl r\n");
		if ((s[0] == 27 && s[1] == 0) || s[0] == 4)
			ft_unset_canon(term);
		if (s[0] == '\n')
			ft_enter(l, termtype, term);
		if (s[0] == 8 || s[0] == 127 || (s[0] == 27 && s[2] == '3'))
			printf("Backspace Or Del\n");
}
