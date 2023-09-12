/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:19:31 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/12 20:33:07 by jariza-o         ###   ########.fr       */
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
	while (i < philosophers->info->n_philosophers)
	{
		if ((pthread_create(&person[i], NULL, &ft_thread_routine, &philosophers[i])) != 0) //Pasa la funcion ft_threads_routine, para que mientras se ejecuta el bucle infinito, en los demas hilos se ejecute esto simultaneamente
		{
			// Liberar memoria de info->forks y de philosophers (memoria reservada en main.c)
			ft_errors(THREAD_FAIL);
		}
		i++;
	}
}

int	ft_stop(t_philo *philosophers)
{
	pthread_mutex_lock(philosophers->info->mutex_info);
	if (philosophers->info->is_dead == 1 || philosophers->info->is_eaten == philosophers->info->n_philosophers)
	{
		pthread_mutex_unlock(philosophers->info->mutex_info);
		return (0);
	}
	else
	{
		pthread_mutex_unlock(philosophers->info->mutex_info);
		return (1);
	}
}

/* Comprueba que el philosofo no está muerto*/
int	ft_is_dead(t_philo *philosophers)
{
	long long	t;

	pthread_mutex_lock(philosophers->info->mutex_info);
	pthread_mutex_lock(philosophers->mutex_eat); // Se bloquea para que mientras esta consultando nadie lo cambie, y así evitar si debería estar muerto que cambia el last_eat mientras hace la comprobación
	t = ft_get_actual_time(philosophers) - philosophers->last_eat; // Como la funcion de obtener el tiempo solo hace leer info y siempre va a leer un dato que nadie le escribe, puede realizarlo aunque este bloqueado info con el mutex
	pthread_mutex_unlock(philosophers->mutex_eat);
	if (t >= philosophers->info->t_die)
	{
		ft_print_status(philosophers, "DIE");
		philosophers->info->is_dead = 1;
		pthread_mutex_unlock(philosophers->info->mutex_info);
		return (0);
	}
	else
	{
		pthread_mutex_unlock(philosophers->info->mutex_info);
		return (1);
	}
}

void	ft_loop(t_philo *philosophers) // Bucle infinito que comprueba si ha muerto algunos o se ha parado por algo
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < philosophers->info->n_philosophers)
		{
			if (!ft_is_dead(&philosophers[i]))
				break ;
			i++;
		}
		if (!ft_stop(philosophers))
			break ;
		usleep (100);
	}
	// return ;
}
