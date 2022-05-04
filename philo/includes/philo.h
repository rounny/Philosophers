/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:48:02 by lemmon            #+#    #+#             */
/*   Updated: 2022/05/04 15:36:38 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct timeval	t_timeval;

typedef struct s_philo
{
	int				index;
	int				left_fork;
	int				right_fork;
	int				flag_fork;
	int				count_eat;
	t_timeval		last_eat;
	struct s_data	*data;
	pthread_t		id;
}	t_philo;

typedef struct s_data
{
	int				number_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				number_meal;
	int				count_fed_up;
	t_timeval		start;
	pthread_mutex_t	forks[200];
	pthread_mutex_t	breaker;
	pthread_mutex_t	print_lock;
	t_philo			philo[200];
}t_data;

int				ft_validation(t_data *data, char **av);
int				fill_parameteres(t_data *data, char **av);
int				check_parameteres(t_data *data);
int				ft_atoi(const char *str);
int				ft_isdigit(char c);
int				ft_error(char *msg);
int				init_philosophers(t_data *data);
int				init_forks(t_data *data);
int				start_game(t_data *data);
void			finish_game(t_data *data);
void			*simulation(void *argc);
void			my_sleep(unsigned long ms);
unsigned long	get_time(void);
unsigned long	get_time_in_ms(t_timeval time);
unsigned long	get_cur_time(t_data *sim);

#endif