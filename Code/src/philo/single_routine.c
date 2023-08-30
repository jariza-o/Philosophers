/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:07:29 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/30 20:36:27 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	one_philosopher(t_philo *philosophers)
{
	philosophers->info.t_start = ft_get_time_ms();
	printf ("Start Time: %lld\n", philosophers->info.t_start);
	printf ("[%lld] ", ft_get_actual_time(philosophers));
	printf ("The Philosopher take a fork. \n");
	while (ft_get_actual_time(philosophers) < philosophers->info.t_die);
	ft_print_actual_time(philosophers);
	printf ("Philosopher die.\n");
}
