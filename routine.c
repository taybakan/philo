/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 03:04:04 by taybakan          #+#    #+#             */
/*   Updated: 2023/04/10 17:48:24 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	*routine(t_philo *philo)
{
    int i = 7;
    ft_setup(philo);
    if(philo->id % 2 == 0)
	    usleep(50);
    while(i--)
    {
    getforks(philo);
    dinner(philo);
    ph_sleep(philo);
    }
	return (NULL);
}

void    ft_setup(t_philo *philo)
{
    philo->t_init = ft_get_time();
    philo->last_eat = ft_get_time(); 
}

void    getforks(t_philo *philo)
{   
    pthread_mutex_lock(philo->right_fork_mutex);
    printf("philo %d has taken a fork\n", philo->id);
    pthread_mutex_lock(philo->left_fork_mutex);
    printf("philo %d has taken a fork\n", philo->id);
}

void    dinner(t_philo *philo)
{
    printf("philo %d is eating\n", philo->id);
    pthread_mutex_unlock(philo->left_fork_mutex);
    pthread_mutex_unlock(philo->right_fork_mutex);
}

void    ph_sleep(t_philo *philo)
{
    printf("philo %d is sleeping\n", philo->id);
    usleep(philo->t_sleep);
    printf("philo %d is thinking\n", philo->id);
}