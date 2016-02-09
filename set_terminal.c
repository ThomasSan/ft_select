/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_terminal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <tsanzey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:13:29 by tsanzey           #+#    #+#             */
/*   Updated: 2016/02/08 16:13:37 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_set_canon(struct termios term)
{
	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &term);
	signal(SIGTSTP, ft_handle_sig);
	tputs(tgetstr("vi", NULL), 1, int_char);
	tputs(tgetstr("ti", NULL), 1, int_char);
	ft_putendl("press any key ...");
}

void	ft_unset_canon(void)
{
	struct termios term;

	tcgetattr(0, &term);
	tgetent(NULL, getenv("TERM"));
	tputs(tgetstr("ve", NULL), 1, int_char);
	tputs(tgetstr("cl", NULL), 1, int_char);
	if (tcgetattr(0, &term) == -1)
		ft_putendl("c get error");
	term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, TCSANOW, &term))
		ft_putendl("c set error");
	exit(0);
}

void	ft_stop_canon(struct termios term)
{
	char cp[2];

	if (tcgetattr(0, &term) == -1)
		ft_putendl("c get error");
	cp[0] = term.c_cc[VSUSP];
	cp[1] = 0;
	term.c_lflag |= (ICANON | ECHO);
	signal(SIGTSTP, SIG_DFL);
	tputs(tgetstr("cl", NULL), 1, int_char);
	tputs(tgetstr("ve", NULL), 1, int_char);
	tputs(tgetstr("te", NULL), 1, int_char);
	if (tcsetattr(0, TCSANOW, &term))
		ft_putendl("c set error");
	ioctl(0, TIOCSTI, cp);
}

void	ft_env_error(void)
{
	ft_putendl_red("Please Specify a valid Terminal/Environement");
	ft_unset_canon();
}

void	ft_exit_canon(void)
{
	struct termios term;

	tcgetattr(0, &term);
	tgetent(NULL, getenv("TERM"));
	tputs(tgetstr("ve", NULL), 1, int_char);
	if (tcgetattr(0, &term) == -1)
		ft_putendl("c get error");
	term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, TCSANOW, &term))
		ft_putendl("c set error");
	exit(0);
}