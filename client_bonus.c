/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amounach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 00:10:28 by amounach          #+#    #+#             */
/*   Updated: 2022/04/22 00:38:29 by amounach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_msg(int pid, char str)
{
	int	i;
	int	bit;
	int	kill_pid;

	i = 7;
	while (0 <= i)
	{
		bit = (str >> i) & 1;
		kill_pid = kill(pid, bit + SIGUSR1);
		if (kill_pid == -1)
		{
			write(1, "wrong pid", 9);
			exit(1);
		}
		usleep(500);
		i--;
	}
}

void	handler(int sig)
{
	(void)sig;
	write(1, "send success\n", 12);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*str;

	if (ac != 3)
		exit(EXIT_FAILURE);
	signal(SIGUSR1, handler);
	pid = atoi(av[1]);
	if (pid <= 0)
	{
		printf("pid error\n");
		exit(1);
	}
	str = av[2];
	while (*str)
		send_msg(pid, *str++);
	send_msg(pid, 0);
}
