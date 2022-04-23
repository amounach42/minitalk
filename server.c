/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amounach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 22:58:14 by amounach          #+#    #+#             */
/*   Updated: 2022/04/23 01:56:36 by amounach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *data, void *ss)
{
	static int	i;
	static char	c;
	static int	oldpid;

	(void)ss;
	if (oldpid != data -> si_pid)
	{
		write(1, "\n", 1);
		i = 0;
		c = 0;
	}
	c = (c << 1) | (sig & 1);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	oldpid = data -> si_pid;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write(1, "pid =>", 8);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
}
