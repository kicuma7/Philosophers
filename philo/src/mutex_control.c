/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:54:11 by jquicuma          #+#    #+#             */
/*   Updated: 2024/12/13 15:13:03 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void philo_id_even(t_philo *philo);
static void philo_id_odd(t_philo *philo);
void        *check_death(void *philo);

void clean_rc_print(char *status, t_philo *philo)
{
    long    time_diff;
    
    pthread_mutex_lock(&philo->data->print_mutex);
    time_diff = current_time_in_ms() - philo->data->initial_time_ms;
    if (!ft_strcmp(status, FORK))
        printf("%s[%ld] philo %d %s%s\n", BYELLOW, time_diff, philo->id, FORK, COLOUR_RESET);
    else if (!ft_strcmp(status, EAT))
        printf("%s[%ld] philo %d %s%s\n", BGREEN, time_diff, philo->id, EAT, COLOUR_RESET);
    else if (!ft_strcmp(status, SLEEP))
        printf("%s[%ld] philo %d %s%s\n", BBLUE, time_diff, philo->id, SLEEP, COLOUR_RESET);
    else if (!ft_strcmp(status, THINK))
        printf("%s[%ld] philo %d %s%s\n", BGRAY, time_diff, philo->id, THINK, COLOUR_RESET);
    else if (!ft_strcmp(status, DEAD))
        printf("%s[%ld] philo %d %s%s\n", BRED, time_diff, philo->id, DEAD, COLOUR_RESET);
    pthread_mutex_unlock(&philo->data->print_mutex);
}

void pick_forks(t_philo *philo)
{
    if ((philo->id % 2) == 0)
        philo_id_even(philo);
    else
        philo_id_odd(philo);
}

static void philo_id_even(t_philo *philo)
{
    if (!pthread_mutex_lock(philo->left_fork))
    {
        clean_rc_print(FORK, philo);
        if (!pthread_mutex_lock(philo->right_fork))
        {
            clean_rc_print(FORK, philo);
            clean_rc_print(EAT, philo);
            philo->data->last_meal_ms = current_time_in_ms();
            usleep(philo->data->time_to_eat * 1000);
            pthread_mutex_unlock(philo->right_fork);
            pthread_mutex_unlock(philo->left_fork);
            clean_rc_print(SLEEP, philo);
            usleep(philo->data->time_to_sleep * 1000);
            clean_rc_print(THINK, philo);
            usleep(philo->data->time_to_think * 1000);
            //pthread_create(&philo->monitor, NULL, check_death, philo);
        }
        else
        {
            pthread_mutex_unlock(philo->right_fork);
            pthread_mutex_unlock(philo->left_fork);
        }
    }
}

static void philo_id_odd(t_philo *philo)
{
    if (!pthread_mutex_lock(philo->right_fork))
    {
        clean_rc_print(FORK, philo);
        if (!pthread_mutex_lock(philo->left_fork))
        {
            clean_rc_print(FORK, philo);
            clean_rc_print(EAT, philo);
            philo->data->last_meal_ms = current_time_in_ms();
            usleep(philo->data->time_to_eat * 1000);
            pthread_mutex_unlock(philo->right_fork);
            pthread_mutex_unlock(philo->left_fork);
            clean_rc_print(SLEEP, philo);
            usleep(philo->data->time_to_sleep * 1000);
            clean_rc_print(THINK, philo);
            usleep(philo->data->time_to_think * 1000);
            //pthread_create(&philo->monitor, NULL, check_death, philo);
        }
        else
        {
            pthread_mutex_unlock(philo->right_fork);
            pthread_mutex_unlock(philo->left_fork);
        }
    }
}
/*
void    *check_death(void *philos)
{
    long long   current_time;
    t_philo   philo;
    
    philo = *(t_philo *)philos;
    current_time = current_time_in_ms();
    if (current_time - philo.data->last_meal_ms >= philo.data->time_to_die 
        || philo.data->time_to_think <= 0); 
    {
        clean_rc_print(DEAD, &philo);
        exit(EXIT_SUCCESS);
    }
    return (NULL);
}
*/
