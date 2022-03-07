/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 04:24:12 by fathjami          #+#    #+#             */
/*   Updated: 2022/03/07 04:25:50 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_phil *philo, char *msg)
{
	pthread_mutex_lock(&philo->arg->finish_lock);
	if (!philo->arg->finish)
		printf("%lli\t%i\t%s\n", current_time(philo), philo->id + 1, msg);
	pthread_mutex_unlock(&philo->arg->finish_lock);
}

void	*alive(void *arg)
{
	t_phil	*philo;

	philo = arg;
	while (!philo->my_time_has_come)
	{
		if (philo->my_time_has_come + philo->arg->t_die <= current_time(philo))
		{
			print_msg(philo, "died");
			philo->my_time_has_come = 1;
			philo->arg->finish = 1;
		}
		usleep(100);
	}
	return (NULL);
}

void	*hungry(void *args)
{
	t_arg	*arg;

	arg = args;
	while (!arg->finish)
	{
		if (arg->all_ate == arg->nbr_of_philo)
			arg->finish = 1;
	}
	return (NULL);
}
