/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:47:40 by taybakan          #+#    #+#             */
/*   Updated: 2023/04/13 01:11:39 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int free_exit(int i, t_args *args)
{
    i = -1;
    while(i++ < args->n_philo)
        free(args->philo[i]);
    free(args);
    exit(0);
}