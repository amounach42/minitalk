#ifndef MINITALK_H
# define MINITALK_H

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

struct utils
{
	int	i;
	int	pid;
}t_utils;

void	ft_putnbr(unsigned int nb);
int		ft_atoi(const char *str);

#endif
