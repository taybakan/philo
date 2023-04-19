/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   azrael.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:45:47 by taybakan          #+#    #+#             */
/*   Updated: 2023/04/19 06:37:43 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_ate(t_args *args)
{
    if (args->philo[0]->n_eat == - 1)
	{	
        return (1);
	}
    else if (args->philo[0]->data->is_ate >= args->n_philo)
	{
        return (0);
	}
	else
	{
    	return (1);
	}
}

int	*args_to_die(t_args *args, int i)
{
	int *check;

	check = malloc(sizeof(int) * 2);
	pthread_mutex_lock(args->philo[0]->plate);
	if ((int)(ft_get_time() - (args->philo[i]->last_eat)) > args->philo[i]->t_die)
		check[0] = 1;
	else
		check[0] = 0;
	check[1] = is_ate(args);
	pthread_mutex_unlock(args->philo[0]->plate);
	return (check);
}

int	azrael(t_args *args)
{
	int *check;
	int	i;
	int	j;

	ph_wait(ft_get_time(), args->philo[0]->t_die);
	j = 0;
	while (1)
	{
		i = 0;
		while (i < args->n_philo)
		{
			check = args_to_die(args, i);
			pthread_mutex_lock(args->philo[i]->death);
			if (check[0] == 1 && check[1] == 1)
            {
                args->philo[i]->data->is_dead = 1;
				return (ph_write(args->philo[i], "is dead\n"));
            }
			pthread_mutex_unlock(args->philo[i]->death);
			i++;
        	if (check[1] == 0)
			{
				free(check);
            	return (0);
			}
			free(check);
		}
	}
	return (0);
}