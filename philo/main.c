/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:23:34 by rkawahar          #+#    #+#             */
/*   Updated: 2024/07/06 15:19:47 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	checker(char c, long num, int flg)
{
	if (num == 0)
		return (0);
	if (flg == -1)
	{
		num *= -1;
		if ((LONG_MIN + (c - '0')) / 10 > num)
			return (1);
	}
	else
	{
		if ((LONG_MAX - (c - '0')) / 10 < num)
			return (1);
	}
	return (0);
}

int	checker2(int flg)
{
	if (flg == 1)
		return ((int)LONG_MAX);
	else
		return ((int)LONG_MIN);
}

unsigned int	ft_atoi(const char *str)
{
	size_t			i;
	unsigned int	num;
	int				neg_flg;

	num = 0;
	i = 0;
	neg_flg = 1;
	while (str[i] == 32 || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		neg_flg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		if (checker(str[i], num, neg_flg))
			return (checker2(neg_flg));
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	num *= neg_flg;
	return (num);
}

void	create_nord(int *num)
{
	t_info	routine;

	routine.members = num[0];
	routine.limit = num[1];
	routine.eat = num[2];
	routine.sleep = num[3];
	if (num[4])
		routine.meal = num[4];
	else
		routine.meal = NULL;
	
}

int	main(int argc, char **argv)
{
	int		i;
	int		num[5];

	if (argc < 5 || 6 < argc)
		argc_error();
	i = 1;
	while (i < argc)
	{
		num[i - 1] = 0;
		i++;
	}
	i = 1;
	while (argv[i])
	{
		num[i - 1] = ft_atoi(argv[i]);
		if (num < 1)
			number_error();
		i++;
	}
	if (i == 5)
		num[i - 1] = 0;
	create_nord(num);
}
