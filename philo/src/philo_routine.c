/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:17:45 by jquicuma          #+#    #+#             */
/*   Updated: 2024/12/20 10:25:58 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    philo_routine(t_philo *philo)
{
    mutex_print(FORK, philo);
    mutex_print(EAT, philo);
    usleep(philo->data->time_to_eat * 1000);
    unlock_locks(philo->left_fork, philo->right_fork);
    mutex_print(SLEEP, philo);
    usleep(philo->data->time_to_sleep * 1000);
    mutex_print(THINK, philo);
    usleep(philo->data->time_to_think * 1000);
}
