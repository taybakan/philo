#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef unsigned long long t_time;

typedef struct s_philo
{
	int				id;
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	pthread_t		thread;
	pthread_mutex_t	*fork;
}		t_philo;

typedef struct s_args
{
	int			n_philo;
	int			t_die;
	int			t_eat;
	int			t_sleep;
	int			n_eat;
	t_philo		**philo;
}		t_args;

long	ft_atol(const char *str);
int     ft_checkinput(char **argv);
void    thread_init(t_args *args);
void	*routine(t_philo *philo);
void	ft_creat(int argc, char **argv, t_args *args);

#endif