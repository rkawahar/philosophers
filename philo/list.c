/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:20:11 by kawaharadar       #+#    #+#             */
/*   Updated: 2024/10/16 22:55:10 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_info	*creat_node(int	*num, int name)
{
	t_info	*ans;

	ans = (t_info *)malloc(sizeof(t_info));
	if (ans == NULL)
		return (NULL);
	ans->members = num[0];
	ans->limit = (long)num[1];
	ans->eat = (long)num[2];
	ans->sleep = (long)num[3];
	ans->meal = num[4];
	ans->name = name;
	ans->next = NULL;
	ans->pre = NULL;
	ans->time_check = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(ans->time_check, NULL);
	ans->euthanasia = 0;
	return (ans);
}

void	init_fork(t_info *lis)
{
	pthread_mutex_t	*fork;

	fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(fork, NULL);
	lis->left_fork = fork;
	if (lis->next == NULL)
	{
		while (lis->pre)
			lis = lis->pre;
		lis->right_fork = fork;
		return ;
	}
	else
		lis->next->right_fork = fork;
}

void	create_fork(t_info *lis)
{
	pthread_mutex_t *print_mutex;
	long			time;
	int				*death_flg;
	pthread_mutex_t	*death_mutex;

	print_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	death_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	death_flg = (int *)malloc(sizeof(int));
	*death_flg = 0;
	time = gettime();
	pthread_mutex_init(print_mutex, NULL);
	pthread_mutex_init(death_mutex, NULL);
	while (lis)
	{
		init_fork(lis);
		lis->print = print_mutex;
		lis->death_check = death_mutex;
		lis->death = death_flg;
		lis->last_dinner = 0;
		lis->party_start = time;
		lis = lis->next;
	}
}

t_info	*create_list(int *num)
{
	t_info	*lis;
	t_info	*tmp;
	t_info	*first;
	int		i;

	lis = creat_node(num, 1);
	first = lis;
	i = 2;
	while (i <= num[0])
	{
		tmp = creat_node(num, i++);
		lis->next = tmp;
		tmp->pre = lis;
		lis = lis->next;
	}
	create_fork(first);
	return (first);
}
