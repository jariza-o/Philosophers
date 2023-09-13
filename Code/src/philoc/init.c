/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:57:35 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/13 16:21:40 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	ft_init_info(char **argv, t_info *info)
{
	int	i;

	info->n_philosophers = ft_atoi(argv[1]);
	if (info->n_philosophers < 1 || info->n_philosophers > 200)
		ft_errors(PHILO_LIMIT);
	info->t_die = ft_atoi(argv[2]);
	info->t_eat = ft_atoi(argv[3]);
	info->t_sleep = ft_atoi(argv[4]);
	info->t_think = (info->t_die - (info->t_eat + info->t_sleep)) / 2; // PORQUE ES ASI??
	info->t_start = 0;
	if (argv[5])
		info->t_all_eat = ft_atoi(argv[5]);
	else
		info->t_all_eat = -1;
	info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->n_philosophers);
	if (info->forks == NULL)
		ft_errors(MALLOC_FAIL);
	i = 0;
	info->mutex_info = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (info->mutex_info == NULL)
		ft_errors(MALLOC_FAIL);
	if ((pthread_mutex_init(info->mutex_info, NULL) != 0))
	{
		//Liberar memoria de info->forks y de philosophers (memoria reservada en main.c)
		ft_errors(MUTEX_FAIL);
	}
	while (i < info->n_philosophers)
	{
		if ((pthread_mutex_init(&info->forks[i], NULL) != 0))
		{
			//Liberar memoria de info->forks y de philosophers (memoria reservada en main.c)
			ft_errors(MUTEX_FAIL);
		}
		i++;
	}
	info->is_dead = 0;
	info->is_eaten = 0; //NO SE SI PONER -1 CUANDO NO HAYA MAXIMO DE COMIDAS
	info->mutex_info = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (info->mutex_info == NULL)
		ft_errors(MALLOC_FAIL);
	if (pthread_mutex_init(info->mutex_info, NULL) != 0)
		{
			//Liberar memoria de info->forks y de philosophers (memoria reservada en main.c)
			ft_errors(MUTEX_FAIL);
		}
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
		philosophers[i].mutex_eat = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (philosophers[i].mutex_eat == NULL)
			ft_errors(MALLOC_FAIL);
		if (pthread_mutex_init(philosophers[i].mutex_eat, NULL) != 0)
			ft_errors(MUTEX_FAIL);
		if (info->t_all_eat == -1)
			philosophers[i].num_eat = -1;
		else
			philosophers[i].num_eat = 0;
	// NO SE HACE INIT A LOS MUTEX R_FORK Y L_FORK PORQUE COMO LOS IGUALO A MUTEX FORK YA ESTA INICIALIZADO
		if (philosophers[i].id == philosophers[i].info->n_philosophers) // NOSE SI ASÏ SON ZUrDOS LOS PHILOSOPHOS
		{
			philosophers[i].left_fork = &philosophers[i].info->forks[i];
			philosophers[i].right_fork = &philosophers[i].info->forks[0];
			// printf("philosophers[%i].left_fork: %p --> philosophers[%i].info->forks[%i]: %p\n", i, &philosophers[i].left_fork, i, i, &philosophers[i].info->forks[i]);
			// printf("philosophers[%i].right_fork: %p --> philosophers[%i].info->forks[0]: %p\n", i, &philosophers[i].right_fork, i, &philosophers[i].info->forks[0]);
		}
		else
		{
			philosophers[i].left_fork = &philosophers[i].info->forks[i];
			philosophers[i].right_fork = &philosophers[i].info->forks[i + 1];
			// printf("philosophers[%i].left_fork: %p --> philosophers[%i].info->forks[%i]: %p\n", i, &philosophers[i].left_fork, i, i, &philosophers[i].info->forks[i]);
			// printf("philosophers[%i].right_fork: %p --> philosophers[%i].info->forks[%i]: %p\n", i, &philosophers[i].right_fork, i, i + 1, &philosophers[i].info->forks[i + 1]);
		}
		i++;
	}
}
