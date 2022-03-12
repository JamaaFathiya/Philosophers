#include "philo_bonus.h"

void	*alive(void *arg)
{
	t_phil	*philo;

	philo = arg;
	while (!philo->my_time_has_come)
	{
		if (philo->last_meal + philo->arg->t_die <= current_time(philo))
		{
			print_msg(philo, "died");
			philo->my_time_has_come = 1;
			exit (1);
		}
		usleep(1000);
	}
	return (NULL);
}