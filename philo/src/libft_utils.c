/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:05:21 by jquicuma          #+#    #+#             */
/*   Updated: 2024/12/30 09:05:45 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static bool    ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (true);
    return (false);
}

bool    ft_isnumeric_str(char *str)
{
    int    i;

    i = -1;
    if (str[0] == '-' || str[0] == '+')
        i++;
    while (str[++i])
    {
        if (!ft_isdigit(str[i]))
            return (false);
    }
    return (true);
}

long int    ft_atol(const char *nptr)
{
    long int    number;
    int            i;
    int            signal;

    signal = 1;
    number = 0;
    i = 0;
    while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
        i++;
    if ((nptr[i] == '-' || nptr[i] == '+'))
        if (nptr[i++] == '-')
            signal *= -1;
    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        number = (nptr[i] - '0') + (number * 10);
        i++;
    }
    return (number * signal);
}

int    ft_strcmp(const char *s1, const char *s2)
{
    size_t            i;
    unsigned char    *s_s1;
    unsigned char    *s_s2;

    if (!s1 || !s2)
        return (-1);
    i = 0;
    s_s1 = (unsigned char *)s1;
    s_s2 = (unsigned char *)s2;
    while (s_s1[i] || s_s2[i])
    {
        if (s_s1[i] != s_s2[i])
            return (s_s1[i] - s_s2[i]);
        i++;
    }
    return (0);
}

void mutex_print(char *status, t_philo *philo)
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
