/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:19:31 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/05 19:33:25 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	ft_threads(t_philo *philosophers)
{
	int			i;
	pthread_t	*person;

	person = (pthread_t *)malloc(sizeof(pthread_t) * philosophers->info->n_philosophers);
	if (person == NULL)
		ft_errors(MALLOC_FAIL);
	i = 0;
	philosophers->info->t_start = ft_t_start_to_info(philosophers);
	while (i < philosophers->info->n_philosophers - 1)
	{
		if ((pthread_create(&person[i], NULL, &ft_thread_routine, &philosophers[i])) != 0) //Pasa la funcion ft_threads_routine, para que mientras se ejecuta el bucle infinito, en los demas hilos se ejecute esto simultaneamente
		{
			// Liberar memoria de info->forks y de philosophers (memoria reservada en main.c)
			ft_errors(THREAD_FAIL);
		}
		i++;
	}
}

void	ft_is_dead(t_philo *philosophers)
{
	
}

void	ft_loop(t_philo *philosophers) // Bucle infinito que comprueba si ha muerto algunos o se ha parado por algo
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < philosophers->info->n_philosophers)
		{
			if (!ft_is_dead(&philosopher[i]))
				break ;
			i++;
		}
		// if (FUNCION MUST STOP)
			// break ;
		usleep (100);
	}
}
