/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:42:32 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/01 15:48:27 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

long long	ft_get_time_ms(void)
{
	struct timeval	time; //estructura de la librería sys/time.h, devuelve el tiempo desde el EPOH en seg y micro seg

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_t_start_to_info(t_philo *philosopher)
{
	long long	time;
	int			i;

	time = ft_get_time_ms();
	i = 0;
	while (i < philosopher->info->n_philosophers)
	{
		philosopher[i].info->t_start = time;
		i++;
	}
}

long long	ft_get_actual_time(t_philo *philosophers)
{
	return (ft_get_time_ms() - philosophers->info->t_start); //así cogería el del primer filosofo aunque como este dato en todos es igual no pasa nada 
}
