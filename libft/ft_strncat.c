/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <jkarren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 01:52:06 by jkarren           #+#    #+#             */
/*   Updated: 2019/09/29 19:26:30 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*str1;

	str1 = s1;
	while (*s1)
		s1++;
	while (*s2 && n--)
		*s1++ = *s2++;
	*s1 = '\0';
	return (str1);
}