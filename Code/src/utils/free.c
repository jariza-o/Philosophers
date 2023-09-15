/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 03:40:41 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/15 11:28:36 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	ft_free_forks(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_philosophers)
	{
		pthread_mutex_destroy(&info->forks[i]);
		i++;
	}
	free(info->forks);
}

void	ft_free(t_philo *philosophers, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_philosophers)
	{
		pthread_join(philosophers->person[i], NULL);
		pthread_mutex_destroy(philosophers[i].mutex_eat);
		free(philosophers[i].mutex_eat);
		i++;
	}
	ft_free_forks(info);
	pthread_mutex_destroy(info->mutex_info);
	pthread_mutex_destroy(info->mutex_print);
	free(philosophers->person);
	free(info->mutex_info);
	free(info->mutex_print);
	free(philosophers);
}
