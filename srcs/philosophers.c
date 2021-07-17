/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:41:08 by rel-bour          #+#    #+#             */
/*   Updated: 2021/07/17 15:56:36 by rel-bour         ###   ########.fr       */
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

    all = iniit_t();
    
    all->nbr_of_philo = atoi(av[1]);
    all->die_time = atoi(av[2]);
    all->eat_time = atoi(av[3]);
    all->sleep_time = atoi(av[4]);
    if (ac == 6)
        all->nbr_eat = atoi(av[5]);
    if (check_valid_args() == 2)
        return (2);
    all->philos = malloc(sizeof(t_init *) * all->nbr_of_philo);
    all->profile = malloc(sizeof(t_philo) * all->nbr_of_philo); 
    all->forks = malloc(sizeof(pthread_mutex_t *) * all->nbr_of_philo);
    int i = 0;
    while (i < all->nbr_of_philo)
    {
        pthread_mutex_init(&all->forks[i], NULL); 
        i++;
    }
    return (0);
}

void profil_init()
{
    t_init *all;
    
    all = iniit_t();
    int i = 0;
    while (i < all->nbr_of_philo)
    {
        all->profile[i].p_id = i + 1;
        i++;
    }
}

void creat_threads()
{
    int i;
    t_init *all;

    all = iniit_t();
    i = 0;
     
    while (i < all->nbr_of_philo)
    {
        all->profile[i].start_eats = get_in_mic();
        pthread_create(&all->philos[i], NULL, main_philos, &all->profile[i]);
        usleep(100); 
        i++;
    }
    
}

void join_threads()
{
    int i;
    t_init *all;
    
    all = iniit_t();
    i = 0;
    while (i < all->nbr_of_philo)
    {
        pthread_join(all->philos[i], NULL);
        i++;
    }
}

void	print_exit(char *str, int n)
{
	t_init *all;
    
    all = iniit_t();
	struct timeval	time;
	long long		t;

	pthread_mutex_lock(&all->write_lock);
	gettimeofday(&time, NULL); 
	t = (time.tv_usec / 1000) + (time.tv_sec * 1000);
    printf("%lld %d %s\n", t, n, str);
	// printf("=> [%ld]\n", (get_in_mic() - all->profile[n].start_eats) / 1000);
	return ;
	pthread_mutex_unlock(&all->write_lock);
}

int check_life()
{
    t_init *all;
    
    all = iniit_t();
    while (1)
    {
        int i = 0;
        while (i < all->nbr_of_philo)
        {
            if ((get_in_mic() - all->profile[i].start_eats) >= (all->die_time * 1000))
            {
                print_exit("is dead", i + 1);
                printf("=> [%ld]\n", (get_in_mic() - all->profile[i].start_eats) / 1000);
                return 1;
            }
            i++;
        }
        usleep(15);
    }
    return 0;
}

int main(int ac, char **av)
{
    t_init *all;
    
    all = iniit_t();
    if (ac == 5 || ac == 6)
    {
        if (init_args(ac, av) == 2)
            return (1);
        profil_init();     
        pthread_mutex_init(&all->write_lock, NULL);
        creat_threads();
        if (check_life() == 1)
            return (1);
        join_threads();
    }
    return (0);
}