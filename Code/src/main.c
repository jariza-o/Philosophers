/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:44:29 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/17 16:32:13 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int argc, char **argv)
{
	if (argc == 2 && !ft_strcmp(argv[1], "--help"))
		help(); // CREAR FUNCION HELP
	else if (argc == 5 || argc == 6)
	{
		//hACER COMPROBACIONES Y DEMAS
	}
	else
		printf("Error: Incorrect arguments. For help run: philo --help");
}
