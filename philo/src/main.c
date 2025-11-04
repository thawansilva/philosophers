/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:23:05 by thaperei          #+#    #+#             */
/*   Updated: 2025/11/03 21:32:58 by thawan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	create_philo(t_table *table, char **argv, int id)
{
	t_philo	philosopher;

	philosopher.id = id + 1;
	philosopher.num_of_philos = ft_atol(argv[1]);
	philosopher.time_to_die = ft_atol(argv[2]);
	philosopher.time_to_sleep = ft_atol(argv[3]);
	philosopher.time_to_eat = ft_atol(argv[4]);
	philosopher.dead = &table->dead_flag;
	philosopher.is_eating = 0;
	philosopher.meals_eaten = 0;
	philosopher.write_lock = &table->write_lock;
	philosopher.dead_lock = &table->dead_lock;
	philosopher.meal_lock = &table->meal_lock;
	if (argv[5])
		philosopher.amount_of_meals = ft_atol(argv[5]);
	return (philosopher);
}

t_philo	*init_philos(t_table *table, char **argv)
{
	t_philo	*philos;
	int	num_of_philos;
	int i;

	i = 0;
	num_of_philos = ft_atol(argv[1]);
	philos = (t_philo *) malloc(num_of_philos * sizeof(t_philo));
	if (!philos)
		return (NULL);
	while (i < num_of_philos)
	{
		philos[i] = create_philo(table, argv, i);
		i++;
	}
	return (philos);
}

t_table	init_table(int argc, char **argv)
{
	t_table	table;

	(void)argc;
	table.dead_flag = 0;
	pthread_mutex_init(&table.write_lock, NULL);
	pthread_mutex_init(&table.dead_lock, NULL);
	pthread_mutex_init(&table.meal_lock, NULL);
	table.philos = init_philos(&table, argv);
	return (table);
}

void destroy_table(t_table *table)
{
	pthread_mutex_destroy(&table->write_lock);
	pthread_mutex_destroy(&table->dead_lock);
	pthread_mutex_destroy(&table->meal_lock);
	free(table->philos);
}

int	main(int argc, char **argv)
{
	t_table	table;
	// Init forks

	if (!is_valid_args(argc, argv))
		return (1);
	if (ft_atol(argv[1]) == 1)
	{
		ft_putstr_fd("0 1 has taken a fork\n", 1);
		usleep(ft_atol(argv[2]) * 1000);
		ft_putstr_fd(argv[2], 1);
		ft_putstr_fd(" 1 died\n", 1);
	}
	table = init_table(argc, argv);
	destroy_table(&table);
	return (0);
}
