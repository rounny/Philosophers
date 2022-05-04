/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:06:03 by lemmon            #+#    #+#             */
/*   Updated: 2022/05/04 16:13:00 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	philosopher_print(t_data *data, int index, char *msg)
{
	pthread_mutex_lock(&data->print_lock);
	printf("%lu %d %s\n", get_cur_time(data), index + 1, msg);
	pthread_mutex_unlock(&data->print_lock);
}

static void	philosopher_do(int time)
{
	t_timeval		current;
	unsigned long	finish_do;

	gettimeofday(&current, NULL);
	finish_do = get_time_in_ms(current) + time;
	while (get_time_in_ms(current) < finish_do)
	{
		gettimeofday(&current, NULL);
		usleep(200);
	}
}

void	*simulation(void *argc)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)argc;
	data = philo->data;
	if (philo->index % 2 == 0)
		my_sleep(200);
	while (1)
	{
		pthread_mutex_lock(&data->forks[philo->right_fork]);
		pthread_mutex_lock(&data->forks[philo->left_fork]);
		philosopher_print(data, philo->index, "is eating");
		philo->count_eat++;
		gettimeofday(&philo->last_eat, NULL);
		pthread_mutex_lock(&data->breaker);
		if (philo->count_eat == data->number_meal)
			data->count_fed_up++;
		pthread_mutex_unlock(&data->breaker);
		philosopher_do(data->time_eat);
		pthread_mutex_unlock(&data->forks[philo->right_fork]);
		pthread_mutex_unlock(&data->forks[philo->left_fork]);
		philosopher_print(data, philo->index, "is sleeping");
		philosopher_do(data->time_sleep);
		philosopher_print(data, philo->index, "is thinking");
	}
}
