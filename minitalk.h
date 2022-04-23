/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amounach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:08:41 by amounach          #+#    #+#             */
/*   Updated: 2022/04/23 02:08:59 by amounach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

struct s_utils
{
	int	i;
	int	pid;
};

void	ft_putnbr(unsigned int nb);
int		ft_atoi(const char *str);

#endif
