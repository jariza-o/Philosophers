/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:01:03 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/12 18:56:18 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	ft_print_actual_time(t_philo *philosophers)
{
	printf("Time: %lld ", ft_get_actual_time(philosophers));
}

void	ft_printf_info(t_philo *philosophers)
{
	int	i;

	i = 0;
	printf("n_philo: %d\n", philosophers->info->n_philosophers);
	printf("t_die: %d\n", philosophers->info->t_die);
	printf("t_eat: %d\n", philosophers->info->t_eat);
	printf("t_sleep: %d\n", philosophers->info->t_sleep);
	printf("t_think: %d\n", philosophers->info->t_think);
	printf("t_all_eat: %d\n", philosophers->info->t_all_eat);
	printf("t_start: %lld\n", philosophers->info->t_start);
	printf("IMPRIMIR FORKS\n");
	printf("is_dead: %d\n", philosophers->info->is_dead);
	printf("is_eaten: %d\n", philosophers->info->is_eaten);
	printf("IMPRIMIR MUTEX INFO\n");
}

void	ft_print_status(t_philo *philosophers, char *status)
{
	if (!ft_strcmp(status, "FORK"))
		printf("%s[%lld] %d has taken a fork\n", YELLOW, ft_get_actual_time(philosophers), philosophers->id);
	else if (!ft_strcmp(status, "EAT"))
		printf("%s[%lld] %d is eating\n", BLUE, ft_get_actual_time(philosophers), philosophers->id);
	else if (!ft_strcmp(status, "SLEEP"))
		printf("%s[%lld] %d is sleeping\n", PURPLE, ft_get_actual_time(philosophers), philosophers->id);
	else if (!ft_strcmp(status, "THINK"))
		printf("%s[%lld] %d is thinking\n", PINK, ft_get_actual_time(philosophers), philosophers->id);
	else if (!ft_strcmp(status, "DIE"))
		printf("%s[%lld] %d die\n", RED, ft_get_actual_time(philosophers), philosophers->id);
}
