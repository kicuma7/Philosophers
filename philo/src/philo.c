/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 07:51:29 by jquicuma          #+#    #+#             */
/*   Updated: 2024/12/13 12:27:46 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void            init_philos(t_philo **philos, t_data *data);
static void    *routine(void *philo);

int main(int ac, char **av)
{
    int     i;
    t_data  philo_data;
    t_philo *philos;
    
    if (!validate_args(av, ac, &philo_data))
        return (printf("%sError: %sInvalid arguments\n", BRED, WHITE));
    init_philos(&philos, &philo_data);
    i = 0;
    while (i < philo_data.philo_nbr)
        pthread_create(&philos->thread, NULL, &routine, &philos[i++]);
    i = 0;
    while (i < philo_data.philo_nbr)
        pthread_join(philos[i++].thread, NULL);
}

void    init_philos(t_philo **philos, t_data *data)
{
    int i;

    i = 0;
    *philos = malloc(sizeof(t_philo) * data->philo_nbr);
    data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_nbr);
    while (i < data->philo_nbr)
        pthread_mutex_init(&data->forks[i++], NULL);
    i = 0;
    while (i < data->philo_nbr)
    {
        (*philos)[i].id = i + 1;
        (*philos)[i].data = data;
        (*philos)[i].left_fork = &data->forks[i];
        (*philos)[i].right_fork = &data->forks[(i + 1) % data->philo_nbr];
        i++;
    }
}

static void    *routine(void *philos)
{
    t_philo philo;

    philo = *(t_philo *)philos;
    for (int i = 0; i < 10; i++)
        pick_forks(&philo);
    return (NULL);
}
