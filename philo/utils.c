/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:53:34 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/10/17 22:52:45 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_death(t_info *life)
{
	pthread_mutex_lock(life->print);
	printf("%ld %d is died\n", gettime() - life->party_start, life->name);
	pthread_mutex_unlock(life->print);
}

long	gettime(void)
{
	struct timeval	time;
	long			ans;

	gettimeofday(&time, NULL);
	ans = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ans);
}

void	wait_func(long time, t_info *life)
{
	long	wait_start;
	long	finish_time;

	wait_start = gettime();
	finish_time = wait_start + time;
	while (1)
	{
		if (finish_time < gettime() || check_death_flg(life))
			break ;
		usleep(150);
	}
}

void	print_mutex(t_info *life, int type)
{
	long	time;

	pthread_mutex_lock(life->death_check);
	if (*(life->death) == 1 || life->euthanasia)
	{
		pthread_mutex_unlock(life->death_check);
		return ;
	}
	pthread_mutex_unlock(life->death_check);
	time = gettime() - life->party_start;
	pthread_mutex_lock(life->print);
	if (type == THINK)
		printf("%ld %d is thinking\n", time, life->name);
	else if (type == FORK)
		printf("%ld %d has taken a fork\n", time, life->name);
	else if (type == EAT)
		printf("%ld %d is eating\n", time, life->name);
	else if (type == SLEEP)
		printf("%ld %d is sleeping\n", time, life->name);
	pthread_mutex_unlock(life->print);
}

int	check_death_flg(t_info *life)
{
	int	ans;

	ans = 0;
	pthread_mutex_lock(life->death_check);
	if (*(life->death) == 1)
		ans = 1;
	pthread_mutex_unlock(life->death_check);
	return (ans);
}
