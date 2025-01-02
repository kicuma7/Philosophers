/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:56:53 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/02 12:52:02 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// Função para verificar se um filósofo morreu
bool check_death(t_philo *philo)
{
    bool died;

    pthread_mutex_lock(&philo->data->death_mutex);
    died = philo->data->someone_died;
    pthread_mutex_unlock(&philo->data->death_mutex);
    return (died);
}

// Função para marcar um filósofo como morto
void mark_death(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->death_mutex);
    philo->data->someone_died = true;
    pthread_mutex_unlock(&philo->data->death_mutex);
    mutex_print(DEAD, philo);
}

void *death_monitor(void *arg)
{
    t_philo *philos = (t_philo *)arg;
    int i;
    long long current_time;

    while (!check_death(&philos[0]))
    {
        i = 0;
        while (i < philos[0].data->philo_nbr)
        {
            current_time = current_time_in_ms();
            if ((current_time - philos[i].last_meal_abs_usec) >= 
                philos[i].data->time_to_die)
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

void	*monitor(void *args)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)args;
	while (1)
	{
		i = 0;
		while (i < philo->data->philo_nbr)
		{
			usleep(1000);
			if ((current_time_in_ms()
					- philo->last_meal_abs_usec) > philo->data->time_to_die)
			{
				mark_death(&philo[i]);
				philo->data->someone_died = true;
				return (NULL);
			}
			i++;
		}
		usleep(1000);
	}
}
