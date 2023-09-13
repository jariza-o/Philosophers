/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:01:03 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/13 20:23:51 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	ft_print_actual_time(t_philo *philosophers)
{
	printf("Time: %lld ", ft_get_actual_time(philosophers));
}

void	ft_print_status(t_philo *philosophers, char *status)
{
	static int	i;
	if (!ft_strcmp(status, "FORK") && i == 0)
		printf("%s[%lld] %d has taken a fork%s\n", YELLOW, ft_get_actual_time(philosophers), philosophers->id,END);
	else if (!ft_strcmp(status, "EAT") && i == 0)
		printf("%s[%lld] %d is eating%s\n", BLUE, ft_get_actual_time(philosophers), philosophers->id,END);
	else if (!ft_strcmp(status, "SLEEP") && i == 0)
		printf("%s[%lld] %d is sleeping%s\n", PURPLE, ft_get_actual_time(philosophers), philosophers->id,END);
	else if (!ft_strcmp(status, "THINK") && i == 0)
		printf("%s[%lld] %d is thinking%s\n", PINK, ft_get_actual_time(philosophers), philosophers->id,END);
	else if (!ft_strcmp(status, "DIE") && i == 0)
	{
		printf("%s[%lld] %d die%s\n", RED, ft_get_actual_time(philosophers), philosophers->id,END);
		i = 1;
	}
}
