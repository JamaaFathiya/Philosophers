/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:34:42 by fathjami          #+#    #+#             */
/*   Updated: 2022/03/12 17:19:48 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*alive(void *arg)
{
	t_phil	*philo;

	philo = arg;
	while (!philo->my_time_has_come)
	{
		if (philo->last_meal + philo->arg->t_die <= current_time(philo))
		{
			print_msg(philo, "died");
			philo->my_time_has_come = 1;
			exit (1);
		}
		usleep(1000);
	}
	return (NULL);
}
