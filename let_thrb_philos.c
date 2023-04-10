/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_thrb_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 01:32:14 by taybakan          #+#    #+#             */
/*   Updated: 2023/04/10 17:37:17 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mutex_init(t_args *args)
{
	int				i;
	pthread_mutex_t	death;
	pthread_mutex_t	*forks;

	forks = malloc(sizeof(pthread_mutex_t) * args->n_philo);
	i = 0;
	while (i < args->n_philo)
	{
		args->philo[i]->left_fork_mutex = &forks[i];
		args->philo[i]->right_fork_mutex = &forks[(i + 1) % args->n_philo]; 
		i++;
	}
	i = 0;
	while (i < args->n_philo)
	{
		pthread_mutex_init(args->philo[i]->left_fork_mutex, NULL);
		pthread_mutex_init(args->philo[i]->right_fork_mutex, NULL);
		args->philo[i]->death = &death;
		i++;
	}
	pthread_mutex_init(&death, NULL);
}

void	ft_creat(int argc, char **argv, t_args *args)
{
	int	i;

	args->n_philo = ft_atol(argv[1]);
	args->philo = malloc(sizeof(t_philo *) * args->n_philo);
	i = 0;
	while (i < args->n_philo)
	{
		args->philo[i] = malloc(sizeof(t_philo));
		args->philo[i]->id = (i + 1);
		args->philo[i]->n_philo = ft_atol(argv[1]);
		args->philo[i]->t_die = ft_atol(argv[2]);
		args->philo[i]->t_eat = ft_atol(argv[3]);
		args->philo[i]->t_sleep = ft_atol(argv[4]);
		if (argc == 6)
			args->philo[i]->n_eat = ft_atol(argv[5]);
		else
		args->philo[i]->n_eat = -1;
		i++;
	}
	ft_mutex_init(args);
}
