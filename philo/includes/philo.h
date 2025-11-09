/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:23:34 by thaperei          #+#    #+#             */
/*   Updated: 2025/11/09 16:12:43 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define MAX_PHILO 200

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
	int				*has_death;
	size_t			start_time;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_sleep;
	size_t			time_to_eat;
}	t_philo;

typedef struct s_table
{
	int				has_death;
	t_philo			*philos;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
}	t_table;

// Init table
void	init_table(t_table *table, t_philo *philos);
void	init_forks(pthread_mutex_t	*forks, int num_of_philos);
void	init_philos(t_table *table, t_philo *philos, pthread_mutex_t *forks,
			char **argv);

// routine functions
int		start_routines(t_table *table);
void	*philo_routine(void *data);
void	*waiter_routine(void *data);
void	print_message(char *str, t_philo *philo);
int		is_death(t_philo *philo);

// Free Table
void	destroy_table(char *str, t_table *table, pthread_mutex_t *forks);

// Validation
int		is_valid_args(int argc, char **argv);

// Utils
long	ft_atol(const char *nbr);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_usleep(size_t milliseconds);
size_t	get_current_time(void);
#endif 
