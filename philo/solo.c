/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:43:49 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/10/18 00:05:44 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*solo_dinner(void *av)
{
	int		*num;
	long	party_start;
	long	finish_time;

	num = (int *)av;
	party_start = gettime();
	printf("0 1 has taken a fork\n");
	finish_time = party_start + (long)num[1];
	while (1)
	{
		if (finish_time < gettime())
			break ;
		usleep(150);
	}
	printf("%ld 1 is died\n", gettime() - party_start);
	return (NULL);
}

void	philosopher(int *num)
{
	pthread_t	*solo_life;

	solo_life = (pthread_t *)malloc(sizeof(t_info));
	pthread_create(solo_life, NULL, solo_dinner, num);
	pthread_join(*solo_life, NULL);
	free(solo_life);
	free(num);
}
