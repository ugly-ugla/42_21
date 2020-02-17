/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:47:43 by jkarren           #+#    #+#             */
/*   Updated: 2019/09/17 13:07:32 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		ln;
	char	*dp_str;

	ln = 0;
	while (src[ln])
		++ln;
	dp_str = (char *)malloc(sizeof(char) * ln);
	if (dp_str)
	{
		ln = 0;
		while (src[ln])
		{
			dp_str[ln] = src[ln];
			++ln;
		}
		dp_str[ln] = '\0';
	}
	return (dp_str);
}
