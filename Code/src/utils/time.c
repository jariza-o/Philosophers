/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:42:32 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/13 20:49:54 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

long long	ft_get_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long	ft_get_actual_time(t_philo *philosophers)
{
	long long	res;

	res = ft_get_time_ms() - philosophers->info->t_start;
	return (res);
}

long long	ft_t_start_to_info(t_philo *philo)
{
	return (ft_get_actual_time(philo) * philo->info->n_philosophers * 20);
}
