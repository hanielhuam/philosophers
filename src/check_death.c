/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 22:56:22 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/08 23:56:38 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo)
{
	int	result;

	result = 0;
	pthread_mutex_lock(&philo->table->dead_mutex);
	if (philo->table->any_one_died)
		result = 1;
	pthread_mutex_unlock(&philo->table->dead_mutex);
	return (result);
}
