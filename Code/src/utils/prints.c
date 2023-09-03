/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:01:03 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/03 19:28:08 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	ft_print_actual_time(t_philo *philosophers)
{
	printf("Time: %lld ", ft_get_actual_time(philosophers));
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
