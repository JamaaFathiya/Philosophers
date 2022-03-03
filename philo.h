#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

struct arg;

typedef struct  philo
{ 	int state;
	int id;
	pthread_t thread_id;
	struct arg *arg;
}	t_phil;

typedef struct arg
{
	int	nbr_of_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	nbr_meal;
	pthread_mutex_t *locks;
	t_phil *philo;
}	t_arg;


long long	getmili(void);

/* <---------- initilazing functions-----------> */

void			print_error(char *str);
int			init_thread(t_arg *arg);
int			init_mutex(t_arg *arg);
int			ft_atoi(const char *str);
int			init_arg(t_arg *arg, int ac, char **av);
void		join_thread(t_arg *arg);

/* <-------- Core function -----------> */
void	*core(void *philo);
void	take_a_fork(t_phil *philo, int id);
void	eat(t_phil *philo);
void	sleip(t_phil *philo);
# endif
