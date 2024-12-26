/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedoming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:49:29 by sedoming          #+#    #+#             */
/*   Updated: 2024/11/27 19:04:16 by sedoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

void	print(t_philo *philo, char *str)
{
	long	init;

	init = philo->time_init;
	pthread_mutex_lock(&philo->global->mutex);
	if (philo->global->control != 1)
		printf("[%ld][%d] %s\n", (gettimeofday_mills() - init), philo->id, str);
	pthread_mutex_unlock(&philo->global->mutex);
}

int	check_nb_meals(t_philo *philo)
{
	int	i;
	int	finish;

	finish = 0;
	i = 0;
	while (i < philo->nbr_philo)
	{
		usleep(1000);
		if (philo->total_ref == 0)
			finish = 1;
		else
			finish = 0;
		i++;
	}
	return (finish);
}

void	*monitor(void *args)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)args;
	while (1)
	{
		i = 0;
		while (i < philo->nbr_philo)
		{
			usleep(1000);
			if ((gettimeofday_mills()
					- philo->last_meal_time) > philo->time_to_die)
			{
				print(&philo[i], "died");
				philo->global->control = 1;
				return (NULL);
			}
			i++;
		}
		if (check_nb_meals(philo) == 1)
			return (NULL);
		usleep(1000);
	}
}

void	*rotina(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (one_filo(philo) == 1)
		return (NULL);
	while (1)
	{
		if (pick_up_forks(philo) == 1)
			break ;
		if (pick_up_pair_forks(philo) == 1)
			break ;
		if (eat(philo) == 1)
			break ;
		pthread_mutex_unlock(philo->esquerdo);
		pthread_mutex_unlock(philo->direito);
		if (philo->total_ref > 0)
			philo->total_ref--;
		if (philo->total_ref == 0)
			break ;
		sleeping(philo);
		if (philo->global->control == 1)
			break ;
		print(philo, "is thinking🤔");
	}
	return (NULL);
}

int	one_filo(t_philo *philo)
{
	if (philo->nbr_philo == 1)
	{
		pthread_mutex_lock(philo->esquerdo);
		print(philo, "has taken a fork🍽️");
		usleep(philo->time_to_die * 1000);
		pthread_mutex_unlock(philo->esquerdo);
		usleep(10000);
		return (1);
	}
	return (0);
}
