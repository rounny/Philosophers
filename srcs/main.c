/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:52:56 by lemmon            #+#    #+#             */
/*   Updated: 2022/04/22 16:01:48 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_init(t_data	*data)
{
	data->n_philo = 0;
	data->die = 0;
	data->eat = 0;
	data->sleep = 0;
	data->n_eat = 0; // MB if it does not exist, so does not init MB
	data->left_fork = NULL;
	data->right_fork = NULL;
}
 
int main(int ac, char **av)
{
	t_data	data;
	if (ac < 5 || ac > 6)
	{
		printf("Error params\n");
		return (1);
	}
	ft_init(&data);
	if (ft_validation(&data, av))
		return (1);
	//create_philos(&data);
	return (0);
}
