/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:44:29 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/20 13:12:35 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_philo(t_philo *philo)
{
	
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (argc == 2 && !ft_strcmp(argv[1], "--help"))
		help(); // CREAR FUNCION HELP
	else if ((argc == 5 || argc == 6) && !arguments_checker(argv))
	{
		philo = (t_philo *)malloc(sizeof(t_philo));
		if (philo == NULL)
			return (NULL);
		ft_argv_to_int(argv, philo);
		ft_philo(philo);
	}
	else
		printf("Error: Incorrect arguments. For help run: philo --help");
}
