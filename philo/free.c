/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 22:58:05 by rkawahar          #+#    #+#             */
/*   Updated: 2024/10/18 00:40:45 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_mutex_destory(t_info *life)
{
	pthread_mutex_destroy(life->print);
	pthread_mutex_destroy(life->death_check);
	pthread_mutex_destroy(life->right_fork);
	while (life->next)
	{
		pthread_mutex_destroy(life->time_check);
		pthread_mutex_destroy(life->left_fork);
		life = life->next;
	}
	pthread_mutex_destroy(life->time_check);
}

void	ft_free(int *num, t_info *life)
{
	(void)num;
	ft_mutex_destory(life);
	free(num);
	free(life->death);
	free(life->print);
	free(life->death_check);
	free(life->right_fork);
	while (life->next)
	{
		free(life->time_check);
		free(life->left_fork);
		life = life->next;
		free(life->pre);
	}
	free(life->time_check);
	free(life);
}
