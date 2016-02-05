#include "ft_select.h"

void	ft_set_canon(struct termios term)
{
 	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &term);
}

void	ft_unset_canon(struct termios term)
{
	char			*termtype;
	char			*curs;

	termtype = getenv("TERM");
	tgetent(NULL, termtype);
	curs = tgetstr("ve", NULL);
	tputs(curs, 1, int_char);
	if (tcgetattr(0, &term) == -1)
		printf("c get error\n");
	term.c_lflag &= (ICANON | ECHO);
	if (tcsetattr(0, 0, &term))
		printf("c set error\n");
	exit(0);
}

// void	ft_handle_sig(int sig)
// {
// 	if (sig == SIGINT)
// 		ft_unset_canon(term);
// }