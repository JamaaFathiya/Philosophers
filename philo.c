#include "philo.h"

long long getmili(void)
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void  take_a_fork(int id, void *arg)
{
    printf("%li Philospher %i has taken a fork",getmili(), arg->philo->id);
    mutex_lock(arg->locks[id]);
}

void eat(void *arg)
{

    take_a_fork(arg->philo->id, arg);
    take_a_fork((arg->philo->id + 1) % arg->nbr_of_philo, arg);
    arg->philo->state = 1;
    printf("%li Philospher %i is eating",getmili(),  arg->philo->id);
    usleep(arg->t.eat);

}

void sleip(void *arg)
{
    printf("%li Philospher %i is sleeping",getmili(),  arg->philo->id);
    usleep(arg->t_sleep);
}
