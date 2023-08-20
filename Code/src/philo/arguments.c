/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:57:35 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/20 13:10:03 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	ft_argv_to_int(char **argv, t_philo *philo)
{
	philo->n_philo = ft_atoi(argv[1]);
	philo->t_die = ft_atoi(argv[2]);
	philo->t_sleep = ft_atoi(argv[4]);
	if (argv[5]) //ver si así es correcto
		philo->t_all_eat = ft_atoi(argv[5]);
}
