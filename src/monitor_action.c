/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:17:59 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/07 19:24:41 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_action(void *content)
{
	t_table	*table;

	table = (t_table *)content;
	(void)table;
	pthread_mutex_lock(&table->print_mutex);
	write(1, "O monitor apareceu\n", 19);
	pthread_mutex_unlock(&table->print_mutex);
	usleep(1000000);
	return (NULL);
}
