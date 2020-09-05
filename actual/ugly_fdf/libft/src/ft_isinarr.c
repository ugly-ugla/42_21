/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinarr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:45:17 by jkarren           #+#    #+#             */
/*   Updated: 2019/11/01 14:01:51 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_isinarr(char c, char *arr)
{
	char	*tmp;

	if (arr)
	{
		tmp = arr;
		while (*tmp)
		{
			if (*tmp == c)
				return (1);
			tmp++;
		}
	}
	return (0);
}
