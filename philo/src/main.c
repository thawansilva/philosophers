/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:23:05 by thaperei          #+#    #+#             */
/*   Updated: 2025/11/04 20:04:38 by thaperei         ###   ########.fr       */
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

void	destroy_table(t_table *table, pthread_mutex_t *forks)
{
	int	i;

	pthread_mutex_destroy(&table->write_lock);
	pthread_mutex_destroy(&table->dead_lock);
	pthread_mutex_destroy(&table->meal_lock);
	i = 0;
	while (i < table->philos[0].num_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_table			table;
	t_philo			philos[MAX_PHILO];
	pthread_mutex_t	forks[MAX_PHILO];

	if (!is_valid_args(argc, argv))
		return (1);
	if (ft_atol(argv[1]) == 1)
	{
		ft_putstr_fd("0 1 has taken a fork\n", 1);
		usleep(ft_atol(argv[2]) * 1000);
		ft_putstr_fd(argv[2], 1);
		ft_putstr_fd(" 1 died\n", 1);
	}
	init_table(&table, philos);
	init_forks(forks, ft_atol(argv[1]));
	init_philos(philos, &table);
	destroy_table(&table, forks);
	return (0);
}
