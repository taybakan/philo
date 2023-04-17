/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 01:26:43 by taybakan          #+#    #+#             */
/*   Updated: 2023/04/17 20:41:15 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_args	*args;

	if (argc < 5 || argc > 6)
		return (1);
	if (ft_checkinput(argv))
		return (1);
	args = malloc(sizeof(t_args));
	if (ft_creat(argc, argv, args))
		return (1);
	if (thread_init(args))
		return (1);
	return (0);
}
