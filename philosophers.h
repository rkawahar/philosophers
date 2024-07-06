/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:30:52 by rkawahar          #+#    #+#             */
/*   Updated: 2024/07/06 15:11:23 by rkawahar         ###   ########.fr       */
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

typedef struct s_info
{
	int	*members;
	int	*limit;
	int	*eat;
	int	*sleep;
	int	*meal;
}	t_info;

int		ft_printf(const char *str, ...);
int		ft_print_itoa(int num, int len);
int		ft_print_uint(unsigned int num, int len);
int		ft_to_hexaddress(unsigned long int num, int len);
int		ft_to_hex(unsigned int num, int len);
int		ft_to_upperhex(unsigned int num, int len);
void	argc_error(void);

#endif