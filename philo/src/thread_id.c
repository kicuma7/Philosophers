/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 05:38:09 by jquicuma          #+#    #+#             */
/*   Updated: 2024/12/08 06:18:16 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    *print_thread_id(void *id);

int main(void)
{
    t_philo     philo[5];
    int         i;

    i = 0;
    while (i < 5)
    {
        philo[i].philo_id = i + 1;
        pthread_create(&philo[i].philo, NULL, &print_thread_id, &philo[i]);
        i++;    
    }
    i = 0;
    while (i < 5)
        pthread_join(philo[i++].philo, NULL);
    return (0);
}

void    *print_thread_id(void *id)
{
    t_philo philo;

    philo = *(t_philo *)id;
    printf("%sEssa é a thread número %d\n", RED, philo.philo_id);
    return (NULL);
}
