/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedoming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:48:30 by sedoming          #+#    #+#             */
/*   Updated: 2024/12/03 13:15:20 by sedoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H
# include <errno.h>
# include <pthread.h>
# include <stdatomic.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_global
{
	pthread_mutex_t	mutex;
	_Atomic int		control;
}					t_global;

typedef struct s_philo
{
	pthread_mutex_t	*direito;
	pthread_mutex_t	*esquerdo;
	t_global		*global;
	int				id;
	_Atomic int		nbr_philo;
	_Atomic int		total_ref;
	long			time_to_eat;
	long			time_to_sleep;
	long			time_to_die;
	long			time_init;
	atomic_long		last_meal_time;
}					t_philo;

typedef struct s_data
{
	t_philo			*philosophers;
	pthread_t		*philo;
	pthread_t		*threads;
	pthread_t		monitor;
	pthread_mutex_t	*garfos;
	pthread_mutex_t	stop_mutex;
	int				philo_nbr;
	int				stop_simulation;
	atomic_int		total_ref;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			time;
	long			start_time;
}					t_data;

int					ft_atoi(char *str);
void				valid_args(char *str);
void				error_exit(char *str);
long				gettimeofday_mills(void);
void				data_init(t_data *data, t_global *s_global, char **av);
void				mutex_init(t_data *dados);
void				loop_create(t_data *dados, t_global *global);
void				loop_join_and_destroy(t_data *dados, t_global *global);
void				*rotina(void *args);
void				print(t_philo *philo, char *str);
void				*monitor(void *args);
int					philo_died(void *args);
int					one_filo(t_philo *philo);
int					pick_up_forks(t_philo *philo);
int					pick_up_pair_forks(t_philo *philo);
int					eat(t_philo *philo);
void				sleeping(t_philo *philo);
int					check_nb_meals(t_philo *philo);

#endif
