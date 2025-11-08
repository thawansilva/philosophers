/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thawan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:11:27 by thawan            #+#    #+#             */
/*   Updated: 2025/11/08 10:56:22 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	print_message("is thinking", philo);
}

void	dream(t_philo *philo)
{
	print_message("is sleeping", philo);
	ft_usleep(philo->time_to_sleep);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_message("has taken a fork", philo);
	pthread_mutex_lock(philo->l_fork);
	print_message("has taken a fork", philo);
	philo->is_eating = 1;
	print_message("is eating", philo);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

int	is_death(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*(philo->has_death) == 1 && !philo->is_eating)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!is_death(philo))
	{
		eat(philo);
		dream(philo);
		think(philo);
	}
	return ((void *)0);
}
