/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:31:06 by rkawahar          #+#    #+#             */
/*   Updated: 2024/09/17 10:41:55 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	argc_error(void)
{
	printf("\nYou have to write 4 or 5 arguments.\n\n");
	printf("number_of_philosophers: The number of philosophers ");
	printf("and also the number of forks.\n");
	printf("time_to_die (in milliseconds): If a philosopher didnt ");
	printf("start eating time_to_die milliseconds since ");
	printf("the beginning of their ");
	printf("last meal or the beginning of the simulation, they die.\n");
	printf("time_to_eat (in milliseconds): The time it takes for a ");
	printf("philosopher to eat.During that time, they will need ");
	printf("to hold two forks.\n");
	printf("time_to_sleep (in milliseconds): The time a philosopher will ");
	printf("spend sleeping.\n");
	printf("number_of_times_each_philosopher_must_eat (optional ");
	printf("argument): If all philosophers have eaten at least ");
	printf("number_of_times_each_philosopher_must_eat times, the ");
	printf("simulation stops. If not specified, the simulation stops ");
	printf("when a philosopher dies.\n");
}

void	number_error(void)
{
	printf("The number would be bigger than 0, smaller than %ld\n", INT_MAX);
	exit(0);
}
