/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:44:29 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/13 20:19:28 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_philo(t_philo *philosophers)
{
	if (philosophers->info->n_philosophers == 1)
		one_philosopher(philosophers);
	else
	{
		ft_threads(philosophers);
		ft_loop(philosophers);
	}
}

int	main(int argc, char **argv)
{
	t_philo	*philosophers;
	t_info	info;

	if (argc == 2 && !ft_strcmp(argv[1], "--help"))
		ft_help();
	else
	{
		arguments_checker(argv);
		ft_init_info(argv, &info);
		philosophers = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(argv[1]));
		if (philosophers == NULL)
			ft_errors(MALLOC_FAIL);
		ft_init_philosophers(philosophers, &info);
		ft_philo(philosophers);
		ft_free(philosophers, &info);
	}
}
