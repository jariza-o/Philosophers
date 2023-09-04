/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:45:30 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/04 20:09:41 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define YELLOW "\033[0;93m"
# define BLUE "\033[0;96m"
# define PURPLE "\033[0;95m"
# define PINK "\033[0;91m"
# define RED "\033[0;31m"
# define END "\033[0m" // NO SE SI USAR

# define MALLOC_FAIL	1

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
	int				n_philosophers;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				t_all_eat;
	long long		t_start;
	pthread_mutex_t	*forks; //CREO QUE SE PUEDE QUITAR
	int				is_dead;
	// struct s_philo	*philos; //como t_philo está declarado abajo, hay que declararlo así // ESTO LO USO PARA LUEGO DECLARAR ASI EL Nº PHILOS
	// int	t_active;
}	t_info;

typedef struct s_philo
{
	t_info			*info;
	int				id;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	left_fork;
	int				last_eat;
	int				num_eat;
	pthread_t		philosophers;
}	t_philo;

/* HELP */
void		ft_help(void);

/* Errors */
int			arguments_checker(char **str);
void		ft_errors(int error);

/* Philosophers functions */
void		ft_init_info(char **argv, t_info *info);
void		ft_init_philosophers(t_philo *philosophers, t_info *info);
void		one_philosopher(t_philo *philo);
void		ft_threads(t_philo *philosophers);

/* TIME */
long long	ft_get_time_ms(void);
long long	ft_get_actual_time(t_philo *philosophers);
long long	ft_t_start_to_info(t_philo *philo);

/* Print functions */
void		ft_print_status(t_philo *philosophers, char *status);

/* Utils */
int			ft_strcmp(char *s1, char *s2);
int			ft_atoi(const char *str);
void		ft_print_actual_time(t_philo *philosophers);

#endif