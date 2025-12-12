/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 23:57:43 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/12 15:41:44 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_a_fork(t_philo *philo, t_fork *fork)
{
	if (check_death(philo))
		return (1);
	pthread_mutex_lock(&fork->mutex);
	if (check_death(philo))
	{
		pthread_mutex_unlock(&fork->mutex);
		return (1);
	}
	print_mensage(FORK, philo->id, get_current_time() - philo->start_time, \
			&philo->table->print_mutex);
	return (0);
}

void	unlock_forks(t_philo *philo)
{
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
