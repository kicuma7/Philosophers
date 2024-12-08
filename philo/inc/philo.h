/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 05:36:35 by jquicuma          #+#    #+#             */
/*   Updated: 2024/12/08 23:09:18 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>

# include "ansi_code_colors.h"

# define DIE "died"
# define EAT "is eating"
# define THINK "is thinking"
# define FORK "has taken the fork"
# define SLEEP "is sleeping"

typedef struct  s_common_data
{
    int     philo_nbr;
    int     time_to_eat;
    int     time_to_spleep;
    int     time_to_die;
    int     meal_nbr;
    bool    infinit_mode;
}           t_common_data;

typedef struct  s_philo
{
    int             philo_id;
    t_common_data   common_data;
    pthread_t       thread;
    pthread_mutex_t print_mutex;
}                   t_philo;

bool	    ft_isnumeric_str(char *str);
long int	ft_atol(const char *nptr);
bool        validate_args(char **argv, int argc, t_common_data *philo_data_init);
long        get_time_ms(void);
void	    clean_print(char *str, pthread_mutex_t *mutex);

#endif
