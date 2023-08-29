/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:57:35 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/29 19:12:06 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	ft_argv_to_info(char **argv, t_philo *philo)
{
	philo->philosophers.n_philosophers = ft_atoi(argv[1]);
	philo->philosophers.t_die = ft_atoi(argv[2]);
	philo->philosophers.t_eat = ft_atoi(argv[3]);
	philo->philosophers.t_sleep = ft_atoi(argv[4]);
	if (argv[5]) //ver si así es correcto
		philo->philosophers.t_all_eat = ft_atoi(argv[5]);
	else
		philo->philosophers.t_all_eat = -1; // ver si esto es asi, sino poner numero negativo
}
