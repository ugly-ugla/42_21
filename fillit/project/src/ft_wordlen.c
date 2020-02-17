/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 22:54:19 by jkarren           #+#    #+#             */
/*   Updated: 2020/02/12 17:48:38 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_wordlen(char *str, const char lim_ch)
{
	int len;

	len = -1;
	while (str[++len] && str[len] != lim_ch)
		;
	return (len);
}
