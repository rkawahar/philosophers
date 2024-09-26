/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:23:34 by rkawahar          #+#    #+#             */
/*   Updated: 2024/09/26 18:34:49 by kawaharadar      ###   ########.fr       */
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

t_info	*creat_node(char **argv)
{
	t_info	*ans;
	int		num[5];
	int		i;

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
	ans = (t_info *)malloc(sizeof(t_info));
	if (ans == NULL)
		return (NULL);
	ans->members = num[0];
	ans->limit = num[1];
	ans->eat = num[2];
	ans->sleep = num[3];
	ans->meal = num[4];
	return (ans);
}

int	main(int argc, char **argv)
{
	t_info	*routine;

	if (argc != 5 && argc != 6)
	{
		printf("Variable Error: There must be four or five variables.\n");
		return (1);
	}
	if (check_numbers(argv))
	{
		printf("Variable Error: Variables must be in integer type.\n");
		return (1);
	}
	routine = creat_node(argv);
	if (!routine)
	{
		printf("Malloc error or the numbers are not in integer type.\n");
		return (1);
	}
}
