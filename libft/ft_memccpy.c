/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <jkarren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 01:44:48 by jkarren           #+#    #+#             */
/*   Updated: 2020/03/04 14:35:34 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,
		size_t n)
{
	size_t			i;
	unsigned char	*rst;

	i = -1;
	rst = (unsigned char*)dst;
	while (++i < n)
	{
		rst[i] = ((unsigned char *)src)[i];
		if (rst[i] == (unsigned char)c)
			return ((void*)(dst + ++i));
	}
	return (NULL);
}
