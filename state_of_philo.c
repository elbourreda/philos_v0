/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_of_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 20:48:42 by rel-bour          #+#    #+#             */
/*   Updated: 2021/07/14 21:13:27 by rel-bour         ###   ########.fr       */
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
    printf("%d is sleeping\n", i);
    printf("%d is thinking\n", i);


    
    return (NULL);
}