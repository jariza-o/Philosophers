/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:08:19 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/13 20:19:39 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	arguments_checker(char **str)
{
	int	i;
	int	n;

	i = 1;
	while (str[i])
	{
		n = 0;
		while (str[i][n])
		{
			if (str[i][n] >= '0' && str[i][n] <= '9')
				n++;
			else
				ft_errors(ARGUMENTS_FAIL);
		}
		i++;
	}
	if (i != 5 && i != 6)
		ft_errors(ARGUMENTS_FAIL);
	if (ft_atoi(str[1]) < 1 || ft_atoi(str[1]) > 200)
		ft_errors(PHILO_LIMIT);
}

void	ft_errors(int error)
{
	if (error == MALLOC_FAIL)
		printf("Error: Failed to allocated memory.\n");
	else if (error == THREAD_FAIL)
		printf("Error: Failed creating the threads.\n");
	else if (error == ARGUMENTS_FAIL)
		printf("Error: Incorrect arguments. For help run: philo --help\n");
	else if (error == PHILO_LIMIT)
	{
		printf("Error: the minimum number of philosophers is 1 and the ");
		printf("maximum number is 200.\n");
	}
	else if (error == MUTEX_FAIL)
		printf("Error: Failed to create the mutex\n");
	exit (1);
}
