/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 19:55:42 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/06 20:31:44 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	del_table(t_table *table)
{
	if (table->forks)
		free(table->forks);
	if (table->philos)
		free(table->philos);
	free(table);
}
