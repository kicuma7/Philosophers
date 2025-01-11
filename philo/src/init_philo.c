/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:29:54 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/11 13:25:36 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	pick_first_fork_lock(t_philo *philo);
static void	*routine(void *philos);

void	init_philos(t_philo *philos, t_philo_data *data)
{
	pthread_t	monitor_thread;
	int			i;

	i = 0;
	while (i < data->philo_nbr)
		pthread_mutex_init(&data->forks[i++], NULL);
	data->someone_died = false;
	data->initial_time_ms = current_time_in_ms();
	i = 0;
	while (i < data->philo_nbr)
	{
		philos[i].id = i + 1;
		philos[i].data = data;
		philos[i].last_meal_abs_usec = current_time_in_ms();
		philos[i].left_fork = &data->forks[i];
		philos[i].right_fork = &data->forks[(i + 1) % data->philo_nbr];
		pthread_create(&philos[i].philo, NULL, &routine, &philos[i]);
		i++;
	}
	i = 0;
	pthread_create(&monitor_thread, NULL, death_monitor, philos);
	while (i < data->philo_nbr)
		pthread_join(philos[i++].philo, NULL);
	pthread_join(monitor_thread, NULL);
}

static void	*routine(void *philos)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)philos;
	i = 0;
	philo->data->meals_rest = true;
	if (philo->data->infinite_meals)
		while (!check_death(philo))
			pick_first_fork_lock(philo);
	else
	{
		while (i++ < philo->data->num_of_meals && !check_death(philo))
		{
			if (i == philo->data->num_of_meals)
				philo->data->meals_rest = false;
			pick_first_fork_lock(philo);
		}
	}
	return (NULL);
}

static void	pick_first_fork_lock(t_philo *philo)
{
	if ((philo->id % 2) == 0)
	{
		if (!pthread_mutex_lock(philo->left_fork))
		{
			if (check_death(philo))
				return (unlock_locks(philo->left_fork, NULL));
			mutex_print(FORK, philo, BYELLOW);
			if (!pthread_mutex_lock(philo->right_fork))
				philo_routine(philo);
			else
				unlock_locks(philo->left_fork, philo->right_fork);
		}
	}
	else
	{
		usleep(1000);
		if (!pthread_mutex_lock(philo->right_fork))
		{
			if (check_death(philo))
				return (unlock_locks(philo->right_fork, NULL));
			mutex_print(FORK, philo, BYELLOW);
			if (!pthread_mutex_lock(philo->left_fork))
				philo_routine(philo);
			else
				unlock_locks(philo->left_fork, philo->right_fork);
		}
	}
}
