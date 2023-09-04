/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:08:19 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/04 19:49:45 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

int	arguments_checker(char **str)
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
				return (1);
		}
		i++;
	}
	return (0);
}

void	ft_errors(int error)
{
	if (error == MALLOC_FAIL)
		printf("Error: Failed to allocated memory.\n");
	exit (1);
}
