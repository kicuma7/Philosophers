/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_up_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedoming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:38:17 by sedoming          #+#    #+#             */
/*   Updated: 2024/12/03 11:56:10 by sedoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

int	pick_up_forks(t_philo *philo)
{
	if ((philo->id % 2) != 0)
	{
		pthread_mutex_lock(philo->direito);
		if (philo->global->control == 1)
		{
			pthread_mutex_unlock(philo->direito);
			return (1);
		}
		print(philo, "has taken a fork🍽️");
		pthread_mutex_lock(philo->esquerdo);
		if (philo->global->control == 1)
		{
			pthread_mutex_unlock(philo->direito);
			pthread_mutex_unlock(philo->esquerdo);
			return (1);
		}
		print(philo, "has taken a fork🍽️");
	}
	return (0);
}

int	pick_up_pair_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->esquerdo);
		if (philo->global->control == 1)
		{
			pthread_mutex_unlock(philo->esquerdo);
			return (1);
		}
		print(philo, "has taken a fork🍽️");
		pthread_mutex_lock(philo->direito);
		if (philo->global->control == 1)
		{
			pthread_mutex_unlock(philo->direito);
			pthread_mutex_unlock(philo->esquerdo);
			return (1);
		}
		print(philo, "has taken a fork🍽️");
	}
	return (0);
}

int	eat(t_philo *philo)
{
	print(philo, "is eating🍝");
	philo->last_meal_time = gettimeofday_mills();
	usleep(philo->time_to_eat * 1000);
	if (philo->global->control == 1)
	{
		pthread_mutex_unlock(philo->direito);
		pthread_mutex_unlock(philo->esquerdo);
		return (1);
	}
	return (0);
}

void	sleeping(t_philo *philo)
{
	print(philo, "is sleeping😴");
	usleep(philo->time_to_sleep * 1000);
}
