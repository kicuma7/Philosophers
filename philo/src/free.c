/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:33:46 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/01 08:14:23 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    free_all(t_philo_data   *data, t_philo *philo)
{
    int i;
    
    i = 0;
    (void)philo;
    while (i < data->philo_nbr)
    {
        pthread_mutex_destroy(&data->forks[i++]);
        //pthread_mutex_destroy(&philo[i].meal_mutex);
    }
    pthread_mutex_destroy(&data->print_mutex);
    pthread_mutex_destroy(&data->death_mutex);
}

void	unlock_locks(pthread_mutex_t *left_fork, pthread_mutex_t *right_fork)
{
	if (left_fork)
		pthread_mutex_unlock(left_fork);
	if (right_fork)
		pthread_mutex_unlock(right_fork);
	return ;
}