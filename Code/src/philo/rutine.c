/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:16:02 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/06 19:44:28 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

/* Separa entre philosofos pares e impares, para coger el tenedor que no es suyo (CREO QU ES ASI) */
void	ft_take_forks(t_philo *philosophers)
{
	if (philosophers->id % 2 == 0)
	{
		pthread_mutex_lock(philosophers->right_fork);
		ft_print_status(philosophers, "FORK");
		if (!ft_stop(philosophers))
			return ;
		pthread_mutex_lock(philosophers->left_fork);
		ft_print_status(philosophers, "FORK");
	}
	else
	{
		pthread_mutex_lock(philosophers->left_fork);
		ft_print_status(philosophers, "FORK");
		if (!ft_stop(philosophers))
			return ;
		pthread_mutex_lock(philosophers->right_fork);
		ft_print_status(philosophers, "FORK");
	}
}
/* El philosofo coge los Tenedores, apunta cuando empieza a comer, si ha terminado de comer todas las veces que necesita pone que ha terminado, espera a que termine de comer (o si ha ocurrido algo) y suelta los tenedores */
void	ft_eat(t_philo *philosophers)
{
	ft_take_forks(philosophers);
	ft_print_status(philosophers, "EAT");
	// MUTEXT PHILOSOPHER->MUTEX_EAT PARA APUNTAR EL LAST_EAT
	philosophers->last_eat = ft_get_actual_time(philosophers);
	// UNLOCK DEL MUTEX
	philosophers->num_eat++;
	if (philosophers->num_eat == philosophers->info->t_all_eat)
	{
		pthread_mutex_lock(philosophers->info->mutex_info);
		philosophers->info->is_eaten++;
		pthread_mutex_unlock(philosophers->info->mutex_info);
	}
	while (ft_stop(philo->table) && (ft_current_time(philo->table) < philo->last_eat + philo->table->time_to_eat))
		usleep(100); // Mientras pueda seguir comiendo (no ha muerto nadie o faltan por comer) y mientras no haya terminado de comer
	pthread_mutex_unlock(philosophers->left_fork);
	pthread_mutex_unlock(philosophers->right_fork);
	return (NULL);  // ES OBLIGATORIO??
}

void	*ft_thread_routine(void *arg)
{
	t_philo	*philosophers;
	
	philosophers = (t_philo *)malloc(sizeof(t_philo));
	if (philosophers == NULL)
		ft_errors(MALLOC_FAIL);
}
