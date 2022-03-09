/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:18:56 by fathjami          #+#    #+#             */
/*   Updated: 2022/03/09 16:47:00 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_arg(t_arg *arg, int ac, char **av)
{
	arg->nbr_of_philo = ft_atoi(av[1]);
	arg->t_die = ft_atoi(av[2]);
	arg->t_eat = ft_atoi(av[3]);
	arg->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		arg->nbr_meal = ft_atoi(av[5]);
	else
		arg->nbr_meal = -1;
	arg->finish = 0;
	arg->id_table = malloc(arg->nbr_of_philo * sizeof(int));
	if (!arg->id_table)
		return (0);
	return (1);
}
	// philo = malloc(arg->nbr_of_philo * sizeof(t_phil));
	// if (!arg->philo)
	// 	return (0);
	// while (++i < arg->nbr_of_philo)
	// {
	// 	arg->philo[i].id = i;
	// 	arg->philo[i].nb_of_meals = 0;
	// 	arg->philo[i].arg = arg
	// }

// int	init_thread(t_arg *arg)
// {
// 	int			i;
// 	t_phil		*p;
// 	pthread_t	monitor;

// 	i = 0;
// 	arg->creation_time = getmili();
// 	while (i < arg->nbr_of_philo)
// 	{
// 		p = &arg->philo[i];
// 		p->arg = arg;
// 		if (pthread_create(&(arg->philo[i].thread_id), NULL, core, p))
// 			return (0);
// 		pthread_create(&monitor, NULL, alive, p);
// 		pthread_detach(monitor);
// 		i++;
// 		usleep(100);
// 	}
// 	if (arg->nbr_meal >= 0)
// 	{
// 		pthread_create(&monitor, NULL, hungry, arg);
// 		pthread_detach(monitor);
// 	}
// 	return (1);
// }

// int	init_mutex(t_arg *arg)
// {
// 	int	i;

// 	i = 0;
// 	pthread_mutex_init(&arg->finish_lock, NULL);
// 	while (i < arg->nbr_of_philo)
// 	{
// 		if (pthread_mutex_init(arg->locks + i, NULL))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// void	join_thread(t_arg *arg)
// {
// 	int	i;

// 	i = 0;
// 	while (i < arg->nbr_of_philo)
// 		pthread_join(arg->philo[i++].thread_id, NULL);
// 	i = 0;
// 	while (i < arg->nbr_of_philo)
// 		pthread_mutex_destroy(&arg->locks[i++]);
// 	pthread_mutex_destroy(&arg->finish_lock);
// 	free(arg->philo);
// 	free(arg->locks);
// 	free(arg);
// }
