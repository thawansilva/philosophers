/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:09:12 by thaperei          #+#    #+#             */
/*   Updated: 2025/11/08 11:15:36 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_routines(t_table *table, pthread_mutex_t *forks)
{
	pthread_t	waiter;
	int		i;

	if (pthread_create(&waiter, NULL, &waiter_routine, table->philos) != 0)
	{
		destroy_table("Error: Create waiter thread", table, forks);
		return (0);
	}
	i = 0;
	while (i < table->philos[0].num_of_philos)
	{
		if (pthread_create(&(table->philos[i].thread), NULL, &philo_routine,
				&table->philos[i]) != 0)
		{
			destroy_table("Error: Create philo thread", table, forks);
			return (0);
		}
		i++;
	}
	if (pthread_join(waiter, NULL) != 0)
	{
		destroy_table("Error: Destroy waiter thread", table, forks);
		return (0);
	}
	i = 0;
	while (i < table->philos[0].num_of_philos)
	{
		if (pthread_join(table->philos[i].thread, NULL) != 0)
		{
			destroy_table("Error: Destroy philo thread", table, forks);
			return (0);
		}
		i++;
	}
	return (1);
}
