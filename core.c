#include "philo.h"

void *core(void *arg)
{
    t_phil *philo;

    philo = (t_phil *)arg;
    while(1)
    {
        if(philo->state == 0)
            eat(philo);
        else if (philo->state == 1)
        {
            philo->state = 2;
            sleip(philo);
        }
        else if(philo->state == 2)
        {
            philo->state = 0;
            printf("%lli Philospher %i is thinking\n",getmili(),philo->id + 1);
        }
    }
    return (NULL);
}
