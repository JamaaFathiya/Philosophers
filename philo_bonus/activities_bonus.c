/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:30:09 by fathjami          #+#    #+#             */
/*   Updated: 2022/03/13 01:41:54 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_msg(t_phil *philo, char *msg)
{
	if (!philo->my_time_has_come)
		printf("%lli\t%i\t%s\n", current_time(philo), philo->id, msg);
}

void	activities(t_phil *philo)
{
	pthread_t	monitor;

	pthread_create(&monitor, NULL, alive, philo);
	while (1)
	{
		sem_wait(philo->arg->available_forks);
		print_msg(philo, "has taken a fork");
		sem_wait(philo->arg->available_forks);
		print_msg(philo, "has taken a fork");
		philo->last_meal = current_time(philo);
		print_msg(philo, "is eating");
		usleep(philo->arg->t_eat * 1000);
		sem_post(philo->arg->available_forks);
		sem_post(philo->arg->available_forks);
		philo->nb_of_meals++;
		if (philo->nb_of_meals == philo->arg->nbr_meal)
			exit (0);
		print_msg(philo, "is sleeping");
		usleep(philo->arg->t_sleep * 1000);
		print_msg(philo, "is thinking");
	}
	pthread_join(monitor, NULL);
	exit(0);
}
