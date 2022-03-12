/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:35:23 by fathjami          #+#    #+#             */
/*   Updated: 2022/03/12 16:35:39 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_all(t_arg *arg)
{
	int	ret;
	int	i;

	i = -1;
	while (++i < arg->nbr_of_philo)
	{
		waitpid(-1, &ret, 0);
		if (ret != 0)
		{
			i = 0;
			while (i < arg->nbr_of_philo)
				kill(arg->id_table[i++], 15);
			break ;
		}
	}
	sem_close(arg->available_forks);
	free (arg->id_table);
	free (arg);
}
