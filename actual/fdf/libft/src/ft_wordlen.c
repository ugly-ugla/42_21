/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 22:54:19 by jkarren           #+#    #+#             */
/*   Updated: 2019/09/29 23:00:21 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_wordlen(char *str, const char lim_ch)
{
	int len;

	len = -1;
	while (str[++len] && str[len] != lim_ch)
		;
	return (len);
}
