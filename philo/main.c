/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:23:34 by rkawahar          #+#    #+#             */
/*   Updated: 2024/10/18 00:17:28 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(char *str)
{
	int	ans;
	int	i;
	int	tmp;

	ans = 0;
	i = 0;
	while (str[i])
	{
		tmp = str[i] - '0';
		if (ans > (2147483647 - tmp) / 10)
			return (-1);
		ans = ans * 10 + tmp;
		i++;
	}
	return (ans);
}

int	check_numbers(char **num)
{
	int	i;
	int	index;

	i = 1;
	while (num[i])
	{
		index = 0;
		while (num[i][index])
		{
			if (num[i][index] < '0' || num[i][index] > '9')
				return (1);
			index++;
		}
		i++;
	}
	return (0);
}

int	*ft_atois(char **argv)
{
	int	*num;
	int	i;

	num = (int *)malloc(sizeof(int) * 5);
	if (num == NULL)
		return (NULL);
	i = 0;
	while (++i < 6)
	{
		if (argv[i] == NULL)
			num[i - 1] = 0;
		else
		{
			num[i - 1] = ft_atoi(argv[i]);
			if (num[i - 1] == -1)
				return (NULL);
		}
	}
	return (num);
}

int	main(int argc, char **argv)
{
	t_info	*routine;
	int		*num;

	if (argc != 5 && argc != 6)
		return \
		(printf("Variable Error: There must be four or five variables.\n"));
	if (check_numbers(argv))
		return (printf("Variable Error: Variables must be in integer type.\n"));
	num = ft_atois(argv);
	if (num == NULL || num[0] == 0)
	{
		free(num);
		return (printf("Argv[1] must be bigger than 0.\n"));
	}
	if (num[0] == 1)
		philosopher(num);
	else
	{
		routine = create_list(num);
		if (!routine)
			return \
			(printf("Malloc error or the numbers are not in integer type.\n"));
		life_is_beautiful(routine, num);
	}
	return (0);
}
