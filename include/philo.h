/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:03:18 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/05 15:23:31 by hmacedo-         ###   ########.fr       */
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
	int id;
}		t_fork;

typedef struct s_philo
{
	int				id;
	struct s_table	*table;
	struct s_fork	*right_fork;
	struct s_fork	*left_fork;
}					t_philo;

typedef struct s_table
{
	struct t_philo	*philos;
	struct t_fork	*forks;
	int				philo_nbr;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				satisfied_nbr;
	int				any_one_died;
}					t_table;

int 	validate_args(int argc, char **argv);
int		init_table(int argc, char **argv, t_table *table);
void	dinner(t_table *table);
int		ft_isdigit(char c);
int		ft_atoi(char *str);

#endif
