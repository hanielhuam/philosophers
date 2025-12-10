/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 20:15:43 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/09 20:57:36 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_mensage(char *str, int id, long time, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	printf(str, time, id);
	pthread_mutex_unlock(mutex);
}
