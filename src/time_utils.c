/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 23:20:16 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/12 18:37:20 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_current_time(void)
{
	struct timeval	time;
	unsigned long	time_ms;

	time_ms = 0l;
	gettimeofday(&time, NULL);
	time_ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (time_ms);
}

void	precision_sleep(unsigned long time)
{
	struct timeval	spected_time;
	struct timeval	current_time;

	if (time == 0l)
		return ;
	gettimeofday(&current_time, NULL);
	spected_time.tv_sec = current_time.tv_sec + time / 1000000;
	spected_time.tv_usec = current_time.tv_usec + time % 1000000;
	while (spected_time.tv_sec >= current_time.tv_sec && \
			spected_time.tv_usec > current_time.tv_usec)
		gettimeofday(&current_time, NULL);
}
