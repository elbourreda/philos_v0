/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_of_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 20:48:42 by rel-bour          #+#    #+#             */
/*   Updated: 2021/07/17 19:34:08 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void ft_usleep(long  time)
{
	long 	microb;
	long 	r;

	microb = current_time_micr();
	r = time - 60;
	usleep(r * 1000);
	while ((current_time_micr() - microb) < (time * 1000))
	{
	}
}

void *main_philos(void *args)
{
    t_philo *profil;
    t_init *all;

    all = iniit_t();
    profil = (t_philo *)args;
    while (1)
    {
        /// taking forks && lock forks
        pthread_mutex_lock(&all->forks[profil->p_id - 1]);        
        new_print("has taken a lift fork", profil->p_id, 1);
        
        pthread_mutex_lock(&all->forks[profil->p_id % all->nbr_of_philo]);
        new_print("has taken a right fork", profil->p_id, 1);
        
        //start eating
        new_print("is eating", profil->p_id, 1);

        // eat times count        
        profil->nbr_times_eat++;
        
        // last time eat
        profil->start_eats = current_time_micr();

        // waiting time to eat
        usleep(all->eat_time * 1000);
        // ft_usleep(all->eat_time);
    
        //unlock forks 
        pthread_mutex_unlock(&all->forks[profil->p_id - 1]);
        pthread_mutex_unlock(&all->forks[profil->p_id % all->nbr_of_philo]);

        //start sleeping
        new_print("is sleeping", profil->p_id, 1);
        
        // waiting time to sleep
        usleep(all->sleep_time * 1000);
        // ft_usleep(all->sleep_time);

        //start thinking
        new_print("is thinking", profil->p_id, 1);
    }
    return (NULL);
}
