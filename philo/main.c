/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 01:26:43 by taybakan          #+#    #+#             */
/*   Updated: 2023/04/13 04:28:40 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_args	*args;

	if (argc < 5 || argc > 6)
		return (0);
	if (!ft_checkinput(argv))
		return (0);
	args = malloc(sizeof(t_args));
	ft_creat(argc, argv, args);
	thread_init(args);
	return (0);
}
