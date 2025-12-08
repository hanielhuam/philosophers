/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:17:59 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/07 23:21:50 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_has_died(t_philo philo)
{
	
}

static int	look_for_death(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		if (philo_has_died(table->philos[i]))
		{
			pthread_mutex_lock(&table->dead_mutex);
			
			pthread_mutex_unlock(&table->dead_mutex);
		}
	}
	return (0);
}

static int	is_everybody_satisfied(t_table *table)
{
	
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
