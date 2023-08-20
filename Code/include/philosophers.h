/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:45:30 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/20 13:12:03 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_philo
{
	int	n_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	t_all_eat;
}	t_philo;

/* Errors */
int		arguments_checker(char **str);

/* Philosophers functions */
void	ft_argv_to_int(char **argv, t_philo *philo);

/* Utils */
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(const char *str);

#endif