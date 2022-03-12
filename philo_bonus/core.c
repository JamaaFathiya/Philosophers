#include "philo_bonus.h"

void    core(t_arg *arg)
{
    int         i;
    int         ret;
    t_phil      *philo;

    i = 0;
    philo = malloc(arg->nbr_of_philo * sizeof(t_phil));
    if (!philo)
        return;
    arg->creation_time = getmili();
    while (i < arg->nbr_of_philo)
    {
        philo[i].arg = arg;
        philo[i].nb_of_meals = 0;
        philo[i].last_meal = arg->creation_time;
        philo[i].my_time_has_come = 0;
        pthread_mutex_init(&philo[i].finish_lock, NULL);
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