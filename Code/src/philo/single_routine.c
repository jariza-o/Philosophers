/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:07:29 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/29 18:55:59 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	one_philosopher(t_philo *philo)
{
	printf ("Start Time: %lld\n", philo->t_start);
	printf ("The Philosopher take a fork. \n");
	while (ft_get_actual_time(philo) < philo->philosophers.t_die);
	ft_print_actual_time(philo);
	printf ("Philosopher die.\n");
}
