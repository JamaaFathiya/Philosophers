#include "philo.h"

void core(void *arg)
{
    while(1)
    {
        if(arg->philo->state == 0)
            eat(arg);
        else if (arg->philo->atate == 1)
        {
            arg->philo->state = 2;
            sleip(arg);
        }
        else if(arg->philo->state == 2)
            arg->philo->state = 0;
    }
}


void eat(void *arg)
{

    take_a_fork(arg->philo->id);
    take_a_fork((arg->philo->id + 1) % arg->nbr_of_philo);
    arg->philo->state = 1;
    usleep(arg->t.eat);

}



















void    create_thread(pthread_t *philo, void * (*core)(void *), void *arg)
{
    int i;

    i = 0;
    while(i < args->nbr_of_philo)
    {
        arg->philo->state = 0;
        arg->philo->id = i;
        pthread_create(&philo[i++], NULL, core, arg);
    }
}


void    join_thread(pthread *philo, int n, \
                    void * (*core)(void *), void *arg)
{
    int i;

    i = 0;
    while(i < args->nbr_of_philo)
        pthread_join(philo[i++], NULL);
}

void    mutex_init(pthread_mutex_t *locks)
{
    int i;

    i = 0;
    while(i < args->nbr_of_philo)
    {
        pthread_mutex_init(locks + i);
        i++;
    }
}

int main(int ac, char **av)
{
    t_args *args;
    pthread_t *philo;
    pthread_mutex_t *locks;

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
    philo = malloc(args->nbr_of_philo * sizeof(pthread_t));
    if (!philo)
        return (NULL);
    locks = malloc(args->nbr_of_philo * sizeof(pthread_mutex_t);
            if (!locks)
            return (NULL);
    create_thread(philo ,core ,args);
    join_thread(philo, args);
    mutex_init(locks, args);
}
