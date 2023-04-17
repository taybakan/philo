/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 01:58:35 by taybakan          #+#    #+#             */
/*   Updated: 2023/04/17 20:33:15 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_write(t_philo *philo, char *status)
{
	t_time	now;

	now = ft_get_time() - philo->t_init;	
	if (!ft_strncmp(status, "is dead\n", 8))
	{
		printf("%llu: philo %d %s", now, philo->id, status);
		pthread_mutex_unlock(philo->death);
		return (1);
	}
	if (ft_is_dead(philo))
		return (1);
	pthread_mutex_lock(philo->write);
	printf("%llu: philo %d %s", now, philo->id, status);
	pthread_mutex_unlock(philo->write);
	return (0);
}
