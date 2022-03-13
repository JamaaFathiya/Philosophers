/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:31:27 by fathjami          #+#    #+#             */
/*   Updated: 2022/03/13 02:52:31 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*core(void *arg)
{
	t_phil	*philo;

	philo = (t_phil *)arg;
	while (!philo->arg->finish)
	{
		eat(philo);
		sleep_and_think(philo);
	}
	return (NULL);
}
