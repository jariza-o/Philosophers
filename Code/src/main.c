/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:44:29 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/28 16:59:50 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

// void	ft_init_stuct(t_philo *philo)
// {
// 	philo = (t_philo *)malloc(sizeof(t_philo));
// 	philo->t_start = 0;
// 	philo->philosophers->n_philosophers = 0;
// 	philo->philosophers->t_die = 0;
// 	philo->philosophers->t_eat = 0;
// 	philo->philosophers->t_sleep = 0;
// 	philo->philosophers->t_all_eat = 0;
// }


void	ft_philo(t_philo *philo)
{
	philo->t_start = ft_get_time_ms();

	if (philo->philosophers->n_philosophers == 1)
		one_philosopher(philo);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	// ft_init_stuct(philo);
	if (argc == 2 && !ft_strcmp(argv[1], "--help"))
		printf("HELP FUNCTION\n");
		// help(); // CREAR FUNCION HELP
	else if ((argc == 5 || argc == 6) && !arguments_checker(argv))
	{
		ft_argv_to_info(argv, philo);
		philo = (t_philo *)malloc(sizeof(t_philo) * philo->philosophers->n_philosophers);
		if (philo == NULL)
			return 0;
		ft_philo(philo);
	}
	else
		printf("Error: Incorrect arguments. For help run: philo --help");
}
