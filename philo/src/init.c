/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedoming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:49:16 by sedoming          #+#    #+#             */
/*   Updated: 2024/12/03 11:55:23 by sedoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

void	data_init(t_data *data, t_global *global, char **av)
{
	memset(data, 0, sizeof(t_data));
	data->philo_nbr = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	global->control = 0;
	if (av[5] != NULL)
		data->total_ref = ft_atoi(av[5]);
	else
		data->total_ref = -1;
	data->philo = (pthread_t *)malloc(sizeof(pthread_t) * data->philo_nbr);
	data->philosophers = (t_philo *)malloc(sizeof(t_philo) * data->philo_nbr);
	data->garfos = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->philo_nbr);
	mutex_init(data);
	pthread_mutex_init(&global->mutex, NULL);
	loop_create(data, global);
	loop_join_and_destroy(data, global);
}

void	mutex_init(t_data *dados)
{
	int	i;

	i = 0;
	while (i < dados->philo_nbr)
		pthread_mutex_init(&dados->garfos[i++], NULL);
}

void	loop_create(t_data *dados, t_global *global)
{
	int	i;

	i = 0;
	dados->time = gettimeofday_mills();
	while (i < dados->philo_nbr)
	{
		memset(&dados->philosophers[i], 0, sizeof(t_philo));
		dados->philosophers[i].time_init = gettimeofday_mills();
		dados->philosophers[i].id = i + 1;
		dados->philosophers->nbr_philo = dados->philo_nbr;
		dados->philosophers[i].time_to_die = dados->time_to_die;
		dados->philosophers[i].time_to_eat = dados->time_to_eat;
		dados->philosophers[i].time_to_sleep = dados->time_to_sleep;
		dados->philosophers[i].total_ref = dados->total_ref;
		dados->philosophers[i].direito = &dados->garfos[i];
		dados->philosophers[i].esquerdo = &dados->garfos[(i + 1)
			% dados->philo_nbr];
		dados->philosophers[i].last_meal_time = gettimeofday_mills();
		dados->philosophers[i].global = global;
		pthread_create(dados->philo + i, NULL, rotina, &dados->philosophers[i]);
		i++;
	}
	pthread_create(&dados->monitor, NULL, monitor, dados->philosophers);
}

void	loop_join_and_destroy(t_data *dados, t_global *global)
{
	int	i;

	i = 0;
	while (i < dados->philo_nbr)
		pthread_join(dados->philo[i++], NULL);
	pthread_join(dados->monitor, NULL);
	i = 0;
	while (i < dados->philo_nbr)
		pthread_mutex_destroy(&dados->garfos[i++]);
	pthread_mutex_destroy(&global->mutex);
	free(dados->philo);
	free(dados->philosophers);
	free(dados->garfos);
}
