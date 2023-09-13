/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:01:03 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/13 18:02:01 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	ft_print_actual_time(t_philo *philosophers)
{
	printf("Time: %lld ", ft_get_actual_time(philosophers));
}

void	ft_printf_info(t_philo *philosophers)
{
	// int	i;

	// i = 0;
	// printf("%sn_philo: %d\n", PRINT, philosophers->info->n_philosophers);
	// printf("t_die: %d\n", philosophers->info->t_die);
	// printf("t_eat: %d\n", philosophers->info->t_eat);
	// printf("t_sleep: %d\n", philosophers->info->t_sleep);
	// printf("t_think: %d\n", philosophers->info->t_think);
	// printf("t_all_eat: %d\n", philosophers->info->t_all_eat);
	// printf("t_start: %lld\n", philosophers->info->t_start);
	// printf("IMPRIMIR FORKS\n");
	// printf("is_dead: %d\n", philosophers->info->is_dead);
	// printf("is_eaten: %d\n", philosophers->info->is_eaten);
	// printf("IMPRIMIR MUTEX INFO%s\n", END);

	printf("%s T ACTUAL: %lld%s\n", PRINT, ft_get_actual_time(philosophers), END);
}

void	ft_print_status(t_philo *philosophers, char *status)
{
	if (!ft_strcmp(status, "FORK"))
		printf("%s[%lld] %d has taken a fork%s\n", YELLOW, ft_get_actual_time(philosophers), philosophers->id,END);
	else if (!ft_strcmp(status, "EAT"))
		printf("%s[%lld] %d is eating%s\n", BLUE, ft_get_actual_time(philosophers), philosophers->id,END);
	else if (!ft_strcmp(status, "SLEEP"))
		printf("%s[%lld] %d is sleeping%s\n", PURPLE, ft_get_actual_time(philosophers), philosophers->id,END);
	else if (!ft_strcmp(status, "THINK"))
		printf("%s[%lld] %d is thinking%s\n", PINK, ft_get_actual_time(philosophers), philosophers->id,END);
	else if (!ft_strcmp(status, "DIE"))
		printf("%s[%lld] %d die%s\n", RED, ft_get_actual_time(philosophers), philosophers->id,END);
}
