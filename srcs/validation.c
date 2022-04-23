/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:41:54 by lemmon            #+#    #+#             */
/*   Updated: 2022/04/22 16:02:17 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		dig;
	long	res;

	sign = 1;
	dig = 0;
	res = 0;
	while (*str == '\n' || *str == '\t' || *str == ' ' || \
			*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	// if (*str == '-' || *str == '+')
	// {
	// 	if (*str == '-') // не нужны знаки!!!!
	// 	sign = -1;
	// }
	// while (*str == '0')
	// 	str++;
	while ((*str >= '0') && (*str <= '9'))
	{
		res = res * 10 + (*str - '0');
		dig++;
		if (dig > 10 || (res * sign) > MAXINT || (res * sign) < MININT)
		{
			write(1, "Error\n", 6);
			exit(EXIT_SUCCESS); // FORBIDDEN!
		}
		str++;
	}
	return ((int)(res * sign));
}

void	fill_params(t_data *data, char **av)
{
	data->n_philo = ft_atoi(av[1]);
	printf("n - %d\n", data->n_philo);
	data->die = ft_atoi(av[2]);
	printf("die - %d\n", data->die);
	data->eat = ft_atoi(av[3]);
	printf("eat - %d\n", data->eat);
	data->sleep = ft_atoi(av[4]);
	printf("sleep - %d\n", data->sleep);
	if (av[5]) // if exist number if philos, then
		data->n_eat = ft_atoi(av[5]);
	else
		data->n_eat = -1;
	printf("n_eat - %d\n", data->n_eat);
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
			{
				printf("Params are not digits\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	// printf("count = %d\n", i - 1);
	fill_params(data, av);
	return (0);
}
