/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:41:08 by rel-bour          #+#    #+#             */
/*   Updated: 2021/07/14 20:15:51 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"


t_init	*iniit_t(void)
{
	static t_init	all;

	return (&all);
}

void init_args(int ac, char **av)
{
    t_init *all;

    all = iniit_t();
    
    all->nbr_of_philo = atoi(av[1]);
    all->die_time = atoi(av[2]);
    all->eat_time = atoi(av[3]);
    all->sleep_time = atoi(av[4]);
    if (ac == 6)
        all->nbr_eat = atoi(av[5]);
    all->philos = malloc(sizeof(t_init *) * all->nbr_of_philo);
    pthread_mutex_init(&all->forks, NULL);
}

int main(int ac, char **av)
{
    t_init *all;
    
    all = iniit_t();
    if (ac == 5 || ac == 6)
    {
        init_args(ac, av);
        
    }
    return (1);
}