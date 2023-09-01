/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:57:35 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/01 15:47:18 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	ft_argv_to_info(char **argv, t_info *info, t_philo *philosophers)
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
		return ;
	while (i < info->n_philosophers)
	{
		philosophers[i].info = info;
		i++;
	}
}
