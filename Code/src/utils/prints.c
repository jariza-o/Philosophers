/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:01:03 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/14 15:58:08 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	ft_print_actual_time(t_philo *philosophers)
{
	printf("Time: %lld ", ft_get_actual_time(philosophers));
}

void	ft_print_status(t_philo *philo, char *status)
{
	long long int	time;

	time = ft_get_actual_time(philo);
	pthread_mutex_lock(philo->info->mutex_print);
	if (!ft_strcmp(status, "FORK"))
		printf("%s[%lld] %d has taken a fork%s\n", YELLOW, time, philo->id, END);
	else if (!ft_strcmp(status, "EAT"))
		printf("%s[%lld] %d is eating%s\n", BLUE, time, philo->id, END);
	else if (!ft_strcmp(status, "SLEEP"))
		printf("%s[%lld] %d is sleeping%s\n", PURPLE, time, philo->id, END);
	else if (!ft_strcmp(status, "THINK"))
		printf("%s[%lld] %d is thinking%s\n", PINK, time, philo->id, END);
	else if (!ft_strcmp(status, "DIE"))
		printf("%s[%lld] %d die%s\n", RED, time, philo->id, END);
	pthread_mutex_unlock(philo->info->mutex_print);
}
