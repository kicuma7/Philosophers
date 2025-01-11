/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:56:53 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/11 14:59:19 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool	check_death(t_philo *philo)
{
	bool	died;

	died = philo->data->someone_died;
	return (died);
}

void	*death_monitor(void *args)
{
	t_philo			*philos;
	int				i;

	philos = (t_philo *)args;
	while (true)
	{
		i = 0;
		while (i < philos[0].data->philo_nbr)
		{
			if ((current_time_in_ms() \
			- philos[i].last_meal_abs_usec) > philos[0].data->time_to_die)
			{
				if (philos[0].data->meals_rest)
				{
					philos[0].data->someone_died = true;
					mutex_print(DEAD, &philos[i], BRED);
					pthread_mutex_unlock(&philos[0].data->print_mutex);
				}
				return (NULL);
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
