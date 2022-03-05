#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

typedef struct timeval	t_time;
struct					arg;

typedef struct  philo
{
	int			id;
 	int			state;
	int			nb_of_meals;
	struct arg	*arg;
	long long	last_meal;
	pthread_t	thread_id;
}	t_phil;

typedef struct arg
{
	int				t_die;
	int				t_eat;
	int				finish;
	int				t_sleep;
	int				nbr_meal;
	int				nbr_of_philo;
	int				all_ate;
	long long		creation_time;
	t_phil			*philo;
	pthread_mutex_t	*locks;
	pthread_mutex_t	finish_lock;
}	t_arg;

void    *hungry(void *arg);
void    print_msg(t_phil *philo, char *msg);


/* <---------- initilazing functions-----------> */

void		print_error(char *str);
int			init_thread(t_arg *arg);
int			init_mutex(t_arg *arg);
int			ft_atoi(const char *str);
int			init_arg(t_arg *arg, int ac, char **av);
void		join_thread(t_arg *arg);

/* <-------- Core function -----------> */

void	*core(void *philo);

/* <-------- Activities functions -----------> */

void	take_a_fork(t_phil *philo, int id, char *hand);
void	eat(t_phil *philo);
void	sleep_and_think(t_phil *philo);

/* <--------- Utils functions ---------> */

int			ft_atoi(const char *nptr);
long long	getmili(void);
long long	current_time(t_phil *philo);

# endif
