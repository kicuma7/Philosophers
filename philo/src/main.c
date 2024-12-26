/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedoming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:49:01 by sedoming          #+#    #+#             */
/*   Updated: 2024/11/27 16:31:21 by sedoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_data		dados;
	t_global	global;
	int			i;

	if (ac == 5 || ac == 6)
	{
		i = 0;
		while (++i < ac)
		{
			if (ft_atoi(av[i]) == 12)
				error_exit("value is long ❌");
			valid_args(av[i]);
		}
		data_init(&dados, &global, av);
	}
	else
	{
		error_exit("error with arguments ❌");
	}
}
