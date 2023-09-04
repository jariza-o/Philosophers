/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:07:29 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/04 20:11:58 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	one_philosopher(t_philo *philosophers)
{
	philosophers[0].info->t_start = ft_get_time_ms();
	ft_print_status(&philosophers[0], "FORK");
	while (ft_get_actual_time(philosophers) < philosophers->info->t_die);
	ft_print_status(&philosophers[0], "DIE");
}

// void	two_philosophers(t_philo *philosophers)
// {
// 	ft_t_start_to_info(philosophers);
// 	printf(" 1 BLOQUEA LOS TENEDORES (ESENTO)\n");
// 	ft_print_status(&philosophers[0], "FORK");
// 	while (ft_get_actual_time(philosophers) < philosophers->info->t_die && ft_get_actual_time(philosophers) < philosophers->info->t_eat);
// 	philosophers[0].num_eat += 1;
// 	ft_print_status(&philosophers[0], "SLEEP");
// 	printf(" 2 BLOQUEA TENEDORES\n");
// 	ft_print_status(&philosophers[1], "FORK");
// 	while (ft_get_actual_time(philosophers) < philosophers->info->t_die && ft_get_actual_time(philosophers) < philosophers->info->t_eat);
	
// }
