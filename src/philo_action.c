/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:31:05 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/09 20:56:51 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	take_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		if (take_a_fork(philo, philo->right_fork))
			return (1);
		if (take_a_fork(philo, philo->left_fork))
		{
			pthread_mutex_unlock(&philo->right_fork->mutex);
			return (1);
		}
	}
	else
	{
		if (take_a_fork(philo, philo->left_fork))
			return (1);
		if (take_a_fork(philo, philo->right_fork))
		{
			pthread_mutex_unlock(&philo->left_fork->mutex);
			return (1);
		}
	}
	return (0);
}

static int	eat(t_philo *philo)
{
	if (check_death(philo))
	{
		unlock_forks(philo);
		return (1);
	}
	pthread_mutex_lock(&philo->table->is_eating_mutex);
	philo->is_eating = 1;
	philo->last_meal = get_current_time();
	if (philo->table->satisfied_nbr)
		philo->meals_had++;
	pthread_mutex_unlock(&philo->table->is_eating_mutex);
	print_mensage(EAT, philo->id, get_current_time() - philo->start_time, \
			&philo->table->print_mutex);
	usleep(philo->table->eat_time * 1000);
	pthread_mutex_lock(&philo->table->is_eating_mutex);
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->table->is_eating_mutex);
	unlock_forks(philo);
	return (0);
}

static int	sleep_and_think(t_philo *philo)
{
	if (check_death(philo))
		return (1);
	print_mensage(SLEEP, philo->id, get_current_time() - philo->start_time, \
			&philo->table->print_mutex);
	usleep(philo->table->sleep_time);
	if (check_death(philo))
		return (1);
	print_mensage(THINK, philo->id, get_current_time() - philo->start_time, \
			&philo->table->print_mutex);
	return (0);
}

void	*philo_action(void *content)
{
	t_philo	*philo;

	philo = (t_philo *)content;
	if (philo->id % 2)
		usleep(500);
	while (1)
	{
		if (take_forks(philo) || eat(philo))
			break ;
		if (philo->meals_had >= philo->table->satisfied_nbr)
			break ;
		if (sleep_and_think(philo))
			break ;
	}
	return (NULL);
}
