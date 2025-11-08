/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:12:33 by thaperei          #+#    #+#             */
/*   Updated: 2025/11/07 19:57:57 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_input_argv(t_philo *philo, char **argv)
{
	philo->time_to_die = ft_atol(argv[2]);
	philo->time_to_sleep = ft_atol(argv[3]);
	philo->time_to_eat = ft_atol(argv[4]);
	if (argv[5])
		philo->amount_of_meals = ft_atol(argv[5]);
	else
		philo->amount_of_meals = -1;
}

void	init_philos(t_table *table, t_philo *philos, pthread_mutex_t *forks,
		char **argv)
{
	int	i;
	int	num_of_philos;

	i = 0;
	num_of_philos = ft_atol(argv[1]);
	while (i < num_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].num_of_philos = num_of_philos;
		philos[i].has_death = &table->has_death;
		philos[i].is_eating = 0;
		philos[i].start_time = get_current_time();
		philos[i].meals_eaten = 0;
		philos[i].write_lock = &table->write_lock;
		philos[i].dead_lock = &table->dead_lock;
		philos[i].meal_lock = &table->meal_lock;
		init_input_argv(&philos[i], argv);
		philos[i].l_fork = &forks[i];
		if (i == 0)
			philos[i].r_fork = &forks[philos[i].num_of_philos - 1];
		else
			philos[i].r_fork = &forks[i - 1];
		i++;
	}
}

void	init_table(t_table *table, t_philo *philos)
{
	table->has_death = 0;
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
