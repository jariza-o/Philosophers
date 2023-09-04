/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:57:35 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/04 19:51:16 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	ft_init_info(char **argv, t_info *info)
{
	int	i;

	i = 0;
	info->n_philosophers = ft_atoi(argv[1]);
	info->t_die = ft_atoi(argv[2]);
	info->t_eat = ft_atoi(argv[3]);
	info->t_sleep = ft_atoi(argv[4]);
	info->t_start = 0;
	if (argv[5])
		info->t_all_eat = ft_atoi(argv[5]);
	else
		info->t_all_eat = -1;
	info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->n_philosophers);
	if (info->forks == NULL)
		ft_errors(MALLOC_FAIL);
	info->is_dead = 0;
}

void	ft_init_philosophers(t_philo *philosophers, t_info *info)
{
	int	i;

	i = 0;
	while (i <= info->n_philosophers - 1)
	{
		philosophers[i].id = i + 1;
		philosophers[i].info = info; //Le paso la dirección de la tabla info y todos tienen lo mismo
		philosophers[i].last_eat = 0;
		if (info->t_all_eat == -1)
			philosophers[i].num_eat = -1;
		else
			philosophers[i].num_eat = 0;
		if (philosophers[i].id == philosophers[i].info->n_philosophers) // NOSE SI ASÏ SON ZUrDOS LOS PHILOSOPHOS
		{
			philosophers[i].left_fork = philosophers[i].info->forks[i];
			philosophers[i].right_fork = philosophers[i].info->forks[0];
		}
		else
		{
			philosophers[i].left_fork = philosophers[i].info->forks[i];
			philosophers[i].right_fork = philosophers[i].info->forks[i + 1];
		}
		i++;
	}
}