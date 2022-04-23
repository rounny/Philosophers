/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmon <lemmon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:48:02 by lemmon            #+#    #+#             */
/*   Updated: 2022/04/22 12:36:34 by lemmon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

#define MININT -2147483648
#define MAXINT 2147483647

typedef struct s_data
{
	int		n_philo;
	int		die;
	int		eat;
	int		sleep;
	int		n_eat;
	char	*left_fork;
	char	*right_fork;
}t_data;

int		ft_validation(t_data *data, char **av);
void	fill_params(t_data *data, char **av);
int		ft_atoi(const char *str);
int		ft_isdigit(char c);

#endif