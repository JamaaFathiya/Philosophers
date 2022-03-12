/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 04:16:51 by fathjami          #+#    #+#             */
/*   Updated: 2022/03/07 04:28:54 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

typedef struct timeval	t_time;
struct					s_arg;

typedef struct s_philo
{
	int				id;
	int				state;
	int				nb_of_meals;
	struct s_arg	*arg;
	long long		my_time_has_come;
	pthread_t		thread_id;
}	t_phil;

typedef struct s_arg
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

/* <---------- initilazing functions-----------> */

void		print_error(char *str);
void		join_thread(t_arg *arg);
int			init_mutex(t_arg *arg);
int			init_thread(t_arg *arg);
int			ft_atoi(const char *str);
int			init_arg(t_arg *arg, int ac, char **av);

/* <-------------- Core function --------------> */

void		*core(void *philo);

/* <--------- Activities functions ------------> */

void		eat(t_phil *philo);
void		sleep_and_think(t_phil *philo);
void		pickup_forks(t_phil *philo, int id);

/* <----------- Monitoring functions ----------> */

void		*alive(void *arg);
void		*hungry(void *arg);

/* <------------- Utils functions -------------> */

long long	getmili(void);
int			ft_atoi(const char *nptr);
long long	current_time(t_phil *philo);
void		print_msg(t_phil *philo, char *msg);

#endif
