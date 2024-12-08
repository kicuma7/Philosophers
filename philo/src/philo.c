/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 06:41:47 by jquicuma          #+#    #+#             */
/*   Updated: 2024/12/08 08:08:39 by jquicuma         ###   ########.fr       */
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
    return (0);
}
