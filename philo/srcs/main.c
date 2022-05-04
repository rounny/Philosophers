/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:52:56 by lemmon            #+#    #+#             */
/*   Updated: 2022/05/04 15:37:37 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_error(char *msg)
{
	printf("Error: %s\n", msg);
	return (1);
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
