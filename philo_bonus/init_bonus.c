/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:18:56 by fathjami          #+#    #+#             */
/*   Updated: 2022/03/13 01:43:01 by fathjami         ###   ########.fr       */
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
	arg->id_table = malloc(arg->nbr_of_philo * sizeof(int));
	if (!arg->id_table)
		return (0);
	return (1);
}

/*0644
0 > no access to file
6 > read/write permisson for the user
4 > read only for the group and others
*/
int	init_sem(t_arg *arg)
{
	arg->available_forks = sem_open("sem", O_CREAT | O_EXCL, 0644,
			arg->nbr_of_philo);
	if (arg->available_forks == SEM_FAILED || sem_unlink("sem"))
	{
		printf("alloc error\n");
		return (0);
	}
	return (1);
}

void	init_philo(t_phil *philo, t_arg *arg)
{
	philo->arg = arg;
	philo->nb_of_meals = 0;
	philo->last_meal = arg->creation_time;
}
