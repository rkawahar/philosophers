/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:44:11 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/10/01 20:35:30 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	*set_table(int num)
{
	int		i;
	long	*ans;

	i = 0;
	ans = (long *)malloc(sizeof(long) * num);
	if (ans == NULL)
		return (NULL);
	while (i < num)
	{
		ans[i] = 0;
		i++;
	}
	return (ans);
	}

pthread_mutex_t	*set_forks(int num)
{
	pthread_mutex_t	*ans;
	int				i;

	i = 0;
	ans = malloc(sizeof(pthread_mutex_t) * num);
	if (ans == NULL)
		return (NULL);
	while (i < num)
		pthread_mutex_init(&(ans[i++]), NULL);
	return (ans);
}

void	start_party(t_info *routine)
{
	int		i;

	i = 0;
	routine->party_start = gettime();
	while (i < routine->members)
	{
		if (i % 2 == 0)
			create_odd_philo(routine, i + 1);
		else
			create_even_philo(routine, i + 1);
		i++;
	}
	i = 0;
	while (i < routine->members)
		pthread_join(routine->threads[i++], NULL);
}

void	life_is_beautiful(t_info *routine)
{
	routine->last_dinner = set_table(routine->members);
	if (routine->last_dinner == NULL)
		return ;
	routine->forks = set_forks(routine->members);
	pthread_mutex_init(&(routine->print), NULL);
	if (routine->forks == NULL)
	{
		free(routine->last_dinner);
		return ;
	}
	routine->threads = (pthread_t*)malloc(sizeof(pthread_t) * routine->members);
	if (routine->threads == NULL)
	{
		free(routine->last_dinner);
		free(routine->forks);
		return ;
	}
	start_party(routine);
}
