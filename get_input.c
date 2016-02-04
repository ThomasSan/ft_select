#include "ft_select.h"

void	ft_get_input(char *s)
{
		if (s[0] == 27 && s[2] == 'A')
			printf("up\n");
		if (s[0] == 27 && s[2] == 'B')
			printf("down\n");
		if (s[0] == 27 && s[2] == 'C')
			printf("right\n");
		if (s[0] == 27 && s[2] == 'D')
			printf("left\n");
		if (s[0] == 27 && s[2] == '3')
			printf("delete\n");
		if (s[0] == 32)
			printf("space\n");
		if (s[0] == 27 && s[1] == 0)
			printf("escape\n");
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
