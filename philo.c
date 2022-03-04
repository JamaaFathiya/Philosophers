#include "philo.h"

long long getmili(void)
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
    //return (current_time.tv_sec * 100);
}

void  take_a_fork(t_phil *philo, int id, char *hand)
{
    pthread_mutex_lock(&(philo->arg->locks[id]));
    printf("%lli Philospher %i has taken a fork with his %s hand\n", getmili() ,philo->id + 1, hand);
}

void put_down(t_phil *philo, int id)
{
    pthread_mutex_unlock(&(philo->arg->locks[id]));
}

void eat(t_phil *philo)
{
    take_a_fork(philo, philo->id, "right");
    take_a_fork(philo, (philo->id + 1) % philo->arg->nbr_of_philo, "left");
    printf("%lli Philospher %i is eating\n",getmili(), philo->id + 1);
     usleep(philo->arg->t_eat * 1000);
    //sleep(1);
    put_down(philo,  philo->id);
    put_down(philo, (philo->id + 1) % philo->arg->nbr_of_philo);
    philo->state = 1;
}

void sleip(t_phil *philo)
{
   
    printf("%lli Philospher %i is sleeping\n",getmili(), philo->id + 1);
    usleep(philo->arg->t_sleep * 1000);
    //sleep(1);
}
