/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:41:59 by rel-bour          #+#    #+#             */
/*   Updated: 2021/07/14 20:29:22 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_philo
{
    int p_id;
    int p_nbr_philo;
} t_philo;


typedef struct s_init
{
    int nbr_of_philo;
    long eat_time;
    long sleep_time;
    long die_time;
    int nbr_eat;
    pthread_mutex_t forks;
    t_philo *profile;
    pthread_t *philos;
} t_init;

#endif