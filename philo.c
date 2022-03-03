#include "philo.h"

long long getmili(void)
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void  take_a_fork(t_phil *philo, int id)
{
    printf("%lli Philospher %i has taken a fork\n",getmili(), philo->id);
    pthread_mutex_lock(&(philo->arg->locks[id]));
}

void put_down(t_phil *philo, int id)
{
    pthread_mutex_unlock(&(philo->arg->locks[id]));
}

void eat(t_phil *philo)
{
    take_a_fork(philo, philo->id);
    take_a_fork(philo, (philo->id) % philo->arg->nbr_of_philo);
    printf("%lli Philospher %i is eating\n",getmili(), philo->id);
    sleep(1);
    usleep(philo->arg->t_eat);
    put_down(philo,  philo->id);
    put_down(philo, (philo->id) % philo->arg->nbr_of_philo);
    philo->state = 1;
}

void sleip(t_phil *philo)
{
   
    printf("%lli Philospher %i is sleeping\n",getmili(), philo->id);
    usleep(philo->arg->t_sleep);
}
