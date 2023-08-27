/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:45:30 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/27 11:59:42 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

typedef enum e_error
{
	ERROR,
}	t_error;

typedef struct s_info
{
	int			t_die;
	int			t_eat;
	int			t_active;
}	t_info;

typedef struct s_forks
{
	int				available;
	pthread_mutex_t	fork_available;
}	t_forks;

typedef struct s_philo
{
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		t_all_eat;
	t_info	*philosophers;
	t_forks	forks;
}	t_philo;

/* Errors */
int		arguments_checker(char **str);

/* Philosophers functions */
void	ft_argv_to_info(char **argv, t_info *info);

/* Utils */
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(const char *str);

#endif