/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_of_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 20:48:42 by rel-bour          #+#    #+#             */
/*   Updated: 2021/07/15 21:52:35 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"



 long	get_in_mic(void)
{
	struct timeval	time;
	long 		h;

	gettimeofday(&time, NULL);
	h = time.tv_usec + (time.tv_sec * 1000000);
	return (h);
}

void ft_usleep(long  time)

{
	long 	microb;
	long 	r;

	microb = get_in_mic();
	r = time - 60;
	usleep(r * 1000);
	while ((get_in_mic() - microb) < (time * 1000))
	{	
	}
}
long current_time()
{
    long time_now;
    struct timeval	time;
    gettimeofday(&time, NULL);
    
	time_now = (time.tv_usec / 1000) + (time.tv_sec * 1000);
    return (time_now);
}
void *main_philos(void *args)
{
    t_philo *profil;
    t_init *all;

    all = iniit_t();
    profil = (t_philo *)args;
    while (1)
    {
        
        /// taking forks
        pthread_mutex_lock(&all->forks[profil->p_id - 1]);
        printf("%ld | %d has taken a lift fork\n", current_time(),  profil->p_id);
        
        pthread_mutex_lock(&all->forks[profil->p_id % all->nbr_of_philo]);
        printf("%ld | %d has taken a right fork\n", current_time(),  profil->p_id);

        //last eat
        // all->profile[profil->p_id - 1].last_eat = get_in_mic();

        //start eating
        printf("%ld | %d is eating\n", current_time(),  profil->p_id);

        // waiting time to eat
        ft_usleep(all->eat_time);
    
        //unlock forks 
        pthread_mutex_unlock(&all->forks[profil->p_id - 1]);
        pthread_mutex_unlock(&all->forks[profil->p_id % all->nbr_of_philo]);

        //start sleeping
        printf("%ld | %d is sleeping\n", current_time(),  profil->p_id);
    
        // waiting time to sleep
        ft_usleep(all->sleep_time);

        //start thinking
        printf("%ld | %d is thinking\n", current_time(),  profil->p_id);
        
    }

    return (NULL);
}