/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:18:36 by jquicuma          #+#    #+#             */
/*   Updated: 2024/12/30 19:42:18 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int main(int argc, char **argv)
{
    t_philo_data    data;
    t_philo         philos[900];
    
    if (!validate_args(argv, argc, &data))
        return (printf("%sInvalid Args\n%s", BRED, COLOUR_RESET));
    if (data.philo_nbr == 1)
    {
        printf("%s[%d] philo %d %s%s\n", BYELLOW, 0, 1, FORK, COLOUR_RESET);
        usleep(data.time_to_die * 1000);
        printf("%s[%d] philo %d %s%s\n", BRED, data.time_to_die, 1, DEAD, COLOUR_RESET);
        return (0);
    }
    init_philos(philos, &data);
    free_all(&data);
    return (0);
}
