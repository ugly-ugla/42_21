/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 01:44:32 by jkarren           #+#    #+#             */
/*   Updated: 2020/03/04 14:39:05 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*arr;

	if (!size)
		return (NULL);
	arr = (void *)malloc(size);
	if (arr)
	{
		ft_bzero(arr, size);
		return (arr);
	}
	return (NULL);
}
