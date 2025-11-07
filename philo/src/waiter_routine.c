/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thawan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:44:46 by thawan            #+#    #+#             */
/*   Updated: 2025/11/06 21:05:52 by thawan           ###   ########.fr       */
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

void	*waiter_routine(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	(void)table;
	printf("waiter\n");
	// while !has_death && !are_philos_satisfied
	// if time_to_die > last_meal	
	//		change dead_flag to 1
	// if are_philos_satisfied
	// 		change dead_flag to 1
	return (void *)0;
}

