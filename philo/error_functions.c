/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:31:06 by rkawahar          #+#    #+#             */
/*   Updated: 2024/09/26 18:29:30 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_numbers(char **num)
{
	int	i;
	int	index;

	i = 1;
	while (num[i])
	{
		index = 0;
		while(num[i][index])
		{
			if (num[i][index] < '0' || num[i][index] > '9')
				return (1);
			index++;
		}
		i++;
	}
	return (0);
}