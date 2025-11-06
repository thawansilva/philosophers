/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:09:12 by thaperei          #+#    #+#             */
/*   Updated: 2025/11/05 20:17:04 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data)
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

void	*waiter_routine(void *data)
{
	t_table	*philo;

	t_table = (t_table *)data;
	printf("waiter\n");
	// while !has_death && !are_philos_satisfied
	// if time_to_die > last_meal	
	//		change dead_flag to 1
	// if are_philos_satisfied
	// 		change dead_flag to 1
}

void	start_routine(t_table *table, pthread_mutex_t forks)
{
	int		i;
	t_philo	waiter;

	if (pthread_create(&th[i].thread, NULL, &waiter_routine, table) != 0)
		destroy_table("Error: Create waiter thread", table, forks);
	i = 0;
	while (i < table->philos[0].num_of_philos)
	{
		if (pthread_create(&th[i].thread, NULL, &routine, table->philos[i]) != 0)
			destroy_table("Error: Create philo thread", table, forks);
	}
	if (pthread_join(&th[i].thread, NULL) != 0)
		destroy_table("Error: Destroy waiter thread", table, forks);
	i = 0;
	while (i < table->philos[0].num_of_philos)
	{
		if (pthread_join(&th[i].thread, NULL) != 0)
			destroy_table("Error: Destroy philo thread", table, forks);
	}
}
