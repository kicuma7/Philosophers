/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 05:36:35 by jquicuma          #+#    #+#             */
/*   Updated: 2024/12/08 06:15:21 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdlib.h>
# include "ansi_code_colors.h"

# define DIE "died"
# define EAT "is eating"
# define THINK "is thinking"
# define FORK "has taken the fork"
# define SLEEP "is sleeping"

typedef struct  s_philo
{
    pthread_t   philo;
    int         philo_id;   
}               t_philo;

#endif
