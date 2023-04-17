/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 01:26:54 by taybakan          #+#    #+#             */
/*   Updated: 2023/04/17 20:42:46 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		thread_init(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->n_philo)
	{
		args->philo[i]->t_init = ft_get_time();
		args->philo[i]->last_eat = ft_get_time();
		args->philo[i]->total_eat = 0;
		if (pthread_create(&args->philo[i]->thread, NULL, (void *)routine,
				args->philo[i]))
			return(1);
		usleep(50);
		i++;
	}
	i = 0;
	if (azrael(args))
		return (0);
	thread_join(args);
	return(0);
}

int 	thread_join(t_args *args)
{
	int		i;

	i = 0;
	while (i < args->n_philo)
	{
		if (pthread_join(args->philo[i]->thread, NULL))
			return(1);
		i++;
	}
	return (0);
}
