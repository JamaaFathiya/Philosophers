/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:31:27 by fathjami          #+#    #+#             */
/*   Updated: 2022/03/05 18:35:47 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    print_msg(t_phil *philo, char *msg)
{
    pthread_mutex_lock(&philo->arg->finish_lock);
    if (!philo->arg->finish)
        printf("%lli\t%i\t%s\n", current_time(philo), philo->id + 1, msg);
    pthread_mutex_unlock(&philo->arg->finish_lock);
}

void    *hungry(void *args)
{
    t_arg  *arg;

    arg = args;
    while (!arg->finish)
    {
        pthread_mutex_lock(&arg->finish_lock);
        if (arg->all_ate == arg->nbr_of_philo)
        {
            printf("Full!\n");
            arg->finish = 1;
        }
        pthread_mutex_unlock(&arg->finish_lock);
    }
    return (NULL);
}

void *core(void *arg)
{
    t_phil *philo;

    philo = (t_phil *)arg;
    while(!philo->arg->finish)
    {
        eat(philo);
        sleep_and_think(philo);
    }
    return (NULL);
}
