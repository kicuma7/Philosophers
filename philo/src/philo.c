/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 07:51:29 by jquicuma          #+#    #+#             */
/*   Updated: 2024/12/10 16:44:09 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int main(int ac, char **av)
{
    t_data  philo_data;
    
    if (!validate_args(av, ac, &philo_data))
        return (printf("%sError: %sInvalid arguments\n", BRED, WHITE));
    printf("%sphilo_data.philo_nbr: %d\n", BWHITE, philo_data.philo_nbr);
    printf("%sphilo_data.time_to_die: %d\n", BWHITE, philo_data.time_to_die);
    printf("%sphilo_data.time_to_eat: %d\n", BWHITE, philo_data.time_to_eat);
    printf("%sphilo_data.time_to_sleep: %d\n", BWHITE, philo_data.time_to_sleep);
    printf("%sphilo_data.num_of_meals: %d\n", BWHITE, philo_data.num_of_meals);
    printf("%sphilo_data.infinite_meals: %d\n", BWHITE, philo_data.infinite_meals);
    return (0);
}
