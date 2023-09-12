/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:16:02 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/12 19:46:56 by jariza-o         ###   ########.fr       */
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
	pthread_mutex_lock(philosophers->mutex_eat);
	philosophers->last_eat = ft_get_actual_time(philosophers);
	pthread_mutex_unlock(philosophers->mutex_eat);
	philosophers->num_eat++;
	if (philosophers->num_eat == philosophers->info->t_all_eat)
	{
		pthread_mutex_lock(philosophers->info->mutex_info);
		philosophers->info->is_eaten++;
		pthread_mutex_unlock(philosophers->info->mutex_info);
	}
	while (ft_stop(philosophers) && (ft_get_actual_time(philosophers) < philosophers->last_eat + philosophers->info->t_eat))
		usleep(100); // Mientras pueda seguir comiendo (no ha muerto nadie o faltan por comer) y mientras no haya terminado de comer
	pthread_mutex_unlock(philosophers->left_fork);
	pthread_mutex_unlock(philosophers->right_fork);
	// return (NULL);  // ES OBLIGATORIO??
}

void	ft_sleep(t_philo *philosophers)
{
	long long	t; // Porque es lon??

	ft_print_status(philosophers, "SLEEP");
	t = ft_get_actual_time(philosophers);
	while (ft_stop(philosophers) && ft_get_actual_time(philosophers) < (t + philosophers->info->t_sleep)) // Mientras siga bien y el tiempo actual sea menos que cuadno empezo + el tiempo que duerme, sigue durmiendo
		usleep(100);
	// return (NULL);
}
void	ft_think(t_philo *philosophers)
{
	long long	t;

	ft_print_status(philosophers, "THINK");
	t = ft_get_actual_time(philosophers);
	while (ft_stop(philosophers) && (ft_get_actual_time(philosophers) <  (t + philosophers->info->t_think))) // MIentras todo vaya bien y el tiempo sea menor de el de pensar, piensa
		usleep(100);
	// return (NULL);
}

void	*ft_thread_routine(void *arg)
{
	t_philo	*philosophers;

	philosophers = (t_philo *)arg;
	if (philosophers->info->t_die == 0)
		return (NULL);
	while (ft_get_actual_time(philosophers) < 0) //Inicializa el dato de ultima vez que come para así si no come la primera vez a tiempo se pueda morir
	{
		pthread_mutex_lock(philosophers->mutex_eat);
		philosophers->last_eat = ft_get_actual_time(philosophers);
		pthread_mutex_unlock(philosophers->mutex_eat);
		usleep(20);
	}
	if (philosophers->id % 2 == 0)
		usleep(50); // PORQUE ESPERA 50ms??
	while (ft_stop(philosophers)) // Mientras siga vivo o no haya comido todas las veces, en infinito pruea a comer, dormir  y pensar, en ese orden ya que es como lo hacen
	{
		if (ft_stop(philosophers))
			ft_eat(philosophers);
		if (ft_stop(philosophers))
			ft_sleep(philosophers);
		if (ft_stop(philosophers))
			ft_think(philosophers);
	}
	return (NULL);
}
