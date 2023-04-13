/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:47:40 by taybakan          #+#    #+#             */
/*   Updated: 2023/04/13 04:19:36 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_exit(int i, t_args *args)
{
	int	j;

	j = -1;
	while (j++ < args->n_philo)
		free(args->philo[j]);
	free(args);
	exit(i);
}
