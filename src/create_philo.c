/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 22:46:04 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/05 23:40:35 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*create_philo(int id, t_table *table)
{
	t_philo	philo;

	if (!(philo = malloc(sizeof(t_philo))))
	{
		write(2, "Error when alloc t_philo\n", 25);
		return (NULL);
	}
	philo->id = id;
	philo->table = table;
	
	return (philo);
}
