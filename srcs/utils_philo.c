/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 19:22:08 by rel-bour          #+#    #+#             */
/*   Updated: 2021/07/17 19:56:45 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

t_init	*iniit_t(void)
{
	static t_init	all;

	return (&all);
}

int check_valid_args()
{
    t_init *all;

    all = iniit_t();
    if (all->die_time < 60 || all->eat_time < 60)
        return (2);
    else if (all->sleep_time < 60 || all->nbr_of_philo > 200)
        return (2);
    return (0);
}

int init_args(int ac, char **av)
{
    t_init *all;
    int i;

    i = 0;
    all = iniit_t();
    all->nbr_of_philo = atoi(av[1]);
    all->die_time = atoi(av[2]);
    all->eat_time = atoi(av[3]);
    all->sleep_time = atoi(av[4]);
    if (ac == 6)
        all->nbr_eat = atoi(av[5]);
    else
        all->nbr_eat = -1;
    
    if (check_valid_args() == 2)
        return (2);
    
    all->philos = malloc(sizeof(t_init ) * all->nbr_of_philo);
    all->profile = malloc(sizeof(t_philo) * all->nbr_of_philo); 
    all->forks = malloc(sizeof(pthread_mutex_t ) * all->nbr_of_philo);
    while (i < all->nbr_of_philo)
    {
        all->profile[i].nbr_times_eat = 0;
        pthread_mutex_init(&all->forks[i], NULL); 
        i++;
    }
    return (0);
}

void	new_print(char *str, int n, int die)
{
	t_init *all;
    
    all = iniit_t();
	struct timeval	time;
	long long		t;

	pthread_mutex_lock(&all->write_lock);
	gettimeofday(&time, NULL); 
	t = (time.tv_usec / 1000) + (time.tv_sec * 1000);
    printf("%lld %d %s\n", t, n, str);
    if (die == 2)
	    return ;
	pthread_mutex_unlock(&all->write_lock);
}

long    current_time_micr(void)
{
	struct timeval	time;
	long 		time_now;

	gettimeofday(&time, NULL);
	time_now = time.tv_usec + (time.tv_sec * 1000000);
	return (time_now);
}
