/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 06:41:47 by jquicuma          #+#    #+#             */
/*   Updated: 2024/12/09 07:15:51 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int main(int argc, char *argv[])
{
    t_common_data   common;
    t_philo         *thread;
    
    if (!validate_args(argv, argc, &common))
    {
        printf("%sInvalid Data\n", BRED);
        return (0);
    }
    return (0);
}

void    init(t_common_data *common, t_philo **thread)
{
    int i;
    
    *thread = malloc(sizeof(t_philo) * common->philo_nbr);
    if (!*thread)
        return ;
    i = -1;
    while (++i < common->philo_nbr)
    {
        (*thread)[i].common_data = *common;
        (*thread)[i].philo_id = i;
        (*thread)[i].
    }
}
