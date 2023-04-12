/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 01:58:35 by taybakan          #+#    #+#             */
/*   Updated: 2023/04/12 21:25:18 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    ph_write(t_philo *philo, char *status)
{
    t_time  now;

    now = ft_get_time() - philo->t_init;
    pthread_mutex_lock(philo->write);
    printf("%llu: philo %d %s", now, philo->id, status);
    if(!ft_strncmp(status, "is dead\n", 8))
        exit(0);
    pthread_mutex_unlock(philo->write);
    return(0);
}