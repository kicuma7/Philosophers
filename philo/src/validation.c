/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:49:39 by jquicuma          #+#    #+#             */
/*   Updated: 2024/12/26 08:38:29 by jquicuma         ###   ########.fr       */
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

void	validate_args(char *str)
{
	/*if (ft_atoi(str) == 12)
		print_error_and_exit(ERR_VAL);*/
	if (ft_atoi(str) == 0)
		print_error_and_exit(ERROR_ARG);
	while (*str != '\0')
	{
		if (*str == '+')
			str++;
		if (!(*str >= '0' && *str <= '9'))
			print_error_and_exit(ERROR_ARG);
		if ((*str >= 9 && *str <= 13) || *str == 32)
			print_error_and_exit(ERROR_ARG);
		if (*str == '-')
			print_error_and_exit(ERROR_ARG);
		str++;
	}
}
