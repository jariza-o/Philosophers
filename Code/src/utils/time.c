/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:42:32 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/29 19:20:07 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

long long	ft_get_time_ms(void)
{
	struct timeval	time; //estructura de la librería sys/time.h, devuelve el tiempo desde el EPOH en seg y micro seg

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long	ft_get_actual_time(t_philo *philo)
{
	return (ft_get_time_ms() - philo->t_start);
}
