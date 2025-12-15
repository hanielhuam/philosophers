/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:04:11 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/13 20:40:12 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	if (argc < 5 || argc > 6)
		return (1);
	table = malloc(sizeof(t_table));
	if (!table || validate_args(argc, argv))
	{
		free(table);
		return (1);
	}
	if (init_table(argc, argv, table))
	{
		del_table(table);
		return (1);
	}
	dinner(table);
	del_table(table);
	return (0);
}
