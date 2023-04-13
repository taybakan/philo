/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   azrael.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 02:51:02 by taybakan          #+#    #+#             */
/*   Updated: 2023/04/13 04:18:52 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdead(t_args *args)
{
	int	i;
	int	j;

	ph_wait(ft_get_time(), args->philo[0]->t_die);
	j = 0;
	while (1)
	{
		i = 0;
		while (i < args->n_philo)
		{
			pthread_mutex_lock(args->philo[i]->plate);
			if ((int)(ft_get_time()
				- (args->philo[i]->last_eat)) > args->philo[i]->t_die)
				free_exit(ph_write(args->philo[i], "is dead\n"), args);
			pthread_mutex_unlock(args->philo[i]->plate);
			pthread_mutex_lock(args->philo[i]->plate);
			if (args->philo[i]->total_eat == args->philo[i]->n_eat)
				j++;
			pthread_mutex_unlock(args->philo[i]->plate);
			if (j >= args->n_philo - 1)
				return (0);
			i++;
		}
	}
	return (0);
}
