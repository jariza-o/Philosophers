/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:07:29 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/14 21:23:49 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

long long	ft_get_actual_time_one(long long t_base)
{
	return (ft_get_time_ms() - t_base);
}

void	one_philosopher(char **argv)
{
	long long	t_base;
	long long	t_actual;
	long long	t_die;

	t_base = ft_get_time_ms();
	t_die = ft_atoi(argv[2]);
	t_actual = ft_get_actual_time_one(t_base);
	printf("%s[%lld] %d has taken a fork%s\n", YELLOW, t_actual, 1, END);
	while (ft_get_actual_time_one(t_base) < t_die)
	{
	}
	printf("%s[%lld] %d die%s\n", RED, t_die, 1, END);
}
