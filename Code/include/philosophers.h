/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:45:30 by jariza-o          #+#    #+#             */
/*   Updated: 2023/09/15 11:29:25 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define YELLOW "\033[0;93m"
# define BLUE "\033[0;96m"
# define PURPLE "\033[0;95m"
# define PINK "\033[0;91m"
# define RED "\033[0;31m"
# define END "\033[0m"
# define PRINT "\033[38;5;154m"

/* ERRORS DEFINES */
# define MALLOC_FAIL	1
# define THREAD_FAIL	2
# define ARGUMENTS_FAIL	3
# define PHILO_LIMIT	4
# define MUTEX_FAIL		5

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_info
{
	int				n_philosophers;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				t_think;
	int				t_all_eat;
	long long		t_start;
	pthread_mutex_t	*forks;
	int				is_dead;
	int				is_eaten;
	pthread_mutex_t	*mutex_info;
	pthread_mutex_t	*mutex_print;
}	t_info;

typedef struct s_philo
{
	t_info			*info;
	int				id;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*mutex_eat;
	int				last_eat;
	int				num_eat;
	pthread_t		*person;
}	t_philo;

/* HELP */
void		ft_help(void);

/* Errors */
void		arguments_checker(char **str);
void		ft_errors(int error);

/* Philosophers functions */
/* Init Functions */
void		ft_init_info(char **argv, t_info *info);
void		ft_init_philosophers(t_philo *philosophers, t_info *info);

/* Rutine Functions */
void		one_philosopher(char **argv);
void		ft_threads(t_philo *philosophers);
void		*ft_thread_routine(void *arg);
void		ft_loop(t_philo *philosophers);
int			ft_stop(t_philo *philosophers);
void		ft_take_forks(t_philo *philosophers);
void		ft_eat(t_philo *philosophers);
void		ft_sleep(t_philo *philosophers);
void		ft_think(t_philo *philosophers);
int			ft_is_dead(t_philo *philosophers);

/* Time Functions */
long long	ft_get_time_ms(void);
long long	ft_get_actual_time(t_philo *philosophers);
long long	ft_t_start_to_info(t_philo *philo);

/* Free functions*/
void		ft_free_forks(t_info *info);
void		ft_free(t_philo *philosophers, t_info *info);

/* Print functions */
void		ft_print_status(t_philo *philosophers, char *status);

/* Utils */
int			ft_strcmp(char *s1, char *s2);
int			ft_atoi(const char *str);
long int	ft_atol(const char *str);
void		ft_print_actual_time(t_philo *philosophers);

#endif