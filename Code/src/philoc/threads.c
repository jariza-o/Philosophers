/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:19:31 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/14 21:00:55 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	ft_threads(t_philo *philosophers)
{
	int			i;
	pthread_t	*person;

	person = (pthread_t *)malloc(sizeof(pthread_t) \
	* philosophers->info->n_philosophers);
	if (person == NULL)
		ft_errors(MALLOC_FAIL);
	i = 0;
	philosophers->info->t_start = ft_get_actual_time(philosophers) \
	+ philosophers->info->n_philosophers * 20;
	while (i < philosophers->info->n_philosophers)
	{
		if ((pthread_create(&person[i], NULL, ft_thread_routine, \
		&philosophers[i])) != 0)
			ft_errors(THREAD_FAIL);
		i++;
	}
	philosophers->person = person;
}

int	ft_stop(t_philo *philosophers)
{
	pthread_mutex_lock(philosophers->info->mutex_info);
	//printf("%s IS DEAD: %d%s\n", PRINT, philosophers->info->is_dead, END);
	if (philosophers->info->is_dead == 1 || philosophers->info->is_eaten \
	== philosophers->info->n_philosophers)
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

int	ft_is_dead(t_philo *philosophers)
{
	long long	t;

	pthread_mutex_lock(philosophers->info->mutex_info);
	pthread_mutex_lock(philosophers->mutex_eat);
	t = ft_get_actual_time(philosophers) - philosophers->last_eat;
	pthread_mutex_unlock(philosophers->mutex_eat);
	if (t > philosophers->info->t_die)
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

void	ft_loop(t_philo *philosophers)
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
	return ;
}
