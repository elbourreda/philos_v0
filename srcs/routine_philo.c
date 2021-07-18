/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 20:48:42 by rel-bour          #+#    #+#             */
/*   Updated: 2021/07/18 19:46:40 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	profil_init(void)
{
	t_init	*all;
	int		i;

	all = iniit_t();
	i = 0;
	while (i < all->nbr_of_philo)
	{
		all->profile[i].p_id = i + 1;
		i++;
	}
}

void	*main_philos(void *args)
{
	t_philo	*profil;
	t_init	*all;

	all = iniit_t();
	profil = (t_philo *)args;
	while (1)
	{
		pthread_mutex_lock(&all->forks[profil->p_id - 1]);
		new_print("has taken a fork", profil->p_id, 1);
		pthread_mutex_lock(&all->forks[profil->p_id % all->nbr_of_philo]);
		new_print("has taken a fork", profil->p_id, 1);
		profil->start_eats = current_time_micr();
		profil->nbr_times_eat++;
		new_print("is eating", profil->p_id, 1);
		usleep(all->eat_time * 1000);
		pthread_mutex_unlock(&all->forks[profil->p_id - 1]);
		pthread_mutex_unlock(&all->forks[profil->p_id % all->nbr_of_philo]);
		new_print("is sleeping", profil->p_id, 1);
		usleep(all->sleep_time * 1000);
		new_print("is thinking", profil->p_id, 1);
	}
	return (NULL);
}
