/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:55:41 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/06 14:24:03 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	init_args(char **argv, t_philo_data *philo_data_init)
{
	philo_data_init->philo_nbr = ft_atol(argv[1]);
	philo_data_init->time_to_die = ft_atol(argv[2]);
	philo_data_init->time_to_eat = ft_atol(argv[3]);
	philo_data_init->time_to_sleep = ft_atol(argv[4]);
	philo_data_init->someone_died = false;
	pthread_mutex_init(&philo_data_init->print_mutex, NULL);
	pthread_mutex_init(&philo_data_init->death_mutex, NULL);
	if (argv[5])
	{
		philo_data_init->num_of_meals = ft_atol(argv[5]);
		philo_data_init->infinite_meals = false;
	}
	else
	{
		philo_data_init->num_of_meals = 0;
		philo_data_init->infinite_meals = true;
	}
}

bool	validate_args(char **argv, int argc, t_philo_data *philo_data_init)
{
	int			i;
	long int	args_long;

	if (argc != 5 && argc != 6)
		return (false);
	i = 0;
	while (++i < argc)
	{
		args_long = ft_atol(argv[i]);
		if ((!ft_isnumeric_str(argv[i])) || args_long > INT_MAX)
			return (false);
	}
	init_args(argv, philo_data_init);
	if (philo_data_init->philo_nbr <= 0 || philo_data_init->time_to_die <= 0
		|| philo_data_init->time_to_eat <= 0
		|| philo_data_init->time_to_sleep <= 0)
		return (false);
	return (true);
}
