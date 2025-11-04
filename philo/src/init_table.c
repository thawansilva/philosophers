/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:12:33 by thaperei          #+#    #+#             */
/*   Updated: 2025/11/04 20:15:26 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(t_table *table, t_philo *philos, pthread_mutex_t *forks,
		char **argv)
{
	int	i;
	int	num_of_philos;

	i = 0;
	(void)forks;
	// implement forks
	num_of_philos = ft_atol(argv[1]);
	while (i < num_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].num_of_philos = ft_atol(argv[1]);
		philos[i].time_to_die = ft_atol(argv[2]);
		philos[i].time_to_sleep = ft_atol(argv[3]);
		philos[i].time_to_eat = ft_atol(argv[4]);
		philos[i].dead = &table->dead_flag;
		philos[i].is_eating = 0;
		philos[i].meals_eaten = 0;
		philos[i].write_lock = &table->write_lock;
		philos[i].dead_lock = &table->dead_lock;
		philos[i].meal_lock = &table->meal_lock;
		if (argv[5])
			philos->amount_of_meals = ft_atol(argv[5]);
		i++;
	}
}

void	init_table(t_table *table, t_philo *philos)
{
	table->dead_flag = 0;
	table->philos = philos;
	pthread_mutex_init(&table->write_lock, NULL);
	pthread_mutex_init(&table->dead_lock, NULL);
	pthread_mutex_init(&table->meal_lock, NULL);
}

void	init_forks(pthread_mutex_t	*forks, int num_of_philos)
{
	int	i;

	i = 0;
	while (i < num_of_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}
