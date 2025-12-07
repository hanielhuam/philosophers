/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 22:58:45 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/06 21:03:19 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_philo(t_table *table)
{
	int		i;
	t_philo	*philos;

	philos = malloc(sizeof(t_philo) * (table->philo_nbr + 1));
	if (!philos)
	{
		write(2, "Error when alloc t_philo\n", 26);
		return (1);
	}
	table->philos = philos;
	i = 0;
	while (i < table->philo_nbr)
	{
		philos[i].id = i;
		philos[i].table = table;
		config_philo(&philos[i], id, table);
	}
	return (0);
}

static init_forks(t_table *table)
{
	int		i;
	t_forks	forks;

	forks = malloc(sizeof(t_fork) * (table->philo_nbr + 1));
	if (!forks)
	{
		write(2, "Error when alloc t_fork\n", 25);
		return (1);
	}
	i = 0;
	while (forks[i])
		forks[i].id = i++;
	table->forks = forks;
	return (0);
}

int	init_table(int argc, char **argv, t_table *table)
{
	table->philo_nbr = ft_atoi(argv[1]);
	table->die_time = ft_atoi(argv[2]);
	table->eat_time = ft_atoi(argv[3]);
	table->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		table->satisfied_nbr = ft_atoi(argv[5]);
	else
		table->satisfied_nbr = 0;
	table->any_one_died = 0;
	table->philos = NULL;
	table->forks = NULL;
	if (init_forks(table) || init_philos(table))
	{
		clear_table(table);
		return (1);
	}
	return (0);
}
