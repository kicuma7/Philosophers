/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:51:46 by jquicuma          #+#    #+#             */
/*   Updated: 2024/12/26 08:25:49 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_error_and_exit(char *str)
{
	printf("%s %s %s\n", BRED, str, COLOUR_RESET);
	exit(EXIT_FAILURE);
}
