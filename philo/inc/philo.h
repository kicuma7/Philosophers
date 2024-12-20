/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 05:50:43 by jquicuma          #+#    #+#             */
/*   Updated: 2024/12/20 10:24:38 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "colos.h"

# include <stdbool.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>

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
    int             time_to_think;
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
}   t_philo;

bool        validate_args(char **argv, int argc, t_philo_data *philo_data_init);
bool	    ft_isnumeric_str(char *str);
long int	ft_atol(const char *nptr);
int	        ft_strcmp(const char *s1, const char *s2);
void        init_philos(t_philo *philos, t_philo_data *data);
void        free_all(t_philo_data   *data);
long long   current_time_in_ms(void);
void        mutex_print(char *status, t_philo *philo);
void	    unlock_locks(pthread_mutex_t *left_fork, pthread_mutex_t *right_fork);
void        philo_routine(t_philo *philo);

#endif
