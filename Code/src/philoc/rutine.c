/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:16:02 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/13 20:22:09 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	ft_take_forks(t_philo *philosophers)
{
	pthread_mutex_lock(philosophers->right_fork);
	if (!ft_stop(philosophers))
		return ;
	ft_print_status(philosophers, "FORK");
	if (!ft_stop(philosophers))
		return ;
	pthread_mutex_lock(philosophers->left_fork);
	if (!ft_stop(philosophers))
		return ;
	ft_print_status(philosophers, "FORK");
}

void	ft_eat(t_philo *philosophers)
{
	ft_take_forks(philosophers);
	if (!ft_stop(philosophers))
		return ;
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
		usleep(100);
	pthread_mutex_unlock(philosophers->left_fork);
	pthread_mutex_unlock(philosophers->right_fork);
}

void	ft_sleep(t_philo *philosophers)
{
	long long	t; // Porque es lon??

	ft_print_status(philosophers, "SLEEP");
	if (!ft_stop(philosophers))
		return ;
	t = ft_get_actual_time(philosophers);
	while (ft_stop(philosophers) && ft_get_actual_time(philosophers) < (t + philosophers->info->t_sleep))
		usleep(100);
}
void	ft_think(t_philo *philosophers)
{
	long long	t;

	if (!ft_stop(philosophers))
		return ;
	ft_print_status(philosophers, "THINK");
	t = ft_get_actual_time(philosophers);
	while (ft_stop(philosophers) && (ft_get_actual_time(philosophers) <  (t + philosophers->info->t_think)))
		usleep(100);
}

void	*ft_thread_routine(void *arg)
{
	t_philo	*philosophers;

	philosophers = (t_philo *)arg;
	if (philosophers->info->t_die == 0)
		return (NULL);
	while (ft_get_actual_time(philosophers) < 0)
	{
		pthread_mutex_lock(philosophers->mutex_eat);
		philosophers->last_eat = ft_get_actual_time(philosophers);
		pthread_mutex_unlock(philosophers->mutex_eat);
		usleep(20);
	}
	if (philosophers->id % 2 == 0)
		usleep(50);
	while (ft_stop(philosophers))
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
