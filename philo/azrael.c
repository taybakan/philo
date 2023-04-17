/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   azrael.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:45:47 by taybakan          #+#    #+#             */
/*   Updated: 2023/04/17 20:47:25 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_ate(t_args *args)
{
    if (args->philo[0]->n_eat == - 1)
        return (1);
    if (args->philo[0]->data->is_ate >= args->n_philo)
        return (0);
    return (1);
}

int	azrael(t_args *args)
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
			pthread_mutex_lock(args->philo[i]->death);
			if ((int)(ft_get_time()
				- (args->philo[i]->last_eat)) > args->philo[i]->t_die
                && is_ate(args))
            {
                args->philo[i]->data->is_dead = 1;
				return (ph_write(args->philo[i], "is dead\n"));
            }
			pthread_mutex_unlock(args->philo[i]->death);
			i++;
		}
        if (!is_ate(args))
            return (0);
	}
	return (0);
}