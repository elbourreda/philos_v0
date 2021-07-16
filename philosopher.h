/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:41:59 by rel-bour          #+#    #+#             */
/*   Updated: 2021/07/16 21:20:40 by rel-bour         ###   ########.fr       */
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
    long start_eats;
} t_philo;


typedef struct s_init
{
    int nbr_of_philo;
    long eat_time;
    long sleep_time;
    long die_time;
    int nbr_eat;
    long start;
    pthread_mutex_t *forks;
    pthread_mutex_t write_lock;
    t_philo *profile;
    pthread_t *philos;

} t_init;

// long *sart_eat;
//  long old9;
void *main_philos(void *args);
t_init	*iniit_t(void);
long current_time();

long	get_in_mic(void);
#endif