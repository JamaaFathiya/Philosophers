/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 04:16:51 by fathjami          #+#    #+#             */
/*   Updated: 2022/03/09 18:09:30 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <semaphore.h>

typedef struct timeval	t_time;
struct					s_arg;

typedef struct s_philo
{
	int				id;
	int				nb_of_meals;
	struct s_arg	*arg;
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
	int				*id_table;
	sem_t			available_f;
	long long		creation_time;
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

void		core(t_arg *arg);

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
