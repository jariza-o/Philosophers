/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:44:29 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/14 21:27:16 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

// static void ft_leaks()
// {
// 	system("leaks -q philo");
// }

void	ft_philo(t_philo *philosophers, t_info *info)
{
	ft_threads(philosophers);
	ft_loop(philosophers);
	usleep(1000);
	ft_free(philosophers, info);
}

int	main(int argc, char **argv)
{
	// atexit(ft_leaks);
	t_philo	*philosophers;
	t_info	info;

	if (argc == 2 && !ft_strcmp(argv[1], "--help"))
		ft_help();
	else
	{
		arguments_checker(argv);
		if (ft_atoi(argv[1]) == 1)
			one_philosopher(argv);
		else
		{
			ft_init_info(argv, &info);
			philosophers = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(argv[1]));
			if (philosophers == NULL)
				ft_errors(MALLOC_FAIL);
			ft_init_philosophers(philosophers, &info);
			ft_philo(philosophers, &info);
		}
	}
}
