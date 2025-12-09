/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:31:05 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/08 21:25:16 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(&philo->right_fork->mutex);
		print_mensage(FORK, philo->id, get_current_time() - philo->start_time, \
				&philo->table.print_mutex);
		pthread_nutex_lock(&philo->left_fork->mutex);
		print_mensage(FORK, philo->id, get_current_time() - philo->start_time, \
				&philo->table.print_mutex);
	}
	else
	{
		pthread_mutex_lock(&philo->left_fork->mutex);
		print_mensage(FORK, philo->id, get_current_time() - philo->start_time, \
				&philo->table.print_mutex);
		pthread_nutex_lock(&philo->right_fork->mutex);
		print_mensage(FORK, philo->id, get_current_time() - philo->start_time, \
				&philo->table.print_mutex);
	}
}

static void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->table.is_eating_mutex);
	philo->is_eating = 1;
	philo->last_meal = get_current_time();
	if (philo->table->satisfied_nbr)
		philo->meals_had++;
	pthread_mutex_unlock(&philo->table.is_eating_mutex);
	print_mensage(EAT, philo->id, get_current_time() - philo->start_time, \
			&philo->table->print_mutex);
	usleep(philo->table->eat_time * 1000);
	if (philo->id % 2)
	{
		pthread_mutex_unlock(&philo->right_fork->mutex);
		pthread_mutex_unlock(&philo->left_fork->mutex);
	}
	else
	{	
		pthread_mutex_unlock(&philo->left_fork->mutex);
		pthread_mutex_unlock(&philo->right_fork->mutex);
	}
}

void	*philo_action(void *content)
{
	t_philo	*philo;

	philo = (t_philo *)content;
	while (1)
	{
		take_forks(philo);
		eat(philo);
		if (philo->meals_had >= philo->table->satisfied_nbr)
			break ;
		//sleep
		//think
	}
	return (NULL);
}
