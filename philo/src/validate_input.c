/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:42:58 by thaperei          #+#    #+#             */
/*   Updated: 2025/11/09 14:46:07 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_valid_number(char *str)
{
	int	i;
	int	number;

	i = 0;
	number = ft_atol(str);
	if (number > INT_MAX || number <= 0)
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_amount_args(int argc)
{
	if (argc != 5 && argc != 6)
	{
		ft_putstr_fd("Not enough arguments\n", 2);
		return (0);
	}
	return (1);
}

int	is_valid_amount_philo(char *philo)
{
	int	i;

	if (!(ft_atol(philo) > 0 && ft_atol(philo) <= 200))
	{
		ft_putstr_fd("Invalid number of philosophers\n", 2);
		return (0);
	}
	i = 0;
	while (philo[i])
	{
		if (!(philo[i] >= '0' && philo[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_args(int argc, char **argv)
{
	int	i;

	if (!is_valid_amount_args(argc) || !is_valid_amount_philo(argv[1]))
		return (0);
	i = 2;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
		{
			ft_putstr_fd("Invalid number\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}
