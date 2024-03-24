/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:27:58 by jaqribei          #+#    #+#             */
/*   Updated: 2024/03/23 21:07:58 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_dinner	t_dinner;

enum						e_philo_state
{
	HAS_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
};

typedef struct s_philo_state
{
	enum e_philo_state	mode;
	long				time;
}	t_philo_state;

typedef struct s_philo
{
	int				id;
	int				last_meal;
	int				number_of_meals;
	pthread_t		philo;
	t_dinner		*philo_diner;
	t_philo_state	state;
}					t_philo;

typedef struct s_dinner
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_meals;
	int				is_dead;
	int				program_start;
	t_philo			*philos;
	pthread_mutex_t	*fork;
	pthread_mutex_t	one_fork;
	pthread_mutex_t	mutex_control_eat;
	pthread_mutex_t	mutex_state;
	pthread_mutex_t	mutex_dead;
	pthread_mutex_t	mutex_print;

}					t_dinner;

t_dinner	*get_input(void);

int			ft_atoi(const char *nptr);
int			check_validate_args(int argc, char *argv[]);
void		ft_bzero(void *s, size_t n);
void		init_philo(int argc, char *argv[]);
void		populate_philo(void);
long		get_time(void);
void		thread_create(void);
int			verify_dinner_state(void);
void		*philosopher_routine(void *param);
void		set_philosopher_state(t_philo *philo, enum e_philo_state mode);
void		philo_eat_routine(t_philo *philo, enum e_philo_state mode);
void		philo_sleep_routine(t_philo *philo, enum e_philo_state mode);
int			philo_take_forks(t_philo *philo, int first, int second,
				enum e_philo_state mode);
int			verify_forks(int first, int second);

#endif