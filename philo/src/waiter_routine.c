/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thawan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:44:46 by thawan            #+#    #+#             */
/*   Updated: 2025/11/09 16:30:01 by thaperei         ###   ########.fr       */
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
	if (get_current_time() - philo->last_meal >= philo->time_to_die
		&& !philo->is_eating)
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
			pthread_mutex_lock(philos[0].dead_lock);
			*philos->has_death = 1;
			pthread_mutex_unlock(philos[0].dead_lock);
			return (0);
		}
		i++;
	}
	return (1);
}

int	are_philos_satisfied(t_philo *philos)
{
	int	i;
	int	are_satisfied;

	i = 0;
	are_satisfied = 1;
	if (philos[0].amount_of_meals == -1)
		return (0);
	while (i < philos[i].num_of_philos)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_eaten < philos[i].amount_of_meals)
			are_satisfied = 0;
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	if (are_satisfied)
	{
		pthread_mutex_lock(philos[0].dead_lock);
		*philos->has_death = 1;
		pthread_mutex_unlock(philos[0].dead_lock);
		return (1);
	}
	return (are_satisfied);
}

void	*waiter_routine(void *data)
{
	t_philo	*philos;

	philos = (t_philo *)data;
	while (1)
	{
		if (!are_philos_alive(philos) || are_philos_satisfied(philos))
			break ;
	}
	return (philos);
}
