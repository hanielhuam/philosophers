/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:04:11 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/04 23:26:47 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, cher **argv)
{
	t_table	*table;

	if (argc < 5 || argc > 6)
		return (1);
	table = malloc(sizeof(t_table));
	if (!table || validate_args(argc, args) || init_table(argc, argv, table))
		return (1);
	dinner(table);
	return (0);
}
