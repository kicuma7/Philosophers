/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 05:52:57 by jquicuma          #+#    #+#             */
/*   Updated: 2024/12/20 08:04:09 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void init_args(char **argv, t_philo_data *philo_data_init)
{
    philo_data_init->philo_nbr = ft_atol(argv[1]);
    philo_data_init->time_to_die = ft_atol(argv[2]);
    philo_data_init->time_to_eat = ft_atol(argv[3]);
    philo_data_init->time_to_sleep = ft_atol(argv[4]);
    philo_data_init->time_to_think = philo_data_init->time_to_die -
                                     (philo_data_init->time_to_eat + philo_data_init->time_to_sleep);
    pthread_mutex_init(&philo_data_init->print_mutex, NULL);
    if (philo_data_init->time_to_think < 0)
        philo_data_init->time_to_think = 0;
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

bool validate_args(char **argv, int argc, t_philo_data *philo_data_init)
{
    int i;
    long int args_long;

    if (argc != 5 && argc != 6)
        return (false);
    i = 0;
    while (++i < argc)
    {
        args_long = ft_atol(argv[i]);
        if ((!ft_isnumeric_str(argv[i])) || args_long > INT_MAX ||
            args_long < INT_MIN)
            return (false);
    }
    init_args(argv, philo_data_init);
    return (true);
}
