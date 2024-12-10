/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 07:51:29 by jquicuma          #+#    #+#             */
/*   Updated: 2024/12/10 16:34:26 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int main(int ac, char **av)
{
    t_data  philo_data;
    
    if (!validate_args(av, ac, &philo_data))
        return (printf("%sError: Invalid arguments%s\n", RED, WHITE));
}
