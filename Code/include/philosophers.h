/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:45:30 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/01 15:46:49 by jariza-o         ###   ########.fr       */
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
	int		n_philosophers;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		t_all_eat;
	long long		t_start;
	pthread_mutex_t	*forks;
	
	// struct s_philo	*philos; //como t_philo está declarado abajo, hay que declararlo así // ESTO LO USO PARA LUEGO DECLARAR ASI EL Nº PHILOS
	// int	t_active;
}	t_info;

typedef struct s_philo
{
	t_info			*info;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	left_fork;
	int				last_eat;
	int				num_eat;
	pthread_t	philosophers;
}	t_philo;

/* Errors */
int			arguments_checker(char **str);

/* Philosophers functions */
void		ft_argv_to_info(char **argv, t_info *info, t_philo *philosophers);
void		one_philosopher(t_philo *philo);

/* TIME */
long long	ft_get_time_ms(void);
void		ft_t_start_to_info(t_philo *philosopher);
long long	ft_get_actual_time(t_philo *philosophers);

/* Utils */
int			ft_strcmp(char *s1, char *s2);
int			ft_atoi(const char *str);
void		ft_print_actual_time(t_philo *philosophers);

#endif