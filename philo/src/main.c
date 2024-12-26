/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:49:01 by jquicuma          #+#    #+#             */
/*   Updated: 2024/12/26 08:38:40 by jquicuma         ###   ########.fr       */
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
			validate_args(av[i]);
		data_init(&dados, &global, av);
	}
	else
		print_error_and_exit(ERROR_ARG);
	return (0);
}
