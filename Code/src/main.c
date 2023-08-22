/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:44:29 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/21 14:20:01 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_philo(t_philo *philo)
{
	
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_info	info;

	if (argc == 2 && !ft_strcmp(argv[1], "--help"))
		help(); // CREAR FUNCION HELP
	else if ((argc == 5 || argc == 6) && !arguments_checker(argv))
	{
		ft_argv_to_info(argv, &info);
		philo = (t_philo *)malloc(sizeof(t_philo) * info.n_philo);
		if (philo == NULL)
			return (NULL);
		ft_philo(philo);
	}
	else
		printf("Error: Incorrect arguments. For help run: philo --help");
}
