/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:30:41 by fathjami          #+#    #+#             */
/*   Updated: 2022/03/12 16:33:14 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	core(t_arg *arg)
{
	int		i;
	int		ret;
	t_phil	*philo;

	i = 0;
	philo = malloc(arg->nbr_of_philo * sizeof(t_phil));
	if (!philo)
		return ;
	arg->creation_time = getmili();
	while (i < arg->nbr_of_philo)
	{
		init_philo(&philo[i], arg);
		ret = fork();
		if (ret == 0)
		{
			philo[i].id = i + 1;
			activities(&philo[i]);
		}
		else
			arg->id_table[i] = ret;
		i++;
		usleep(100);
	}
	free (philo);
}
