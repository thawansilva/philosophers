/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thawan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:11:27 by thawan            #+#    #+#             */
/*   Updated: 2025/11/06 21:14:18 by thawan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	print_message("is thinking", philo);
}

void	sleep(t_philo *philo)
{
	print_message("is sleeping", philo);
	ft_usleep(philo->time_to_sleep);
}

void	eat(t_philo *philo)
{
	// Pega um garfo (lock)
	// pega outro garfo (lock)
	// lock meal
	// printa mensagem de meal
	// unlock meal
	// increase meal eaten
	// stop for time_to_eat time
	// unlock forks
}

void	*philo_routine(void *data)
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
	return (void *)0;
}

