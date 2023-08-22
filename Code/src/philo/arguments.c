/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:57:35 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/21 14:10:25 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	ft_argv_to_info(char **argv, t_info *info)
{
	info->n_philo = ft_atoi(argv[1]);
	info->n_philo = ft_atoi(argv[2]);
	info->t_sleep = ft_atoi(argv[4]);
	if (argv[5]) //ver si así es correcto
		info->t_all_eat = ft_atoi(argv[5]);
	else
		info->t_all_eat = NULL; // ver si esto es asi, sino poner numero negativo
}
