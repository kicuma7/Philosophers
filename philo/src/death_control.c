/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:56:53 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/01 07:57:28 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// Função para verificar se um filósofo morreu
bool check_death(t_philo *philo)
{
    bool died;

    pthread_mutex_lock(&philo->data->death_mutex);
    died = philo->data->someone_died;
    pthread_mutex_unlock(&philo->data->death_mutex);
    return (died);
}

// Função para marcar um filósofo como morto
void mark_death(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->death_mutex);
    philo->data->someone_died = true;
    pthread_mutex_unlock(&philo->data->death_mutex);
    mutex_print(DEAD, philo);
}
