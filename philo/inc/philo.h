/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:51:41 by jquicuma          #+#    #+#             */
/*   Updated: 2024/12/30 19:28:10 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "ansi_color_codes.h"

# include <errno.h>
# include <pthread.h>
# include <stdatomic.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>
# include <stdatomic.h>

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DEAD "died"

typedef struct s_philo_data
{
    int             philo_nbr;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             num_of_meals;
    pthread_mutex_t forks[900];
    bool            infinite_meals;
    pthread_mutex_t print_mutex;
    long long       initial_time_ms;
}           t_philo_data;

typedef struct  s_philo
{
    int             id;
    pthread_t       philo;
    t_philo_data    *data;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    _Atomic long long   last_meal_abs_usec;
    pthread_mutex_t meal_mutex;
}   t_philo;

long	current_time_in_ms(void);
long int    ft_atol(const char *nptr);
bool    ft_isnumeric_str(char *str);
int    ft_strcmp(const char *s1, const char *s2);
bool validate_args(char **argv, int argc, t_philo_data *philo_data_init);
void    free_all(t_philo_data   *data);
void	unlock_locks(pthread_mutex_t *left_fork, pthread_mutex_t *right_fork);
void init_philos(t_philo *philos, t_philo_data *data);
void philo_routine(t_philo *philo);
void mutex_print(char *status, t_philo *philo);
//bool check_death(t_philo *philo);
//void mark_death(t_philo *philo);
//void *death_monitor(void *arg);

#endif
