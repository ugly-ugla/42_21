/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:49:21 by jkarren           #+#    #+#             */
/*   Updated: 2019/09/17 13:02:30 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int fctrl;

	fctrl = 1;
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (fctrl);
	if (nb > 1)
	{
		fctrl = nb;
		while (nb > 1 && nb--)
			fctrl *= nb;
	}
	return (fctrl);
}
