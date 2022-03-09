#include "philo_bonus.h"

void    test(t_phil *philo)
{
    printf("I am the philosopher with ID : %i\n", philo->id);
    exit (0);
}

void    core(t_arg *arg)
{
    t_phil *philo;
    int     i;
    int     ret;

    philo = malloc(arg->nbr_of_philo * sizeof(t_phil));
    if (!philo)
        return;
    philo->arg = arg;
    i = 0;
    while (i < arg->nbr_of_philo)
    {
        ret = fork();
        if (ret == 0)
        {
            philo[i].id = i + 1;
            test(&philo[i]);
        }
        else
            arg->id_table[i] = ret;
        i++;
    }

    waitpid(-1, &ret, 0);
    printf("ret = %i\n", ret);
    printf ("-------- ID table -----------\n");
    for (int i = 0 ; i < arg->nbr_of_philo; i++)
    {
        printf("      pid %i: %i\n", i, arg->id_table[i]);
    }
}
// 101001010100101010