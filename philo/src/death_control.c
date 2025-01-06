/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:56:53 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/06 14:35:22 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool	check_death(t_philo *philo)
{
	bool	died;

	pthread_mutex_lock(&philo->data->death_mutex);
	died = philo->data->someone_died;
	pthread_mutex_unlock(&philo->data->death_mutex);
	return (died);
}

void	mark_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death_mutex);
	philo->data->someone_died = true;
	pthread_mutex_unlock(&philo->data->death_mutex);
	mutex_print(DEAD, philo);
}

void	*death_monitor(void *arg)
{
	t_philo		*philos;
	int			i;
	long long	current_time;

	philos = (t_philo *)arg;
	while (!check_death(&philos[0]))
	{
		i = 0;
		while (i < philos[0].data->philo_nbr)
		{
			current_time = current_time_in_ms();
			if ((current_time
					- philos[i].last_meal_abs_usec) >= philos[i].data->time_to_die)
			{
				mark_death(&philos[i]);
				return (NULL);
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}

/*
void	*monitor(void *args)
{
	t_philo			*philos;
	t_philo_data	*data;
	int				i;

	philos = (t_philo *)args;
	data = philos[0].data;
	while (true)
	{
		i = 0;
		while (i < data->philo_nbr)
		{
			pthread_mutex_lock(&philos[i].meal_mutex);
			if ((current_time_in_ms()
					- philos[i].last_meal_abs_usec) > data->time_to_die)
			{
				pthread_mutex_lock(&data->print_mutex);
				data->someone_died = true;
				printf("%s[%lld] philo %d %s%s\n", BRED, current_time_in_ms()
					- data->initial_time_ms, philos[i].id, DEAD, R);
				pthread_mutex_unlock(&data->print_mutex);
				pthread_mutex_unlock(&philos[i].meal_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(&philos[i].meal_mutex);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
*/
