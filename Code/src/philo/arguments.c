/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:57:35 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/03 19:57:08 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	ft_init_info(char **argv, t_info *info, t_philo *philosophers)
{
	int	i;

	i = 0;
	info->n_philosophers = ft_atoi(argv[1]);
	info->t_die = ft_atoi(argv[2]);
	info->t_eat = ft_atoi(argv[3]);
	info->t_sleep = ft_atoi(argv[4]);
	info->t_start = 0;
	if (argv[5]) //ver si así es correcto
		info->t_all_eat = ft_atoi(argv[5]);
	else
		info->t_all_eat = -1; // ver si esto es asi, sino poner numero negativo
	info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->n_philosophers);
	if (info->forks == NULL)
		return ; //PONER MENSAJE DE ERROR
	while (i < info->n_philosophers)
	{
		philosophers[i].info = info;
		i++;
	}
	ft_t_start_to_info(philosophers); // NOSE SI ESTA FUNCION ESTA BIEN
}

void	ft_init_philosophers(t_philo *philosophers)
{
	int	i;

	i = 0;
	while (i <= philosophers->info->n_philosophers - 1)
	{
		philosophers[i].id = i + 1;
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
