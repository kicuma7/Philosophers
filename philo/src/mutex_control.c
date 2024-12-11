/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:54:11 by jquicuma          #+#    #+#             */
/*   Updated: 2024/12/11 17:33:37 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    clean_rc_print(char *status, t_philo *philo)
{
    pthread_mutex_lock(&philo->data->print_mutex);
    if (!ft_strcmp(status, FORK))
        printf("%sphilo %d %s\n", BHYELLOW, philo->id, FORK);
    else if (!ft_strcmp(status, EAT))
        printf("%sphilo %d %s\n", BGREEN, philo->id, EAT);
    else if (!ft_strcmp(status, SLEEP))
        printf("%sphilo %d %s\n", BYELLOW, philo->id, SLEEP);
    pthread_mutex_unlock(&philo->data->print_mutex);
}

void pick_forks(t_philo *philo)
{
    if ((philo->id % 2) == 0)
    {
        if (!pthread_mutex_lock(philo->left_fork))
        {
            clean_rc_print(FORK, philo);
            if (!pthread_mutex_lock(philo->right_fork))
            {
                clean_rc_print(FORK, philo);
                clean_rc_print(EAT, philo);
                usleep(philo->data->time_to_eat * 1000);
                pthread_mutex_unlock(philo->right_fork);
                pthread_mutex_unlock(philo->left_fork);
                clean_rc_print(SLEEP, philo);
                usleep(philo->data->time_to_sleep * 1000);
            }
            else
            {
                pthread_mutex_unlock(philo->right_fork);
                pthread_mutex_unlock(philo->left_fork);
            }     
        }
    }
    else
    {
        if (!pthread_mutex_lock(philo->right_fork))
        {
            clean_rc_print(FORK, philo);
            if (!pthread_mutex_lock(philo->left_fork))
            {
                clean_rc_print(FORK, philo);
                clean_rc_print(EAT, philo);
                usleep(philo->data->time_to_eat * 1000);
                pthread_mutex_unlock(philo->right_fork);
                pthread_mutex_unlock(philo->left_fork);
                clean_rc_print(SLEEP, philo);
                usleep(philo->data->time_to_sleep * 1000);
            }
            else
            {
                pthread_mutex_unlock(philo->right_fork);
                pthread_mutex_unlock(philo->left_fork);
            }     
        }
    }
}
