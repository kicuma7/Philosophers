/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 07:47:42 by jquicuma          #+#    #+#             */
/*   Updated: 2024/12/10 07:51:08 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# include "ansi_colors.h"

typedef struct  s_philo_data
{
    pthread_t       thread;
    int             id;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
}                   t_philo_data;

#endif
