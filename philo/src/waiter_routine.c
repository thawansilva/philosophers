/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thawan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:44:46 by thawan            #+#    #+#             */
/*   Updated: 2025/11/07 22:18:38 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(char *str, t_philo *philo)
{
	int	current_time;

	pthread_mutex_lock(philo->write_lock);
	current_time = get_current_time() - philo->start_time;
	if (!philo->has_death)
		printf("%d %d %s\n", current_time, philo->id, str);
	pthread_mutex_unlock(philo->write_lock);
}

int	are_philos_alive(t_table *table)
{
	int	i;
	size_t	last_meal;

	i = 0;
	while (i < table->philos[0].num_of_philos)
	{
		last_meal = table->philos[i].last_meal;
		if (get_current_time() - last_meal > table->philos[i].time_to_die)
		{
			print_message("dead", &table->philos[i]);
			pthread_mutex_lock(&table->dead_lock);
			table->has_death = 1;
			pthread_mutex_unlock(&table->dead_lock);
			return (0);
		}
	}
	return (1);
}

void	*waiter_routine(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	printf("waiter\n");
	while (1)
	{
		if (!are_philos_alive(table))
			break ;
//		if (are_philos_satisfied(table))
//			break ;
	}
//	 while !has_death && !are_philos_satisfied
//	 if time_to_die > last_meal	
//			change dead_flag to 1
//	 if are_philos_satisfied
//	 		change dead_flag to 1
	return (void *)0;
}

