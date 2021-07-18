/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 19:22:08 by rel-bour          #+#    #+#             */
/*   Updated: 2021/07/18 20:25:28 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	ft_isdigit(char nb)
{
	if ((nb >= '0' && nb <= '9'))
		return (1);
	else
		return (0);
}

int	init_args(int ac, char **av)
{
	t_init	*all;
	int		i;

	i = -1;
	all = iniit_t();
	pthread_mutex_init(&all->write_lock, NULL);
	all->nbr_of_philo = ft_atoi(av[1]);
	all->die_time = ft_atoi(av[2]);
	all->eat_time = ft_atoi(av[3]);
	all->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		all->nbr_eat = ft_atoi(av[5]);
	else
		all->nbr_eat = -1;
	if (check_valid_args() == 2)
		return (2);
	all->philos = malloc(sizeof(t_init) * all->nbr_of_philo);
	all->profile = malloc(sizeof(t_philo) * all->nbr_of_philo);
	all->forks = malloc(sizeof(pthread_mutex_t) * all->nbr_of_philo);
	while (++i < all->nbr_of_philo)
	{
		all->profile[i].nbr_times_eat = 0;
		pthread_mutex_init(&all->forks[i], NULL);
	}
	return (0);
}

void	new_print(char *str, int n, int die)
{
	t_init			*all;
	struct timeval	time;
	long long		t;

	all = iniit_t();
	pthread_mutex_lock(&all->write_lock);
	gettimeofday(&time, NULL);
	t = (time.tv_usec / 1000) + (time.tv_sec * 1000);
	printf("%lld %d %s\n", t, n, str);
	if (die == 2)
		return ;
	pthread_mutex_unlock(&all->write_lock);
}

long	current_time_micr(void)
{
	struct timeval	time;
	long			time_now;

	gettimeofday(&time, NULL);
	time_now = time.tv_usec + (time.tv_sec * 1000000);
	return (time_now);
}
