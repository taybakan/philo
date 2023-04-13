/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 03:04:04 by taybakan          #+#    #+#             */
/*   Updated: 2023/04/13 04:10:39 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(t_philo *philo)
{
	while (philo->n_eat == -1 || philo->total_eat < philo->n_eat)
	{
		getforks(philo);
		ph_sleep(philo);
	}
	return (NULL);
}

void	getforks(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork_mutex);
	ph_write(philo, "has taken a fork\n");
	pthread_mutex_lock(philo->left_fork_mutex);
	ph_write(philo, "has taken a fork\n");
	dinner(philo);
}

void	dinner(t_philo *philo)
{
	pthread_mutex_lock(philo->plate);
	ph_write(philo, "is eating\n");
	philo->last_eat = ft_get_time();
	philo->total_eat++;
	pthread_mutex_unlock(philo->plate);
	ph_wait(ft_get_time(), philo->t_eat);
	pthread_mutex_unlock(philo->left_fork_mutex);
	pthread_mutex_unlock(philo->right_fork_mutex);
}

void	ph_sleep(t_philo *philo)
{
	ph_write(philo, "is sleeping\n");
	ph_wait(ft_get_time(), philo->t_sleep);
	ph_write(philo, "is thinking\n");
}