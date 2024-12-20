/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 06:29:19 by jquicuma          #+#    #+#             */
/*   Updated: 2024/12/20 10:31:41 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void     pick_first_fork_lock(t_philo *philo);
static void    *routine(void *philos);

void    init_philos(t_philo *philos, t_philo_data *data)
{
    int i;

    i = 0;
    while (i < data->philo_nbr)
        pthread_mutex_init(&data->forks[i++], NULL);
    data->initial_time_ms = current_time_in_ms();
    i = 0;
    while (i < data->philo_nbr)
    {
        philos[i].id = i + 1;
        philos[i].data = data;
        philos[i].left_fork = &data->forks[i];
        philos[i].right_fork = &data->forks[(i + 1) % data->philo_nbr];
        pthread_create(&philos[i].philo, NULL, &routine, &philos[i]);
        i++;
    }
    i = 0;
    while (i < data->philo_nbr)
        pthread_join(philos[i++].philo, NULL);
}

static void    *routine(void *philos)
{
    t_philo philo;
    int     i;

    philo = *(t_philo *)philos;
    i = 0;
    if (philo.data->infinite_meals)
        while (true)
            pick_first_fork_lock(&philo);
    else
        while (i++ < philo.data->num_of_meals)
            pick_first_fork_lock(&philo);
    return (NULL);
}

static void pick_first_fork_lock(t_philo *philo)
{
    if ((philo->id % 2) == 0)
    {
        if (!pthread_mutex_lock(philo->left_fork))
        {
            mutex_print(FORK, philo);
            if (!pthread_mutex_lock(philo->right_fork))
                philo_routine(philo);
            else
                unlock_locks(philo->left_fork, philo->right_fork);
        } 
    }
    else
    {
        if (!pthread_mutex_lock(philo->right_fork))
        {
            mutex_print(FORK, philo);
            if (!pthread_mutex_lock(philo->left_fork))
                philo_routine(philo);
            else
                unlock_locks(philo->left_fork, philo->right_fork);
        }
    }
}
