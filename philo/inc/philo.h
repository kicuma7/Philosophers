/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 07:47:42 by jquicuma          #+#    #+#             */
/*   Updated: 2024/12/13 12:40:52 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

# include "ansi_colors.h"

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DEAD "died"

typedef struct s_data
{
    int             philo_nbr;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             time_to_think;
    int             num_of_meals;
    bool            infinite_meals;
    pthread_mutex_t *forks;
    pthread_mutex_t print_mutex;
}           t_data;

typedef struct s_philo
{
    int             id;
    pthread_t       thread;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    t_data          *data;
}                   t_philo;

bool        validate_args(char **argv, int argc, t_data *philo_data_init);
bool	    ft_isnumeric_str(char *str);
long int	ft_atol(const char *nptr);
int         ft_strcmp(const char *s1, const char *s2);
void        clean_rc_print(char *status, t_philo *philo);
void        pick_forks(t_philo *philo);

#endif
