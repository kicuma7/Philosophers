/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:58:15 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/07 12:38:40 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_routine(t_philo *philo)
{
	if (check_death(philo))
	{
		unlock_locks(philo->left_fork, philo->right_fork);
		return ;
	}
	mutex_print(FORK, philo);
	if (check_death(philo))
		return ;
	mutex_print(EAT, philo);
	philo->last_meal_abs_usec = current_time_in_ms();
	usleep(philo->data->time_to_eat * 1000);
	unlock_locks(philo->left_fork, philo->right_fork);
	if (check_death(philo))
		return ;
	mutex_print(SLEEP, philo);
	usleep(philo->data->time_to_sleep * 1000);
	if (check_death(philo))
		return ;
	mutex_print(THINK, philo);
}
