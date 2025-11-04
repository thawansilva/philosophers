/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:23:34 by thaperei          #+#    #+#             */
/*   Updated: 2025/11/03 20:53:57 by thawan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	int				is_eating;
	int				meals_eaten;
	int				num_of_philos;
	int				amount_of_meals;
	int				*dead;
	size_t			start_meal;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_sleep;
	size_t			time_to_eat;
}	t_philo;

typedef struct s_table
{
	int				dead_flag;
	t_philo			*philos;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
}	t_table;

long	ft_atol(const char *nbr);
void	ft_putstr_fd(char *s, int fd);

// Validation
int		is_valid_args(int argc, char **argv);
#endif 
