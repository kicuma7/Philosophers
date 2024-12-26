/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedoming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:49:39 by sedoming          #+#    #+#             */
/*   Updated: 2024/11/27 19:21:31 by sedoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

int	ft_atoi(char *str)
{
	int		sinal;
	long	rest;

	sinal = 1;
	rest = 0;
	if (*str == '-')
	{
		str++;
		sinal = -1;
	}
	if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			rest = rest * 10 + *str - '0';
		str++;
	}
	if (rest >= 2147483647)
		return (12);
	return (sinal * rest);
}

void	valid_args(char *str)
{
	if (ft_atoi(str) == 0)
		error_exit("error with characters ❌");
	while (*str != '\0')
	{
		if (*str == '+')
			str++;
		if (!(*str >= '0' && *str <= '9'))
			error_exit("error with characters ❌");
		if ((*str >= 9 && *str <= 13) || *str == 32)
			error_exit("error with characters ❌");
		if (*str == '-')
			error_exit("error with characters ❌");
		str++;
	}
}

long	gettimeofday_mills(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
