/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:09:12 by thaperei          #+#    #+#             */
/*   Updated: 2025/11/09 15:17:05 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philosophers(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].num_of_philos)
	{
		if (pthread_create(&(philos[i].thread), NULL, &philo_routine,
				&philos[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	remove_philosophers(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].num_of_philos)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	start_routines(t_table *table)
{
	pthread_t	waiter;

	if (pthread_create(&waiter, NULL, &waiter_routine, table->philos) != 0)
		return (0);
	if (create_philosophers(table->philos) != 1)
		return (0);
	if (pthread_join(waiter, NULL) != 0)
		return (0);
	if (remove_philosophers(table->philos) != 1)
		return (0);
	return (1);
}
