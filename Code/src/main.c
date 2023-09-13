/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:44:29 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/13 16:22:19 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

// void	ft_init_stuct(t_philo *philo)
// {
// 	philo->t_start = 0;
// 	philo->philosophers.n_philosophers = 0;
// 	philo->philosophers.t_die = 0;
// 	philo->philosophers.t_eat = 0;
// 	philo->philosophers.t_sleep = 0;
// 	philo->philosophers.t_all_eat = 0;
// }


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
	t_info	info; // NO COMPILA PORQUE ESTA UNITILIZADA Y NO SI INCIALIZARLA

	if (argc == 2 && !ft_strcmp(argv[1], "--help"))
		ft_help();
	else // if ((argc == 5 || argc == 6) && !arguments_checker(argv)) // COMENTADO PORQUE HE CAMBIADO LA FUNCION DE ARG_CHECk
	{
		arguments_checker(argv);
		ft_init_info(argv, &info);
		philosophers = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(argv[1]));
		if (philosophers == NULL) //preguntar si es lo mismo que if (!philosophers)
			ft_errors(MALLOC_FAIL);
		ft_init_philosophers(philosophers, &info);
		ft_philo(philosophers);
		ft_free(philosophers, &info); //lo podría hacer sin pasarle info ya que esta en philosophers la dirección de info
	}
	// else // COMENTADO PORQUE HE CAMBIADO LA FUNCION DE ARG_CHECk
	// 	ft_errors(ARGUMENTS_FAIL);
}
