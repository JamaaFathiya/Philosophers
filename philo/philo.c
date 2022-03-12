/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:31:54 by fathjami          #+#    #+#             */
/*   Updated: 2022/03/07 04:12:38 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pickup_forks(t_phil *philo, int id)
{
	pthread_mutex_lock(&(philo->arg->locks[id]));
	print_msg(philo, "has taken a fork");
	pthread_mutex_lock(&(philo->arg->locks[(id + 1)
			% philo->arg->nbr_of_philo]));
	print_msg(philo, "has taken a fork");
}

void	put_down(t_phil *philo, int id)
{
	pthread_mutex_unlock(&(philo->arg->locks[id]));
	pthread_mutex_unlock(&(philo->arg->locks[(id + 1)
			% philo->arg->nbr_of_philo]));
}

void	eat(t_phil *philo)
{
	pickup_forks(philo, philo->id);
	philo->my_time_has_come = current_time(philo);
	philo->nb_of_meals++;
	if (philo->nb_of_meals == philo->arg->nbr_meal)
		philo->arg->all_ate++;
	print_msg(philo, "is eating");
	usleep(philo->arg->t_eat * 1000);
	put_down(philo, philo->id);
}

void	sleep_and_think(t_phil *philo)
{
	print_msg(philo, "is sleeping");
	usleep(philo->arg->t_sleep * 1000);
	print_msg(philo, "is thinking");
}
