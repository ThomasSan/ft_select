#include "ft_select.h"

void	ft_signal(void)
{
	int i;

	i = 0;
	while (i < 32)
	{
		signal(i, ft_handle_sig);
		i++;
	}
}

void	ft_handle_sig(int sig)
{
	struct termios	term;

	if (sig == SIGINT)
		ft_unset_canon(term);
	else if (sig == SIGCONT)
		ft_set_canon(term);
	else if (sig == SIGTSTP)
		ft_stop_canon(term);
}
