/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:44:05 by jquicuma          #+#    #+#             */
/*   Updated: 2024/12/09 06:59:48 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    print_philo_status(t_philo *thread, char *status)
{
    pthread_mutex_lock(&thread->print_mutex);
    if (!ft_strcmp(status, DIE))
        printf("%sphilo %d %s\n", BRED, thread->philo_id, DIE);
    if (!ft_strcmp(status, FORK))
        printf("%sphilo %d %s\n", YELLOW, thread->philo_id, FORK);
    if (!ft_strcmp(status, EAT))
        printf("%sphilo %d %s\n", BGREEN, thread->philo_id, EAT);
    if (!ft_strcmp(status, SLEEP))
        printf("%sphilo %d %s\n", GRAY, thread->philo_id, SLEEP);
    if (!ft_strcmp(status, THINK))
        printf("%sphilo %d %s\n", BBLUE, thread->philo_id, THINK);
    pthread_mutex_unlock(&thread->print_mutex);
}
