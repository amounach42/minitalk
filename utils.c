#include "minitalk.h"

static int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void	ft_putnbr(unsigned int nb)
{
	long	n;
	int		res;

	res = 0;
	n = nb;
	if (n <=9 )
	{
		res = n + 48;
		write(1, &res, 1);
	}
	else
	{
		ft_putnbr(res / 10);
		ft_putnbr(res % 10);
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;

	while (is_space(str[i]))
		i++;
	while (str[i])
	{
		if (str[i] == '-')
		{
			sign *= -1;
			i++;
		}
		else if (str[i] == '+')
			i++;
		while (str[i] && str[i] >= '0' && str[i] <= '9')
		{
			res *= 10;
			res += str[i] - 48;
			i++;
		}
	}
	return (res * sign);
}
