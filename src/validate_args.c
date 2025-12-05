/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:39:46 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/04 23:26:30 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

static int is_valid_number(char *str)
{
	char	*init;

	if (!str || !*str)
		return (0);
	init = str;
	while (*init)
	{
		if (!ft_isdigit(*init++))
			return (0);
	}
	if (ft_atoi(str) > 0)
		return (1);
	return (1);
}

int	validate_args(int argc, char **args)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(args[i]))
		{
			write(2, "number not aceptable\n", 21);
			return (1);
		}
	}
	return (0);
}
