/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 01:26:54 by taybakan          #+#    #+#             */
/*   Updated: 2023/04/09 05:34:22 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void    thread_init(t_args *args)
{
    int     i;

    i = 0;
    while(i < args->n_philo)
    {
        pthread_create(&args->philo[i]->thread, NULL, (void *)routine, args->philo[i]);
		i++;
    }
	i = 0;
	while(i < args->n_philo)
	{
		pthread_join(args->philo[i]->thread, NULL);
		i++;
	}
}