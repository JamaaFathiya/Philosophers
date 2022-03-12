/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 04:16:51 by fathjami          #+#    #+#             */
/*   Updated: 2022/03/12 14:45:28 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <signal.h>
# include <sys/time.h>
# include <sys/types.h>
# include <semaphore.h>

typedef struct timeval	t_time;
struct					s_arg;

typedef struct s_philo
{
	int				id;
	int				nb_of_meals;
	int				my_time_has_come;
	long long		last_meal;
	pthread_mutex_t	finish_lock;
	struct s_arg	*arg;
}	t_phil;

typedef struct s_arg
{
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nbr_meal;
	int				nbr_of_philo;
	int				*id_table;
	sem_t			*available_forks;
	long long		creation_time;

}	t_arg;

/* <---------- initilazing functions-----------> */

int			init_arg(t_arg *arg, int ac, char **av);
int			init_sem(t_arg *arg);

/* <-------------- Core functions --------------> */

void		core(t_arg *arg);
void		activities(t_phil *philo);

/* <--------- Activities functions ------------> */

void		eat(t_phil *philo);
void		sleep_and_think(t_phil *philo);
void		pickup_forks(t_phil *philo, int id);

/* <----------- Monitoring functions ----------> */
void		*alive(void *arg);

/* <------------- Utils functions -------------> */

long long	getmili(void);
int			ft_atoi(const char *nptr);
long long	current_time(t_phil *philo);
void		print_msg(t_phil *philo, char *msg);
void		print_error(char *str);


void		free_all(t_arg *arg);
#endif
