/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 22:46:04 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/06 23:22:29 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	config_philo(t_philo *philo, int id, t_table *table)
{
	philo->id = id;
	philo->table = table;
	philo->start_time = get_current_time();
	philo->last_meal = philo->start_time;
	philo->meals_had = 0;
	philo->is_eating = 0;
	philo->left_fork = &table->forks[id];
	if (id == table->philo_nbr)
		philo->right_fork = &table->forks[0];
	else
		philo->right_fork = &table->forks[id + 1];
}
