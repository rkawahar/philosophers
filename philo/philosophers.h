/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:30:52 by rkawahar          #+#    #+#             */
/*   Updated: 2024/10/02 12:43:08 by kawaharadar      ###   ########.fr       */
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

typedef struct s_info
{
	int				members;
	int				limit;
	int 			eat;
	int				sleep;
	int				meal;
	long			*last_dinner;
	long			party_start;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	pthread_t		*threads;
}	t_info;

typedef struct s_identity
{
	int				name;
	t_info			*routine;
}	t_identity;

int		check_numbers(char **num);
void	life_is_beautiful(t_info *routine);
void	create_odd_philo(t_info *routine, int i);
void	create_even_philo(t_info *routine, int i);
long	gettime(void);
void	wait_func(long time);
void	printf_mutex(t_identity *identity, int type);

#endif