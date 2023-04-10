/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 03:04:04 by taybakan          #+#    #+#             */
/*   Updated: 2023/04/09 07:24:25 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	*routine(t_philo *philo)
{
    ft_setup(philo);
    if(philo->id % 2 == 0)
	    usleep(50);
    while (0)
        getforks(philo);
	return (NULL);
}

void    ft_setup(t_philo *philo)
{
    philo->t_init = ft_get_time();
    philo->last_eat = ft_get_time(); 
}

//void    getforks(t_philo *philo);
//{   
//    (void)philo;
//}