/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_csqrt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:25:24 by jkarren           #+#    #+#             */
/*   Updated: 2020/03/04 14:25:34 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** calculate square root of x with ceiling
*/

int		ft_csqrt(int x)
{
	int	ret;

	ret = 0;
	while (ret * ret < x)
		++ret;
	return (ret);
}
