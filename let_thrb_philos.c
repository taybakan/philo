/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_thrb_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 01:32:14 by taybakan          #+#    #+#             */
/*   Updated: 2023/04/09 06:12:04 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_creat(int argc, char **argv, t_args *args)
{
	int	i;

	args->n_philo = ft_atol(argv[1]);
	args->t_die = ft_atol(argv[2]);
	args->t_eat = ft_atol(argv[3]);
	args->t_sleep = ft_atol(argv[4]);
	if (argc == 6)
		args->n_eat = ft_atol(argv[5]);
	else
		args->n_eat = -1;
	args->philo = malloc(sizeof(t_philo *) * (args->n_philo - 1));
	i = 0;
	while (i < args->n_philo)
	{
		args->philo[i] = malloc(sizeof(t_philo));
		args->philo[i]->id = i + 1;
		args->philo[i]->n_philo = args->n_philo;
		args->philo[i]->t_die = args->t_die;
		args->philo[i]->t_eat = args->t_eat;
		args->philo[i]->t_sleep = args->t_sleep;
		args->philo[i]->n_eat = args->n_eat;
		i++;
	}	
	printf("%d\n", args->philo[1]->id);
}
