/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:57:35 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/15 11:29:07 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	ft_init_inf_mutex(t_info *info)
{
	int	i;

	i = 0;
	info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* info->n_philosophers);
	if (info->forks == NULL)
		ft_errors(MALLOC_FAIL);
	while (i < info->n_philosophers)
	{
		if ((pthread_mutex_init(&info->forks[i], NULL) != 0))
			ft_errors(MUTEX_FAIL);
		i++;
	}
	info->mutex_info = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (info->mutex_info == NULL)
		ft_errors(MALLOC_FAIL);
	if ((pthread_mutex_init(info->mutex_info, NULL) != 0))
		ft_errors(MUTEX_FAIL);
	info->mutex_print = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (info->mutex_print == NULL)
		ft_errors(MALLOC_FAIL);
	if ((pthread_mutex_init(info->mutex_print, NULL) != 0))
		ft_errors(MUTEX_FAIL);
}

void	ft_init_info(char **argv, t_info *info)
{
	info->n_philosophers = ft_atoi(argv[1]);
	if (info->n_philosophers < 1 || info->n_philosophers > 200)
		ft_errors(PHILO_LIMIT);
	info->t_die = ft_atoi(argv[2]);
	info->t_eat = ft_atoi(argv[3]);
	info->t_sleep = ft_atoi(argv[4]);
	info->t_think = (info->t_die - (info->t_eat + info->t_sleep)) / 2;
	info->t_start = 0;
	if (argv[5])
		info->t_all_eat = ft_atoi(argv[5]);
	else
		info->t_all_eat = -1;
	info->is_dead = 0;
	info->is_eaten = 0;
	ft_init_inf_mutex(info);
}

void	ft_init_philo_mutex(t_philo *philo)
{
	philo->mutex_eat = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (philo->mutex_eat == NULL)
		ft_errors(MALLOC_FAIL);
	if (pthread_mutex_init(philo->mutex_eat, NULL) != 0)
		ft_errors(MUTEX_FAIL);
}

void	ft_init_philosophers(t_philo *philosophers, t_info *info)
{
	int	i;

	i = 0;
	while (i <= info->n_philosophers - 1)
	{
		philosophers[i].id = i + 1;
		philosophers[i].info = info;
		philosophers[i].last_eat = 0;
		ft_init_philo_mutex(&philosophers[i]);
		if (info->t_all_eat == -1)
			philosophers[i].num_eat = -1;
		else
			philosophers[i].num_eat = 0;
		if (philosophers[i].id == philosophers[i].info->n_philosophers)
		{
			philosophers[i].left_fork = &philosophers[i].info->forks[i];
			philosophers[i].right_fork = &philosophers[i].info->forks[0];
		}
		else
		{
			philosophers[i].left_fork = &philosophers[i].info->forks[i];
			philosophers[i].right_fork = &philosophers[i].info->forks[i + 1];
		}
		i++;
	}
}
