/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 21:40:23 by rel-bour          #+#    #+#             */
/*   Updated: 2021/07/18 19:37:51 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	secend_check(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac != 5 && ac != 6)
	{
		printf("Error: Number of arguments not valid\n");
		return (2);
	}
	while (av[++i])
	{
		j = 0;
		if (av[i][j] == '+' || av[i][j] == '-')
			j++;
		while (av[i][j] != '\0')
		{
			if (ft_isdigit(av[i][j]) != 1)
			{
				printf("Error: arguments not valid\n");
				return (2);
			}
			j++;
		}
	}
	return (0);
}

long	ft_atoi(char *str)
{
	long	rslt;
	int		sign;
	int		cnt;

	rslt = 0;
	sign = 1;
	cnt = 0;
	while (str[cnt] == 32 || (str[cnt] >= 9 && str[cnt] <= 13))
		cnt++;
	if (str[cnt] == '-')
	{
		cnt++;
		sign = -1;
	}
	else if (str[cnt] == '+')
		cnt++;
	while (str[cnt] >= '0' && str[cnt] <= '9')
	{
		rslt = rslt * 10 + (str[cnt] - '0');
		cnt++;
	}
	return (rslt * sign);
}

t_init	*iniit_t(void)
{
	static t_init	all;

	return (&all);
}

int	check_valid_args(void)
{
	t_init	*all;

	all = iniit_t();
	if (all->die_time < 60 || all->eat_time < 60)
		return (2);
	else if (all->sleep_time < 60 || all->nbr_of_philo > 200)
		return (2);
	return (0);
}
