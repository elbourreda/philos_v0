/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:41:08 by rel-bour          #+#    #+#             */
/*   Updated: 2021/07/17 20:05:50 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

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
        all->profile[i].start_eats = current_time_micr();
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

int check_life()
{
    t_init *all;
    int i;

    all = iniit_t();
    while (1)
    {
        i = 0;
        while (i < all->nbr_of_philo)
        {
            if ((current_time_micr() - all->profile[i].start_eats) >= (all->die_time * 1000))
            {
                new_print("is dead", i + 1, 2);
                return (1);
            }
            if (all->nbr_eat != -1 && all->profile[i].nbr_times_eat >= all->nbr_eat)
                return (1);
            i++;
        }
        usleep(15);
    }
    return 0;
}
int	ft_isdigit(char number)
{
	if ((number >= '0' && number <= '9'))
		return (1);
	else
		return (0);
}

int secend_check(int ac, char **av)
{
    int i;
    int j;

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

int main(int ac, char **av)
{
    t_init *all;
    
    all = iniit_t();
    if (secend_check(ac, av) == 2 || init_args(ac, av) == 2)
        return (1);
    profil_init();     
    pthread_mutex_init(&all->write_lock, NULL);
    // creat_threads();
    if (check_life() == 1)
        return (1);
    // join_threads();
    return (0);
}