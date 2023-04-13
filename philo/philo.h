/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 04:10:04 by taybakan          #+#    #+#             */
/*   Updated: 2023/04/13 04:30:08 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef unsigned long long	t_time;

typedef struct s_philo
{
	int						id;
	int						n_philo;
	int						t_die;
	int						t_eat;
	int						t_sleep;
	int						n_eat;
	int						total_eat;
	int						rip;
	t_time					last_eat;
	t_time					t_init;
	pthread_t				thread;
	pthread_mutex_t			*plate;
	pthread_mutex_t			*write;
	pthread_mutex_t			*left_fork_mutex;
	pthread_mutex_t			*right_fork_mutex;
}							t_philo;

typedef struct s_args
{
	int						n_philo;
	t_philo					**philo;
}							t_args;

int							ft_atol(char *str);
int							ft_checkinput(char **argv);
void						thread_init(t_args *args);
void						ph_wait(int w_time, int p_time);
void						*routine(t_philo *philo);
void						ft_creat(int argc, char **argv, t_args *args);
void						getforks(t_philo *philo);
void						dinner(t_philo *philo);
void						ph_sleep(t_philo *philo);
int							ph_write(t_philo *philo, char *status);
int							ft_isdead(t_args *args);
int							ft_strncmp(const char *s1, const char *s2,
								size_t n);
int							free_exit(int i, t_args *args);
int							ft_isdigit(int c);
t_time						ft_get_time(void);

#endif