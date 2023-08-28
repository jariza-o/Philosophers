/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:45:30 by jariza-o          #+#    #+#             */
/*   Updated: 2023/08/28 16:50:21 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef enum e_error
{
	ERROR,
}	t_error;

typedef struct s_info
{
	int	n_philosophers;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	t_all_eat;
	//int	t_active;
}	t_info;

typedef struct s_philo
{
	long long		t_start;
	t_info			*philosophers;
	// pthread_mutex_t	*forks;
}	t_philo;

/* Errors */
int			arguments_checker(char **str);

/* Philosophers functions */
void		ft_argv_to_info(char **argv, t_philo *philo);
void		one_philosopher(t_philo *philo);

/* TIME */
long long	ft_get_time_ms(void);
long long	ft_get_actual_time(t_philo *philo);

/* Utils */
int			ft_strcmp(char *s1, char *s2);
int			ft_atoi(const char *str);
void		ft_print_actual_time(t_philo *philo);

#endif