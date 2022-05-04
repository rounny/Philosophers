/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:41:54 by lemmon            #+#    #+#             */
/*   Updated: 2022/05/04 15:41:41 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

int	check_parameteres(t_data *data)
{
	if (data->number_philo < 1 || data->time_die < 1 || data->time_eat < 1 \
	|| data->time_sleep < 1 || data->number_philo > 200)
		return (ft_error("Invalid parameters"));
	return (0);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	while (*str == '\n' || *str == '\t' || *str == ' ' || \
			*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while ((*str >= '0') && (*str <= '9'))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return ((int)(res * sign));
}

int	fill_parameteres(t_data *data, char **av)
{
	data->number_philo = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	if (av[5])
	{
		data->number_meal = ft_atoi(av[5]);
		if (data->number_meal < 1)
			return (ft_error("Invalid parameters"));
	}
	else
		data->number_meal = -1;
	data->count_fed_up = 0;
	return (check_parameteres(data));
}

int	ft_validation(t_data *data, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]))
				return (ft_error("Invalid parameters"));
			j++;
		}
		i++;
	}
	return (fill_parameteres(data, av));
}
