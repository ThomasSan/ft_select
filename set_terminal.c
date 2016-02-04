#include "ft_select.h"

void	ft_set_canon(struct termios *term)
{
 	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &term);
}

void	ft_unset_canon(struct termios *term)
{ 	
	tcgetattr(0, &term);
	term.c_lflag &= (ICANON | ECHO);
	tcsetattr(0, TCSANOW, &term)
}