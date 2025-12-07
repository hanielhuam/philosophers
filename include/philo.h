/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:03:18 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/06 20:33:00 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_fork
{
	int				id;
	pthread_mutex_t mutex;
}					t_fork;

typedef struct s_philo
{
	int				id;
	long			start_time;
	long			last_meal;
	int				meals_had;
	struct s_table	*table;
	pthread_t		philo;
	struct s_fork	*right_fork;
	struct s_fork	*left_fork;
}					t_philo;

typedef struct s_table
{
	pthread_t		monitor;
	struct t_philo	*philos;
	struct t_fork	*forks;
	int				philo_nbr;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				satisfied_nbr;
	int				any_one_died;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	dead_mutex;
}					t_table;

int 	validate_args(int argc, char **argv);
int		init_table(int argc, char **argv, t_table *table);
void	dinner(t_table *table);
int		ft_isdigit(char c);
int		ft_atoi(char *str);
void	config_philo(t_philo *philo, int id, t_table *table);
long	get_current_time(void);
void    del_table(t_table *table);

#endif
