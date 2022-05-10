/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:52:56 by lemmon            #+#    #+#             */
/*   Updated: 2022/05/10 15:02:24 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_error(char *msg)
{
	printf("Error: %s\n", msg);
	return (1);
}

int	start_game(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_philo)
	{
		if (pthread_create(&(data->philo[i].id), NULL, simulation,
				(void *)&(data->philo[i])))
			return (ft_error("Create error"));
		if (pthread_detach(data->philo[i].id) != 0)
			return (ft_error("Detach error"));
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
		return (ft_error("Wrong number of arguments"));
	if (ft_validation(&data, av))
		return (1);
	if (init_philosophers(&data) || init_forks(&data))
		return (1);
	if (start_game(&data))
		return (1);
	finish_game(&data);
	return (0);
}
