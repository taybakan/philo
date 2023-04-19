/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_and_terminate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:14:27 by taybakan          #+#    #+#             */
/*   Updated: 2023/04/17 18:44:57 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_wait(int w_time, int p_time)
{
	t_time	t;

	t = ft_get_time();
	while ((int)(t - p_time) < w_time)
	{
		t = ft_get_time();
		usleep(3);
	}
	return (0);
}