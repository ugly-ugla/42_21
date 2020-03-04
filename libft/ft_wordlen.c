/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 22:54:19 by jkarren           #+#    #+#             */
/*   Updated: 2020/03/04 14:56:37 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordlen(char *str, const char lim_ch)
{
	size_t	len;

	len = -1;
	while (str[++len] && str[len] != lim_ch)
		;
	return (len);
}
