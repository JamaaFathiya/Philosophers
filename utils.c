/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:25:15 by fathjami          #+#    #+#             */
/*   Updated: 2022/03/07 04:14:37 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	getmili(void)
{
	t_time	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

long long	current_time(t_phil *philo)
{
	long long	time;

	time = getmili() - philo->arg->creation_time;
	return (time);
}

void	print_error(char *str)
{
	printf("Error! %s", str);
	exit (1);
}

static int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\f' || c == '\v'
		|| c == '\r' || c == ' ');
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	s;

	i = 0;
	res = 0;
	s = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res *= 10;
		res += (int)nptr[i] - 48;
		i++;
	}
	return (res * s);
}
