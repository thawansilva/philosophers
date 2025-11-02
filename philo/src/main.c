/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:23:05 by thaperei          #+#    #+#             */
/*   Updated: 2025/11/02 12:04:55 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Create table and philos
t_philo	*init_philos(t_table table, char **argv)
{
	t_philo	*philos;
	int	num_of_philos;
	int i;

	i = 0;
	num_of_philos = ft_atol(argv[1]);
	philos = (t_philo *) malloc(num_of_philos * sizeof(t_philo));
	(void)table;
	if (!philos)
		return (NULL);
	while (i < num_of_philos)
	{
		//table.philos[i] = create_philo();
		i++;
	}
	free(philos);
	return (NULL);
}

t_table	init_table(int argc, char **argv)
{
	t_table	table;

	(void)argv;
	(void)argc;
	table.dead_flag = 0;
	table.philos = init_philos(table, argv);
//	pthread_mutex_init(&table.write_lock, NULL);
//	pthread_mutex_init(&table.dead_lock, NULL);
//	pthread_mutex_init(&table.meal_lock, NULL);
	return (table);
}

int	main(int argc, char **argv)
{
	t_table	table;

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
	return (0);
}
