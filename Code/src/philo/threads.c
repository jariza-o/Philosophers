/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:19:31 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/04 20:11:02 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	ft_threads(t_philo *philosophers)
{
	int			i;
	pthread_t	*person;

	person = (pthread_t *)malloc(sizeof(pthread_t) * philosophers->info->n_philosophers);
	if (person == NULL)
		ft_errors(MALLOC_FAIL);
	i = 0;
	philosophers->info->t_start = ft_t_start_to_info(philosophers);
	while (i < philosophers->info->n_philosophers - 1)
	{
		if ((pthread_create(&person[i], NULL, NAME_FUNCION, &philosophers[i])) != 0) //CREAR FUNCION PARA NAME_FUNCION
			return ; //CREAR FUNCION DE ERROR
		i++;
	}
}
