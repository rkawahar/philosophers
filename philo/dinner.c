/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:58:39 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/10/17 19:13:59 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat_counter(t_info *lis, int eat_time)
{
	pthread_mutex_lock(lis->time_check);
	lis->last_dinner = gettime() - lis->party_start;
	pthread_mutex_unlock(lis->time_check);
	if (lis->meal == eat_time)
	{
		lis->euthanasia = 1;
		pthread_mutex_lock(lis->death_check);
		*(lis->death) = *(lis->death) - 1;
		pthread_mutex_unlock(lis->death_check);
	}
}

void	*philos_life(void *routine)
{
	t_info	*philo;
	int		eat_time;

	eat_time = 0;
	philo = (t_info *)routine;
	if (philo->name % 2 == 0)
		wait_func(30, philo);
	while (1)
	{
		pthread_mutex_lock(philo->right_fork);
		print_mutex(philo, FORK);
		pthread_mutex_lock(philo->left_fork);
		print_mutex(philo, FORK);
		print_mutex(philo, EAT);
		eat_counter(philo, ++eat_time);
		wait_func(philo->eat, philo);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		print_mutex(philo, SLEEP);
		wait_func(philo->sleep, philo);
		print_mutex(philo, THINK);
		if (check_death_flg(philo) || philo->euthanasia)
			break ;
	}
	return (NULL);
}

void	life_is_beautiful(t_info *routine)
{
	t_info		*first;
	pthread_t	the_death;

	first = routine;
	while (routine)
	{
		pthread_create(&(routine->thread), NULL, philos_life, routine);
		routine = routine->next;
	}
	pthread_create(&the_death, NULL, the_death_life, first);
	while (first)
	{
		pthread_join(first->thread, NULL);
		first = first->next;
	}
	pthread_join(the_death, NULL);
}
