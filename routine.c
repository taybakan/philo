/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 03:04:04 by taybakan          #+#    #+#             */
/*   Updated: 2023/04/09 06:14:36 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	*routine(t_philo *philo)
{
    if(philo->id % 2 == 0)
	    usleep(50);
    get_equipped(t_philo *philo);
	return (NULL);
}

void    get_equipped(t_philo *philo)
{
    
}
