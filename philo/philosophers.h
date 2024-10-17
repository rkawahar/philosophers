/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:30:52 by rkawahar          #+#    #+#             */
/*   Updated: 2024/10/17 21:33:10 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdarg.h>
# include <limits.h>

# define THINK 1
# define FORK 2
# define SLEEP 3
# define EAT 4
# define DEATH 5

typedef struct s_info
{
	int				members;
	long			limit;
	long 			eat;
	long			sleep;
	int				meal;
	int				name;
	int				*death;
	long			party_start;
	long			last_dinner;
	int				euthanasia;
	pthread_t		thread;
	pthread_mutex_t	*print;
	pthread_mutex_t	*death_check;
	pthread_mutex_t	*time_check;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_info		*next;
	struct s_info		*pre;
}	t_info;

t_info	*create_list(int *num);
long	gettime(void);
void	life_is_beautiful(t_info *routine);
void	wait_func(long time, t_info *life);
void	print_mutex(t_info *life, int type);
void	*the_death_life(void *routine);
int		check_death_flg(t_info *life);
void	print_death(t_info *life);
void	philosopher(int *num);

#endif