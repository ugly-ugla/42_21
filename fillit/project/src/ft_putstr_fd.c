/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <jkarren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 01:54:46 by jkarren           #+#    #+#             */
/*   Updated: 2020/02/12 17:56:05 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putstr_fd(const char *str, int fd)
{
	if (str)
		write(fd, str, ft_strlen((char *)str));
}
