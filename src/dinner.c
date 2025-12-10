/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 23:00:35 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/07 17:26:19 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dinner(t_table *table)
{
	int	i;

	pthread_create(&table->monitor, NULL, &monitor_action, table);
	i = 0;
	while (i < table->philo_nbr)
	{
		pthread_create(&table->philos[i].philo, NULL, &philo_action, \
				&table->philos[i]);
		i++;
	}
	pthread_join(table->monitor, NULL);
	i = 0;
	while (i < table->philo_nbr)
		pthread_join(table->philos[i++].philo, NULL);
}
