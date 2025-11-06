/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:09:12 by thaperei          #+#    #+#             */
/*   Updated: 2025/11/05 22:19:52 by thawan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	printf("philo: %d\n", philo->id);
//	while (!philo->has_death)
//	{
//		eat(philo);
//		sleep(philo);
//		think(philo);
//	}
}

// refactor the function and develop routines
int	start_routine(t_table *table, pthread_mutex_t *forks)
{
	int		i;
	t_philo	waiter;

	if (pthread_create(&waiter.thread, NULL, &waiter_routine, table) != 0)
	{
		destroy_table("Error: Destroy waiter thread", table, forks);
		return (0);
	}
	i = 0;
	while (i < table->philos[0].num_of_philos)
	{
		if (pthread_create(&table->philos[i].thread, NULL, &routine, table->philos[i]) != 0)
		{
			destroy_table("Error: Destroy philo thread", table, forks);
			return (0);
		}
	}
	if (pthread_join(&waiter.thread, NULL) != 0)
	{
		destroy_table("Error: Destroy waiter thread", table, forks);
		return (0);
	}
	i = 0;
	while (i < table->philos[0].num_of_philos)
	{
		if (pthread_join(&table->philos[i].thread, NULL) != 0)
		{
			destroy_table("Error: Destroy philo thread", table, forks);
			return (0);
		}
	}
	return (1);
}
