/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:58:15 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/01 08:13:09 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void verify_last_meal(t_philo *philo, long long actual_last_meal);

void philo_routine(t_philo *philo)
{
    mutex_print(FORK, philo);
    mutex_print(EAT, philo);
    //philo->last_meal_abs_usec = current_time_in_ms();
    //if (philo->id == 1)
    verify_last_meal(philo, current_time_in_ms());
    usleep(philo->data->time_to_eat * 1000);
    unlock_locks(philo->left_fork, philo->right_fork);
    mutex_print(SLEEP, philo);
    usleep(philo->data->time_to_sleep * 1000);
    mutex_print(THINK, philo);
}

static void verify_last_meal(t_philo *philo, long long actual_last_meal)
{
    if ((actual_last_meal - philo->last_meal_abs_usec) >= (philo->data->time_to_die + 5))
    {
        printf("\n\nPhilo Number: %d LM %lld\n\n", philo->id, actual_last_meal - philo->last_meal_abs_usec);
        mutex_print(DEAD, philo);
        exit(EXIT_FAILURE);
    }
    philo->last_meal_abs_usec = actual_last_meal;
    return ;
}
