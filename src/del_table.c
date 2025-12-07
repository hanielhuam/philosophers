/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 19:55:42 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/06 23:27:13 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	del_table(t_table *table)
{
	int	i;

	i = 0;
	if (table->forks)
	{
		while (i < table->philo_nbr)
			pthread_mutex_destroy(&table->forks[i++].mutex);
		free(table->forks);
	}
	if (table->philos)
		free(table->philos);
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->dead_mutex);
	free(table);
}
