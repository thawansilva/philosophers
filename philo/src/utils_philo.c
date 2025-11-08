/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:49:53 by thaperei          #+#    #+#             */
/*   Updated: 2025/11/08 10:50:18 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isspace(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

long	ft_atol(const char *nbr)
{
	long	sign;
	long	result;

	result = 0;
	sign = 1;
	while (ft_isspace(*nbr))
		nbr++;
	if (*nbr == '-' || *nbr == '+')
	{
		if (*nbr++ == '-')
			sign *= -1;
	}
	while (*nbr >= '0' && *nbr <= '9')
		result = result * 10 + (*nbr++ - '0');
	return (result * sign);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (fd < 0)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) < 0)
		ft_putstr_fd("Error: gettimeofday()\n", 2);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

size_t	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}
