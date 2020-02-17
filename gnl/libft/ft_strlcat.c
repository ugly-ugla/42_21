/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <jkarren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 01:52:18 by jkarren           #+#    #+#             */
/*   Updated: 2019/09/29 19:26:08 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char			*dest_cpy;
	const char		*src_cpy;
	size_t			i;
	size_t			dlen;

	i = size;
	dest_cpy = dest;
	src_cpy = src;
	while (i-- && *dest_cpy)
		dest_cpy++;
	dlen = dest_cpy - dest;
	i = size - dlen;
	if (i == 0)
		return (dlen + ft_strlen((char *)src_cpy));
	while (*src_cpy)
	{
		if (i != 1)
		{
			*dest_cpy++ = *src_cpy;
			--i;
		}
		src_cpy++;
	}
	*dest_cpy = '\0';
	return (dlen + (src_cpy - src));
}
