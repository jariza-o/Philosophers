/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:42:32 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/04 20:09:22 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

long long	ft_get_time_ms(void)
{
	struct timeval	time; //estructura de la librería sys/time.h, devuelve el tiempo desde el EPOH en seg y micro seg

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long	ft_get_actual_time(t_philo *philosophers)
{
	return (ft_get_time_ms() - philosophers->info->t_start); //así cogería el del primer filosofo aunque como este dato en todos es igual no pasa nada 
}

long long	ft_t_start_to_info(t_philo *philo)
{
	return (ft_get_time_ms() * philo->info->n_philosophers * 20);  //Se añade este tiempo de inicio porque hay que tener en cuenta el tiempo que se tarda en crear los hilos
}
