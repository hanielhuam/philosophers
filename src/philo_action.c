/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:31:05 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/07 18:10:07 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_action(void *content)
{
	t_philo	*philo;

	philo = (t_philo *)content;
	if (pthread_mutex_lock(&philo->table->print_mutex))
		write(1, "impossible_lock\n", 16);
	printf("This is philo %d and start now\n", philo->id);
	if (pthread_mutex_unlock(&philo->table->print_mutex))
		write(1, "impossible_unlock\n", 18);
	usleep(1000000);
	return (NULL);
}
