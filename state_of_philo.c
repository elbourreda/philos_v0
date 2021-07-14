/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_of_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 20:48:42 by rel-bour          #+#    #+#             */
/*   Updated: 2021/07/14 21:17:49 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void *main_philos(void *args)
{
    t_init *all;
    int *id;
    int i;
    
    all = iniit_t();
    id = (int *)args;
    i = id[0];
    
    printf("%d has taken a fork lift\n", i);
    printf("%d has taken a fork right\n", i);
    printf("%d is eating\n", i);
    usleep(all->eat_time);
    printf("%d is sleeping\n", i);
    usleep(all->sleep_time);
    printf("%d is thinking\n", i);
    return (NULL);
}