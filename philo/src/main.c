/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:18:36 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/07 12:52:39 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_philo_data	data;
	t_philo			philos[900];

	if (!validate_args(argv, argc, &data))
		return (printf("%sInvalid Args\n%s", BRED, R));
	if (data.philo_nbr == 1)
	{
		printf("%s[%d] philo %d %s%s\n", BYELLOW, 0, 1, FORK, R);
		usleep(data.time_to_die * 1000);
		printf("%s[%d] philo %d %s%s\n", BRED, data.time_to_die, 1, DEAD, R);
		return (0);
	}
	init_philos(philos, &data);
	free_all(&data, philos);
	return (0);
}
