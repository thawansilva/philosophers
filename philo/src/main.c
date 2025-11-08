/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:23:05 by thaperei          #+#    #+#             */
/*   Updated: 2025/11/08 11:17:00 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_table(char *str, t_table *table, pthread_mutex_t *forks)
{
	int	i;

	if (str != NULL)
		ft_putstr_fd(str, 2);
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
		return (0);
	}
	init_table(&table, philos);
	init_forks(forks, ft_atol(argv[1]));
	init_philos(&table, philos, forks, argv);
	start_routines(&table, forks);
	destroy_table(NULL, &table, forks);
	return (0);
}
