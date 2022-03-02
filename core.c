#include "philo.h"

void *core(void *arg)
{
    t_phil *philo;

    philo = (t_phil *)arg;
    printf("hi i am the philosopher %d\n", philo->id);
   /* while(1)
    {
        if(arg->philo[id]->state == 0)
            eat(arg);
        else if (arg->philo[id]->atate == 1)
        {
            arg->philo->state = 2;
            sleip(arg);
        }
        else if(arg->philo[id]->state == 2)
        {
            arg->philo[id]->state = 0;
            printf("%li Philospher %i is thinking",getmili(),
                    arg->philo[id]->id);
        }
    }*/
    return (NULL);
}
