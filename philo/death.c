/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 01:13:06 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/10/21 11:30:13 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	checker(t_info *life)
{
	int	ans;

	ans = 0;
	pthread_mutex_lock(life->death_check);
	if (*(life->death) == -(life->members))
		ans = 1;
	pthread_mutex_unlock(life->death_check);
	return (ans);
}

t_info	*judge(t_info *life)
{
	if (life->next)
			life = life->next;
	else
	{
		while (life->pre)
			life = life->pre;
	}
	return (life);
}

void	*the_death_life(void *routine)
{
	t_info	*life;
	long	time;
	long	lastdinner;

	life = (t_info *)routine;
	while (1)
	{
		pthread_mutex_lock(life->time_check);
		lastdinner = life->last_dinner;
		pthread_mutex_unlock(life->time_check);
		time = gettime() - life->party_start - lastdinner;
		if (time > life->limit || checker(life) == 1)
		{
			pthread_mutex_lock(life->death_check);
			*(life->death) = 1;
			pthread_mutex_unlock(life->death_check);
			if (checker(life) == 0)
				print_death(routine, time + lastdinner);
		}
		if (check_death_flg(life) || checker(life))
			break ;
		life = judge(life);
	}
	return (NULL);
}
