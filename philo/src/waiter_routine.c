/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thawan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:44:46 by thawan            #+#    #+#             */
/*   Updated: 2025/11/08 11:28:03 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(char *str, t_philo *philo)
{
	size_t	current_time;

	pthread_mutex_lock(philo->write_lock);
	current_time = get_current_time() - philo->start_time;
	if (!is_death(philo))
		printf("%zu %d %s\n", current_time, philo->id, str);
	pthread_mutex_unlock(philo->write_lock);
}

int	is_philo_alive(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_current_time() - philo->last_meal > philo->time_to_die)
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (0);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (1);
}

int	are_philos_alive(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].num_of_philos)
	{
		if (!is_philo_alive(&philos[i]))
		{
			print_message("dead", &philos[i]);
			pthread_mutex_lock(philos[i].dead_lock);
			*(philos[i].has_death) = 1;
			pthread_mutex_unlock(philos[i].dead_lock);
			return (0);
		}
		i++;
	}
	return (1);
}

void	*waiter_routine(void *data)
{
	t_philo	*philos;

	philos = (t_philo *)data;
	printf("waiter\n");
	while (1)
	{
		if (!are_philos_alive(philos))
			break ;
//		if (are_philos_satisfied(table))
//			break ;
	}
//	 while !has_death && !are_philos_satisfied
//	 if time_to_die > last_meal	
//			change dead_flag to 1
//	 if are_philos_satisfied
//	 		change dead_flag to 1
	return ((void *)0);
}
