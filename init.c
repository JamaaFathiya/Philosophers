/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:18:56 by fathjami          #+#    #+#             */
/*   Updated: 2022/03/04 10:04:51 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int init_arg(t_arg *arg, int ac, char **av)
{
    int i;
    
    i = 0;
    arg->nbr_of_philo = ft_atoi(av[1]);
    arg->t_die = ft_atoi(av[2]);
    arg->t_eat = ft_atoi(av[3]);
    arg->t_sleep = ft_atoi(av[4]);
    if (ac == 6)
        arg->nbr_meal = ft_atoi(av[5]);
    arg->philo = malloc(arg->nbr_of_philo * sizeof(t_phil));
    arg->locks = malloc(arg->nbr_of_philo * sizeof(pthread_mutex_t));
    if (!arg->philo || !arg->locks)
        return (0);
    while (i < arg->nbr_of_philo)
    {
        arg->philo[i].id = i;
        arg->philo[i].state = 0;
        i++;
    }
    return (1);
}

int init_thread(t_arg *arg)
{
    int i;

    i = 0;
    while (i < arg->nbr_of_philo)
    {
        t_phil *p;
        
        p = &arg->philo[i];
        p->arg = arg;
        if(pthread_create(&(arg->philo[i].thread_id), NULL, core, p))
            return (0);
            i++;
        usleep(100);
    }
    return (1);
}

int init_mutex(t_arg *arg)
{
    int i;

    i = 0;
    while (i < arg->nbr_of_philo)
    {
        if (pthread_mutex_init(arg->locks + i, NULL))
            return (0);
        i++;
    }
    return (1);
}

void    join_thread(t_arg *arg)
{
    int i;

    i = 0;
    while (i < arg->nbr_of_philo)
        pthread_join(arg->philo[i++].thread_id, NULL);
}