/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:03:18 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/04 23:26:38 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthreads.h>
# include <sys/time.h>

typedef struct s_fork
{
	int id;
}			t_fork;

typedef struct s_philo
{
	int		id;
	t_table	*table;
	t_fork	*right_fork;
	t_fork	*left_fork;
}			t_philo;

typedef struct s_table
{
	t_philo	*philos;
	t_fork	*forks;
	int		philo_nbr;
	int		die_time;
	int		eat_time;
	int		sleep_time;
	int		satisfied_nbr;
	int		any_one_died;
}			t_table;

int 	validate_args(int argc, char **argv);
int		init_table(int argc, char argv**, t_table *table);
void	dinner(t_table *table);


#endif
