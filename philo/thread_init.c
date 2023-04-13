/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 01:26:54 by taybakan          #+#    #+#             */
/*   Updated: 2023/04/13 04:11:21 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_init(t_args *args)
{
	int i;

	i = 0;
	while (i < args->n_philo)
	{
		args->philo[i]->t_init = ft_get_time();
		args->philo[i]->total_eat = 0;
		if (pthread_create(&args->philo[i]->thread, NULL, (void *)routine,
				args->philo[i]))
			free_exit(1, args);
		usleep(30);
		i++;
	}
	ft_isdead(args);
	i = 0;
	while (i < args->n_philo)
	{
		if (pthread_join(args->philo[i]->thread, NULL))
			free_exit(1, args);
		i++;
	}
}
