/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   born.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:42:59 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/10/02 12:43:02 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*odd_philos_move(void *identity_void)
{
	t_identity	*identity;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;

	identity = (t_identity*)identity_void;
	right = &(identity->routine->forks[identity->name - 1]);
	if (identity->name == identity->routine->members)
		left = &(identity->routine->forks[0]);
	else
		left = &(identity->routine->forks[identity->name]);
	while(1)
	{
		printf_mutex(identity, THINK);
		pthread_mutex_lock(right);
		printf_mutex(identity, FORK);
		pthread_mutex_lock(left);
		printf_mutex(identity, FORK);
		identity->routine->last_dinner[identity->name - 1] = gettime() - identity->routine->party_start;
		printf_mutex(identity, EAT);
		wait_func(identity->routine->eat);
		pthread_mutex_unlock(right);
		pthread_mutex_unlock(left);
		printf_mutex(identity, SLEEP);
		wait_func(identity->routine->sleep);
	}
}

void	create_odd_philo(t_info *routine, int i)
{
	t_identity	identity;
	pthread_t	thread;

	identity.name = i;
	identity.routine = routine;
	pthread_create(&thread, NULL, odd_philos_move, &identity);
	routine->threads[i - 1] = thread;
}

void	*even_philos_move(void *identity_void)
{
	t_identity	*identity;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;

	identity = (t_identity*)identity_void;
	right = &(identity->routine->forks[identity->name - 1]);
	if (identity->name == identity->routine->members)
		left = &(identity->routine->forks[0]);
	else
		left = &(identity->routine->forks[identity->name]);
	wait_func(30);
	while(1)
	{
		printf("%ld %d is thinking\n", gettime() - identity->routine->party_start, identity->name);
		pthread_mutex_lock(right);
		printf("%ld %d has taken a fork\n", gettime() - identity->routine->party_start, identity->name);
		pthread_mutex_lock(left);
		printf("%ld %d has taken a fork\n", gettime() - identity->routine->party_start, identity->name);
		identity->routine->last_dinner[identity->name - 1] = gettime() - identity->routine->party_start;
		printf("%ld %d is eating\n", gettime() - identity->routine->last_dinner[identity->name - 1], identity->name);
		wait_func(identity->routine->eat);
		pthread_mutex_unlock(right);
		pthread_mutex_unlock(left);
		printf("%ld %d is sleeping\n", gettime() - identity->routine->party_start, identity->name);
		wait_func(identity->routine->sleep);
	}
}

void	create_even_philo(t_info *routine, int i)
{
	t_identity identity;
	pthread_t	thread;

	identity.name = i;
	identity.routine = routine;
	pthread_create(&thread, NULL, even_philos_move, &identity);
	routine->threads[i - 1] = thread;
}
