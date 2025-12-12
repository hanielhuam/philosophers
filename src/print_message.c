/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 20:15:43 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/12 16:58:54 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_mensage(char *str, int id, long time, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	printf(str, time, id);
	pthread_mutex_unlock(mutex);
}

void	print_mensage_fork(char *str, int id, long time, \
		pthread_mutex_t *mutex, int fork_id)
{
	pthread_mutex_lock(mutex);
	printf(str, time, id);
	printf(" %d \n", fork_id);
	pthread_mutex_unlock(mutex);
}
