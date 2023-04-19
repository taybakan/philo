/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 03:04:04 by taybakan          #+#    #+#             */
/*   Updated: 2023/04/19 08:02:39 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(t_philo *philo)
{
	while (1)
	{
		if (getforks(philo))
			break ;
		if (ph_sleep(philo))
			break ;
	}
	return (NULL);
}

int	ft_is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->death);
	if (philo->data->is_dead == 1)
		return (1);
	pthread_mutex_unlock(philo->death);
	return (0);
}

int	getforks(t_philo *philo)
{
	pthread_mutex_lock(philo->plate);
	if (philo->n_eat != -1 && philo->total_eat >= philo->n_eat
		&& philo->finished == 0)
	{
		philo->finished = 1;
		philo->data->is_ate++;
		pthread_mutex_unlock(philo->plate);
		return (1);
	}
	pthread_mutex_unlock(philo->plate);
	pthread_mutex_lock(philo->right_fork_mutex);
	if (ph_write(philo, "has taken a fork\n"))
		return (1);
	pthread_mutex_lock(philo->left_fork_mutex);
	if (ph_write(philo, "has taken a fork\n"))
		return (1);
	if (dinner(philo))
		return (1);
	return (0);
}

int	dinner(t_philo *philo)
{
	pthread_mutex_lock(philo->plate);
	philo->last_eat = ft_get_time();
	if (ph_write(philo, "is eating\n"))
		return (1);
	philo->total_eat++;
	pthread_mutex_unlock(philo->plate);
	ph_wait(philo->t_eat, ft_get_time());
	pthread_mutex_unlock(philo->left_fork_mutex);
	pthread_mutex_unlock(philo->right_fork_mutex);
	return (0);
}

int	ph_sleep(t_philo *philo)
{
	if (ph_write(philo, "is sleeping\n"))
		return (1);
	ph_wait(philo->t_sleep, ft_get_time());
	if (ph_write(philo, "is thinking\n"))
		return (1);
	return (0);
}
