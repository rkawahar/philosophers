/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:31:06 by rkawahar          #+#    #+#             */
/*   Updated: 2024/07/06 15:04:34 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	argc_error(void)
{
	ft_printf("\nYou have to write 4 or 5 arguments.\n\n");
	ft_printf("number_of_philosophers: The number of philosophers ");
	ft_printf("and also the number of forks.\n");
	ft_printf("time_to_die (in milliseconds): If a philosopher didnt ");
	ft_printf("start eating time_to_die milliseconds since ");
	ft_printf("the beginning of their ");
	ft_printf("last meal or the beginning of the simulation, they die.\n");
	ft_printf("time_to_eat (in milliseconds): The time it takes for a ");
	ft_printf("philosopher to eat.During that time, they will need ");
	ft_printf("to hold two forks.\n");
	ft_printf("time_to_sleep (in milliseconds): The time a philosopher will ");
	ft_printf("spend sleeping.\n");
	ft_printf("number_of_times_each_philosopher_must_eat (optional ");
	ft_printf("argument): If all philosophers have eaten at least ");
	ft_printf("number_of_times_each_philosopher_must_eat times, the ");
	ft_printf("simulation stops. If not specified, the simulation stops ");
	ft_printf("when a philosopher dies.\n");
}

void	number_error(void)
{
	ft_printf("The number would be bigger than 0, smaller than %ld\n", INT_MAX);
	exit(0);
}
