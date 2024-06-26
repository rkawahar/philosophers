/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:30:52 by rkawahar          #+#    #+#             */
/*   Updated: 2024/06/26 17:33:08 by rkawahar         ###   ########.fr       */
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

int		ft_printf(const char *str, ...);
int		ft_print_itoa(int num, int len);
int		ft_print_uint(unsigned int num, int len);
int		ft_to_hexaddress(unsigned long int num, int len);
int		ft_to_hex(unsigned int num, int len);
int		ft_to_upperhex(unsigned int num, int len);
void	argc_error(void);

#endif