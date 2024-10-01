/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:53:34 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/09/26 23:46:46 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	gettime(void)
{
	struct timeval	time;
	long			ans;

	gettimeofday(&time, NULL);
	ans = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ans);
}
void	wait_func(long time)
{
	long 	wait_start;
	long	finish_time;

	wait_start = gettime();
	finish_time = wait_start + time;
	while (1)
	{
		if (finish_time < gettime())
			break;
		usleep(150);
	}
}
