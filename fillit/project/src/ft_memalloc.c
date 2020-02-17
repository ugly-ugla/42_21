/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 01:44:32 by jkarren           #+#    #+#             */
/*   Updated: 2020/02/12 17:55:23 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_memalloc(size_t size)
{
	void	*arr;

	arr = (void *)malloc(size);
	if (arr)
	{
		ft_bzero(arr, size);
		return (arr);
	}
	return (NULL);
}
