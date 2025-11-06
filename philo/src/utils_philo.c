/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:49:53 by thaperei          #+#    #+#             */
/*   Updated: 2025/11/05 21:55:03 by thawan           ###   ########.fr       */
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
