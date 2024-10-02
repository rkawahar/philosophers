/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:53:34 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/10/02 12:40:40 by kawaharadar      ###   ########.fr       */
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
void	printf_mutex(t_identity *identity, int type)
{
	pthread_mutex_lock(&identity->routine->print);
	if (type == THINK)
		printf("%ld %d is thinking\n", gettime() - identity->routine->party_start, identity->name);
	else if (type == FORK)
		printf("%ld %d has taken a fork\n", gettime() - identity->routine->party_start, identity->name);
	else if (type == EAT)
		printf("%ld %d is eating\n", identity->routine->last_dinner[identity->name - 1], identity->name);
	else if (type == SLEEP)
		printf("%ld %d is sleeping\n", gettime() - identity->routine->party_start, identity->name);
	pthread_mutex_unlock(&identity->routine->print);
}
