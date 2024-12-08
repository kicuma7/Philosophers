/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 05:38:09 by jquicuma          #+#    #+#             */
/*   Updated: 2024/12/08 07:49:06 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void init_args(char **argv, t_common_data *philo_data_init)
{
    philo_data_init->philo_nbr = ft_atol(argv[1]);
    philo_data_init->time_to_die = ft_atol(argv[2]);
    philo_data_init->time_to_eat = ft_atol(argv[3]);
    philo_data_init->time_to_spleep = ft_atol(argv[4]);
    if (argv[5])
    {
        philo_data_init->meal_nbr = ft_atol(argv[5]);
        philo_data_init->infinit_mode = false;
    }
    else
    {
        philo_data_init->meal_nbr = 0;
        philo_data_init->infinit_mode = true;
    }
}

bool    validate_args(char **argv, int argc, t_common_data *philo_data_init)
{
    int         i;
    long int    args_long;
    
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
