/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 06:41:47 by jquicuma          #+#    #+#             */
/*   Updated: 2024/12/08 07:57:37 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int main(int argc, char *argv[])
{
    t_common_data   common;
    
    if (!validate_args(argv, argc, &common))
    {
        printf("%sInvalid Data\n", BRED);
        return (0);
    }
    printf("%s Infinit Mode: %d\n", BYELLOW, common.infinit_mode);
    printf("%s Meal Number: %d\n", BBLUE, common.meal_nbr);
    printf("%s Philo Number: %d\n", BGRAY, common.philo_nbr);
    printf("%s Time to die: %d\n", BRED, common.time_to_die);
    printf("%s Time to eat: %d\n", BMAGENTA, common.time_to_eat);
    printf("%s Time to sleep: %d\n", BORANGE,  common.time_to_spleep);
    return (0);
}
