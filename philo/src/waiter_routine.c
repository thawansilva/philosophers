/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thawan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:44:46 by thawan            #+#    #+#             */
/*   Updated: 2025/11/05 21:45:36 by thawan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

