#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct args
{
	int	nbr_of_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	nbr_meal;
}	t_args;

# endif
