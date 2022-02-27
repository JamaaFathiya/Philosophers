#include "philo.h"


void    create_thread(pthread *philo, int n, \
                    void * (*core)(void *), void *arg)
{
    int i;

    i = 0;
    while(i < n)
        pthread_create(philo[i++], NULL, core, arg);
}

int main(int ac, char **av)
{
    t_args *args;
    p_thread *philo;

    args = malloc(sizeof(t_args));
    memset(args, 0);
    memset(philo, 0);
    if (ac > 4)
    {
        args->nbr_of_philo = atoi(av[1]);
        args->t_die = atoi(av[2]);
        args->t_eat = atoi(av[3]);
        args->t_sleep = atoi(av[4]);
        if (ac == 6)
            args->nbr_meal=atoi(av[5]);
    }
    philo = malloc(args->nbr_of_philo * sizeof(p_thread));
    if (!philo)
        return (NULL);
    create_thread(philo, args->nbr_of_philo);
}
