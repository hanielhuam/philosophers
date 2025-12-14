/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:03:18 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/12 21:45:55 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define DEAD "%ld %d died\n"
# define THINK "%ld %d is thiking\n"
# define SLEEP "%ld %d is sleeping\n"
# define EAT "%ld %d is eating\n"
# define FORK "%ld %d has taken a fork\n"

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	mutex;
}					t_fork;

typedef struct s_philo
{
	int				id;
	unsigned long	start_time;
	unsigned long	last_meal;
	int				meals_had;
	int				is_eating;
	struct s_table	*table;
	pthread_t		philo;
	struct s_fork	*right_fork;
	struct s_fork	*left_fork;
}					t_philo;

typedef struct s_table
{
	pthread_t		monitor;
	struct s_philo	*philos;
	struct s_fork	*forks;
	int				philo_nbr;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				satisfied_nbr;
	int				any_one_died;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	is_eating_mutex;
}					t_table;

int				validate_args(int argc, char **argv);
int				init_table(int argc, char **argv, t_table *table);
void			dinner(t_table *table);
int				ft_isdigit(char c);
int				ft_atoi(char *str);
void			config_philo(t_philo *philo, int id, t_table *table);
unsigned long	get_current_time(void);
void			del_table(t_table *table);
void			*monitor_action(void *content);
void			*philo_action(void *content);
void			print_mensage(char *str, int id, long time, \
		pthread_mutex_t *mutex);
int				check_death(t_philo *philo);
int				take_a_fork(t_philo *philo, t_fork *fork);
void			unlock_forks(t_philo *philo);
void			precision_sleep(unsigned long time);

#endif
