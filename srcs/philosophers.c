/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:41:08 by rel-bour          #+#    #+#             */
/*   Updated: 2021/07/18 19:34:05 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	creat_threads(void)
{
	int		i;
	t_init	*all;

	all = iniit_t();
	i = 0;
	while (i < all->nbr_of_philo)
	{
		all->profile[i].start_eats = current_time_micr();
		pthread_create(&all->philos[i], NULL, main_philos, &all->profile[i]);
		usleep(100);
		i++;
	}
}

void	join_threads(void)
{
	int		i;
	t_init	*all;

	all = iniit_t();
	i = 0;
	while (i < all->nbr_of_philo)
	{
		pthread_join(all->philos[i], NULL);
		i++;
	}
}

int	status_life(int i, long is_philo_die)
{
	t_init	*all;

	all = iniit_t();
	is_philo_die = (current_time_micr() - all->profile[i].start_eats);
	if (is_philo_die >= (all->die_time * 1000))
	{
		new_print("is dead", i + 1, 2);
		return (1);
	}
	return (0);
}

int	check_life(void)
{
	t_init	*all;
	int		i;
	long	is_philo_die;
	int		done_eating;

	all = iniit_t();
	while (1)
	{
		i = -1;
		done_eating = 0;
		while (++i < all->nbr_of_philo)
		{
			if (status_life(i, done_eating) == 1)
				return (1);
			if (all->nbr_eat != -1 \
				&& all->profile[i].nbr_times_eat >= all->nbr_eat)
			{	
				done_eating++;
				if (done_eating == all->nbr_of_philo)
					return (1);
			}
		}
		usleep(15);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_init	*all;

	all = iniit_t();
	if (secend_check(ac, av) == 2 || init_args(ac, av) == 2)
		return (1);
	profil_init();
	pthread_mutex_init(&all->write_lock, NULL);
	creat_threads();
	if (check_life() == 1)
		return (1);
	join_threads();
	return (0);
}
