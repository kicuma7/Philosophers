/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 06:01:32 by jquicuma          #+#    #+#             */
/*   Updated: 2024/12/20 07:17:25 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int main(int ac, char **av)
{
    t_philo_data    data;
    t_philo         philo[900];
    
    if (!validate_args(av, ac, &data))
        return (printf("%sInvalid Args\n%s", BRED, COLOUR_RESET));
    init_philos(philo, &data);
    free_all(&data);
    return (0);
}
