/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amounach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 22:54:58 by amounach          #+#    #+#             */
/*   Updated: 2022/04/21 01:57:03 by amounach         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	int		pid;
	char	*str;

	if (ac != 3)
		exit(EXIT_FAILURE);
	pid = atoi(av[1]);
	if (pid <= 0)
	{
		printf("pid error\n");
		exit(1);
	}
	str = av[2];
	while (*str)
		send_msg(pid, *str++);
}
