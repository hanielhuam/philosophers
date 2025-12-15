/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 23:20:16 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/15 15:21:27 by hmacedo-         ###   ########.fr       */
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

void	msleep(unsigned long time)
{
	unsigned long	start_time;

	if (time == 0l)
		return ;
	start_time = get_current_time();
	while (start_time + time > get_current_time())
		usleep(500);
}
