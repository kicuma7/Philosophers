/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 06:46:14 by jquicuma          #+#    #+#             */
/*   Updated: 2024/12/20 09:59:08 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    free_all(t_philo_data   *data)
{
    int i;
    
    i = 0;
    while (i < data->philo_nbr)
        pthread_mutex_destroy(&data->forks[i++]);
    pthread_mutex_destroy(&data->print_mutex);
}

void	unlock_locks(pthread_mutex_t *left_fork, pthread_mutex_t *right_fork)
{
	if (left_fork)
		pthread_mutex_unlock(left_fork);
	if (right_fork)
		pthread_mutex_unlock(right_fork);
	return ;
}
