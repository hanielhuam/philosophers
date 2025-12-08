/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:17:59 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/08 17:27:06 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_has_died(t_philo *philo)
{
	int	result;

	result = 0;
	pthread_mutex_lock(&philo->table->is_eating_mutex);
	if (philo->table->last_meal + philo->table->eat_time < get_current_time() \
			&& !philo->is_eating)
		result = 1;
	pthread_mutex_unlock(&philo->table->is_eating_mutex);
	return (result);
}

static int	look_for_death(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		if (philo_has_died(&table->philos[i]))
		{
			pthread_mutex_lock(&table->dead_mutex);
			table->any_one_died = 1;
			pthread_mutex_unlock(&table->dead_mutex);
			print_mensage(DEAD, i, philo->start_time - get_current_time(), \
					&table->print_mutex);
			return (1);
		}
	}
	return (0);
}

static int	is_everybody_satisfied(t_table *table)
{
	int	i;

	if (!table->satisfied_nbr)
		return (0);
	i = 0;
	while (i < table->philo_nbr)
	{
		pthread_mutex_lock(&table->is_eating);
		if (table->philos[i].meals_had < table->satisfied_nbr)
		{
			pthread_mutex_unlock(&table->is_eating);
			return (0):
		}
		pthread_mutex_unlock(&table->is_eating);
	}
	return (1);
}

void	*monitor_action(void *content)
{
	t_table	*table;

	table = (t_table *)content;
	while (1)
	{
		if (look_for_death(table))
			break ;
		if (is_everybody_satisfied(table))
			break ;
		usleep(5);
	}
	return (NULL);
}
